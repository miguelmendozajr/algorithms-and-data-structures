// Gabriel Ernesto Mujica Proulx A01285409
// Miguel Mendoza Jaidar A01234354
// Esteban Sierra Baccio A00836286

// Actividad 4.3
// Ultima modificacion 27/nov/2023

#include <fstream>
#include <sstream>
using namespace std;

#include "Error.h"
#include "funciones.cpp"

#include <cstdlib>
#include <vector>
#include <typeinfo>

void printVector(vector<int> vec){
        string linea = "";
        for(int celda : vec){
            linea = linea + to_string(celda);
        }
        cout << linea;
}

// Función para agregar una arista al grafo no dirigido
void agregarArista(vector<int> adj[], int u, int v) {
    adj[u].push_back(v); // Agregar v a la lista de adyacencia de u
    //adj[v].push_back(u); // Si el grafo es no dirigido, agregar u a la lista de adyacencia de v
}

// Función para imprimir la lista de adyacencia
void imprimirListaAdyacencia(vector<int> adj[], int V) {
    for (int i = 0; i < V; ++i) {
        cout << "Lista de adyacencia del nodo " << i << ":";

        for (int j = 0; j < adj[i].size(); ++j)
            cout << " -> " << adj[i][j];

        cout << endl;
    }
}


int main() {
	fstream my_file;
	my_file.open("bitacora.txt", ios::in);
	if (!my_file) {
        print("No such file");
        return 0;
    }



    string linea;

    int tamaño = 16808;

    Error errList[tamaño];
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

        // Se convierten las horas minutos y segundos a INT
        int hora = stoi(str1 + str2);
        int minuto = stoi(str3 + str4);
        int segundo = stoi(str5 + str6);
    

        // Se crea objeto de error
        Error nerr;
        nerr.setip(IP);
        nerr.setRazon(razon);
        nerr.setFecha(Date(0,mes,dia,hora,minuto,segundo));
        errList[lineNumber] = nerr;

        if(lineNumber%3000 == 0){print("Cargando el archivo: " + to_string((lineNumber*100)/tamaño) + "%");} 
        lineNumber++;

    } 
            
    my_file.close();
    print("Se cargo el archivo correctamente.");

    // Se crea la lista de adyacencia
    vector<int> adj[tamaño];

    int i = 0;
    int iguales = 0;
    for(Error listaErrores : errList){

        int j = 0;
        for(Error listaErrores2 : errList){
            //print("Comparando: " + (listaErrores.getStringip()) + "==" + (listaErrores2.getStringip()));
            if(listaErrores.getip().getPort() == listaErrores2.getip().getPort()){
                
                agregarArista(adj,i,j);
                iguales++;
            }
            //if(iguales>=3) return 0;

            j++;
        }
        i++;
    }

    ofstream myfile;
    myfile.open ("listaAdyacencia.txt");

    for (int i = 0; i < tamaño; ++i) {
        myfile << "Lista de adyacencia del nodo " << i << ":";

        for (int j = 0; j < adj[i].size(); ++j)
            myfile << " -> " << adj[i][j];

        myfile << endl;
    }

    myfile.close();
    print("Se ha creado el archivo: listaAdyacencia.txt");

    int fanoutCount = 0;
    int nodeNumber = 0;
    for (int i=0; i<tamaño; ++i){
        if(adj[i].size() > fanoutCount){
            fanoutCount = adj[i].size();
            nodeNumber = i;       
        }
    }
    print("El nodo con mayor fanout es el nodo: " + to_string(nodeNumber) + " con " + to_string(fanoutCount) + " nodos!");


	return 0;
}