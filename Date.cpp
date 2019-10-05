#include "Date.h"

Data obterData() {

	Data x;

	time_t t = time(NULL);
	struct tm* date = localtime(&t);

	x.time = t;
	x.seg = date->tm_sec;
	x.min = date->tm_min;
	x.hor = date->tm_hour;
	x.dia = date->tm_mday;
	x.mes = date->tm_mon;
	x.ano = date->tm_year + 1900;

	return x;
}

Data obterData(time_t copy) {

	Data x;

	struct tm* date = localtime(&copy);

	x.time = copy;
	x.seg = date->tm_sec;
	x.min = date->tm_min;
	x.hor = date->tm_hour;
	x.dia = date->tm_mday;
	x.mes = date->tm_mon;
	x.ano = date->tm_year + 1900;

	return x;
}

Data criarData(int dia, int mes, int ano) {

	Data x;

	x.seg = 0;
	x.min = 0;
	x.hor = 0;
	x.dia = dia;
	x.mes = mes;
	x.ano = ano;

	struct tm time = { 0 };

	time.tm_year = ano - 1900;
	time.tm_mon = mes - 1;
	time.tm_mday = dia;

	x.time = mktime(&time);

	return x;
}