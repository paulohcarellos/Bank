#include "Conta.h"

int Banco::Conta::_Proximo_num_conta = 0;

Data obterData() {

	Data x;

	time_t t = time(NULL);
	struct tm* date = localtime(&t);

	x.time = t;
	x.seg = date->tm_sec;
	x.min = date->tm_min;
	x.hor = date->tm_hour;
	x.dia = date->tm_mday;
	x.mes = date->tm_mon;
	x.ano = date->tm_year;

	return x;
}

Banco::Cliente::Cliente() {
}

Banco::Cliente::Cliente(const Cliente& copia) {

	_Nome_cliente = copia._Nome_cliente;
	_Cpf_cnpj = copia._Cpf_cnpj;
	_Endereco = copia._Endereco;
	_Fone = copia._Fone;
}

Banco::Cliente::Cliente(string nome, string cpf, string endereco, string fone) {

	_Nome_cliente = nome;
	_Cpf_cnpj = cpf;
	_Endereco = endereco;
	_Fone = fone;
}

string Banco::Cliente::Get_nome() {

	return _Nome_cliente;
}

string Banco::Cliente::Get_Cpf_cnpj() {
	return _Cpf_cnpj;
}

string Banco::Cliente::Get_Endereco() {
	return _Endereco;
}

string Banco::Cliente::Get_Fone() {
	return _Fone;
}

void Banco::Cliente::Set_Nome(string nome) {
	_Nome_cliente = nome;
}

void Banco::Cliente::Set_Cpf_cnpj(string cpf) {
	_Cpf_cnpj = cpf;
}

void Banco::Cliente::Set_Endereco(string endereco) {
	_Endereco = endereco;
}

void Banco::Cliente::Set_Fone(string fone) {
	_Fone = fone;
}

Banco::Conta::Conta(Cliente& cliente) {

	_Num_conta = _Proximo_num_conta++;
	_Cliente = cliente;
	_Saldo = 0;
}

int Banco::Conta::Get_Numero_conta() {
	return _Num_conta;
}

double Banco::Conta::Get_saldo() {
	return _Saldo;
}

Banco::Cliente Banco::Conta::Get_cliente() {
	return _Cliente;
}

bool Banco::Conta::Debitar(double valor, string descricao) {

	if ((_Saldo - valor) < 0) {

		return false;
	}

	else {

		_Saldo -= valor;
		_Movimentacoes.push_back(Movimentacao(descricao, 'D', valor));

		return true;
	}
}

void Banco::Conta::Creditar(double valor, string descricao) {

	_Saldo += valor;
	_Movimentacoes.push_back(Movimentacao(descricao, 'C', valor));
}

vector<Banco::Conta::Movimentacao> Banco::Conta::extrato() {

	return _Movimentacoes;
}

vector<Banco::Conta::Movimentacao> Banco::Conta::extrato(Data inicio) {

	vector<Movimentacao> ext;

	for (Movimentacao i : _Movimentacoes) {

		if (difftime(inicio.time, i.Get_Data().time) > 0)
			ext.push_back(i);
	}

	return ext;
}

vector<Banco::Conta::Movimentacao> Banco::Conta::extrato(Data inicio, Data fim) {

	vector<Movimentacao> ext;

	for (Movimentacao i : _Movimentacoes) {

		if ((difftime(inicio.time, i.Get_Data().time) > 0) && (difftime(i.Get_Data().time, fim.time) < 0))
			ext.push_back(i);
	}

	return ext;
}

Banco::Conta::Movimentacao::Movimentacao() {

	_Data = obterData();
	_Debito_Credito = 'N';
	_Valor = 0;
}

Banco::Conta::Movimentacao::Movimentacao(string descricao, char debito_credito, double valor) {

	_Data = obterData();
	_Descricao = descricao;
	_Debito_Credito = debito_credito;
	_Valor = valor;
}

string Banco::Conta::Movimentacao::Get_Descricao() {	
	return _Descricao;
}

char Banco::Conta::Movimentacao::Get_Debito_Credito() {
	return _Debito_Credito;
}

double Banco::Conta::Movimentacao::Get_Valor() {
	return _Valor;
}

Data Banco::Conta::Movimentacao::Get_Data(){
	return _Data;
}

Banco::Banco(string nome) {

	_Banco = nome;
}

void Banco::inserirCliente(Cliente &x) {

	_Clientes.push_back(x);
}

void Banco::criarConta(Cliente &x) {

	_Contas.push_back(Conta(x));
}

