#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std; 
int cantidad;
int gg();
int imprimir();
struct nombres{
	string alumno;
	int codigo;
	int promedio;
	int edad; 
};
int main(){
	gg();
	imprimir();
}

int gg (){

cout<<"ingrese la cantidad de personas ";
cin>>cantidad;
nombres persona[cantidad];
for(int i=0; i<cantidad;i++){



cout<<"ingrese el nombre: "; 
fflush(stdin); 
getline(cin,persona[i].alumno);// al momento de poner el punto se almacena en la variable creada.Xd
cout<<"ingrese el codigo : "<<endl;
cin>>persona[i].codigo;
cout<<"ingrese la edad : "<<endl;
cin>>persona[i].edad;
cout<<"ingrese el promedio : "<<endl;
cin>>persona[i].promedio;

}
}
int imprimir(){
nombres persona[cantidad];
for(int i=0; i<cantidad;i++){


cout<<"su datos son : "<<persona[i].alumno<<"\t"<<persona[i].edad<<"\t"<<persona[i].codigo<<"\t"<<persona[i].promedio<<endl;
}
}

