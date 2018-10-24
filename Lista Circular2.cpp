
#include <iostream>
#include <cstdlib>
using namespace std;

struct Nodo{
            int Dato;    
            Nodo *Sigte; 
            };
 
typedef struct Nodo Nodo1;
Nodo1 *Cola;
Nodo1 *Cabeza;


void menu()
{
    cout<<"\n\t\tLISTA ENLAZADA CIRCULAR\n\n"<<endl;
    cout<<" 1. INSERTAR AL INICIO "<<endl;
    cout<<" 2. INSERTAR AL FINAL "<<endl;
    cout<<" 3. REPORTAR LISTA"<<endl ;
    cout<<" 4. CONTEO"<<endl;
  	cout<<" 5. BUSQUEDA"<<endl;
  	cout<<" 6. ELIMINACION"<<endl;
  	cout<<" 7. REPETIR"<<endl;
  	cout<<" 8. DISTANCIA"<<endl;
  	cout<<" 9. INSERTAR LUEGO DE..."<<endl;
  	cout<<" 10. SALIR"<<endl;
    cout<<"INGRESE OPCION: ";
}
 
void InsertarInicio()
{
   Nodo1 *NuevoNodo;
   NuevoNodo=new struct Nodo;
 
   cout<<"\n**INSERTA AL INICIO**\n";
   cout<<"\nINGRESE DATO:";
   cin>>NuevoNodo->Dato;
   NuevoNodo->Sigte=NULL;

 
 
   if(Cabeza==NULL)
    {
        cout<<"insertando primer elemento!";
        Cabeza=NuevoNodo;
        Cabeza->Sigte=Cabeza;
        Cola=NuevoNodo;
      }
   else if(NuevoNodo->Dato!=Cabeza->Dato)
    {
        NuevoNodo->Sigte = Cabeza;
        Cabeza = NuevoNodo;
        Cola->Sigte = Cabeza;
    }else{
	cout<<"el numero ya existe"<<endl;
}

}
void InsertarFinal()
{
    Nodo1 *NuevoNodo;
    NuevoNodo=new struct Nodo;
    cout<<"\n INSERTA AL INICIO\n";
    cout<<"\nINGRESE DATO:";
    cin>>NuevoNodo->Dato;
    NuevoNodo->Sigte=NULL;
 
     if(Cabeza==NULL)
        {
             cout<<"PRIMER ELEMENTO..!!!";
             Cabeza=NuevoNodo;
             Cabeza->Sigte=Cabeza;
             Cola=NuevoNodo;
        }
     else if(NuevoNodo->Dato!=Cabeza->Dato)
        {
          Cola->Sigte = NuevoNodo;
          NuevoNodo->Sigte = Cabeza;
          Cola = NuevoNodo;
        }
        else {
        	cout<<"el numero ya existe "<<endl;
		}
}
/////////////////////////// conteo
void conteo(){
	Nodo1 *aux;
	int i=0;
	if(Cabeza!=NULL)
	
	aux=Cabeza;
	do{
			i++;
		aux=aux->Sigte;
	}
	while(aux!=Cabeza);
	cout<<i;
}

/////////////////////////// busqueda
void busqueda(){
	int num;
	int i=1;
	Nodo1 *busqueda;
	cout<<"ingrese el numero a buscar:";
	cin>>num;
	if(Cabeza!=NULL){
		
			busqueda=Cabeza;
	while((busqueda!=NULL)&&(busqueda->Dato!=num)){
				i++;
			busqueda=busqueda->Sigte;
		}
		
		if(busqueda->Dato==num){
			cout<<"el numero	"<<num<<"	se encuentra dentro de la lista en la posicion	"<<i<<endl;
		}
		else{
			cout<<"el numero	"<<num<<"	no esta dentro de la lista";
		}
	}
	else{
		cout<<"la lista esta vacia";
	}
	
	
}
/////////////////////////////////
void eliminar(){
	if(Cabeza!=NULL){
		int borrar;
		Nodo1 *borra;
		Nodo1 *aux=NULL;
		cout<<"indique el numero a borrar:";
		cin>>borrar;
		borra=Cabeza;
			do{
			aux=borra;
			borra=borra->Sigte;
		}
		while((borra!=Cabeza)&&(borra->Dato!=borrar));
		if(borra==Cabeza){
			cout<<"el valor no existe en la lista.";
		}
		else if(aux==NULL){
			Cabeza=Cabeza->Sigte;
			delete borra;
			Cabeza->Sigte=Cabeza;
		}
		else {
		aux->Sigte=borra->Sigte;
		delete borra;	
		}
	}
}
////////////////////////////
void distancia(){
	int num;
	int i,a=0;
	Nodo1 *busqueda,*aux;
	cout<<"ingrese el numero a buscar:";
	cin>>num;
	if(Cabeza!=NULL){
		
			busqueda=Cabeza;
		do{
			busqueda=busqueda->Sigte;
		}
		while((busqueda!=Cabeza)&&(busqueda->Dato!=num));
		if(busqueda->Dato==num){
			aux=busqueda;
			while(aux!=Cabeza){
				i++;
				aux=aux->Sigte;
			}		
			cout<<"la cantidad de nodos entre el numero  "<<num<<"	y la cabeza es: "<<i<<endl;
			while(aux!=Cola){
				a++;
				aux=aux->Sigte;
			}
			cout<<"la cantidad de nodos entre el numero  "<<num<<"	y la cola es: "<<a<<endl;
				
		}
	}			
}
////////////////////////////////

