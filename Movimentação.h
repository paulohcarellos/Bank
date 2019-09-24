#ifndef MOVIMENTAÇAO_H
#define MOVIMENTAÇAO_H

#include <iostream>
#include <string>
#include <time.h>

class Movimentacao {

    private :
            struct tm * _Data;
            string _Descriçao;
            char _Debito_Credito;
            double _Valor;
    public :
            void Criar_mov(struct, string, char, double);
            ~Mov();
            string Get_Descriçao();
            char Get_Debito_Credito();
            double Get_Valor();
            struct Get_Data();
};

#endif
