#ifndef IP_H
#define IP_H

#include <string>

using namespace std;

class IP{
	private:
		string address;
	public:
        IP();
		IP(string _address);

		// setters
		void setAddress(string _ip);

        // getters
        string getAddress();
		long long getInt();
};

IP::IP() {
}

IP::IP(string _address) {
    address = _address;
}

void IP::setAddress(string _ip) {
    address = _ip;
}

string IP::getAddress() {
    return address;
}

long long IP::getInt(){
	int colonPos = address.find(':');
    string ipPart = address.substr(0, colonPos);
    string portPart = address.substr(colonPos + 1);

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

    long long ipInt = stoll(paddedIP);
    long long portInt = stoll(portPart);
    long long result = (ipInt * 10000) + portInt;

    return result;
};

#endif