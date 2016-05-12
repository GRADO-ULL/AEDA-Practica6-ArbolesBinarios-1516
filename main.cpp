#include<iostream>
#include<stdlib.h>

#include "DNI.h"
#include "nodo.h"
#include "arbol.h"

using namespace std;


int main()
{
    /*DNI dni1(12345678);
    DNI dni2(87654321);
    DNI dni3(11111111);
    
    nodo<TDATO>* n2 = new nodo<TDATO>(dni1);
    nodo<TDATO>* n3 = new nodo<TDATO>(dni2);
    nodo<TDATO>* n1 = new nodo<TDATO>(dni3, n2, n3);

    cout << "Probando clase nodo y metodos:" << endl;
    cout << "Imprimiendo valor de raiz: " << n1->get_dato() << endl;    
    cout << "Imprimiendo valor de nodo-hijo derecha de n1: " << (n1->get_derecha())->get_dato() << endl;
    cout << "Imprimiendo valor de nodo-hijo izquierda de n1: " << (n1->get_izquierda())->get_dato() << endl;
    */
    
    Arbol<int> a1;

    int opcion_elegida = 0;
    TDATO nuevo_dato;
    TDATO eliminar_dato;
    TDATO buscar_dato;
    
    int contador = 0;
    cout << "-----PRACTICA 6. ARBOLES BINARIOS DE BUSQUEDA.-----" << endl;
    cout << "MENU:" << endl;
    
    do
    {
        cout << "Opciones disponibles." << endl;
        cout << "1.- Insertar." << endl;
        cout << "2.- Eliminar." << endl;
        cout << "3.- Buscar." << endl;
        cout << "4.- Salir y mostrar el arbol." << endl;
        cout << "Opcion:";
        cin >> opcion_elegida;
        switch(opcion_elegida)
        {
            case 1:
            {
                cout << "Nuevo nodo a insertar:";
                cin >> nuevo_dato;
                a1.insertar(nuevo_dato);
                break;
            }
            
            case 2:
            {
                cout << "Dato a eliminar:";
                cin >> eliminar_dato;
                a1.eliminar(eliminar_dato);
                break;
            }
            case 3:
            {
                cout << "Dato a buscar:";
                cin >> buscar_dato;
                if(a1.buscar(buscar_dato) != NULL)
                {
                    cout << "Dato encontrado" << endl;    
                }
                else
                {
                    cout << "Dato no encontrado" << endl;
                }
                
                break;
            }
            case 4:
            {
                cout << "Ha introducido salir del sistema." << endl;
                break;
            }
            default:
                cerr << "Opcion introducida no valida." << endl;
                opcion_elegida = 4;                
        }
        cout << "------------------------------------" << endl;
    }while(opcion_elegida != 4);
    
    a1.imprimir();
    cout << endl;
    
    return 0;
}