#include <iostream>
#include <string>
#include "Banco.h"

using namespace std;


int main() {

	Banco itau;

	/*
	Banco::Cliente Jefferson("Jefferson", "12343245621", "Rua dos Sonhos", "958743652");
	Banco::Cliente Joaquim("Joaquim", "56941235725", "Rua das Desilusoes", "954872516");
	Banco::Cliente Jairo("Jairo", "56847525401", "Rua Onirica", "958463259");
	Banco::Cliente Jaime("Jaime", "47856985420", "Rua dos Pesadelos", "9251325698");

	itau.inserirCliente(Jefferson);
	itau.inserirCliente(Joaquim);
	itau.inserirCliente(Jairo);
	itau.inserirCliente(Jaime);

	itau.criarConta(Jefferson);
	itau.criarConta(Joaquim);
	itau.criarConta(Jairo);
	itau.criarConta(Jaime);

	itau.deposito(0, 450);
	itau.deposito(1, 100);
	itau.deposito(2, 2000);
	itau.deposito(3, 50000);

	itau.saque(0, 50);
	itau.saque(1, 100);

	itau.transferencia(2, 3, 200);
	itau.transferencia(4, 1, 500);

	itau.save();
	*/

	//400
	//0
	//1800
	//50200

	itau.load("data.txt");
	itau.save();

	return 0;
}
