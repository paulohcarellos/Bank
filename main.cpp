#include <iostream>
#include <string>
#include "Banco.h"
#include "Interface.h"

using namespace std;


int main() {

	Banco banco("BANCO DO SUCESSO");
	banco.load("save.txt");

	Interface inter;		
	inter.menu(banco);

	banco.save("save.txt");
	return 0;
}
