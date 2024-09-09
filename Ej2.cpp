#include <iostream>
#include "Cola/Cola.h"
using namespace std;
/*Implementar una función que suprima de la cola todos los elementos mayores que un número 
“n” dado como límite. Al final se 
debe imprimir la cola depurada sin perder el orden que había desde la cola original.*/

int main() {
    char a;
    int num;
    Cola <int> queue,aux;
    cout << "Ingrese los caracteres de la cola 1, para finalizar ingrese un punto" << endl;

    while(a!='.'){
        cin>>num;
        if (a!='.'){
            queue.encolar(num);
        }  
        cout<<"ingresa otro? si) cualquier tecla. no) .\n";
        cin>>a;
    }

    cout << "Ingrese los caracteres el numero que no quiere pasar" << endl;
    cin>>num;

    while(!queue.esVacia()){
        a=queue.desencolar();
        if (a<=num){
            aux.encolar(a);
        }
    }

    while (!aux.esVacia())
    {
        cout<<" ->"<<aux.desencolar();
    }
    

    return 0;
}
