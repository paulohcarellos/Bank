#include <ctime>
#include <iostream>
#include <string>


#include "data.h"

void Data::Obter_Data(){
    time_t timer;
    struct tm *horarioLocal;

  time(&timer); // Obtem informações de data e hora
  horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

  int dia= horarioLocal->tm_mday;
  int mes = horarioLocal->tm_mon + 1;
  int ano = horarioLocal->tm_year + 1900;

  int hora = horarioLocal->tm_hour;
  int min  = horarioLocal->tm_min;
  int sec  = horarioLocal->tm_sec;

  std::string horario = std::to_string(hora) + ":" + std::to_string(min) + ":" + std::to_string(sec);
  std::string data = std::to_string(dia) + ":" + std::to_string(mes) + ":" + std::to_string(ano);
   std::string soma = data + "       " + horario;
   this->_Data = soma;
}

Data::~Data(){

}

string Data::Get_data(){
    return this->_Data;
}
