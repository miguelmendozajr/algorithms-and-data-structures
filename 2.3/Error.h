// Gabriel Ernesto Mujica Proulx A01285409
// Miguel Mendoza Jaidar A01234354
// Esteban Sierra Baccio A00836286

// Declaración y definición de la clase Error

#include "IP.h"

class Error{
	private:
		string month;
        string day;
        string time;
		IP ip;
		string text;

	public:
		Error();
		Error(string _month, string _day, string _time, string _ip, string _text);

		// setters
		void setMonth(string _month);
		void setDay(string _day);
		void setTime(string _time);
		void setIp(string _ip);
		void setText(string _text);

		// getters
		string getMonth();
		string getDay();
		string getTime();
		IP getIp();
		string getText();

		// special getter
		long long getIpInt();
};

Error::Error(){};

Error::Error(string _month, string _day, string _time, string _ip, string _text){
    month = _month;
	day = _day;
	time = _time;
	ip = IP(_ip);
	text = _text;
};

void Error::setMonth(string _month){
    month = _month;
};
void Error::setDay(string _day){
    day = _day;
};
void Error::setTime(string _time){
    time = _time;
};
void Error::setIp(string _ip){
    ip = IP(_ip);
};
void Error::setText(string _text){
    text = _text;
};

string Error::getMonth(){
    return month;
};
string Error::getDay(){
    return day;
};
string Error::getTime(){
    return time;
};
IP Error::getIp(){
    return ip;
};
string Error::getText(){
	return text;
};

/*

long long Error::getIpInt(){
	int colonPos = ip.find(':');
    string ipPart = ip.substr(0, colonPos);
    string portPart = ip.substr(colonPos + 1);

    // Separamos las secciones de la IP
    istringstream ipStream(ipPart);
    string section;
    string paddedIP = "";

    while (getline(ipStream, section, '.')) {
        // Nos aseguramos que cada intervalo entre los puntos, sean de 3 digitos
        while (section.size() < 3) {
            section = "0" + section;
        }
        paddedIP += section;
    }

	//

    long long ipInt = stoll(paddedIP);
    long long portInt = stoll(portPart);
    long long result = (ipInt * 10000) + portInt;

    return result;
}

*/