#include "Banco.h"

#define findcell(str1, str2, i) while(str1[i] != ',' && str1[i] != '\0'){str2 += str1[i++];}i++;

int Banco::Conta::proxNum = 1;

Banco::Cliente::Cliente() {
}

Banco::Cliente::Cliente(const Cliente& copia) {

	nomeCliente = copia.nomeCliente;
	CPF = copia.CPF;
	End = copia.End;
	Fone = copia.Fone;
}

Banco::Cliente::Cliente(string nome, string cpf, string endereco, string fone) {

	nomeCliente = nome;
	CPF = cpf;
	End = endereco;
	Fone = fone;
}

string Banco::Cliente::getNome() {

	return nomeCliente;
}

string Banco::Cliente::getCPF() {
	return CPF;
}

string Banco::Cliente::getEnd() {
	return End;
}

string Banco::Cliente::getFone() {
	return Fone;
}

void Banco::Cliente::setNome(string nome) {
	nomeCliente = nome;
}

void Banco::Cliente::SetCPF(string cpf) {
	CPF = cpf;
}

void Banco::Cliente::setEnd(string endereco) {
	End = endereco;
}

void Banco::Cliente::setFone(string fone) {
	Fone = fone;
}

Banco::Conta::Conta() {

	numConta = NULL;
	Saldo = 0;
	Dono = Cliente();
}

Banco::Conta::Conta(Banco::Cliente& cliente) {

	numConta = proxNum++;
	Dono = cliente;
	Saldo = 0;
}

Banco::Conta::Conta(int num, double saldo, Banco::Cliente& c) {

	numConta = num;
	Saldo = saldo;
	Dono = c;
}

int Banco::Conta::getNum() {
	return numConta;
}

int Banco::Conta::getProx() {
	return proxNum;
}

void Banco::Conta::setProx(int num) {

	proxNum = num;
}

double Banco::Conta::getSaldo() {
	return Saldo;
}

Banco::Cliente Banco::Conta::getDono() {
	return Dono;
}

bool Banco::Conta::debitar(double valor, string descricao) {

	if ((Saldo - valor) > 0) {
		Saldo -= valor;
		Movis.push_back(Movimentacao(descricao, 'D', valor));
		return true;
	}

	return false;
}

void Banco::Conta::creditar(double valor, string descricao) {

	Saldo += valor;
	Movis.push_back(Movimentacao(descricao, 'C', valor));
}

void Banco::Conta::setExtrato(vector<Banco::Conta::Movimentacao> set) {

	Movis = set;
}

vector<Banco::Conta::Movimentacao> Banco::Conta::getExtrato() {

	return Movis;
}

vector<Banco::Conta::Movimentacao> Banco::Conta::getExtrato(Data inicio) {

	vector<Movimentacao> ext;

	for (Movimentacao i : Movis) {

		if (difftime(inicio.time, i.getDataMov().time) > 0)
			ext.push_back(i);
	}

	return ext;
}

vector<Banco::Conta::Movimentacao> Banco::Conta::getExtrato(Data inicio, Data fim) {

	vector<Movimentacao> ext;

	for (Movimentacao i : Movis) {

		if ((difftime(inicio.time, i.getDataMov().time) > 0) && (difftime(i.getDataMov().time, fim.time) < 0))
			ext.push_back(i);
	}

	return ext;
}

Banco::Conta::Movimentacao::Movimentacao() {
	
	DB = 'N';
	Valor = 0;
	dataMov = obterData();	
}

Banco::Conta::Movimentacao::Movimentacao(string desc, char dc, double valor) {

	DB = dc;
	Valor = valor;
	Desc = desc;
	dataMov = obterData();
}

Banco::Conta::Movimentacao::Movimentacao(string desc, char dc, double valor, Data data) {

	DB = dc;
	Valor = valor;
	Desc = desc;	
	dataMov = data;
}

string Banco::Conta::Movimentacao::getDesc() {
	return Desc;
}

char Banco::Conta::Movimentacao::getDB() {
	return DB;
}

double Banco::Conta::Movimentacao::getValor() {
	return Valor;
}

