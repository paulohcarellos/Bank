#ifndef INTER_H
#define INTER_H

#include <iostream>
#include <iomanip>  
#include <string>
#include <conio.h>
#include "Banco.h"
#include "Date.h"

class Interface {

	public:

		Interface();
		void menu(Banco& b);
		void cadastrar_cliente(Banco& b);
		void criar_conta(Banco& b);
		void excluir_cliente(Banco& b);
		void excluir_conta(Banco& b);
		void deposito(Banco& b);
		void saque(Banco& b);
		void transferencia(Banco& b);
		void tarifa(Banco& b);
		void CPMF(Banco& b);
		void saldo(Banco& b);
		void extrato_mes(Banco& b);
		void extrato_data_inicial(Banco& b);
		void extrato_data_inicial_final(Banco& b);
		void listar_clientes(Banco& b);
		void listar_contas(Banco& b);
};

#endif