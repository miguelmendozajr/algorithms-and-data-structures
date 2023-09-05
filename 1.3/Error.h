//Gabriel Ernesto Mujica Proulx
//A01285409
//01/09/2023
//Declaración clase Error

#ifndef ERROR_CPP
#define ERROR_CPP

#include <bits/stdc++.h>

using namespace std;

class Error{
	private:
		int mes;
		int dia;
		string hora;
		string IP;
		string razon;

	public:
		Error();
		Error(string _mes, int _dia, string _hora, string _IP, string _razon);

		void setMes(string _mes);
		void setDia(int _dia);
		void setHora(string _hora);
		void setIP(string _IP);
		void setRazon(string _razon);

		int getMes();
		int getDia();
		string getHora();
		string getIP();
		string getRazon();



};
