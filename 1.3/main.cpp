// Gabriel Ernesto Mujica Proulx A01285409
// Miguel Mendoza Jaidar A01234354
// Esteban Sierra Baccio A00836286

// Actividad 1.3
// Ultima modificacion 07/09/2023

#include <fstream>
#include <sstream>
using namespace std;

#include "Error.h"
#include "funciones.cpp"

#include <cstdlib>
#include <vector>
#include <typeinfo>

int main() {
	fstream my_file;
	my_file.open("bitacora.txt", ios::in);
	if (!my_file) cout << "No such file";
	else {

        string linea;
        getline(my_file, linea);

        Error errList[16808];
        int lineNumber = 0;
        
        // Se lee el archivo bitácora hasta encontrar un renglón vacío 
        while(getline(my_file, linea)){

                // Se lee cada línea y se convierte en un arreglo dividido por espacios
                string arr[6];
                int i = 0;
                stringstream ssin(linea);
                while (ssin.good() && i < 6){
                    ssin >> arr[i];
                    ++i;
                }

            string Str_mes = arr[0];
            string Str_dia = arr[1];
            string Str_horario = arr[2];
            string IP = arr[3];
            string razon = arr[4] + " " + arr[5];

            int mes = getMonthAsNumber(Str_mes);
            int dia = stoi(Str_dia);

            char tab2[1024];
            strcpy(tab2, Str_horario.c_str());
            //string _horas = tab2[0] + tab2[1];
            string str1(1, tab2[0]);
            string str2(1, tab2[1]);
            string str3(1, tab2[3]);
            string str4(1, tab2[4]);
            string str5(1, tab2[6]);
            string str6(1, tab2[7]);

            // Se juntan los números
            string Str_hora = str1 + str2;
            string Str_minuto = str3 + str4;
            string Str_segundo = str5 + str6;

            // Se convierten las horas minutos y segundos a INT
            int hora = stoi(Str_hora);
            int minuto = stoi(Str_minuto);
            int segundo = stoi(Str_segundo);
        
            print("Se cargó la línea: " + to_string(lineNumber));

            Error nerr;
            nerr.setIP(IP);
            nerr.setRazon(razon);
            nerr.setFecha(Date(0,mes,dia,hora,minuto,segundo));
            errList[lineNumber] = nerr;

            lineNumber = lineNumber + 1;

        } 
                
        my_file.close();
        print("Se cargo el archivo correctamente.");

        string respuestaStr = input<string>("¿Te gustaría ordenar la lista por fecha? [Y/N] ");
        print("Ordenando...");


        int n = 1805;
        bool interruptor = true;
        int pasada;
        
        // Se ordena por mes el arreglo de errores
        for (pasada=0; pasada<n-1 && interruptor; pasada++) { 
            interruptor = false; // no se han hecho intercambios
            int j;
            for (j=0; j<n-1-pasada; j++) { 
                if (errList[j+1].getFecha().getMonth() < errList[j].getFecha().getMonth()) {
                    Error tmp;
                    tmp = errList[j]; 
                    errList[j] = errList[j+1]; 
                    errList[j+1] = tmp; 
                    interruptor = true;
                } 
            } 
        } 
        print("Ya se ha ordenado :)");
        int mesInicial = input<int>("¿A partir de qué mes quieres ver los errores? [1..12] ");
        int mesFinal = input<int>("¿Hasta qué mes quieres ver los erroes? [1...12] ");

        ofstream bitfiltrada("bitfiltrada.txt");
        

        string bitf_linea = "";
        for (int index = 0; index < 1860; index++){
            if(errList[index].getFecha().getMonth() > mesInicial && errList[index].getFecha().getMonth() > mesInicial < mesFinal){
                string mes = getNumberAsMonth(errList[index].getFecha().getMonth());
                string dia = to_string(errList[index].getFecha().getDay());
                string hora = errList[index].getFecha().getTime();
                string ip = errList[index].getIP();
                string razon = errList[index].getRazon();

                bitf_linea = bitf_linea + mes + "" + dia + " " + hora + " " + ip + " " + razon + "\n";

            }
        }
        bitfiltrada << bitf_linea;
        print("Se ha filtrado la lista de errores. La podrás encontrar en el archivo bitfiltrada.txt");
        bitfiltrada.close();



	}

	return 0;
}
