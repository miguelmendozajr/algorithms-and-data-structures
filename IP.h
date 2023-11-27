// Esteban Sierra Baccio
// Declaración y definición de la clase IP
// Ultima modificacion 14/nov/2023

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

vector<string> split(string str, char pattern) {
    
    int posInit = 0;
    int posFound = 0;
    string splitted;
    vector<string> results;
    
    while(posFound >= 0){
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        results.push_back(splitted);
    }
    
    return results;
}


class IP{
	private:
		int num1;
		int num2;
		int num3;
		int num4;
		int port;

	public:
		IP(),
		IP(string _IP);

		void setIP(string _IP);

		string getIP();
		int getPort();

		bool operator > (IP _ip);
		bool operator < (IP _ip);
		bool operator == (IP _ip);

};

IP::IP(){
	num1 = 0;
	num2 = 0;
	num3 = 0;
	num4 = 0;
	port = 0;
}

IP::IP(string _IP){
	vector<string> results, results2;
	results = split(_IP, '.');
	results2 = split(_IP, ':');
	num1 = stoi(results[0]);
	num2 = stoi(results[1]);
	num3 = stoi(results[2]);
	num4 = stoi(results[3]);
	port = stoi(results2[1]);
}

void IP::setIP(string _IP){
	vector<string> results, results2;
	results = split(_IP, '.');
	results2 = split(_IP, ':');
	num1 = stoi(results[0]);
	num2 = stoi(results[1]);
	num3 = stoi(results[2]);
	num4 = stoi(results[3]);
	port = stoi(results2[1]);
}

string IP::getIP(){
	return to_string(num1) + "." + to_string(num2) + "." + to_string(num3) + "." + to_string(num4) + ":" + to_string(port);
}

int IP::getPort(){
	return port;
}

bool IP::operator>(IP _ip){
	if(num1 > _ip.num1){return true;}
	else if (num1 < _ip.num1){return false;}
	else if (num1 == _ip.num1){
		if(num2 > _ip.num2){return true;}
		else if (num2 < _ip.num2){return false;}
		else if (num2 == _ip.num2){
			if(num3 > _ip.num3){return true;}
			else if (num3 < _ip.num3){return false;}
			else if (num3 == _ip.num3){
				if(num4 > _ip.num4){return true;}
				else if (num4 < _ip.num4){return false;}
				else if (num4 == _ip.num4){
					if(port > _ip.port){return true;}
					else if (port < _ip.port){return false;}
					else if (port == _ip.port){return false;}
				}
			}
		}
	}
	return false;
}

/// @brief 
/// @param _ip 
/// @return 
bool IP::operator<(IP _ip){
	if(num1 > _ip.num1){return false;}
	else if (num1 < _ip.num1){return true;}
	else if (num1 == _ip.num1){
		if(num2 > _ip.num2){return false;}
		else if (num2 < _ip.num2){return true;}
		else if (num2 == _ip.num2){
			if(num3 > _ip.num3){return false;}
			else if (num3 < _ip.num3){return true;}
			else if (num3 == _ip.num3){
				if(num4 > _ip.num4){return false;}
				else if (num4 < _ip.num4){return true;}
				else if (num4 == _ip.num4){
					if(port > _ip.port){return false;}
					else if (port < _ip.port){return true;}
					else if (port == _ip.port){return false;}
				}
			}
		}
	}
	return false;
}

bool IP::operator==(IP _ip){
	if(num1 == _ip.num1 && num2 == _ip.num2 && num3 == _ip.num3 && num4 == _ip.num4 && port == _ip.port){
		return true;
	}
	else{
		return false;
	}
}