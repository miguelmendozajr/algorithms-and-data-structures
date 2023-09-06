// Gabriel Ernesto Mujica Proulx A01285409
// Miguel Mendoza Jaidar A01234354
//01/09/2023

//Implementacion clase Error
#include "Error.h"

using namespace std;

Error::Error(){
	mes = 1;
	dia = 1;
	hora = "-";
	IP = "-";
	razon = "-";
}

Error::Error(string _mes, int _dia, string _hora, string _IP, string _razon){
	if(_mes == "Jan"){
		mes == 1;
	}
	if(_mes == "Feb"){
		mes == 2;
	}
	if(_mes == "Mar"){
		mes == 3;
	}
	if(_mes == "Apr"){
		mes == 4;
	}
	if(_mes == "May"){
		mes == 5;
	}
	if(_mes == "Jun"){
		mes == 6;
	}
	if(_mes == "Jul"){
		mes == 7;
	}
	if(_mes == "Aug"){
		mes == 8;
	}
	if(_mes == "Sep"){
		mes == 9;
	}
	if(_mes == "Oct"){
		mes == 10;
	}
	if(_mes == "Nov"){
		mes == 11;
	}
	if(_mes == "Dec"){
		mes == 12;
	}
	dia = _dia;
	hora = _hora;
	IP = _IP;
	razon = _razon;
}


void Error::setMes(string _mes){

}

void Error::setDia(int _dia){

}

void Error::setHora(string _hora){

}

void Error::setIP(string _IP){

}

void Error::setRazon(string _razon){

}


int Error::getMes(){

}

int Error::getDia(){

}

string Error::getHora(){

}

string Error::getIP(){

}

string Error::getRazon(){
	return razon;
}
