// Gabriel Ernesto Mujica Proulx A01285409
// Miguel Mendoza Jaidar A01234354
// Esteban Sierra Baccio A00836286

// Actividad 1.3
// Ultima modificacion 15/nov/2023


#include <fstream>          // Permite leer archivos
#include <sstream>          // Permite leer archivos
#include <map>

#include "Error.h"          // Importa la clase de Error
#include "funciones.cpp"    // Importa funciones básicas necesarias
#include "BST.h"

using namespace std;        // Permite el uso automático de "std::"


int main() {

    // Abre el archivo bitacora.txt
	fstream my_file;
	my_file.open("bitacora.txt", ios::in);
	if (!my_file) cout << "No such file";
	else {

        // Declaramos la estructura de datos a usar.
        BST<IP> Arbol;

        // Se lee el archivo bitácora hasta encontrar un renglón vacío. Dificultad O(n)
        string linea;
        int lineNumber = 0;
        while(getline(my_file, linea)){

            // Se lee cada línea y se convierte en un arreglo dividido por espacios
            string arr[6];
            int i = 0;
            stringstream ssin(linea);
            while (ssin.good() && i < 6){
                ssin >> arr[i];
                ++i;
            }

            // Se divide el arreglo en variables
            string Str_mes = arr[0];
            string Str_dia = arr[1];
            string Str_horario = arr[2];
            IP nIP;
            nIP = arr[3];
            cout << nIP.getIP() << endl;
            string razon = arr[4] + " " + arr[5];

            /*
            int mes = getMonthAsNumber(Str_mes);
            int dia = stoi(Str_dia);

            // Se divide el horario en valores numéricos
            char tab2[1024];
            strcpy(tab2, Str_horario.c_str());
            string str1(1, tab2[0]);
            string str2(1, tab2[1]);
            string str3(1, tab2[3]);
            string str4(1, tab2[4]);
            string str5(1, tab2[6]);
            string str6(1, tab2[7]);

            // Se juntan los números y se convierten a INT
            int hora = stoi(str1 + str2);
            int minuto = stoi(str3 + str4);
            int segundo = stoi(str5 + str6);
            */

            print("Se cargó la línea: " + to_string(lineNumber));

            /*
            // Se crea el objeto ERROR con los datos de cada línea de la bitácora y se agrega a la 
            Error nerr;
            nerr.setip(IP);
            nerr.setRazon(razon);
            nerr.setFecha(Date(0,mes,dia,hora,minuto,segundo));
            Arbol.add(nerr);
            */

            //Se agrega el IP a un nodo del arbol
            Arbol.add(nIP);

            lineNumber = lineNumber + 1;
        } 
        // Se cierra el archivo 
        my_file.close();


        cout << "Archivo cargado y ordenado correctamente" << endl;

        cout << "\nIngresa la cantidad de accesos de las IPs que buscas: " << endl;
        int accesos;
        cin >> accesos;
        cout << "Las siguientes IPs tienen " << accesos << " accesos: " << endl;
        Arbol.printKey(accesos);


        /* 
        bool interruptor = true;
        int pasada;
        
        print("Ya se ha ordenado :)");

        
        // Se crean las fechas para filtrar la información
        int* fechaInicial;
        fechaInicial = input("¿A partir de qué fecha quieres ver los errores? [dd mm] ", 2);
        Date fechaInicialDate = Date(0,fechaInicial[1]-1, fechaInicial[0]);
        print("fecha inicial: " + fechaInicialDate.getDate());

        int* fechaFinal;
        fechaFinal = input("¿Hasta qué mes quieres ver los erroes? [dd mm] ", 2);
        Date fechaFinalDate = Date(0,fechaFinal[1]-1, fechaFinal[0]);
        print("Fecha final: " + fechaFinalDate.getDate());



        
        ofstream bitfiltrada("bitfiltrada.txt");
        string bitf_linea = "";

        // Se filtra la información en un string. Dificultad: O(n)
        for (int index = 0; index < lineNumber; index++){
            if(LaLista[index].getFecha() > fechaInicialDate && LaLista[index].getFecha() < fechaFinalDate){
                string mes = getNumberAsMonth(LaLista[index].getFecha().getMonth());
                string dia = to_string(LaLista[index].getFecha().getDay());
                string hora = LaLista[index].getFecha().getTime();
                string ip = LaLista[index].getIP();
                string razon = LaLista[index].getRazon();

                bitf_linea = bitf_linea + mes + " " + dia + " " + hora + " " + ip + " " + razon + "\n";

            }
        }
        bitfiltrada << bitf_linea;
        print("Se ha filtrado la lista de errores. La podrás encontrar en el archivo bitfiltrada.txt");
        bitfiltrada.close();
        */
	}
    
	return 0;
}