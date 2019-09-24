#ifndef CONTA_H
#define CONTA_H

#include <iostream>
#include <string>
#include "cliente.h"
#include "Movimentacao.h"
#include <vector>

using namespace std;

class Conta {
        private :
            int _Num_conta;
            double _Saldo;
            Cliente _Cliente;
            std::vector<Movimentacao> Movimentacoes;
            static int _Proximo_num_conta;
        public :
            void Criar_conta(Cliente);
            ~Conta();
            void Incrementar_numero_conta();
            int Get_Numero_conta();
            string Get_cliente();
            double Get_saldo();
            void Debitar(double, string);
            void Creditar(double, string);
            Movimentacao extrato1(string, string);
};





#endif // CONTA_H
