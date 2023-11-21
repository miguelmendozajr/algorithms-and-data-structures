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
		int key;

	public:
		IP(),
		IP(string _IP);
		IP(string _IP, int _key);

		void setIP(string _IP);
		void setKey(int _key);

		string getIP();
		int Key() {return key;}

		bool operator > (IP _ip);
		bool operator < (IP _ip);
		bool operator == (IP _ip);
		bool operator != (IP _ip);

		void incKey();
};

IP::IP(){
	num1 = 0;
	num2 = 0;
	num3 = 0;
	num4 = 0;
	key = 1;
}

IP::IP(string _IP){
	vector<string> results;
	results = split(_IP, '.');
	num1 = stoi(results[0]);
	num2 = stoi(results[1]);
	num3 = stoi(results[2]);
	num4 = stoi(results[3]);
	key = 1;
}

IP::IP(string _IP, int _key){
	vector<string> results;
	results = split(_IP, '.');
	num1 = stoi(results[0]);
	num2 = stoi(results[1]);
	num3 = stoi(results[2]);
	num4 = stoi(results[3]);
	key = _key;
}

void IP::setIP(string _IP){
	vector<string> results;
	results = split(_IP, '.');
	num1 = stoi(results[0]);
	num2 = stoi(results[1]);
	num3 = stoi(results[2]);
	num4 = stoi(results[3]);
}

void IP::setKey(int _key){
	key = _key;
}

string IP::getIP(){
	return to_string(num1) + "." + to_string(num2) + "." + to_string(num3) + "." + to_string(num4);
}

bool IP::operator>(IP _ip){
	if(key > _ip.key){return true;}
	else if (key < _ip.key){return false;}
	else if (key == _ip.key){
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
					else if (num4 == _ip.num4){return false;}
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
	if(key > _ip.key){return false;}
	else if (key < _ip.key){return true;}
	else if (key == _ip.key){
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
					else if (num4 == _ip.num4){return false;}
				}
			}
		}
	}
	return false;
}


bool IP::operator==(IP _ip){
	if(num1 == _ip.num1 && num2 == _ip.num2 && num3 == _ip.num3 && num4 == _ip.num4){
		return true;
	}
	else{
		return false;
	}
}

bool IP::operator!=(IP _ip){
	if(num1 != _ip.num1 || num2 != _ip.num2 || num3 != _ip.num3 || num4 != _ip.num4){
		return true;
	}
	else{
		return false;
	}
}

void IP::incKey(){
	key += 1;
}
