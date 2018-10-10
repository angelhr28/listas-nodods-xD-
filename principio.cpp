#include<iostream>
#include <stdlib.h>
#include<stdio.h>
#include<conio.h>
using namespace std;

struct nodo{
	int dato;/////dato de la celda 
	struct nodo *sgte=NULL;//// puntero !dato!:!sgte ->
};

typedef struct nodo *tnodo; /// alias cambio de struct nodo = *tnodo

void alprincipio (tnodo &principio, int valor){
	 tnodo nuevonodo;
 	nuevonodo =new (struct nodo);/// creas nuevo nodo 
 	nuevonodo->dato=valor;//el valor remplaza a dato
 	nuevonodo->sgte=principio;
 	principio =nuevonodo;

}


//////////////////eliminar///////////////

/*void insertarFinal(Tnodo &principio, int valor)
{    //Definimos un puntero temp a tipo nodo
    Tnodo temp, nuevonodo = new(struct nodo);
 
    nuevonodo->Dato  = valor;
    nuevonodo->sgte = NULL;
 
    if(cabeza==NULL)
    {
        cabeza = nuevoNodo;
    }
    else
    {
        temp = cabeza;
        while(temp->sgte!=NULL)
        {
            temp = temp->sgte;
        }
        temp->sgte = nuevoNodo;
    }
 
}


*/
//////////////////////////////////////////////////////////////

void imprimir(tnodo principio){
	   int i = 0;
	 cout<<endl;
	 
     while(principio != NULL)///// conteo //////
	      {
          //cout <<principio->dato <<" ";
          i++;
          principio = principio->sgte;
     }
     cout<<endl<<i;
	
}

///////////maximo valor de una lista //////////////
void maximo (tnodo principio,int valor ){
	int mayor = 0;
	int cant;
	cout<<"ingresa el cantidad de elementos";
	cin>>cant;
	
	for(int i=0;i<cant;i++){
		cout<<"ingrese los valores de la lista:";
		cin>>valor;
	
		if(valor<mayor){
		mayor = valor;
		cout<<"el numero mayor es: "<<mayor ;	
		}
	}
	
}


//////////////// buscar un elemente


int main(){
	int info;
	tnodo principio = NULL;
		cout<<"numero de insertar";
		cin>>info;
	alprincipio(principio,info);
	imprimir(principio);
	maximo (principio,info);
	return 0;
	
}
