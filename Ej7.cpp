/*Imagina una oficina con varias impresoras compartidas por varios empleados.
 Cada vez que un empleado envía un documento para imprimir, este se coloca en una cola de impresión. 
 Las impresoras trabajan de manera que el primer documento enviado es el primero en ser impreso. Si una impresora está ocupada, 
 el documento queda en espera en la cola hasta que la impresora esté disponible.
Implementar un sistema de gestión de colas de impresión en el que se:
•	Agreguen documentos a la cola de impresión.
•	Se impriman documentos en el orden en que fueron enviados.
•	Se pueda mostrar el estado de la cola de impresión y los documentos pendientes.
*/

#include <iostream>
#include "Cola/Cola.h"
using namespace std;

struct Documento {
    string nombre;
    int paginas;

    Documento(const string& nombre = "", int paginas = 0) : nombre(nombre), paginas(paginas) {}

    void mostrar() const {
        cout << "Documento: " << nombre << ", Paginas: " << paginas << endl;
    }
};

int main(){
    bool c=true;
    Documento doc;
    Cola <Documento> cola,aux;
    int op;

     while (c)
    {
        cout<<"quiere: 1) agregar un documento a la cola de impresión, 2) Imprimir un documento, 3) mostrar estado de cola, 4) salir\n";
        cin>>op;

        switch (op){
        case 1:
            cout<<"ingrese el nombre del documento: \n";
            cin>>doc.nombre;
            cout<<"ingrese el nro de paginas del documento: \n";
            cin>>doc.paginas;
            cola.encolar(doc);

            break;
        case 2:
            doc=cola.desencolar();
            cout<<"\n IMPRESIÓN \n"<<"Nombre: "<<doc.nombre<<", Nro de páginas: "<<doc.paginas<<endl;

            break;
        case 3:
            cout<<"Documentos en la cola: \n";
            while(!aux.esVacia()){
                aux.desencolar();
            }
            while(!cola.esVacia()){
                doc=cola.desencolar();
                cout<<"* ";
                doc.mostrar();
                aux.encolar(doc);
            }
            while (!aux.esVacia())
            {
                cola.encolar(aux.desencolar());
            }
            break;
        default:
            cout<<"Saliendo del programa...";
            return 0;
            break;
        }
    }

}