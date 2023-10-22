// Gabriel Ernesto Mujica Proulx A01285409
// Miguel Mendoza Jaidar A01234354
// Esteban Sierra Baccio A00836286

// Actividad 2.3
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Error.h"
#include "DoublyLinkedList.h"
using namespace std;

int main() {
    DoublyLinkedList<Error> list;

	fstream my_file;
	my_file.open("bitacora.txt", ios::in);
	if (!my_file) cout << "No such file";
	else {
        string line;
        while(getline(my_file,line)){
            vector<string> lineValues;
            stringstream ssin(line);
            string word;
            while (ssin >> word) {
                lineValues.push_back(word);
            }

            string month = lineValues[0];
            string day = lineValues[1];
            string time = lineValues[2];
            string ip = lineValues[3];
            string text = lineValues[4];

            for (int i = 5; i < lineValues.size(); i++) {
                text += " " + lineValues[i];
            };

            Error err(month, day, time, ip, text);
            list.prepend(err);
        }; 
        my_file.close();
	}

    cout << "Ordenando por IP (toma bastante tiempo)..." << endl;
    list.sortByIp();
    
    string input1, input2;
    cout << "Indica la IP del INICIO de la busqueda: ";
    cin >> input1;
    cout << "Indica la IP del FINAL de la busqueda: ";
    cin >> input2;
    IP ip1(input1), ip2(input2);
    list.filterByIp(ip1.getInt(), ip2.getInt());

    cout << "Escribiendo datos ordenados en el archivo..." << endl;
    list.writeDataToFile();
    cout << "Proceso terminado." << endl;

	return 0;
}
