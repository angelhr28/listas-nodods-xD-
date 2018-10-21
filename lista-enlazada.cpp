#include <iostream>
using namespace std;

struct Nodo
{
    int Dato;
    Nodo *Siguiente;
    Nodo *Anterior;
};

typedef struct Nodo *Tnodo;
//typedef struct Nodo *Tnodo;

void Imprimir(Tnodo lista)
{
    Tnodo aux = lista;

    while(aux != NULL)
    {
        cout << aux -> Dato << " ";
        aux = aux -> Siguiente;
    }

    cout << endl;

}

void InsertarAdelante(Tnodo &lista)
{
    Tnodo NuevoNodo = new struct Nodo ;
    int Valor;

    cout << "Introduce el Dato: ";
    cin >> Valor;

    NuevoNodo -> Dato = Valor;
    NuevoNodo -> Siguiente = NULL;
    NuevoNodo -> Anterior = NULL;
    
    if(lista == NULL)
    {
        lista = NuevoNodo;
    }
    else
    {
        NuevoNodo -> Siguiente = lista;
        lista -> Anterior = NuevoNodo;
        lista  = NuevoNodo;
    }
}
void InsertarFinal(Tnodo &lista){
	Tnodo aux=lista;
	Tnodo NuevoNodo = new struct Nodo ;
    int x;

    cout << "Introduce el Dato: ";
        cin >> x;

    NuevoNodo -> Dato = x;
    NuevoNodo -> Siguiente = NULL;
    NuevoNodo -> Anterior = NULL;
    
    if(lista == NULL)//VERIFICA QUE LA LISTA EXISTE
    {
        lista = NuevoNodo;
    }
    else
    {
        while(aux->Siguiente!=NULL)
        	aux=aux->Siguiente;
        aux->Siguiente=NuevoNodo;
		NuevoNodo->Anterior=aux;	
    }
	
}

int main()
{
    int opc;
    Tnodo lista = NULL;
    while(1)
    {
        cout << "L I S T A S  D O B L E S" << endl
             << "1) Insertar al incio" << endl
             << "2) Insertar al final" << endl
              << "3) Imprimir" << endl
             << "3) Salir" << endl
             << "Seleccione Opcion: ";
        do
        {
            cin >> opc;
        }while(opc < 1 && opc > 10);

        switch(opc)
        {
        case 1:
            InsertarAdelante(lista);
            Imprimir(lista);
        break;
        case 2:
        	InsertarFinal(lista);
        	Imprimir(lista);
        break;
        case 3:
        	
        	Imprimir(lista);
        break;
		case 4:
            exit(0);
        break;
        default:
            cout << "Opcion Invalida" << endl;
        break;
        }
    }
}