Data Banco::Conta::Movimentacao::getDataMov() {
	return dataMov;
}

Banco::Banco() {
}

Banco::Banco(string nome) {
	_Banco = nome;
}

void Banco::inserirCliente(Cliente x) {
	Clientes.push_back(x);
}

void Banco::criarConta(Cliente& x) {
	Contas.push_back(Conta(x));
}

void Banco::excluirCliente(string cpf) {

	bool match = false;

	if (checkCliente(cpf))
		Clientes.erase(Clientes.begin() + findCliente(cpf));
}

void Banco::excluirConta(int nConta) {

	if (checkConta(nConta))
		Contas.erase(Contas.begin() + findConta(nConta));
}

void Banco::deposito(int nConta, double valor) {

	if (checkConta(nConta))
		Contas[findConta(nConta)].creditar(valor, "Deposito");
}

bool Banco::saque(int nConta, double valor) {

	if (checkConta(nConta)) {

		Contas[findConta(nConta)].debitar(valor, "Saque");
		return true;
	}	

	return false;
}

bool Banco::transferencia(int c1, int c2, double valor) {

	if (checkConta(c1)) {
		if (checkConta(c2)) {
			if (Contas[findConta(c1)].debitar(valor, ("Transferencia para conta " + to_string(c1)))) {
				Contas[findConta(c2)].creditar(valor, ("Transferencia da conta " + to_string(c2)));
				return true;
			}
		}
	}

	return false;
}

void Banco::tarifa() {

	for (unsigned int i = 0; i < Contas.size(); i++)
		Contas[i].debitar(15, "Cobranca de tarifa");

}

void Banco::CPMF() {

	double tarifa;
	Data now = obterData();

	for (unsigned int i = 0; i < Contas.size(); i++) {

		tarifa = 0;

		for (Conta::Movimentacao i : Contas[i].getExtrato()) {

			if (difftime(now.time, i.getDataMov().time) < 604800 && i.getDB() == 'D')
				tarifa += i.getValor();
		}

		tarifa *= 0.0038;

		Contas[i].debitar(tarifa, "Cobranca de CPMF");
		
	}
}

double Banco::saldo(int nConta) {

	if (checkConta(nConta))
		return Contas[findConta(nConta)].getSaldo();

	return -1;
}

vector<Banco::Conta::Movimentacao> Banco::extrato(int nConta) {

	Data now = obterData();
	int mes = now.mes;
	int ano = now.ano;

	vector<Conta::Movimentacao>	x;
	vector<Conta::Movimentacao> copy = Contas[findConta(nConta)].getExtrato();

	if (checkConta(nConta)) {

		for (Conta::Movimentacao i : copy)
			if (i.getDataMov().mes == mes && i.getDataMov().ano == ano)
				x.push_back(i);	
	}

	return x;
}

vector<Banco::Conta::Movimentacao> Banco::extrato(int nConta, Data inicio) {
	
	Data now = obterData();

	vector<Conta::Movimentacao>	copy;
	vector<Conta::Movimentacao>	x;

	if (checkConta(nConta)) {

		copy = Contas[findConta(nConta)].getExtrato();

		for (Conta::Movimentacao i : copy)		
			if (difftime(now.time, inicio.time) > 0)
				x.push_back(i);			
	}

	return x;
}

vector<Banco::Conta::Movimentacao> Banco::extrato(int nConta, Data inicio, Data fim) {

	Data now = obterData();

	vector<Conta::Movimentacao>	copy;
	vector<Conta::Movimentacao>	x;

	if (checkConta(nConta)) {

		copy = Contas[findConta(nConta)].getExtrato();

		for (Conta::Movimentacao i : copy)
			if (difftime(now.time, inicio.time) > 0 && difftime(now.time, fim.time) < 0)
				x.push_back(i);
	}

	return x;
}

vector<Banco::Cliente> Banco::clientes() {

	return Clientes;
}

vector<Banco::Conta> Banco::contas() {

	return Contas;
}

