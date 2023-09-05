//Gabriel Ernesto Mujica Proulx
//A01285409
//Actividad 1.3
//01/09/2023

#include <bits/stdc++.h>

#include "Error.cpp"
#include "Error.h"

using namespace std;

// Función para cargar los datos de un archivo
void cargarArchivo(vector<Error*> &errores){
    // Se lee el archivo de la bitácora de errores
    string archivo = "bitacora.txt";
    ifstream archivoBitacora(archivo);

    // Se valida que se pueda leer el archivo
    if(archivoBitacora.is_open()){
        string linea;
        
        // Se lee el archivo de errores hasta encontrar un renglón vacío 
        while(getline(archivoBitacora, linea)){
            stringstream ss(linea);
            string mes;
            int dia;
            string hora;
            string IP;
            string razon;

            ss >> mes >> dia >> hora >> IP >> razon;

            errores.push_back(new Error(mes, dia, hora, IP, razon));
        } 
                
        archivoBitacora.close();
        cout << "Se cargo el archivo correctamente." << endl;
    }
    else {
        cout << "Archivo de bitácora invalido." << endl;
    }
}
