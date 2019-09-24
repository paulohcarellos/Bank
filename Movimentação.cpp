#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <chrono>
#include "Movimentacao.h"
#include <ctime>
#include "Movimentacao.h"


void Movimentacao::Criar_mov(string descricao,char debito_credito, double valor){
    Data D1;
    D1.Obter_Data();
    _Data = D1;
    _Descricao = descricao;
    _Debito_Credito = debito_credito;
    _Valor = valor;
    cout<<"\n\n movimentacao criada ";
}

Movimentacao::~Movimentacao(){

}

string Movimentacao::Get_Descricao(){
    return this->_Descricao;
}

char Movimentacao::Get_Debito_Credito(){
    return this->_Debito_Credito;
}

double Movimentacao::Get_Valor(){
    return this->_Valor;
}

string Movimentacao::Get_Data(){
    return this->_Data.Get_data();
}