int Banco::findCliente(string cpf) {

	for (unsigned int i = 0; i < Clientes.size(); i++) {
		if (Clientes[i].getCPF() == cpf)
			return i;
	}

	return -1;
}

int Banco::findCliente(Cliente x) {

	for (unsigned int i = 0; i < Clientes.size(); i++) {
		if (Clientes[i].getCPF() == x.getCPF())
			return i;
	}

	return -1;
}

int Banco::findConta(int conta) {

	for (unsigned int i = 0; i < Contas.size(); i++) {
		if (Contas[i].getNum() == conta)
			return i;
	}

	return -1;
}

bool Banco::checkCliente(string cpf) {

	for (Cliente i : Clientes)
		if (i.getCPF() == cpf)
			return true;

	return false;
}

bool Banco::checkCliente(Cliente x) {

	for (Cliente i : Clientes)
		if (i.getCPF() == x.getCPF())
			return true;

	return false;
}

bool Banco::checkConta(int conta) {

	for (Conta i : Contas)
		if (i.getNum() == conta)
			return true;

	return false;
}

bool Banco::checkConta(string cpf) {

	for (Cliente i : Clientes)
		for (Conta j : Contas)
			if (i.getCPF() == j.getDono().getCPF() && i.getCPF() == cpf)
				return true;

	return false;
}

Banco::Cliente* Banco::cliente(int i) {

	return &(Clientes[i]);
}

Banco::Conta* Banco::conta(int i) {

	return &(Contas[i]);
}

void Banco::save(string file) {

	ofstream save;
	save.open(file, ofstream::out | ofstream::trunc);

	for (Cliente i : Clientes)
		save << i.getNome() << "," << i.getCPF() << "," << i.getFone() << "," << i.getEnd() << endl;

	save << "-" << endl;

	for (Conta i : Contas)
		save << i.getNum() << "," << i.getSaldo() << "," << i.getDono().getCPF() << endl;

	save << "-" << endl;

	if (Contas.size() > 0)
		save << Contas[0].getProx() << endl;
	else
		save << "0" << endl;

	save << "-" << endl;

	for (Conta i : Contas) {
		
		vector<Conta::Movimentacao> x = i.getExtrato();

		save << i.getNum() << endl;

		for (Conta::Movimentacao j : x)
			save << j.getDataMov().time << "," << j.getValor() << "," << j.getDB() << "," << j.getDesc() << endl;

		save << endl;
	}
}

void Banco::load(string file) {

	ifstream load;
	load.open(file);

	int i;
	string line;
	string cell;

	getline(load, line);

	if (line == "-" || line.size() == 0)
		return;

	while (line != "-") {

		vector<string> att;
		i = 0;

		for (int j = 0; j < 4; j++) {

			findcell(line, cell, i);
			att.push_back(cell);
			cell.clear();
		}

		this->inserirCliente(Cliente(att[0], att[1], att[2], att[3]));

		getline(load, line);
	}

	getline(load, line);

	while (line != "-") {

		vector<string> att;
		i = 0;

		for (int j = 0; j < 3; j++) {

			findcell(line, cell, i);
			att.push_back(cell);
			cell.clear();
		}

		Contas.push_back(Conta(stoi(att[0]), stod(att[1]), Clientes[findCliente(att[2])]));

		cell.clear();
		getline(load, line);
	}

	getline(load, line);
		
	if (line != "0") {

		Contas[0].setProx(stoi(line));
	}

	getline(load, line);
	getline(load, line);

	int k = 0;

	while (!load.eof()) {
		
		int n = 0;
		
		vector<Conta::Movimentacao> set;

		int nConta = stoi(line);
		getline(load, line);

		while (line.size() > 0) {

			i = 0;
			vector<string> att;

			for (int j = 0; j < 4; j++) {

				findcell(line, cell, i);
				att.push_back(cell);
				cell.clear();
			}

			set.push_back(Banco::Conta::Movimentacao(att[3], att[2][0], stod(att[1]), obterData(stoi(att[0]))));
			getline(load, line);			
		}

		cout << k << endl;

		Contas[k++].setExtrato(set);
		set.clear();
		getline(load, line);
	}		
};
