#include <iostream>
#include <string.h>
using namespace std;


void printArray(int arr[], int size){   
    int i = 0;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


template <class T>
T input(string textoPrevio){
    cout << textoPrevio;
    T resultado;
    cin >> resultado;
    return resultado;
}


void print(string thisIsAString){
    cout << thisIsAString << endl;
}


int getMonthAsNumber(string value){
    if(value == "Jan") return 0;
    if(value == "Feb") return 1;
    if(value == "Mar") return 2;
    if(value == "Apr") return 3;
    if(value == "May") return 4;
    if(value == "Jun") return 5;
    if(value == "Jul") return 6;
    if(value == "Aug") return 7;
    if(value == "Sep") return 8;
    if(value == "Oct") return 9;
    if(value == "Nov") return 10;
    if(value == "Dec") return 11;
    else return -1;
}

string getNumberAsMonth(int value){
    if(value == 0) return "Jan";
    if(value == 1) return "Feb";
    if(value == 2) return "Mar";
    if(value == 3) return "Apr";
    if(value == 4) return "May";
    if(value == 5) return "Jun";
    if(value == 6) return "Jul";
    if(value == 7) return "Aug";
    if(value == 8) return "Sep";
    if(value == 9) return "Oct";
    if(value == 10) return "Nov";
    if(value == 11) return "Dec";
    else return "Na";
}
