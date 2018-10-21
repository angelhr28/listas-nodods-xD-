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
////////////////////////
void medio (Tnodo &lista){
	if( lista!=NULL){
		Tnodo aux=new struct Nodo;
		Tnodo nuevo = new struct Nodo;
		aux=lista;
		int valor,num;
		cout<<"ingrese el valor a buscar: "<<endl;
		cin>>valor;
		cout<<"ingrese el nuevo valor del nodo:	"<<endl;
		cin>>num;
		nuevo->Dato=num;
		nuevo->Siguiente=NULL;
		nuevo->Anterior=NULL;

		while((aux->Siguiente!=NULL)&&(aux->Dato!=valor)){
			aux=aux->Siguiente;
			}
		if(aux->Siguiente!=NULL){
			nuevo->Siguiente=aux->Siguiente;
			nuevo->Anterior=aux;
			aux->Siguiente = nuevo;
			aux  = aux->Siguiente;
			aux->Anterior = nuevo;	
		}
		else{
			aux->Siguiente=nuevo;
			aux->Siguiente->Anterior=aux;
			
		}		
	}
	
	
}
////////////////////////
void eliminar(Tnodo &lista){
	if(lista!=NULL){
		Tnodo aux;
		aux=lista;
		if(aux->Siguiente!=NULL){
			lista=lista->Siguiente;
			delete aux;
			lista->Siguiente->Anterior=NULL;
		}
		
	}
	
}

////////////////////////
void eliminarvalor(Tnodo &lista){
	
		int valor;
		int borrar;
	
		cout<<"ingrese el valor a borrar:	";
		cin>>borrar;
	if(lista!=NULL){
			Tnodo borra;
			Tnodo aux=NULL;
			borra->Siguiente=NULL;
			borra->Anterior=NULL;
			aux->Anterior=NULL;
			aux->Siguiente=NULL;
		borra=lista;
		while((borra!=NULL)&&(borra->Dato!=borrar)){
			aux=borra;
			borra=borra->Siguiente;
		}
		if(borra==NULL){
			cout<<"no se encuentra el valor";
		}
		else if(aux==NULL){
			lista=lista->Siguiente;
			delete borra;
		}
		else{
			aux->Siguiente=borra->Siguiente;
			borra->Siguiente->Anterior=aux;
			delete borra;
		}
	}
	
	
}

void repoio(Tnodo lista){
	int repoio;
	cout<<"Indique el numero de veces a repetir	:V";
	cin>>repoio;
	for(int i=0;i<repoio;i++){
		Imprimir(lista);
	}
		cout<<"A POCO NO ES FAKE :v"<<endl;
}
////////////////////////
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
             << "4) Insertar delante de un numero" << endl
			 << "5) Eliminar primer valor" << endl
             << "6) Eliminar por valor" << endl
			 << "7) Repoio" << endl
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
        	medio(lista);
        	Imprimir(lista);
        break;
        case 5:
        	eliminar(lista);
        	Imprimir(lista);
    	break;
        case 6:
        	eliminarvalor(lista);
        	Imprimir(lista);
        break;
        case 7:
        	repoio(lista);
        break;
		default:
            cout << "Opcion Invalida" << endl;
        break;
        }
    }
}
