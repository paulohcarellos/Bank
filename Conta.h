#ifndef CONTA_H
#define CONTA_H

#include <string>
#include <vector>
#include <ctime>

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

class Conta {
	
	private :

		class Cliente {

		private:

			string _Nome_cliente;
			string _Cpf_cnpj;
			string _Endereco;
			string _Fone;

		public:

			Cliente();
			Cliente(const Cliente &copia);
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

		class Movimentacao {

		private:

			Data _Data;
			string _Descricao;
			char _Debito_Credito;
			double _Valor;

		public:

			Movimentacao();
			Movimentacao(string descricao, char debito_Credito, double valor);
			string Get_Descricao();
			char Get_Debito_Credito();
			double Get_Valor();
			Data Get_Data();
		};

		int _Num_conta;
		double _Saldo;
		Cliente _Cliente;
		vector<Movimentacao> _Movimentacoes;
		static int _Proximo_num_conta;



	public :

		Conta();
		Conta(double saldo, Cliente cliente, static int proxNumConta);
		int Get_Numero_conta();
		double Get_saldo();
		string Get_cliente();	
		bool Debitar(double, string); //Retorna true/false dependendo do sucesso da operacao
		void Creditar(double, string);
		vector<Movimentacao> extrato();
		vector<Movimentacao> extrato(Data inicio);
		vector<Movimentacao> extrato(Data inicio, Data fim);
};

#endif // CONTA_H
