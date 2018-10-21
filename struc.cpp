#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void servicio();
void imprimir();
struct persona{
	string nombre;
	string apellido;
	int dni;
	int edad;

	
};
persona *dato;
	int num;
	
int main(){
	servicio();
	imprimir();
}

void servicio(){

	cout<<"ingrese el numero de trabajadores ";
	cin>>num;
		dato= new persona[num];
	for(int i=0;i<num;i++){
		cout<<"ingrese el nombre del trabajador: ";
		fflush(stdin);
		getline(cin,dato[i].nombre);
		cout<<"ingrese  el apellido :	";
		getline(cin,dato[i].apellido);
		cout<<"ingrese su edad:	";
		cin>>dato[i].edad;
		
	}


}
void imprimir(){
for(int i=0;i<num;i++){

		cout<< dato[i].nombre<<"	"<<dato[i].apellido<<"	"<<dato[i].edad<<endl;
	}
}


