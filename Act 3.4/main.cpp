// Gabriel Ernesto Mujica Proulx A01285409
// Miguel Mendoza Jaidar A01234354
// Esteban Sierra Baccio A00836286

// Actividad 3.4
// Ultima modificacion 21/nov/2023
// Main para procesar archivo bitacora


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
    my_file.open("bitacora-V2.txt", ios::in);
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
            IP nIP;
            nIP = arr[3];

            print("Se cargo la linea: " + to_string(lineNumber));


            //Se agrega el IP a un nodo del arbol
            Arbol.add(nIP);
            lineNumber = lineNumber + 1;
        } 
        // Se cierra el archivo 
        my_file.close();
        cout << "\nArchivo cargado y ordenado correctamente." << endl;

        //Se imprime la informacion relevante que se pide
        cout << "\nLa llave mas grande es: " << Arbol.getGreatestKey() << endl;
        cout << "\nLas siguientes son las IPs con mas accesos: " << endl;
        Arbol.printKey(Arbol.getGreatestKey());
        Arbol.printKey(Arbol.getGreatestKey() - 1);

        //Se pide un numero al usuario para imprimir las IPs con cierta cantidad de accesos
        cout << "\nIngresa un numero para imprimir las IPs con esa llave: " << endl;
        int accesos;
        cin >> accesos;
        cout << "Las siguientes IPs tienen " << accesos << " accesos: " << endl;
        Arbol.printKey(accesos);

    }

    return 0;
}