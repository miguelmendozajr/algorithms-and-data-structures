// Gabriel Ernesto Mujica Proulx A01285409
// Miguel Mendoza Jaidar A01234354
// Esteban Sierra Baccio A00836286

// Declaración y definición de la clase Error
// Ultima modificacion 07/09/2023

#include <string>
#include "Date.h"
#include "IP.h"

using namespace std;

class Error{
	private:
        Date fecha;
		IP ip;
		string razon;

	public:
		Error();
		Error(Date _fecha, string _ip, string _razon);

		void setip(string _ip);
		void setRazon(string _razon);
        void setFecha(Date _fecha);

		string getip();
		string getRazon();
        Date getFecha();

};

Error::Error(){
    Date fecha;
	ip = IP();
	razon = "-";
}

Error::Error(Date _fecha, string _ip, string _razon){
    fecha = _fecha;
	ip = IP(_ip);
	razon = _razon;
}

void Error::setip(string _ip){
    ip = IP(_ip);
}

void Error::setRazon(string _razon){
    razon = _razon;
}

void Error::setFecha(Date _fecha){
    fecha = _fecha;
}

string Error::getip(){
    return ip.getIP();
}

string Error::getRazon(){
	return razon;
}

Date Error::getFecha(){
    return fecha;
}
