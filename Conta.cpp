#include "Conta.h"
//#include "Movimentacao.h"

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
	_Debito_Credito = 'N';
	_Valor = 0;
}

Conta::Movimentacao::Movimentacao(string descricao, char debito_credito, double valor) {
	//Data D1;
	//D1.Obter_Data();
	//_Data = D1;
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

/*
string Conta::Movimentacao::Get_Data(){
	return _Data.Get_data();
}

*/

int Conta::_Proximo_num_conta = 0;

Conta::Conta() {

	_Num_conta = _Proximo_num_conta++;
	_Saldo = 0;
	_Cliente = Cliente();
}

Conta::Conta(double saldo, Cliente cliente, static int proximoNumConta) {

    _Num_conta = _Proximo_num_conta;
	_Cliente = cliente;
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

/*
void Conta::Debitar(double valor, string descricao){
	double saldo;
	saldo = this->_Saldo;
		if(saldo - valor >= 0){
			this->_Saldo = saldo - valor;
			 Movimentacao M1;
			 M1.Criar_mov(descricao,'D', valor);
			 Movimentacoes.push_back(M1);
		}else
			this->_Saldo = saldo;
}

void Conta::Creditar(double valor, string descricao){
		this->_Saldo += valor;
		Movimentacao M1;
		M1.Criar_mov(descricao,'C', valor);
		Movimentacoes.push_back(M1);
}
*/
