#ifndef MOVIMENTA�AO_H
#define MOVIMENTA�AO_H

#include <iostream>
#include <string>
#include <time.h>

class Movimentacao {

    private :
            struct tm * _Data;
            string _Descri�ao;
            char _Debito_Credito;
            double _Valor;
    public :
            void Criar_mov(struct, string, char, double);
            ~Mov();
            string Get_Descri�ao();
            char Get_Debito_Credito();
            double Get_Valor();
            struct Get_Data();
};

#endif
