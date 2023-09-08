// Gabriel Ernesto Mujica Proulx A01285409
// Miguel Mendoza Jaidar A01234354
// Esteban Sierra Baccio A00836286

// Declaración y definición de la clase Error
// Ultima modificacion 07/09/2023

#include <string>
#include "Date.h"

using namespace std;

class Error{
	private:
        Date fecha;
		string IP;
		string razon;

	public:
		Error();
		Error(Date _fecha, string _IP, string _razon);

		void setIP(string _IP);
		void setRazon(string _razon);
        void setFecha(Date _fecha);

		string getIP();
		string getRazon();
        Date getFecha();



};

Error::Error(){
    Date fecha;
	IP = "-";
	razon = "-";
}

Error::Error(Date _fecha, string _IP, string _razon){
    fecha = _fecha;
	IP = _IP;
	razon = _razon;
}

void Error::setIP(string _IP){
    IP = _IP;
}

void Error::setRazon(string _razon){
    razon = _razon;
}

void Error::setFecha(Date _fecha){
    fecha = _fecha;
}

string Error::getIP(){
    return IP;
}

string Error::getRazon(){
	return razon;
}

Date Error::getFecha(){
    return fecha;
}
