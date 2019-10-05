#ifndef DATE_H
#define DATE_H
#pragma warning(disable:4996)

#include <ctime>

struct Data {

	time_t time;

	int seg;
	int min;
	int hor;
	int dia;
	int mes;
	int ano;
};

Data obterData();
Data obterData(time_t copy);
Data criarData(int dia, int mes, int ano);

#endif
