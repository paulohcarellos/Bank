#include <iostream>
#include <string>
#include "Banco.h"
#include "Interface.h"

using namespace std;


int main() {

	Banco banco("BANCO DO SUCESSO");
	banco.load("teste.txt");

	Interface inter;		
	inter.menu(banco);

	banco.save("teste.txt");

	return 0;
}
