
#include <iostream>
#include <conio.h>
using namespace std;
 //creamos nuestro nodo
struct nodo{
       int Dato;        
       struct nodo *sgte;
};

//Con la palabra typedef definimos un alias llamado "tnodo" que es de tipo "struct nodo *" 
//Creamos un alias para tipo de dato puntero a nodo:
typedef struct nodo *Tnodo;
//insertamos el una
void insertarInicio(Tnodo &cabeza, int valor)
{   //Definimos un puntero nuevoNodo a tipo nodo
    Tnodo nuevoNodo;
    nuevoNodo = new(struct nodo);
    nuevoNodo->Dato = valor;
    nuevoNodo->sgte = cabeza;
    cabeza  = nuevoNodo;
}

void insertarFinal(Tnodo &cabeza, int valor)
{    //Definimos un puntero temp a tipo nodo
    Tnodo temp, nuevoNodo = new(struct nodo);
 
    nuevoNodo->Dato  = valor;
    nuevoNodo->sgte = NULL;
 
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
 
void reportarLista(Tnodo cabeza)
{
     //int i = 0;
	 cout<<endl;
	 
     while(cabeza != NULL)
     {
          cout <<cabeza->Dato <<" ";
          cabeza = cabeza->sgte;
          //i++;
     }
    // cout<<endl<<i;
}

///////////maximo valor de una lista //////////////

void maximo(Tnodo cabeza){
	int mayor = 0;
	
     while(cabeza != NULL)
     {
		if(cabeza->Dato  > mayor){
			mayor = cabeza->Dato;
//			
		}
         
         cabeza = cabeza->sgte;
     
     }
	cout<<"el numero maximo es: "<<mayor<<endl;
	
	
}



void menu()
{
    cout<<"\n \t LISTA ENLAZADA SIMPLE\n\n";
    cout<<" 1. INSERTAR AL INICIO ";
    cout<<" 2. INSERTAR AL FINAL ";
    cout<<"3. NUMERO MAXIMO";
	cout<<" 3. SALIR  :";
}
 
int main()
{   //variable global que apunta al primer nodo de la lista y que ademàs esta vacía
    Tnodo cabeza = NULL;
    int opcion;    
    int info;  
    int pos,a=1;    
 
 
 
 
 
 
   while(a!=0){
    	menu();  
			cin>> opcion;
             
        switch(opcion)
        {
        
			case 1:
 
                 cout<< "\n NUMERO A INSERTAR: ";
				 cin>> info;
                 insertarInicio(cabeza, info);
                 reportarLista(cabeza);
            break;
 
 
            case 2:
 
                 cout<< "\n NUMERO A INSERTAR: "; 
				 cin>> info;
                 insertarFinal(cabeza, info );
                 reportarLista(cabeza);
              break;
              
			  case 3:
			  cout<<"NUMERO MAYOR: "<<endl;
			  	maximo(cabeza);   
                 
                 
                 
            break;


                    }

        cout<<endl<<endl;
 
}

}
