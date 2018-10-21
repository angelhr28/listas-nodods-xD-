#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct nodo{
	int dato;
	nodo *sig=NULL;
};
typedef struct nodo *tnodo;//alias al nodo
//void ingreseadelante();
void ingreseadelante(tnodo &cabeza, int valor){
	tnodo aux;
	aux = new(struct nodo);
	aux->dato=valor;
	aux->sig=cabeza;
	cabeza=aux;
}
void final(tnodo &cabeza, int valor){
	tnodo aux,nuevo=new (struct nodo);
	nuevo->dato=valor;
	nuevo->sig=NULL;
	
	if(cabeza==NULL){
		cabeza=nuevo;
	}
	else{
		aux=cabeza;
		while(aux->sig!=NULL){
			aux=aux->sig;
		}
		aux->sig=nuevo;
	}
}
/////////////numero mayor
void busqueda(tnodo cabeza){
	int a,i=1;
	cout<<"ingrese el valor q desebuscar:	";
	cin>>a;
	while (cabeza!=NULL){
		if(cabeza->dato==a){
			cout<<"el numero "<<a<<"	se encuentra el la lista en la posicion" <<i++;
		}
		else{
			 i++;
		}
		cabeza=cabeza->sig;
	}
	
}
///////////borrar
void borrar(tnodo &cabeza){
	int borra;
	cout<<"numero a borrar:	";
	cin>>borra;
	if(cabeza!=NULL){
		tnodo aux=NULL;
		tnodo borrar;
		borrar=cabeza;
		while((borrar!=NULL)&&(borrar->dato!=borra)){
			aux=borrar;
			borrar=borrar->sig;
		}
		if(borrar==NULL){
		cout<<"el valor no existe";	
		}
		else if(aux==NULL){
			cabeza=cabeza->sig;
			delete borrar;
		}
		else{
			aux->sig=borrar->sig;
			delete borrar;
		}
	}
}

//////////dos primeros 
void dosprimeros(tnodo &cabeza){
	if(cabeza!=NULL){

		tnodo aux1,aux2=NULL;
		aux1=cabeza;
		if(aux1!= NULL){
			aux2=aux1;
			aux1=aux1->sig;
//				if(aux2!=NULL){
//					aux2=aux1;
//					aux1=aux1->sig;     pendejada mia xD 
//				
//				}
		cabeza=aux1->sig;
		delete aux1;
		delete aux2;
		
		}
	}
}
//////////////dos ultimos
void dosfinal(tnodo &cabeza){
	if(cabeza!=NULL){
		tnodo aux1;
		tnodo aux2=NULL;
		aux1=cabeza;
	
		while(aux1!=NULL){
			
			aux2=aux1;
			aux1=aux1->sig;
		}
	
		if(aux2!=NULL){
			cabeza->sig=NULL;
			delete aux1;
			delete aux2;
			
			
		}
	
	}
	
}


/////////////////////////////77
void imprimir(tnodo cabeza){
	int i=1;
	while(cabeza !=NULL){
		cout<<"["<<i++<<"]->"<<cabeza->dato;
		cabeza=cabeza->sig;
		
	}
	
}


void menu(){
	cout<<"1.adelante"<<endl;
	cout<<"2.atras"<<endl;
	cout<<"3.buscar"<<endl;
}

int main (){
	
	tnodo cabeza=NULL ;
	int valor;
	int a=1;
	int opc;
	while(a!=0)	{
		menu();
		cin>>opc;
		switch(opc){
		case 1:
			cout<<"ingrese el numero adelante:	";
			cin>>valor;
			ingreseadelante(cabeza, valor);
		
			break;
		case 2:
			cout<<"ingrese el numero final:	";
			cin>>valor;
			final(cabeza,valor);
			
			break;
		case 3:
			cout<<"busqueda";
			busqueda(cabeza);
			
			break;
		case 4:
			 dosprimeros(cabeza);
			break;	
		case 5:
			dosfinal(cabeza);
			break;
		}
		system("pause");
		system("cls");
		cout<<"--------------VALORES DE LA LISTA---------------------"<<endl;
		imprimir(cabeza);
		cout<<endl;
		cout<<"----------------------------------"<<endl;
	}
	
}
