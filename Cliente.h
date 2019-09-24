#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>

using namespace std;

class Cliente {
    private :
            string _Nome_cliente;
            string _Cpf_cnpj;
            string _Endereco;
            string _Fone;
    public  :
            void Criar_cliente(string, string, string, string);
            ~Cliente();
            string Get_nome();
            string Get_Cpf_cnpj();
            string Get_Endereco();
            string Get_Fone();
            void Set_Nome(string);
            void Set_Cpf_cnpj(string);
            void Set_Endereco(string);
            void Set_Fone(string);
};

#endif // CLIENTE_H
