#include "linkedList.h"
#include <string>

// Código de ejecución: g++ -std=c++11 -o main main.cpp && ./main

int main() {

    // int
    linkedList<int> listaInt;

    // create 
    listaInt.addFirst(10);
    listaInt.addFirst(20);
    listaInt.addFirst(30);
    listaInt.addFirst(40);
    listaInt.addFirst(50);
    listaInt.addFirst(60);
    listaInt.print();

    // read
    std::cout<<"Primer elemento: "<<listaInt.read(0)<<",  ";
    std::cout<<"Segundo elemento: "<<listaInt.read(1)<<", ";
    std::cout<<"Tercer elemento: "<<listaInt.read(2)<<std::endl;

    // update 
    listaInt = listaInt.update(0, 100).update(1, 90).update(2, 80);
    listaInt.print();

    // delete
    listaInt = listaInt.del(0).del(1).del(2);
    listaInt.print();

    // str
    linkedList<std::string> listaStr;
    listaStr.addFirst("Olla");
    listaStr.addFirst("Estufa");
    listaStr.addFirst("Jarra");
    listaStr.addFirst("Plato");
    listaStr.print();

    // read
    std::cout<<"Primer elemento: "<<listaStr.read(0)<<",  ";
    std::cout<<"Segundo elemento: "<<listaStr.read(1)<<", ";
    std::cout<<"Tercer elemento: "<<listaStr.read(2)<<std::endl;
    
    // update 
    listaStr = listaStr.update(0, "Cuchara").update(1, "Tenedor").update(2, "Cuchillo");
    listaStr.print();

    // delete
    listaStr = listaStr.del(0).del(1).del(0);
    listaStr.print();
}