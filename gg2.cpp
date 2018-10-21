 #include <iostream>
//#include <conio.h>
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


 //////////////////impresion de listas///////////////
void reportarLista(Tnodo cabeza)
{
     //int i = 0;
	 cout<<endl;
	 
    while(cabeza != NULL)
    {
          cout <<cabeza->Dato <<" ";////////////////////////////////////////////////////////////////////////////////
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


//////////////////////minimo valor////////////////////////
void minimo(Tnodo cabeza){
	int minimo = 999999999;
	
    while(cabeza != NULL)
    {
		if(cabeza->Dato < minimo){
			minimo = cabeza->Dato;
//			
		}
         
         cabeza = cabeza->sgte;
     
    }
	cout<<"el numero maximo es: "<<minimo<<endl;
}


/////////////////////buscar/////////////////////
void busqueda(Tnodo cabeza ){
	int num;
	cout<<"introdusca el numero a buscar";
	cin>>num;
	while(cabeza != NULL)
    {
		if(cabeza->Dato == num ){
			cout<< "el numero esta dentro de la lista";		
		}
        
         cabeza = cabeza->sgte;
     
    }
}
	
	
///////////// eliminar//////////////
void eliminar(Tnodo &cabeza){
	int num;
	cout<<"introdusca el numero a eliminar";
	cin>>num;

	if(cabeza!=NULL){

		Tnodo aux_borrar;
		Tnodo anterior=NULL;
		aux_borrar = cabeza;
		
		while( (aux_borrar != NULL) && (aux_borrar->Dato !=num) ){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->sgte;	

		}
		if(aux_borrar == NULL){
			cout<<"el elemento no existe: ";
		}
		else if(anterior==NULL){
			cabeza=cabeza->sgte;
			delete aux_borrar;
		}
		else{
			anterior->sgte=aux_borrar->sgte;
			delete aux_borrar;
		}
	}
}

///////////////////eliminar repoio xD //////////////
void eliminar_repoio(Tnodo &cabeza,int &info){
	int num;
	cout<<"inserte el numero a eliminar:";
	cin>>num;
	
	if(num==info){
	
	Tnodo aux=cabeza;
	info=aux->Dato;
	cabeza=aux->sgte;
	delete aux;
	}
	
}


/////////////////  eliminar varios  /////////////////
void eliminar_varios (Tnodo cabeza, int numero_eliminado) {

	Tnodo nodo_auxiliar = new nodo;

	nodo_auxiliar = NULL;

	if (cabeza == NULL) {
		cout << "its empty";
	} else{
		while (cabeza != NULL) {
			
			cout << "hola esto funciona ? "<< endl;
			cout << cabeza->Dato<<endl;
			if (cabeza->Dato == numero_eliminado ) {
				// en caso de que sea el ultimo
				if (cabeza->sgte == NULL) {
					nodo_auxiliar->sgte = NULL;
					return ;
				}

				if (nodo_auxiliar != NULL) {
					nodo_auxiliar->sgte = cabeza->sgte;
					//cabeza = cabeza->sgte;
					cabeza = cabeza->sgte;
				}

				//if ()
				// else {
				//	cabeza = cabeza->sgte;
				//}
			}
			nodo_auxiliar = cabeza;
			cabeza = cabeza->sgte;
		}
	}
}


void mostrar (Tnodo cabeza) {
	while (cabeza != NULL) {
		cout << cabeza->Dato;

		cabeza = cabeza->sgte;
	}
}

////////////////////////////////
void menu()
{
    cout<<"\n \t LISTA ENLAZADA SIMPLE\n\n"<<endl;
    cout<<"1.  INSERTAR AL INICIO "<<endl;
    cout<<"2.  INSERTAR AL FINAL "<<endl;
    cout<<"3.  NUMERO MAXIMO"<<endl;
	cout<<"4.  NUMERO MINIMO"<<endl;
	cout<<"5.  BUSQUEDA DE UN NUMERO"<<endl;
	cout<<"6.  ELIMINAR UN NUMERO "<<endl;
	cout<<"7.  ELIMINAR VARIOS NUMEROS "<<endl;
	cout<<"3.  OPCION  :"<<endl;
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
            break;
 
 
            case 2:
 
                cout<< "\n NUMERO A INSERTAR FINAL: "; 
				cin>> info;
                insertarFinal(cabeza, info );
                 
            break;
              
			case 3:
			  	cout<<"NUMERO MAYOR: "<<endl;
			  	maximo(cabeza);
			break;   
            
            case 4:
				//case 8:
				cout << "mostrar todo";
				mostrar(cabeza);
			//break;
			//   	cout<<"NUMERO MAYOR: "<<endl;
			//  	minimo(cabeza);   
            break;
            
            case 5:
    			cout<<"BUSCAR UN NUMERO:"<<endl;
    			busqueda(cabeza);
    		break;
			
			case 6: 
			  	cout<<"ELIMINACION DE NUMERO"<<endl;
			  	eliminar(cabeza);
			break;
            
            case 7:
				int numero_eliminado = 0;
				cout<<"ELIMINACION DE VARIOS NUMEROS"<<endl;
				cout << "ingrese el numero que quieres eliminar" <<endl;
				cin >> numero_eliminado;
				eliminar_varios(cabeza, numero_eliminado);	
				// while(cabeza!=NULL){
						
				// eliminar_repoio(cabeza,info);
				// cout<<info<<"->"<<endl;	
				// }
            break;


	
		}
                    
			
        cout<<endl<<endl;
 		//system("cls");
		cout<<"-----------------LOS ELEMENTOS DE LA LISTA ----------------";
		reportarLista(cabeza);
		cout<<endl<<endl;
		cout<<"-------------------------------------------------------------------";	 
	}	
}
