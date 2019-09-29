#include "Conta.h"

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

Conta::Cliente::Cliente() {
}

Conta::Cliente::Cliente(const Cliente& copia) {

	_Nome_cliente = copia._Nome_cliente;
	_Cpf_cnpj = copia._Cpf_cnpj;
	_Endereco = copia._Endereco;
	_Fone = copia._Fone;
}

Conta::Cliente::Cliente(string nome, string cpf, string endereco, string fone) {

	_Nome_cliente = nome;
	_Cpf_cnpj = cpf;
	_Endereco = endereco;
	_Fone = fone;
}

string Conta::Cliente::Get_nome() {

	return _Nome_cliente;
}

string Conta::Cliente::Get_Cpf_cnpj() {
	return _Cpf_cnpj;
}

string Conta::Cliente::Get_Endereco() {
	return _Endereco;
}

string Conta::Cliente::Get_Fone() {
	return _Fone;
}

void Conta::Cliente::Set_Nome(string nome) {
	_Nome_cliente = nome;
}

void Conta::Cliente::Set_Cpf_cnpj(string cpf) {
	_Cpf_cnpj = cpf;
}

void Conta::Cliente::Set_Endereco(string endereco) {
	_Endereco = endereco;
}

void Conta::Cliente::Set_Fone(string fone) {
	_Fone = fone;
}

Conta::Movimentacao::Movimentacao() {

	_Data = obterData();
	_Debito_Credito = 'N';
	_Valor = 0;
}

Conta::Movimentacao::Movimentacao(string descricao, char debito_credito, double valor) {

	_Data = obterData();
	_Descricao = descricao;
	_Debito_Credito = debito_credito;
	_Valor = valor;
}

string Conta::Movimentacao::Get_Descricao() {	
	return _Descricao;
}

char Conta::Movimentacao::Get_Debito_Credito() {
	return _Debito_Credito;
}

double Conta::Movimentacao::Get_Valor() {
	return _Valor;
}

Data Conta::Movimentacao::Get_Data(){
	return _Data;
}

int Conta::_Proximo_num_conta = 0;

Conta::Conta() {

	_Num_conta = _Proximo_num_conta++;
	_Saldo = 0;
	_Cliente = Cliente();
}

Conta::Conta(double saldo, Cliente cliente, static int proximoNumConta) {

    _Num_conta = _Proximo_num_conta;
	_Cliente = Cliente(cliente);
    _Saldo = saldo;
	proximoNumConta++;
}

int Conta::Get_Numero_conta(){
    return _Num_conta;
}

double Conta::Get_saldo(){
    return _Saldo;
}

string Conta::Get_cliente(){
    return _Cliente.Get_nome();
}

bool Conta::Debitar(double valor, string descricao){

	if ((_Saldo - valor) < 0) {

		return false;
	}

	else {

		_Saldo -= valor;
		_Movimentacoes.push_back(Movimentacao(descricao, 'D', valor));

		return true;
	}
}

void Conta::Creditar(double valor, string descricao){
	
	_Saldo += valor;
	_Movimentacoes.push_back(Movimentacao(descricao, 'C', valor));
}

vector<Conta::Movimentacao> Conta::extrato() {

	return _Movimentacoes;
}

vector<Conta::Movimentacao> Conta::extrato(Data inicio) {

	vector<Movimentacao> ext;

	for (Movimentacao i : _Movimentacoes) {

		if (difftime(inicio.time, i.Get_Data().time) > 0)
			ext.push_back(i);
	}

	return ext;
}

vector<Conta::Movimentacao> Conta::extrato(Data inicio, Data fim) {

	vector<Movimentacao> ext;

	for (Movimentacao i : _Movimentacoes) {

		if ((difftime(inicio.time, i.Get_Data().time) > 0) && (difftime(i.Get_Data().time, fim.time) < 0))
			ext.push_back(i);
	}

	return ext;
}
