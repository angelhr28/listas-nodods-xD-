#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;


struct datos{
	string nombre;
	string apellido;
	int edad;
};
 
int cantidad;

int main (){
	
	cout<<"ingrese la cantidad de personas ";
cin>>cantidad;

	
	datos *persona=new datos[cantidad];
 //persona=new int[5];	
for(int i=0;i<5;i++){
	cout<<"ingrese el nombre: "<<endl;
	fflush(stdin);
	getline(cin,persona[i].nombre);
	cout<<"ingrese el apellido"<<endl;
	fflush(stdin);
	getline(cin,persona[i].apellido);
	cout<<"ingrese su codigo: "<<endl;
	cin>>persona[i].edad;
}	
for (int i=0;i<5;i++){
	cout<<"datos del alumno "<<i+1<<"	"<<persona[i].nombre <<"	"<<persona[i].apellido<<endl<<endl;
	cout<<"el codigo del alumno:  "<<i+1<<"  es: "<<persona[i].edad<<endl<<endl; 
}
	
}
