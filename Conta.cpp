#include "conta.h"
#include <string>
#include <stdio.h>
#include "cliente.h"
#include "Movimentacao.h"



int Conta::_Proximo_num_conta = 1;

void Conta::Criar_conta(Cliente cliente){
    _Num_conta = _Proximo_num_conta;
    _Cliente = cliente;
    _Saldo = 0;
    this->Incrementar_numero_conta();
}

Conta::~Conta(){


}

void Conta::Incrementar_numero_conta(){
    _Proximo_num_conta++;
}

int Conta::Get_Numero_conta(){
    return this->_Num_conta;
}

double Conta::Get_saldo(){
    return this->_Saldo;
}

string Conta::Get_cliente(){
    return this->_Cliente.Get_nome();
}

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


