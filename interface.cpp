#include "interface.h"

void inter::gotoxy(int x, int y)
{
	int x;
	int y;
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void inter::pagina_de_inicio()
{
	system("cls");
	gotoxy(35, 11);
	cout << "Trabalho Pds2";
	gotoxy(35, 17);
	cout << "Sistema de Blibioteca";
	cout << "\n\nGrupo : Luis Gustavo, Marina, Luana, Iana";
	getch();
}