void Banco::excluirCliente(string cpf) {

	bool match = false;

	for (unsigned int i = 0; i < _Contas.size(); i++) {
		if (_Contas[i].Get_cliente().Get_Cpf_cnpj() == cpf)
			match = true;
	}

	if (!match) {
		for (unsigned int i = 0; i < _Clientes.size(); i++) {
			if (_Clientes[i].Get_Cpf_cnpj() == cpf)
				_Clientes.erase(_Clientes.begin() + i);
		}
	}
}

void Banco::excluirConta(int nConta) {

	for (unsigned int i = 0; i < _Contas.size(); i++) {
		if (_Contas[i].Get_Numero_conta() == nConta)
			_Contas.erase(_Contas.begin() + i);
	}
}

void Banco::deposito(int nConta, double valor) {

	for (unsigned int i = 0; i < _Contas.size(); i++) {
		if (_Contas[i].Get_Numero_conta() == nConta)
			_Contas[i].Creditar(valor, "Deposito");	
	}
}

void Banco::saque(int nConta, double valor) {

	for (unsigned int i = 0; i < _Contas.size(); i++) {
		if (_Contas[i].Get_Numero_conta() == nConta)
			_Contas[i].Debitar(valor, "Saque");
	}
}

void Banco::transferencia(int c1, int c2, double valor) {

	int n1;
	int n2;

	for (unsigned int i = 0; i < _Contas.size(); i++) {
		if (_Contas[i].Get_Numero_conta() == c1)
			n1 = i;
	}

	for (unsigned int i = 0; i < _Contas.size(); i++) {
		if (_Contas[i].Get_Numero_conta() == c2)
			n2 = i;
	}

	_Contas[n1].Debitar(valor, ("Transferencia para conta " + to_string(c1)));
	_Contas[n2].Creditar(valor, ("Transferencia da conta " + to_string(c2)));
}

void Banco::tarifa() {

	for (unsigned int i = 0; i < _Contas.size(); i++) {
		_Contas[i].Debitar(15, "Cobranca de tarifa");
	}
}

void Banco::CPMF() {

	double tarifa;
	Data now = obterData();

	for (unsigned int i = 0; i < _Contas.size(); i++) {
		
		tarifa = 0;

		for (Conta::Movimentacao i : _Contas[i].extrato()) {
			if (difftime(i.Get_Data().time, now.time) < 604800)
				tarifa += i.Get_Valor();
		}

		tarifa *= 0.0038;

		_Contas[i].Debitar(tarifa, "Cobranca de CPMF");
	}
}

double Banco::saldo(int nConta) {

	for (unsigned int i = 0; i < _Contas.size(); i++) {
		if (_Contas[i].Get_Numero_conta() == nConta)
			return _Contas[i].Get_saldo();
	}

	return -1;
}

vector<Banco::Conta::Movimentacao> Banco::extrato(int nConta) {

	Data now = obterData();
	int mes = now.mes;
	int ano = now.ano;

	vector<Conta::Movimentacao>	x;

	for (unsigned int i = 0; i < _Contas.size(); i++) {
		if (_Contas[i].Get_Numero_conta() == nConta) {
			for (Conta::Movimentacao i : _Contas[i].extrato()) {
				if (i.Get_Data().ano == ano && i.Get_Data().mes == mes)
					x.push_back(i);
			}
		}

		return x;
	}

	return vector<Banco::Conta::Movimentacao>();
}

vector<Banco::Conta::Movimentacao> Banco::extrato(int nConta, Data inicio) {

	vector<Conta::Movimentacao>	x;

	for (unsigned int i = 0; i < _Contas.size(); i++) {
		if (_Contas[i].Get_Numero_conta() == nConta) {
			for (Conta::Movimentacao i : _Contas[i].extrato()) {
				if (difftime(inicio.time, i.Get_Data().time) > 0)
					x.push_back(i);
			}
		}

		return x;
	}

	return vector<Banco::Conta::Movimentacao>();
}

vector<Banco::Conta::Movimentacao> Banco::extrato(int nConta, Data inicio, Data fim) {

	vector<Conta::Movimentacao>	x;

	for (unsigned int i = 0; i < _Contas.size(); i++) {
		if (_Contas[i].Get_Numero_conta() == nConta) {
			for (Conta::Movimentacao i : _Contas[i].extrato()) {
				if (difftime(inicio.time, i.Get_Data().time) > 0 && difftime(i.Get_Data().time, fim.time) < 0)
					x.push_back(i);
			}
		}

		return x;
	}

	return vector<Banco::Conta::Movimentacao>();
}

vector<Banco::Cliente> Banco::clientes() {

	return _Clientes;
}

vector<Banco::Conta> Banco::contas() {

	return _Contas;
}

void save();
void load();
