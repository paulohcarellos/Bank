#include <iostream>
#include <stdio.h>
#include <string>
#include "cliente.h"
#include<windows.h>
#include "Movimentacao.h"
#include "Conta.h"



using namespace std;


int main()
{
    //Cliente C1,C2;
    //C1.Criar_cliente("LUIS", "123", "Rua A", "234556");
    //C2.Criar_cliente("LUCAS", "1551", "Rua B", "233678");
    //Conta CO1,CO2;
    //CO1.Criar_conta(C1);
    //CO2.Criar_conta(C2);
    //cout << "cliente = " << CO1.Get_cliente() << "numero conta = " << CO1.Get_Numero_conta() << "saldo = " << CO1.Get_saldo() << endl;
    //cout << "cliente = " << CO2.Get_cliente() << "numero conta = " << CO2.Get_Numero_conta() << "saldo = " << CO2.Get_saldo() << endl;
    //cout << "cliente = " << C1.Get_nome() << "cpf = " << C1.Get_Cpf_cnpj() << "endereco = " << C1.Get_Endereco() << "fone = " << C1.Get_Fone() << endl;
    //C1.Set_Nome("Gustavo");
    //cout << "cliente = " << C1.Get_nome() << "cpf = " << C1.Get_Cpf_cnpj() << "endereco = " << C1.Get_Endereco() << "fone = " << C1.Get_Fone() << endl;//
    Movimentacao M1;
    M1.Criar_mov("MD", '0', 200000);
    cout << "descricao = " << M1.Get_Descricao() << "debitocredito = " << M1.Get_Debito_Credito() << "valor = " << M1.Get_Valor() << "data = " << M1.Get_Data() << endl;
return 0;
}