void delantedeotro(){
	Nodo1 *busqueda;
	Nodo1 *aux;
	Nodo1 *nuevo_nodo = new struct Nodo;
	int numero_ingresado;
	int numero_delante;
	
	cout<< "ingresar un numero que quieras encontrar"<<endl;
	cin>> numero_ingresado;
	cout << "ahora el numero que ira delante"<<endl;
	cin >> numero_delante;
	nuevo_nodo->Dato = numero_delante;
	if(Cabeza!=NULL){	
		busqueda=Cabeza;
		aux = busqueda->Sigte;
	
		while(busqueda->Sigte != Cabeza) {
			
			if (busqueda->Dato == numero_ingresado) {
				busqueda->Sigte = nuevo_nodo;
				nuevo_nodo->Sigte = aux; 
				return ;
			}

			if (aux->Dato == numero_ingresado){	
			
				if (aux->Sigte == Cabeza) {
					
					aux->Sigte = nuevo_nodo;
					nuevo_nodo->Sigte = Cabeza;
					return ;
				}
				else {
					busqueda = busqueda->Sigte;
					aux = busqueda->Sigte;
					busqueda->Sigte = nuevo_nodo;
					nuevo_nodo->Sigte = aux; 
				}
			}
			busqueda=busqueda->Sigte;
			aux = busqueda->Sigte;
		}
		
	}
		
}
////////////////////////////////////
void Mostrar()
{   Nodo1 *aux;
    aux=Cabeza;

    if(Cabeza!=NULL)
     {
          do
          {    cout<<"  "<<aux->Dato;
               aux = aux->Sigte;
          }while(aux!=Cabeza);
      }
     else
         cout<<"\n\n\tLista vacia...!"<<endl;
 
 
}
/////////////////////
void repoio(){
	int num;
	cout<<"igrese la cantidad de visitas";
	cin>>num;
	for( int i=0;i<num;i++){
		Mostrar();
	}
}




///////////////7////
int main(void)
{
    Cabeza = NULL;
    int op;    
 
    do
    {
        menu();
        cin>>op;
 
        switch(op)
        {
            case 1:
                    InsertarInicio();
                    break;
 
            case 2:
                    InsertarFinal();
                    break;
            case 3:
                    cout<<"\n\n Lista Circular \n\n";
                    Mostrar();
                    break;
 			case 4: 
 					cout<<"el numero de nodos son:	";
 					conteo();
 					break;
 			case 5: 
 					cout<<"busqueda"<<endl;
 					busqueda();
 					break;
 			case 6:
 					cout<<"eliminar "<<endl;
 					eliminar();
 					Mostrar();
 					break;
 			case 7:
 					cout<<"repetir"<<endl;
 					repoio();
 					break; 
 			case 8: 
 					cout<<"repetidos"<<endl;
 					distancia();
 					break;
 			case 9: 
 					cout<<"insertar delante de:"<<endl;
 					delantedeotro();
 					Mostrar();
 					break;
            default: cout<<"OPCION NO VALIDA...!!!";
                     break; 
        }
 
        cout<<endl<<endl;
 
    }while(op!=10);
}

