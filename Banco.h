#ifndef BANCO_H
#define BANCO_H
#pragma warning(disable:4996)

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "Date.h"

using namespace std;

class Banco {


public:

	class Cliente {

	private:

		string nomeCliente;
		string CPF;
		string End;
		string Fone;

	public:

		Cliente();
		Cliente(const Cliente& copia);
		Cliente(string nome, string cpf, string endereco, string fone);
		void setNome(string nome);
		void SetCPF(string cpf);
		void setEnd(string endereco);
		void setFone(string fone);
		string getNome();
		string getCPF();
		string getEnd();
		string getFone();

	};

	class Conta {

	public:

		class Movimentacao {

		private:

			char DB;
			double Valor;	
			Data dataMov;
			string Desc;

		public:

			Movimentacao();
			Movimentacao(string desc, char dc, double valor);
			Movimentacao(string desc, char dc, double valor, Data data);
			char getDB();
			double getValor();
			Data getDataMov();
			string getDesc();
		};

		Conta();
		Conta(Banco::Cliente& cliente);
		Conta(int num, double saldo, Banco::Cliente& c);
		int getNum();
		int getProx();	
		double getSaldo();
		bool debitar(double, string); //Retorna true/false dependendo do sucesso da operacao	
		void creditar(double, string);
		void setProx(int num);
		void setExtrato(vector<Movimentacao> set);			
		vector<Movimentacao> getExtrato();
		vector<Movimentacao> getExtrato(Data inicio);
		vector<Movimentacao> getExtrato(Data inicio, Data fim);
		Banco::Cliente getDono();

	private:

		int numConta;
		double Saldo;
		Banco::Cliente Dono;
		vector<Movimentacao> Movis;
		static int proxNum;

	};

	Banco();
	Banco(string nome);
	void inserirCliente(Cliente x);
	void criarConta(Cliente& x);
	void excluirCliente(string cpf);
	void excluirConta(int nConta);
	void deposito(int nConta, double valor);
	bool saque(int nConta, double valor);
	bool transferencia(int c1, int c2, double valor);
	void tarifa();
	void CPMF();
	double saldo(int nConta);
	vector<Conta::Movimentacao> extrato(int nConta);
	vector<Conta::Movimentacao> extrato(int nConta, Data inicio);
	vector<Conta::Movimentacao> extrato(int nConta, Data inicio, Data fim);
	vector<Cliente> clientes();
	vector<Conta> contas();
	int findCliente(string cpf);
	int findCliente(Cliente x);
	int findConta(int conta);
	bool checkCliente(string cpf);
	bool checkCliente(Cliente x);
	bool checkConta(int conta);
	bool checkConta(string cpf);
	Cliente* cliente(int i);
	Conta* conta(int i);
	void save(string file);
	void load(string file);


private:

	string _Banco;
	vector<Cliente> Clientes;
	vector<Conta> Contas;

};

#endif // BANCO_H