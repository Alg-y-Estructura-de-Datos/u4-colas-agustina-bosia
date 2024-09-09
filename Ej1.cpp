#include <iostream>
#include "Cola/Cola.h"
using namespace std;
/*Diseñe un programa que sea capaz de leer dos colas y mediante un mensaje indicar si son iguales.
Nota: los elementos constitutivos de las colas son caracteres.*/

bool sonIguales(Cola <char>& queue1, Cola <char>& queue2){
    char variable;
    int tama1,tama2;


    cout << "ingrese el tamaño de la cola 1:" << endl;
    cin>> tama1;
    cout << "ingrese el tamaño de la cola 2:" << endl;
    cin>> tama2;

    if (tama1!=tama2){
        return false;
    } 

    for (int i=0; i<tama1; i++){
        cout<<"ingrese el elemento"<<i+1<<"de la fila 1:\n" ;
        cin>>variable;
        queue1.encolar(variable);
    }
    for (int i=0; i<tama2; i++){
        cout<<"ingrese el elemento"<<i+1<<"de la fila 2:\n" ;
        cin>>variable;
        queue2.encolar(variable);
    }
    
    while (!queue1.esVacia()){
        if(queue1.desencolar()!=queue2.desencolar())return false;
    }

    return true;
}

int main() {
    Cola <char> queue1;
    Cola <char> queue2;
    char variable;
    int tama1,tama2;

    if (sonIguales(queue1,queue2)) {
        cout<<"son iguales\n";
    }
    else{
        cout<<"no son iguales\n";
    } 

    return 0;
}
