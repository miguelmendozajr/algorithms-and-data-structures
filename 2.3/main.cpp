// Gabriel Ernesto Mujica Proulx A01285409
// Miguel Mendoza Jaidar A01234354
// Esteban Sierra Baccio A00836286

// Actividad 1.3
// Ultima modificacion 07/09/2023


#include <fstream>          // Permite leer archivos
#include <sstream>          // Permite leer archivos

#include "Error.h"          // Importa la clase de Error
#include "funciones.cpp"    // Importa funciones básicas necesarias

#include "DoublyLinkedList.h"   

using namespace std;        // Permite el uso automático de "std::"


int main() {

    // Abre el archivo bitacora.txt
	fstream my_file;
	my_file.open("bitacora.txt", ios::in);
	if (!my_file) cout << "No such file";
	else {

        string linea;
        DoublyLinkedList<Error> LaLista;
        //Error errList[16808];
        int lineNumber = 0;
        
        // Se lee el archivo bitácora hasta encontrar un renglón vacío. Dificultad O(n)
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
            string IP = arr[3];
            string razon = arr[4] + " " + arr[5];

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

            // Se juntan los números
            string Str_hora = str1 + str2;
            string Str_minuto = str3 + str4;
            string Str_segundo = str5 + str6;

            // Se convierten las horas minutos y segundos a INT
            int hora = stoi(Str_hora);
            int minuto = stoi(Str_minuto);
            int segundo = stoi(Str_segundo);
        
            print("Se cargó la línea: " + to_string(lineNumber));

            // Se crea el objeto ERROR con los datos de cada línea de la bitácora y se agrega a la lista
            Error nerr;
            nerr.setIP(IP);
            nerr.setRazon(razon);
            nerr.setFecha(Date(0,mes,dia,hora,minuto,segundo));
            LaLista.addLast(nerr);
            //errList[lineNumber] = nerr;

            lineNumber = lineNumber + 1;
        } 
        // Se cierra el archivo 
        my_file.close();


        print("Se cargo el archivo correctamente.");
        print("Ordenando...");

    // Se recorre la lista 
         
        bool interruptor = true;
        int pasada;
        
        // Se ordena por fecha el arreglo de errores a través de un bubblesort. Dificultad: O(n^2)
        
        for (pasada=0; pasada< lineNumber - 1 && interruptor; pasada++) { 
            interruptor = false; // no se han hecho intercambios
            int j;
            for (j = 0; j < lineNumber - 1-pasada; j++) { 
                if (LaLista[j+1].getIP() < LaLista[j].getIP()) {
                    Error tmp;
                    tmp = LaLista[j]; 
                    LaLista[j] = LaLista[j+1]; 
                    LaLista[j+1] = tmp;
                    print("Intercambioo");
                    interruptor = true;
                } 
            } 
        } 
        
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
	}

	return 0;
}
