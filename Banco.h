#ifndef BANCO_H
#define BANCO_H

#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>


using namespace std;

struct Data {

	time_t time;

	int seg;
	int min;
	int hor;
	int dia;
	int mes;
	int ano;
};

class Banco {


public:

	class Cliente {

	private:

		string _Nome_cliente;
		string _Cpf_cnpj;
		string _Endereco;
		string _Fone;

	public:

		Cliente();
		Cliente(const Cliente& copia);
		Cliente(string nome, string cpf, string endereco, string fone);
		void Set_Nome(string nome);
		void Set_Cpf_cnpj(string cpf);
		void Set_Endereco(string endereco);
		void Set_Fone(string fone);
		string Get_nome();
		string Get_Cpf_cnpj();
		string Get_Endereco();
		string Get_Fone();

	};

	class Conta {

	public:

		class Movimentacao {

		private:

			string _Descricao;
			char _Debito_Credito;
			double _Valor;	
			Data _Data;

		public:

			Movimentacao();
			Movimentacao(string descricao, char dc, double valor);
			Movimentacao(string descricao, char dc, double valor, Data data);
			double Get_Valor();
			char Get_Debito_Credito();
			string Get_Descricao();
			Data Get_Data();
		};

		Conta();
		Conta(Banco::Cliente& cliente);
		Conta(int num, double saldo, Banco::Cliente& c);
		int Get_Numero_conta();
		int Get_prox();
		void Set_prox(int num);
		double Get_saldo();
		Banco::Cliente Get_cliente();
		bool Debitar(double, string); //Retorna true/false dependendo do sucesso da operacao
		void Creditar(double, string);
		void extrato(vector<Movimentacao> set);
		vector<Movimentacao> extrato();
		vector<Movimentacao> extrato(Data inicio);
		vector<Movimentacao> extrato(Data inicio, Data fim);

	private:

		int _Num_conta;
		double _Saldo;
		Banco::Cliente _Cliente;
		vector<Movimentacao> _Movimentacoes;
		static int _Proximo_num_conta;

	};

	Banco();
	Banco(string nome);
	void inserirCliente(Cliente x);
	void criarConta(Cliente& x);
	void excluirCliente(string cpf);
	void excluirConta(int nConta);
	void deposito(int nConta, double valor);
	void saque(int nConta, double valor);
	void transferencia(int c1, int c2, double valor);
	void tarifa();
	void CPMF();
	double saldo(int nConta);
	vector<Conta::Movimentacao> extrato(int nConta);
	vector<Conta::Movimentacao> extrato(int nConta, Data inicio);
	vector<Conta::Movimentacao> extrato(int nConta, Data inicio, Data fim);
	vector<Cliente> clientes();
	vector<Conta> contas();
	void save();
	void load(string file);


private:

	string _Banco;
	vector<Cliente> _Clientes;
	vector<Conta> _Contas;

};

#endif // BANCO_H