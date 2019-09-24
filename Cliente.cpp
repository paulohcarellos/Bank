#include "cliente.h"
#include <string>
#include <stdio.h>


void Cliente::Criar_cliente(string nome, string cpf, string endereco, string fone){
        _Nome_cliente = nome;
        _Cpf_cnpj = cpf;
        _Endereco = endereco;
        _Fone = fone;
        cout<<"\n\n cliente criado ";
}

Cliente::~Cliente(){

}

string Cliente::Get_nome(){
    return this->_Nome_cliente;
}

string Cliente::Get_Cpf_cnpj(){
    return this->_Cpf_cnpj;
}

string Cliente::Get_Endereco(){
    return this->_Endereco;
}

string Cliente::Get_Fone(){
    return this->_Fone;
}

void Cliente::Set_Nome(string nome){
    _Nome_cliente = nome;
}

void Cliente::Set_Cpf_cnpj(string cpf){
    _Cpf_cnpj = cpf;
}

void Cliente::Set_Endereco(string endereco){
    _Endereco = endereco;
}

void Cliente::Set_Fone(string fone){
    _Fone = fone;
}
