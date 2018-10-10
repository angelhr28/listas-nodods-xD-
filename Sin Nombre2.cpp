#include<iostream>
#include <stdlib.h>
#include<stdio.h>
#include<conio.h>
using namespace std;
struct nodo{
	int dato;
	nodo *sgte=NULL;
};
nodo *inicio=NULL;
nodo *final=NULL;
bool esVacio(nodo *inicio){//////////// poder verificar si 
	return inicio==NULL;
}
void insert_inicio(nodo *&inicio, nodo *&fin, int dato ){
	nodo *nuevonodo=new nodo;
	nuevonodo->dato=dato;
	if(esVacio(inicio)){
		inicio=fin=nuevonodo;
	}else{
		nuevonodo->sgte=inicio;
		inicio=nuevonodo;
	}
}



void imprimir(nodo *inicio){
	if(esVacio(inicio)){
		cout<<"Vacio";
	} else{
		nodo *recorrer=new nodo;
		recorrer=inicio;
		while(recorrer!=NULL){
			cout<<recorrer->dato;
			recorrer=recorrer->sgte;
		}
		
	}
}
int main(){
	insert_inicio(inicio,final,5);
		imprimir(inicio);
	return 0;
}
