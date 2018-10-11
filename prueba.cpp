#include<iostream>
#include<conio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
struct nodo {
	int dato;
	nodo *sig=NULL;
};
typedef struct nodo *Tnodo;//////le das un alias 
///////////////inicio
void inicio(Tnodo &cabeza,int valor){
	Tnodo nuevo;
	nuevo=new (struct nodo);
	nuevo->dato=valor;
	nuevo->sig=cabeza;
	cabeza=nuevo;
}
//////////7final
void final(Tnodo &cabeza, int valor){
	Tnodo aux,nuevo=new (struct nodo);
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
/////7/7imprimir
void imprime(Tnodo cabeza){
	int i=1;
	cout<<endl;
	while(cabeza !=NULL){
		cout<<i++<<")"<<cabeza->dato<<"	";///////////////////////////////////////////7cambio	
		cabeza=cabeza->sig;
	}
}
////////////////////NUMERO MAYOR
void mayor(Tnodo cabeza){
	int mayor=0;
	while(cabeza!=NULL){
		if(cabeza->dato>mayor){
			mayor=cabeza->dato;
		}
		cabeza=cabeza->sig;
	}
	cout<<"el numero mayor es:	"<<mayor<<endl;
}
///////////////////menor
void menor(Tnodo cabeza){
	int menor=9999999;
	while(cabeza!=NULL){
		if(cabeza->dato<menor){
			menor=cabeza->dato;
		}
		cabeza=cabeza->sig;
	}
	cout<<"el numero menor es: "<<menor<<endl;
}

///////////busqueda
void busqueda(Tnodo cabeza){
	int n;
	int bus;
	cout<<"indique el numero a buscar:	"<<endl;
	cin>>bus;
	while(cabeza!=NULL){
		if(cabeza->dato==bus){
			n++;
			cout<<"el numero	"<< bus << "	si existe en la lista en la posicion 	"<<n<<endl;
		}
		else
		{
			n++;
		}
		cabeza=cabeza->sig;
	}

	
}
/////////////eliminar
void eliminar(Tnodo &cabeza){
	int borra;
	cout<<"indique el numero a borrar:	";
	cin>>borra;


	if(cabeza!=NULL){
		Tnodo aux=NULL;
		Tnodo borrar;
		borrar = cabeza;
		while((borrar !=NULL)&&(borrar->dato!=borra)){
			aux=borrar;
			borrar=borrar->sig;
		}
		if(borrar==NULL){
		cout<<"el numero no esta en la lista.";
		}
		else if( aux ==NULL){
				cabeza=cabeza->sig;
				delete borrar;
		}
		else{
			aux->sig=borrar->sig;
			delete borrar;
			
		}
	}
	
}

////////////////////repoios 
void repoio(Tnodo &cabeza,int num ){
	
	
	
	Tnodo aux=cabeza;
	num=aux->dato;
	cabeza=aux->sig;
	delete aux;
		
}
///////////////////////////////////
void eliminar_varios (Tnodo cabeza, int numero_eliminado) {

	Tnodo nodo_auxiliar = new nodo;

	nodo_auxiliar = NULL;

	if (cabeza == NULL) {
		cout << "its empty";
	} else{
		while (cabeza != NULL) {
			
			//cout << "hola esto funciona ? "<< endl;
			cout << cabeza->dato<<endl;
			if (cabeza->dato == numero_eliminado ) {
				// en caso de que sea el ultimo
				if (cabeza->sig == NULL) {
					nodo_auxiliar->sig = NULL;
					return ;
				}

				if (nodo_auxiliar != NULL) {
					nodo_auxiliar->sig = cabeza->sig;
					//cabeza = cabeza->sgte;
					cabeza = cabeza->sig;
				}

				//if ()
				// else {
				//	cabeza = cabeza->sgte;
				//}
			}
			nodo_auxiliar = cabeza;
			cabeza = cabeza->sig;
		}
	}
}



/////////////////////////////////////////
void menu(){
	cout<<"1. INGRESO ADELANTE"<<endl;
	cout<<"2. INGRESE AL FINAL"<<endl;
	cout<<"3. NUMERO MAYOR"<<endl;
	cout<<"4. NUMERO MENOR"<<endl;
	cout<<"5. BUSQUEDA DE UN VALOR"<<endl;
	cout<<"6. ELIMINACION DE VALOR"<<endl;
	cout<<"7. ELIMINACION DE VALORES REPETIDOS"<<endl;
	cout<<"OPCION: ";
}
int main(){
	Tnodo cabeza=NULL;
	int valor;
	int opcion;
	int gg=1;
	while(gg!=0){
		menu();
		cin>>opcion;
		
		switch(opcion){
			case 1: 
				cout<<"INGRESE UN NUMERO ADELANTE"<<endl;
				cin>>valor;
				inicio(cabeza,valor);
				break;
			case 2:
				cout<<"INGRESE UN NUMERO FINAL"<<endl;
				cin>>valor;
				final(cabeza,valor);
				
				break;
			case 3:
				cout<<"NUMERO MAYOR"<<endl;
				mayor(cabeza);
				break;
			case 4:
				cout<<"NUMERO MENOR "<<endl;
				menor(cabeza);
				break;
			case 5:
				cout<<"BUSQUEDA DE NUMERO"<<endl;
				busqueda(cabeza);
				break;
			case 6:
				cout<<"ELIMINAR UN NUMERO"<<endl;
				eliminar(cabeza);
				break;
			case 7: 
				int borrar;
				/*cout<<"ELIMINACION DE NUMEROS MULTIPLES";
				cout<<"que numero desea eliminar";
				cin>>borrar;
				
				while(cabeza!=NULL){
					repoio(cabeza,borrar);
				}*/
					int numero_eliminado = 0;
				cout<<"ELIMINACION DE VARIOS NUMEROS"<<endl;
				cout << "ingrese el numero que quieres eliminar" <<endl;
				cin >> numero_eliminado;
				eliminar_varios(cabeza, numero_eliminado);	
				
				
		}
		system("pause");
		system("cls");
		cout<<"--------------VALORES DE LA LISTA---------------------"<<endl;
		imprime(cabeza);
		cout<<endl;
		cout<<"----------------------------------"<<endl;
	}
	return 0; 
}
