#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include <iostream>
#include <string>
#include <stdio.h>
#include "Data.h"


using namespace std;

class Movimentacao {

    private :
            Data _Data;
            string _Descricao;
            char _Debito_Credito;
            double _Valor;
    public :
            void Criar_mov(string, char, double);
            ~Movimentacao();
            string Get_Descricao();
            char Get_Debito_Credito();
            double Get_Valor();
            string Get_Data();
};

#endif // MOVIMENTACAO_H

