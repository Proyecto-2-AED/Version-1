//------------------------LIBRERIAS-------------------------------
#include <stdio.h> //entrada y salida de datos
#include <stdlib.h> //gestion de memoria
#include <string.h>  //manipulacion de strings
#include <time.h> //manejo de tiempos


//-----------------------CONSTANTES------------------------------

#define LONG 40
#define MAX 200
#define BIG 2000

//-----------------------ESTRUCTURAS------------------------------
//---------REGISTRO NIÑ@------------------

typedef struct ListaR ListaR;
typedef struct NodoR NodoR;

struct NodoR
{
  int identificacion;
  char nombre[50];
  char N_usuario[50];
  char lugar[50];
  char correo[50];
  char fecha_nacimiento[15];
  int edad;
  char necesidades_especiales[100];
  
	NodoR *siguiente;
	NodoR *anterior; 
};

struct ListaR
{
	NodoR *inicio;
	NodoR *final;
};



//---------REGISTRO AYUDANTE------------------
typedef struct ListaAS ListaDobleAS;
typedef struct NodoAS NodoAS;

struct NodoAS
{
	int identificacionAS;
	char nombreAS [MAX];
	char puestoAS [MAX];
	char funcionesAS [MAX];
	char fechaInicioAS [MAX];
	NodoAS *siguiente;
	NodoAS *anterior; 
};

struct ListaAS
{
	NodoAS *inicio;
	NodoAS *final;
	int tamanoAS;
};


//---REGISTRO DE JUGUETES, ARBOL BINARIO-------


struct node {
	int codigo;
    char nombre[50];
    char descripcion[100];
    char categoria[100];
    int rangoI;
    int rangoF;
    int costo_total;
	struct node *left, *right;
};


//---------REGISTRO DE COMPORTAMIENTO------------------

typedef struct ListaC ListaC;
typedef struct NodoC NodoC;

struct NodoC
{
  int IDnino;
  char nombrePadre[50];
  char nombreMadre[50];
  char Des_comportamiento[100];
  char fecha_Registro[15];
  char comportamiento[15];
  int contador_comport;
  
	NodoC *siguiente;
	NodoC *anterior; 
};

struct ListaC
{
	NodoC *inicio;
	NodoC *final;
};

//---------REGISTRO DE DOMICILOS------------------

typedef struct Nodo Vertice;
typedef struct Arista Arista;
typedef struct Lista Lista;

// Estructuras del vertice de lugares
struct Nodo{
	char idVertice [LONG]; 
	char nombreLugar [LONG];
	int codPostal;
	Vertice* sig;
	Arista* ady; 
	int visitado,terminado;
	int monto;
	char anterior[MAX];
};

// Estructuras de la arista de rutas
struct Arista{
	Vertice* vrt; 
	Arista* sig;
	char origen [LONG];
	char destino [LONG];
	int tiempo;
	int distancia;
	char tipoRuta[LONG];
};


// Estructuras de la pila para vertices en lista adyacente
struct Lista{
	Vertice* lugar;
	Lista* sig;
};

Vertice* inicio=NULL;
Lista* ini=NULL;
Lista* final=NULL; 


//------------------------ESTRUCTURAS CARTA DE SANTA-------------------------------
typedef struct NodoCarta NodoCarta; //estructura de la carta
typedef struct ListaCartaNino ListaCartaNino; //estructura de los puntero inicio y final
typedef struct NodoDeseo NodoDeseo; //
typedef struct ListaDeseo ListaDeseo; //

struct NodoCarta
{
	int idNinoC;
	char nombreNInoC[LONG];
	int anio;
	char juguete1 [LONG], juguete2 [LONG], juguete3 [LONG], juguete4 [LONG], juguete5 [LONG], juguete6 [LONG], juguete7 [LONG];
	char juguete8 [LONG], juguete9 [LONG], juguete10 [LONG];
	char estado [LONG];
	ListaDeseo *puntoListaD;
	NodoCarta *siguiente;
	NodoCarta *anterior; 
};

struct ListaCartaNino
{
	NodoCarta *inicio;
	NodoCarta *final;
	int cantidadJuguetes;
};

struct NodoDeseo{
	char nombreJuguete [LONG];
	char qEstado [LONG];
	NodoDeseo *siguiente;
	NodoDeseo *anterior; 
};

struct ListaDeseo{
	NodoDeseo *inicio;
	NodoDeseo *final;
};

//                                       TODO SOBRE REGISTRO DE NIN@S
//-----------------------------------------------------------------------------------------------------------------

//CREACION DE LA LISTA DOBLE PARA REGISTRO DEL NIN@

ListaR *listaNueva(void)
{
	ListaR *L;
	L = (ListaR *) malloc(sizeof(ListaR));
	L->inicio = NULL;
	L->final = NULL;
	return L;
}

//CREACION DEL NODO PARA LISTA DOBLE REGISTRO DEL NIN@
NodoR* crearNodo(int identificacion, char nombre[],char N_usuario[], char lugar[], char correo[], char fecha_nacimiento[],int edad,char necesidades_especiales[])
{
	NodoR *nuevo;
	nuevo = (NodoR *) malloc(sizeof(NodoR));
	nuevo->anterior = NULL;
	nuevo->siguiente = NULL;
	
	nuevo->identificacion = identificacion;	
	strcpy(nuevo->nombre,nombre);
	strcpy(nuevo->N_usuario,N_usuario);
	strcpy(nuevo->lugar,lugar);
	strcpy(nuevo->correo,correo);
	strcpy(nuevo->fecha_nacimiento,fecha_nacimiento);
	nuevo->edad = edad;	
	strcpy(nuevo->necesidades_especiales,necesidades_especiales);
	
	return nuevo;
}

//INSERTAR DATOS EN LA LISTA DOBLE REGISTRO DEL NIN@

void insertarNino(ListaR *L, int identificacion, char nombre[],char N_usuario[], char lugar[], char correo[], char fecha_nacimiento[],int edad,char necesidades_especiales[])
{
	if(L->inicio == NULL) //Valida si la lista est? vac?a
	{
		//Inserta al inicio de la lista
		L->inicio = crearNodo(identificacion,nombre,N_usuario,lugar,correo,fecha_nacimiento,edad,necesidades_especiales);
		L->final = L->inicio;
		return;
	}
	
	//Inserta el dato al final de la lista, no necesita un ciclo porque tiene el puntero final
	L->final->siguiente = crearNodo(identificacion,nombre,N_usuario,lugar,correo,fecha_nacimiento,edad,necesidades_especiales);
	L->final->siguiente->anterior = L->final;
	L->final = L->final->siguiente;
}


//MOSTRAR LISTA DOBLE REGISTRO DEL NIN@
void mostrarListaIzqDer(const ListaR *L)
{
	NodoR *i;
	printf("____________________________________________________________________________\n");
	printf("LISTA DE REGISTROS DE NINOS Y NINAS: \n\n");
	for(i = L->inicio; i!= NULL; i = i->siguiente){
	
		printf("IDENTIFICACION: %d \n", i->identificacion);
		printf("NOMBRE: %s \n", i->nombre);
		printf("NOMBRE USUARIO: %s \n", i->N_usuario);
		printf("LUGAR DE RESIDENCIA: %s \n", i->lugar);
		printf("CORREO: %s \n", i->correo);
		printf("FECHA DE NACIMIENTO: %s \n", i->fecha_nacimiento);
		printf("EDAD: %d \n", i->edad);
		printf("NECESIDADES ESPECIALES: %s \n\n\n", i->necesidades_especiales);
		}
	printf("____________________________________________________________________________\n");
}


//ELIMINAR NIN@ DE LA LISTA DOBLE 

void eliminarNino(ListaR *L, int identificacion)
{
	NodoR *aux = L->inicio;
	
	//Valida si la lista esta vacia
	if(L->inicio == NULL)
	{
		printf("La lista esta vacia...\n");		
	}
	else
	{
//Si el nodo a eliminar esta al inicio de la lista
		if(L->inicio->identificacion == identificacion)
		{
		aux = L->inicio;
		printf("\n-----------------------------------------");
		printf("El nino con identificacion %d ha sido eliminado \n", aux->identificacion);
		printf("-----------------------------------------");
		
		if(L->inicio == L->final) //Verifica si la lista solo ten?a un nodo para actualizar el puntero final
		{
			L->inicio = NULL;
			L->final = NULL;
		}
		else{
			L->inicio = L->inicio->siguiente;
			L->inicio->anterior = NULL;	
		}		
		free(aux);

		}
	//-----------------------------	
		else 
		{
			while(aux != NULL)
			{
				if(aux->identificacion == identificacion){
					aux->anterior->siguiente = aux->siguiente;
					if(aux != L->final)
						aux->siguiente->anterior = aux->anterior;
					else if(aux == L->final) //Valida si era el ultimo nodo de la lista para actualizar el puntero final
						L->final = L->final->anterior;					
					break;
				}
				aux = aux->siguiente;					
			}
			
		
		if(aux != NULL)
		{
			printf("El nino con identificacion %d ha sido eliminado \n", aux->identificacion);
			free(aux);
		}
	}
}
}

//VERIFICAR NINO REPETIDO Y EXISTE

int repetir_nino(ListaR *L, int identificacion)
{
	NodoR *nAux = L->inicio;
	
	while(nAux != NULL)
	{
		if(nAux->identificacion == identificacion)
			return -1;
		nAux = nAux->siguiente;		
	}
	
}




// MODIFICAR INFORMACION DE LISTA DOBLE REGISTRO NINO

void ModificarNino(ListaR *L, int identificador, int opcion){

    NodoR *aux = L->inicio;
    int ok = 0;
	int resultado;
    char nuevolugar[50],nueva_nece[100],nuevo_usuario[50];

    while(aux != NULL && !ok)
        {   
            if(aux->identificacion == identificador)
            {ok = 1;
			break;
			}
            else
            {aux=aux->siguiente;}
        }    

    if(ok)
    {
        printf("\nEL NIÑ@ CON IDENTIFICADOR %d SI ESTA REGISTRADO \n\n", identificador);
        if (opcion == 1){
            printf("Digite el nuevo lugar de residencia \n\n");
            gets(nuevolugar);
            strcpy(aux->lugar,nuevolugar);
            
             printf("-----------------------------------------");
            printf("EL CAMBIO SE REALIZO CON EXITO \n\n");
            printf("NOMBRE:%s \n",aux->nombre);
            printf("IDENTIFICADOR :%d \n",aux->identificacion);
			printf("NUEVO LUGAR DE RESIDENCIA :%s \n",aux->	lugar);
			printf("-----------------------------------------");
			}
			
		else if (opcion == 2){
            printf("Digite las nuevas necesidades del niño o niña \n\n");
            gets(nueva_nece);
            strcpy(aux->necesidades_especiales,nueva_nece);
            
            printf("-----------------------------------------");
            printf("EL CAMBIO SE REALIZO CON EXITO \n\n");
            printf("NOMBRE:%s \n",aux->nombre);
            printf("IDENTIFICADOR :%d \n",aux->identificacion);
			printf("NUEVAS NECESIDADES ESPECIALES :%s \n",aux->necesidades_especiales);
			printf("-----------------------------------------");
			}
			
		else if (opcion == 3){
            printf("Digite el nuevo nombre de usuario \n\n");
            gets(nuevo_usuario);
            strcpy(aux->N_usuario,nuevo_usuario);
            
            printf("\n-----------------------------------------");
            printf("EL CAMBIO SE REALIZO CON EXITO \n\n");
			printf("NOMBRE:%s \n",aux->nombre);
            printf("IDENTIFICADOR :%d \n",aux->identificacion);
			printf("NUEVO NOMBRE DE USUARIO :%s \n",aux->N_usuario);
			printf("-----------------------------------------");
			}
   		 
   }
   
   else
   		 {printf("\nEL NIÑ@ CON IDENTIFICADOR %s NO ESTA REGISTRADO \n\n", identificador);}

}
//                                       TODO SOBRE COMPORTAMIENTO DEL NINO
//-----------------------------------------------------------------------------------------------------------------

//CREACION DE LA LISTA DOBLE PARA COMPORTAMIENTO


ListaC *listaNuevaComportamiento(void)
{
	ListaC *C;
	C = (ListaC *) malloc(sizeof(ListaC));
	C->inicio = NULL;
	C->final = NULL;
	return C;
}


//CREACION DEL NODO PARA LISTA DOBLE COMPORTAMIENTO
NodoC* crearNodoComportamiento( int IDnino,char nombrePadre[],char nombreMadre[],char Des_comportamiento[],char fecha_Registro[],char comportamiento[],int contador_comport)
{
	NodoC *nuevo;
	nuevo = (NodoC *) malloc(sizeof(NodoC));
	nuevo->anterior = NULL;
	nuevo->siguiente = NULL;
	
	nuevo->IDnino = IDnino;	
	nuevo->contador_comport= contador_comport;
	strcpy(nuevo->nombrePadre,nombrePadre);
	strcpy(nuevo->nombreMadre,nombreMadre);
	strcpy(nuevo->Des_comportamiento,Des_comportamiento);
	strcpy(nuevo->fecha_Registro,fecha_Registro);
	strcpy(nuevo->comportamiento,comportamiento);
	
	return nuevo;
}



//INSERTAR DATOS EN LA LISTA DOBLE COMPORTAMIENTO

void insertarNinoC(ListaC *C, int IDnino,char nombrePadre[],char nombreMadre[],char Des_comportamiento[],char fecha_Registro[],char comportamiento[],int contador_comport)
{
	if(C->inicio == NULL) //Valida si la lista est? vac?a
	{
		//Inserta al inicio de la lista
		C->inicio = crearNodoComportamiento(IDnino,nombrePadre,nombreMadre,Des_comportamiento,fecha_Registro,comportamiento,contador_comport);
		C->final = C->inicio;
		return;
	}
	
	//Inserta el dato al final de la lista, no necesita un ciclo porque tiene el puntero final
	C->final->siguiente = crearNodoComportamiento(IDnino,nombrePadre,nombreMadre,Des_comportamiento,fecha_Registro,comportamiento, contador_comport);
	C->final->siguiente->anterior = C->final;
	C->final = C->final->siguiente;
}


//MOSTRAR LISTA DOBLE REGISTRO DEL NIN@
void mostrarListaComportamiento(const ListaC *C)
{
	NodoC *i;
	printf("__________________________\n");
	printf("LISTA DE COMPORTAMIENTOS DE NINOS Y NINAS: \n\n");
	for(i = C->inicio; i!= NULL; i = i->siguiente){
	
		printf("IDENTIFICACION DEL NINO: %d \n", i->IDnino);
		printf("NOMBRE DEL PADRE: %s \n", i->nombrePadre);
		printf("NOMBRE DE LA MADRE: %s \n", i->nombreMadre);
		printf("FECHA DE REGISTRO: %s \n", i->fecha_Registro);
		printf("DESCRIPCION DEL COMPORTAMIENTO: %s \n", i->Des_comportamiento);
		printf("COMPORTAMIENTO: %s \n\n\n", i->comportamiento);
		}
	printf("__________________________\n");
	printf("\n");
}

// ANALISIS DE COMPORTAMIENTO
 void analisis_comportamiento(const ListaC *C)
{
	int cantidad_bueno=0;
	int cantidad_malo=0;
	
	NodoC *i;
	for(i = C->inicio; i!= NULL; i = i->siguiente){
		if (i->contador_comport == 10){
			cantidad_bueno= cantidad_bueno + 1;	
		}
		else if (i->contador_comport == 11){
			cantidad_malo= cantidad_malo + 1;	
		}
		}
	printf("__________________________\n");
		printf("LA CANTIDAD DE COMPORTAMIENTOS BUENOS ES DE %d:   \n",cantidad_bueno);
		printf("LA CANTIDAD DE COMPORTAMIENTOS MALOS ES DE %d:   \n",cantidad_malo);
	printf("__________________________\n");
	printf("\n");
}



//                                       TODO SOBRE REGISTRO DE JUGUETES
//-----------------------------------------------------------------------------------------------------------------


//Referencias https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/
// crear nodo ABB
struct node* newNode(char nombrex[],int codigox,char descripcionx[],char categoriax[], int rangoIx, int rangoFx, int costo_totalx)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	temp->codigo = codigox;
	strcpy(temp->nombre,nombrex);
	strcpy(temp->descripcion,descripcionx);
	strcpy(temp->categoria, categoriax);
    temp->rangoI = rangoIx; 
	temp->rangoF = rangoFx;
	temp->costo_total = costo_totalx;

	
	temp->left = temp->right = NULL;
	return temp;
}

// imprimir en orden ABB
void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("\n\nNOMBRE DEL JUGUETE %s\nCODIGO DEL JUGUETE JU%d\nDESCRIPCION %s\nCATEGORIA %s\nRANGO DE EDAD %d-%d\nCOSTO TOTAL JUGUETE %d",root->nombre,root->codigo,root->descripcion,root->categoria,root->rangoI,root->rangoF,root->costo_total);
		inorder(root->right);
	}
}

//insertar al ABB
struct node* insert(struct node* node,char nombrex[],int key,char descripcionx[],char categoriax[], int rangoIx, int rangoFx, int costo_totalx)
{
	/* si el arbol esta vacio, retorna el nodo*/
	if (node == NULL)
		return newNode(nombrex,key,descripcionx,categoriax, rangoIx,rangoFx,costo_totalx);

	//sino sigue buscando donde meterlo
	if (strcmp(nombrex,node->nombre) < 0)
		node->left = insert(node->left, nombrex,key,descripcionx,categoriax, rangoIx,rangoFx,costo_totalx);
	else
		node->right = insert(node->right,nombrex,key,descripcionx,categoriax, rangoIx,rangoFx,costo_totalx);

	return node;
}

/* Dada una búsqueda binaria no vacía del
árbol, devuelve el nodo
con el valor de clave mínimo encontrado en
este arból. Tenga en cuenta que el
no es necesario buscar en todo el árbol. */
struct node* minValueNode(struct node* node)
{
	struct node* current = node;

	/* bucle hacia abajo para encontrar la hoja más a la izquierda*/
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

/* Dado un árbol de búsqueda binario
y una llave, esta función
elimina la clave y
devuelve la nueva raíz*/
struct node* deleteNode(struct node* root, char nombrex[])
{
	// caso base
	if (root == NULL)
		return root;

// Si la clave a eliminar
// es más pequeño que el de la raíz
// clave, luego se encuentra en el subárbol izquierdo
	if (strcmp(nombrex,root->nombre) < 0)
		root->left = deleteNode(root->left,nombrex);


// Si la clave a eliminar
// es mayor que la raíz
// clave, luego se encuentra en el subárbol derecho
	else if (strcmp(nombrex,root->nombre) > 0)
		root->right = deleteNode(root->right,nombrex);


// si la clave es la misma que la clave de root,
// entonces este es el nodo
// para ser eliminado
	else {
		// nodo con solo un hijo o sin hijo
		if (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}


// nodo con dos hijos:
// Obtener el sucesor inorder
// (el más pequeño en el subárbol derecho)
		struct node* temp = minValueNode(root->right);

		
// Copiar el orden
// contenido del sucesor de este nodo
		strcpy(root->nombre, temp->nombre);

		//borrar el sucesor de este nodo
		root->right = deleteNode(root->right, temp->nombre);
	}
	return root;
}

int BuscarJ(const struct node* actual, const char juguete[]){

while(actual != NULL){
	if(strcmp(juguete,actual->nombre)== 0){
		printf("ENCONTRADO!");
		printf("\n---------------------------------------------------------------");
		printf("\nNOMBRE DEL JUGUETE %s\nCODIGO DEL JUGUETE JU%d\nDESCRIPCION %s\nCATEGORIA %s\nRANGO DE EDAD %d-%d\n",actual->nombre,actual->codigo,actual->descripcion,actual->categoria,actual->rangoI,actual->rangoF);
		printf("\n---------------------------------------------------------------");
		return 1;
		}
		
	else if(strcmp(juguete, actual->nombre)> 0) actual = actual->left; 
    else if(strcmp(juguete, actual->nombre)< 0) actual = actual->right;
	}
	return 0;	
}


//MODIFICAR DATOS JUGUETE
modificarJuguete(struct node* actual, char juguete[],char opcion[]){
	
   char descripcion [100];
   int edad_minima;
   int edad_maxima;
   int costo;
   int bandera;

   while(actual != NULL){

		if(strcmp(juguete,actual->nombre)== 0){
			printf("\n\nINFORMACION\n-----------------------------------------------");
			printf("\nNOMBRE DEL JUGUETE %s\nDESCRIPCION %s\nRANGO DE EDAD %d-%d\nCOSTO TOTAL JUGUETE %d",actual->nombre,actual->descripcion,actual->rangoI,actual->rangoF,actual->costo_total);
      		printf("\n-----------------------------------------------"); 

			if (strcmp(opcion,"1")==0)
			{
				printf("\nNueva descripcion:");
				fflush (stdin);
				gets (descripcion);
				strcpy(actual->descripcion,descripcion);
				bandera = 1;
				break;
				
			}

			else if (strcmp(opcion,"2")==0)
			{
				printf("\nRango de edad:");
				printf("\nEdad minima: ");
				scanf("%d", &edad_minima);
				printf("\nEdad maxima: ");
				scanf("%d", &edad_maxima);
				actual-> rangoI = edad_minima;
				actual-> rangoF = edad_maxima;
				bandera = 1;
				break;
			}
			else if (strcmp(opcion,"3")==0)
			{
				printf("\nNuevo costo de fabricación:");
				scanf("%d", &costo);
				actual ->costo_total = costo;
				bandera = 1;
				break;
			}
			else
			{
				printf("\nERROR: la funcion no existe, la accion no se pudo realizar con exito.");
			}
		
	  }
	   
      else if(strcmp(juguete, actual->nombre)> 0) actual = actual->left; 
      else if(strcmp(juguete, actual->nombre)< 0) actual = actual->right;
	}

	if (bandera ==1){
   			printf("\n--- MODIFICADO!! ---\n");
   			printf("\n-----------------------------------------------");
			printf("\nNOMBRE DEL JUGUETE %s\nDESCRIPCION %s\nRANGO DE EDAD %d-%d\nCOSTO TOTAL JUGUETE %d",actual->nombre,actual->descripcion,actual->rangoI,actual->rangoF,actual->costo_total);
      		printf("\n-----------------------------------------------");
		} 
		
	else{
		printf("\n--- ERROR, EL NODO NO EXISTE ---\n");
	}
}

	
//                                       TODO SOBRE REGISTRO DE AYUDANTES
//-----------------------------------------------------------------------------------------------------------------

//Declara una lista doble

ListaDobleAS *listaNuevaAS(void)
{
	ListaDobleAS *L;
	L = (ListaDobleAS *) malloc(sizeof(ListaDobleAS));
	L->inicio = NULL;
	L->final = NULL;
	L->tamanoAS = 0; 
	return L;
}

//Crea un nodo a una lista doble

NodoAS* crearNodoAS( int idAS, const char nomAS [MAX], const char puAS [MAX], const char funAS [MAX], const char fechaIAS [MAX] )
{
	NodoAS *nuevo;
	nuevo = (NodoAS *) malloc(sizeof(NodoAS));
	nuevo->anterior = NULL;
	nuevo->siguiente = NULL;
	nuevo->identificacionAS = idAS;
	
	strcpy (nuevo->nombreAS, nomAS);
	strcpy (nuevo->puestoAS, puAS);
	strcpy (nuevo->funcionesAS, funAS);
	strcpy (nuevo->fechaInicioAS, fechaIAS);
	return nuevo;
}

//Inserta un dato a una lista doble

void insertarDato(ListaDobleAS *L, int identiAS, const char nombAS [MAX], const char puesAS [MAX], const char funciAS [MAX], const char fechaIniAS [MAX])
{
	if(L->inicio == NULL) 
	{
	
		L->inicio = crearNodoAS(identiAS, nombAS, puesAS, funciAS, fechaIniAS);
		L->final = L->inicio;
		L->tamanoAS++;
		return;
	}
	L->final->siguiente = crearNodoAS(identiAS, nombAS, puesAS, funciAS, fechaIniAS);
	L->final->siguiente->anterior = L->final;
	L->final = L->final->siguiente;
	L->tamanoAS++;
}

//Funcion para msotrar una lista doble
void mostrarListaAS(const ListaDobleAS *L)
{
	NodoAS *i;
	for(i = L->inicio; i!= NULL; i = i->siguiente){
		printf("id_Ayudante: %d |Nombre: %s |Puesto: %s |Funciones: %s |Fecha de inicio laboral: %s\n", i->identificacionAS, i->nombreAS, i->puestoAS, i->funcionesAS, i->fechaInicioAS);
	}
	printf("\n\n");
}

//Funcion para liberar una lista doble
void liberarLista(ListaDobleAS *L)
{
	NodoAS *n, *aux;
	if(L->inicio == NULL)
		return;
	if(L->inicio->siguiente == NULL)
		return;		
	n = L->inicio;
	
	while(n != NULL)
	{
		aux = n;
		n = n->siguiente;
		free(aux);
	}
	
}


//Funcion para agregar Ayudantes de santa 
ListaDobleAS *agregarAyudantes (ListaDobleAS *LD){
	
	int ideAS;
	char nomBAS [MAX];
	char puesTAS [MAX];
	char funcIAS [MAX];
	char fechaInAS [MAX];
	int puesto;
	int dia;
	int mes;
	int anio;
	
	
	
	char palabra [MAX];

	printf ("-------- Ingrese los datos del ayudante de Santa -------- \n");
	
	printf("Ingrese la identificacion del ayudante: \n");
	scanf("%d", &ideAS);
	
	printf("\nIngrese el nombre del ayudante\n: ");
	scanf("%s", nomBAS);

	printf("\nLos puestos de ayudantes son: 1. Supervisor 2. Ayudante de bodega 3. Mantenimiento 4. Control de calidad 5. Disenador\n");
	printf("Seleccione el numero de puesto que corresponda en las opciones previas: ");
	scanf("%d", &puesto);

	if(puesto != 1 && puesto != 2 && puesto != 3 && puesto != 4 && puesto != 5){
		printf("Debe ingresar un codigo de puesto valido");
		return;
	}
	if (puesto == 1 ){
		strcpy(puesTAS, "Supervisor");
	}
	if (puesto == 2){
		strcpy(puesTAS, "Ayudante_Bodega");
	}
	if (puesto == 3){
		strcpy(puesTAS, "Mantenimiento");
	}
	if (puesto == 4){
		strcpy(puesTAS, "Control_Calidad");
	}
	if (puesto == 5){
		strcpy(puesTAS, "Disenador");
	}
	
	printf("Ingrese las funciones del puesto\n: ");
	scanf("%s", funcIAS);
	
	printf("Ingrese la fecha en que ingreso a laborar con Santa\n: ");
	scanf ("%s",fechaInAS);
	
	insertarDato (LD, ideAS, nomBAS, puesTAS, funcIAS, fechaInAS );
	return LD;
}

//Funcion para determinar la validez de un ID
int esIdValido (ListaDobleAS *L, int id){
	NodoAS *auxiliar;
	
	for (auxiliar = L->inicio; auxiliar != NULL; auxiliar = auxiliar->siguiente){
		if ( auxiliar->identificacionAS == id){
			return 1;
		}
	}
	free(auxiliar);
	return 0;
}

//Funcion para modificar datos de un ayudante 
void modificarAyudante (ListaDobleAS *L)
{
	NodoAS *auxiliar;
	int idModificar;
	int puesto;
	
	printf("Ingrese la identificacion del ayudante de Santa: ");
	scanf("%d",&idModificar);
	
	
	
	if ( esIdValido (L, idModificar) == 0 ){
		printf("Debe ingresar una identificacion valida");
		return;
	}
	
	for (auxiliar = L->inicio; auxiliar!= NULL; auxiliar = auxiliar->siguiente){
		if(auxiliar->identificacionAS == idModificar){
			printf("\nLos puestos de ayudantes son: 1. Supervisor 2. Ayudante de bodega 3. Mantenimiento 4. Control de calidad 5. Disenador\n");
			printf("Seleccione el numero de puesto que corresponda en las opciones previas: ");
			scanf("%d", &puesto);
	
			if(puesto != 1 && puesto != 2 && puesto != 3 && puesto != 4 && puesto != 5){
				printf("Debe ingresar un codigo de puesto valido");
				return;
			}
			if (puesto == 1 ){
				strcpy(auxiliar->puestoAS, "Supervisor");
			}
			if (puesto == 2){
				strcpy(auxiliar->puestoAS, "Ayudante_Bodega");
			}
			if (puesto == 3){
				strcpy(auxiliar->puestoAS, "Mantenimiento");
			}
			if (puesto == 4){
				strcpy(auxiliar->puestoAS, "Control_Calidad");
			}		
			if (puesto == 5){
				strcpy(auxiliar->puestoAS, "Disenador");
			}
	
			printf("Ingrese las funciones del puesto\n: ");
			scanf("%s", auxiliar->funcionesAS);
			}
	}
	free(auxiliar);
}

void eliminarAyudante (ListaDobleAS *L){
	
	NodoAS *aux = L->inicio;
	int idEliminar;
	
	//Valida si la lista esta vacia
	if(L->inicio == NULL)
	{
		printf("La lista esta vacia...\n");	
		return;	
	}
	else
	{
		printf("Ingrese la identificacion del ayudante de Santa: ");
		scanf("%d",&idEliminar);
	
		if ( esIdValido (L, idEliminar) == 0 ){
			printf("Debe ingresar una identificacion valida");
			return;
		}
		
//Si el nodo a eliminar esta al inicio de la lista
		if(L->inicio->identificacionAS == idEliminar) {
		aux = L->inicio;
		printf("El ayudante con identificacion %d ha sido eliminado \n", aux->identificacionAS);
		
		if(L->inicio == L->final) //Verifica si la lista solo ten?a un nodo para actualizar el puntero final
		{
			L->inicio = NULL;
			L->final = NULL;
		}
		else{
			L->inicio = L->inicio->siguiente;
			L->inicio->anterior = NULL;	
		}		
		free(aux);

		}
	//-----------------------------	
		else 
		{
			while(aux != NULL)
			{
				if(aux->identificacionAS == idEliminar) {
					aux->anterior->siguiente = aux->siguiente;
					if(aux != L->final)
						aux->siguiente->anterior = aux->anterior;
					else if(aux == L->final) //Valida si era el ultimo nodo de la lista para actualizar el puntero final
						L->final = L->final->anterior;					
					break;
				}
				aux = aux->siguiente;					
			}
			
		if(aux != NULL)
		{
			printf("El ayudante con identificacion %d ha sido eliminado \n", aux->identificacionAS);
			free(aux);
		}
	}
}
}

//Funcion para cargar datos de ayudantes
ListaDobleAS *cargarAyudantes (){
	
	ListaDobleAS *La;
	La = listaNuevaAS ();
	char archivo[] = "ListaAyudantesSanta.txt";
	char linea[BIG];
	char delimitador [3] = "\t";
	
	int idAS;
	char nomAS [MAX];
	char pueAS [MAX];
	char funAS [MAX];
	char fecIAS [MAX];
	
	
	FILE *punteroArchivoC;
	char *token;

	punteroArchivoC = fopen(archivo, "r+"); // read mode


	while (feof(punteroArchivoC) == 0) {
		//printf("Primer while");
		fgets(linea,MAX,punteroArchivoC);
		//printf("%s\n\n", linea);
		
   		token = strtok(linea, delimitador);
		int contador = 0;
   		while( token != NULL ) {
   			//printf("Segundo while");
   			//printf("El valor de contador es: %d\n\n", contador);
   			
   			if (contador == 0){
   				//printf("Este es el primer if");
   				//printf("Este es el token: %s", token);
				idAS = atoi(token);
				//printf("%d\n", cedula);
				}
				
			if (contador == 1){
				strcpy(nomAS,token);
				//printf("%s\n",nombre);
				}
			if (contador == 2){
				strcpy(pueAS,token);
				//printf("%s\n",correo);
				}
			if (contador == 3){
				strcpy(funAS,token);
				//printf("%d\n",acceso);
				}
			if (contador == 4){
				strcpy(fecIAS,token);
				//printf("%d\n",tel);
				}
   			contador++;	
    		token = strtok(NULL, delimitador);
   	}
   	
	   insertarDato (La,idAS,nomAS,pueAS,funAS, fecIAS);	
	}

    fclose(punteroArchivoC);
    
	free(token);
	
	return La;
}

//Funcion que escribe en un .txt los datos de los ayudantes
void escribirAyudantes (ListaDobleAS *L){
	
	NodoAS *auxiliar;
	char archivo[] = "ListaAyudantesSanta.txt";
	char palabra [MAX];
	int contador = 0;
	FILE *punteroArchivo;
	
	punteroArchivo = fopen(archivo, "w"); // read mode
	
	for (auxiliar = L->inicio; auxiliar != NULL ; auxiliar = auxiliar->siguiente){
		if (contador == 0){
			fprintf(punteroArchivo,"%d\t",auxiliar->identificacionAS);
			fprintf(punteroArchivo,"%s\t",auxiliar->nombreAS);
			fprintf(punteroArchivo,"%s\t",auxiliar->puestoAS);
			fprintf(punteroArchivo,"%s\t",auxiliar->funcionesAS);
			fprintf(punteroArchivo,"%s\t",auxiliar->fechaInicioAS);
		}
		else{
			fprintf(punteroArchivo,"\n%s\t",auxiliar->identificacionAS);
			fprintf(punteroArchivo,"%s\t",auxiliar->nombreAS);
			fprintf(punteroArchivo,"%s\t",auxiliar->puestoAS);
			fprintf(punteroArchivo,"%s\t",auxiliar->funcionesAS);
			fprintf(punteroArchivo,"%s\t",auxiliar->fechaInicioAS);	
		}
		contador ++;
	}
	fclose(punteroArchivo);
	free(auxiliar);
	free(punteroArchivo);
	}
//                                       TODO SOBRE CATALOGO DE DOMICILIOS
//-----------------------------------------------------------------------------------------------------------------

//Métodos del grafo Catálogos para lugares de domicilio 

void ingresarVertice(){
    Vertice* aux;
	Vertice* nuevo=(Vertice*)malloc(sizeof(Vertice));
	//fflush(stdin);
	printf("Ingrese el codigo del lugar: ");
	scanf("%s",nuevo->idVertice);
	printf("Ingrese el nombre del lugar ");
	scanf("%s",nuevo->nombreLugar);
	printf("Ingrese el codigo postal: ");
	scanf("%d",&nuevo->codPostal);
	printf("\n");
	
	nuevo->sig=NULL;
    nuevo->ady=NULL;
    nuevo->visitado=nuevo->terminado=0;
    nuevo->monto=-1;
    strcpy(nuevo->anterior,"");
    if(inicio==NULL){
        inicio=nuevo;
    }else{
        aux=inicio;
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        aux->sig=nuevo;
      }
 
 }

void agregarArista (Vertice* aux, Vertice* aux2, Arista* nuevo){
    Arista* a;
    if(aux->ady==NULL){   
	    aux->ady=nuevo;
        nuevo->vrt=aux2;
    }else{   
	    a=aux->ady;
        while(a->sig!=NULL)
            a=a->sig;
        nuevo->vrt=aux2;
        a->sig=nuevo;
    }
}

void ingresarArista(){
   
    char ini[LONG], fin[LONG];
    int opcion;
    
    Arista* nuevo=(Arista*)malloc(sizeof(Arista));
    nuevo->sig=NULL;
    Vertice* auxiliar;
	Vertice* auxiliar2;
	
    if(inicio==NULL){
         printf("Error: El grafo está vacio\n");
         return;
    }
    
    //fflush(stdin);
    printf("Ingresar lugar de origen:");
    scanf("%s",ini);
    printf("Ingresar lugar de destino:");
    scanf("%s",fin);
    printf("Ingresar tiempo del camino:");
    scanf("%d",&nuevo->tiempo);
    printf("Ingresar distancia del camino:");
    scanf("%d",&nuevo->distancia);
    printf("Los tipos de rutas disponibles son: 1.Terrestre, 2.Maritima y 3.Aerea\n");
    printf("Indique el numero de ruta a escoger:");
    scanf("%d",&opcion);
	
	if (opcion == 1){
		strcpy(nuevo->tipoRuta, "Terrestre");
	}
	else if (opcion == 2){
		strcpy(nuevo->tipoRuta, "Maritima");
	}
	else if (opcion == 3){
		strcpy(nuevo->tipoRuta, "Aerea");
	}
	else{
		printf("Debe ingresar el codigo correcto");
		return;
	}
	
    auxiliar = inicio;
    auxiliar2 = inicio;
    while(auxiliar2 != NULL){
        if(strcmp(auxiliar2->nombreLugar,fin)==0){
            break;
        }
        auxiliar2 = auxiliar2->sig;
    }
    if(auxiliar2 == NULL){
    	printf("Error:lugar no encontrado\n");
    	return;
	}
    while(auxiliar!=NULL){
        if(strcmp(auxiliar->nombreLugar,ini)==0){
            agregarArista(auxiliar,auxiliar2,nuevo);
            return;
        }
        auxiliar = auxiliar->sig;
    }
    if(auxiliar == NULL)
    	printf("Error:lugar no encontrado\n");
}

void visualizarGrafo(){
    Vertice* aux=inicio;
    Arista* ar;
    printf("Vertices\n");
    while(aux!=NULL){   
	    printf("%s:    ",aux->nombreLugar);
        if(aux->ady!=NULL){
            ar=aux->ady;
            while(ar!=NULL){ 
			    printf(" %s %d %d",ar->vrt->nombreLugar,ar->tiempo,ar->distancia);
                ar=ar->sig;
            }
        }
        printf("\n");
        aux=aux->sig;
    }
    printf("\n");
}

void insertarPila(Vertice* aux){
	Lista* nuevo=(Lista*)malloc(sizeof(Lista));
	nuevo->lugar =aux;
	nuevo->sig=NULL;
	if(ini==NULL){
		ini=nuevo;
		final=nuevo;
		
	}else{
	   nuevo->sig=ini;
	   ini=nuevo;    	
	}
}

Vertice* desencolar(){
	Lista* aux;
	if(ini==NULL){
		return NULL;
	}else{
		aux=ini;
		ini=ini->sig;
		aux->sig=NULL;
		if(ini==NULL)
		final=NULL;
	}
	Vertice* resultado=aux->lugar;
	free(aux);
	return resultado;
}

void reiniciar(){
	if(inicio!=NULL){
		Vertice* aux=inicio;
		while(aux!=NULL){
			aux->visitado=aux->terminado=0;
		    aux->monto=-1;
		    strcpy(aux->anterior,"");
		    aux=aux->sig;
		}
	}
}


void eliminarArista(){
	char ini[LONG],fin[LONG];
	printf("ingrese el lugar de origen: ");
	scanf("%s" ,ini);
	printf("ingre el lugar destino: ");
	scanf("%s",fin);
	   
    Arista* a,* eliminar;
    Vertice* aux;
	Vertice* aux2;
    //fflush(stdin);
    aux=inicio;
    
    
	while(aux!=NULL){
		if(strcmp(aux->nombreLugar,ini)==0){
			eliminar=aux->ady;
			int num = 0;
			
			while(eliminar!=NULL){
				if(num==0){
					if(strcmp(eliminar->vrt->nombreLugar, fin)==0){
						aux->ady=eliminar->sig;
						free(eliminar);
						printf("Camino eliminado\n");
						return;
					}
					
				}
				if(strcmp(eliminar->vrt->nombreLugar,fin)==0){
					a->sig=eliminar->sig;
					free(eliminar);
					printf("Camino eliminado\n");
					return;
					}
				num++;
				a=eliminar;
				eliminar=eliminar->sig;
			}
			
		}
		aux=aux->sig;
	}
	printf("camino no encontrado\n");
	return;
    
}


void eliminarAristaLugar(char ini[LONG],char fin[LONG]){   
    Arista* a,* eliminar;
    Vertice* aux;
	Vertice* aux2;
    //fflush(stdin);
    aux=inicio;
	while(aux!=NULL){
		if(strcmp(aux->nombreLugar,ini)==0){
			eliminar=aux->ady;
			int num;
			while(eliminar!=NULL){
				if(num==0){
					if(strcmp(eliminar->vrt->nombreLugar,fin)==0){
						aux->ady=eliminar->sig;
						free(eliminar);
						printf("Camino eliminado\n");
						return;
					}
				}
				if(strcmp(eliminar->vrt->nombreLugar,fin)==0){
					a->sig=eliminar->sig;
					free(eliminar);
					printf("Camino eliminado\n");
					return;
					}
				num++;
				a=eliminar;
				eliminar=eliminar->sig;
			}
			
		}
		aux=aux->sig;
	}
	printf("camino no encontrado\n");
	return;
    
}


void eliminarVertice(){
	Vertice* actual,* anterior;
	Arista* aux;
	actual=inicio;
	char final[LONG];
	//fflush(stdin);
	printf("que lugar desea eliminar: ");
	scanf("%s",final);
	while (actual!=NULL){
		aux=actual->ady;
		while(aux!=NULL){
			if(strcmp(aux->vrt->nombreLugar,final)==0){
				eliminarAristaLugar(actual->nombreLugar, aux->vrt->nombreLugar);
				break;
			}
			aux=aux->sig;
		}
		actual=actual->sig;
	}
	
	actual=inicio;
	if(strcmp(actual->nombreLugar,final)==0){
		inicio=actual->sig;
		free(actual);
	}else{
		int info;
		info=strcmp(actual->nombreLugar,final);
		while(info!=0){
			anterior=actual;
			actual=actual->sig;
			info=strcmp(actual->nombreLugar,final);
		}
		anterior->sig=actual->sig;
		free(actual);
	}
}

//FINAL GRAFO



//-------------------------------------------------------
//------------TODO SOBRE LISTA DE DESEOS-----------------


ListaDeseo *listaNuevaDeseo(void)
{
	ListaDeseo *L;
	L = (ListaDeseo *) malloc(sizeof(ListaDeseo));
	L->inicio = NULL;
	L->final = NULL;
	return L;
}

NodoDeseo* crearNodoDeseo(const char nombreJuguet [LONG] ){
	NodoDeseo *nuevo;
	nuevo = (NodoDeseo *) malloc(sizeof(NodoDeseo));
	
	nuevo->anterior = NULL;
	nuevo->siguiente = NULL;	
	strcpy(nuevo->nombreJuguete, nombreJuguet);
	strcpy(nuevo->qEstado, "Solicitado");
			
	return nuevo;
}

void insertarDeseo(ListaDeseo *L, const char nombrJuguet [LONG])
{
	if(L->inicio == NULL) //Valida si la lista est? vac?a
	{
		//Inserta al inicio de la lista
		L->inicio = crearNodoDeseo(nombrJuguet);
		L->final = L->inicio;
		return;
	}
	
	//Inserta el dato al final de la lista, no necesita un ciclo porque tiene el puntero final
	L->final->siguiente = crearNodoDeseo(nombrJuguet);
	L->final->siguiente->anterior = L->final;
	L->final = L->final->siguiente;
}

void mostrarListaDeseos(const ListaDeseo  *L)
{
	NodoDeseo *i;
	
	printf("LISTA DE DESEOS\n\n");
	for(i = L->inicio; i!= NULL; i = i->siguiente){
	
		printf("NOMBRE: %s| ESTADO: %S \n", i->nombreJuguete, i->qEstado);
		}
}

void eliminarDeseo(ListaDeseo *L, const char nombreJU [LONG])
{
	NodoDeseo *aux = L->inicio;
	
	//Valida si la lista esta vacia
	if(L->inicio == NULL)
	{
		printf("La lista esta vacia...\n");		
	}
	else
	{
//Si el nodo a eliminar esta al inicio de la lista
		if( strcmp (aux->nombreJuguete, nombreJU) == 0)
		{
		aux = L->inicio;
		printf("\n-----------------------------------------");
		printf("El deseo con nombre %s ha sido eliminado \n", aux->nombreJuguete);
		printf("-----------------------------------------");
		
		if(L->inicio == L->final) //Verifica si la lista solo ten?a un nodo para actualizar el puntero final
		{
			L->inicio = NULL;
			L->final = NULL;
		}
		else{
			L->inicio = L->inicio->siguiente;
			L->inicio->anterior = NULL;	
		}		
		free(aux);

		}
	//-----------------------------	
		else 
		{
			while(aux != NULL)
			{
				if(strcmp (aux->nombreJuguete, nombreJU) == 0){
					aux->anterior->siguiente = aux->siguiente;
					if(aux != L->final)
						aux->siguiente->anterior = aux->anterior;
					else if(aux == L->final) //Valida si era el ultimo nodo de la lista para actualizar el puntero final
						L->final = L->final->anterior;					
					break;
				}
				aux = aux->siguiente;					
			}
			
		
		if(aux != NULL)
		{
			printf("El deseo con nombre %s ha sido eliminado \n", aux->nombreJuguete);
			free(aux);
		}
	}
}
}


//Funcion para liberar espacio de la lista deseo
void liberarListaDeseo (ListaCartaNino *L)
{
	NodoCarta *n, *aux;
	if(L->inicio == NULL)
		return;
	if(L->inicio->siguiente == NULL)
		return;		
	n = L->inicio;
	
	while(n != NULL)
	{
		aux = n;
		n = n->siguiente;
		free(aux);
	}
	
}


//'''''''''''''''''''''''''''''''''''''-----------------------------------------------------
//''''''''''''''''''''''''''''''''''''------------TODO SOBRE CARTA DE SANTA-----------------

ListaCartaNino *listaNuevaCARTA (void)
{
	ListaCartaNino *L;
	L = (ListaCartaNino *) malloc(sizeof(ListaCartaNino));
	L->inicio = NULL;
	L->final = NULL;
	L->cantidadJuguetes = 0;
	return L;
}

//---------------------------------------
NodoCarta* crearNodoCARTA(ListaCartaNino *Li, int idNiC, const char nombreNIC[], int aNio, const char jugueteD [], int piCual)
{
	NodoCarta *nuevo, auxiliar;
	
	nuevo = (NodoCarta *) malloc(sizeof(NodoCarta));
	nuevo->anterior = NULL;
	nuevo->siguiente = NULL;	
	nuevo->idNinoC = idNiC;
	strcpy(nuevo->nombreNInoC, nombreNIC);
	strcpy(nuevo->juguete1, "");
	strcpy(nuevo->juguete2, "");
	strcpy(nuevo->juguete3, "");
	strcpy(nuevo->juguete4, "");
	strcpy(nuevo->juguete5, "");
	strcpy(nuevo->juguete6, "");
	strcpy(nuevo->juguete7, "");
	strcpy(nuevo->juguete8, "");
	strcpy(nuevo->juguete9, "");
	strcpy(nuevo->juguete10, "");
	nuevo->anio = aNio;
	
	nuevo->puntoListaD = listaNuevaDeseo ();
	
	
	printf("En crear nodo carta despues copias NULL");
	
	if ( piCual == 1){
		if(Li->cantidadJuguetes == 0){
			strcpy(nuevo->juguete1, jugueteD);
		}
		if(Li->cantidadJuguetes == 1){
			strcpy(nuevo->juguete2, jugueteD);
		}
		if(Li->cantidadJuguetes == 2){
			strcpy(nuevo->juguete3, jugueteD);
		}
		if(Li->cantidadJuguetes == 3){
			strcpy(nuevo->juguete4, jugueteD);
		}
		if(Li->cantidadJuguetes == 4){
			strcpy(nuevo->juguete5, jugueteD);
		}
		if(Li->cantidadJuguetes == 5){
			strcpy(nuevo->juguete6, jugueteD);
		}
		if(Li->cantidadJuguetes == 6){
			strcpy(nuevo->juguete7, jugueteD);
		}
		if(Li->cantidadJuguetes == 7){
			strcpy(nuevo->juguete8, jugueteD);
		}
		if(Li->cantidadJuguetes == 8){
			strcpy(nuevo->juguete9, jugueteD);
		}
		if(Li->cantidadJuguetes == 9){
			strcpy(nuevo->juguete10, jugueteD);
		}
		Li->cantidadJuguetes++; 
	}
	else {
		insertarDeseo (nuevo->puntoListaD, jugueteD );	
	}	
		
	return nuevo;
}

void insertarCarta(ListaCartaNino *L, int idNC, const char nombreNC[LONG], int aNi, const char juGuetD [LONG], int pCual)
{
	
	if(L->inicio == NULL) //Valida si la lista est? vac?a
	{
		//Inserta al inicio de la lista
		L->inicio = crearNodoCARTA(L, idNC,nombreNC,aNi,juGuetD, pCual);
		L->final = L->inicio;
		return;
	}
	
	//Inserta el dato al final de la lista, no necesita un ciclo porque tiene el puntero final
	L->final->siguiente = crearNodoCARTA(L, idNC,nombreNC,aNi,juGuetD, pCual);
	L->final->siguiente->anterior = L->final;
	L->final = L->final->siguiente;
}

void mostrarListaCarta(const ListaCartaNino  *L)
{
	printf("Probando mostrar");
	NodoCarta *i;
	printf("____________________________________________________________________________\n");
	printf("LISTA DE DESEOS Y CARTAS PARA SANTA \n\n");
	for(i = L->inicio; i!= NULL; i = i->siguiente){
	
		printf("ID Nino/Nina: %d | Nombre Nino/Nina: %s | Anio: %d | \n", i->idNinoC, i->nombreNInoC, i->anio);
		printf("LISTA JUGUETES: 1.%s , 2.%s, 3.%s, 4.%s, 5.%s, 6.%s, 7.%s, 8.%s, 9.%s, 10.%s\n", i->juguete1, i->juguete2, i->juguete3, i->juguete4, i->juguete5, i->juguete6, i->juguete7, i->juguete8, i->juguete9, i->juguete10);
		mostrarListaDeseos (i->puntoListaD);
		
		}
	printf("____________________________________________________________________________\n");
}

//Funcion para liberar una lista de carta
void liberarListaCarta (ListaCartaNino *L)
{
	NodoCarta *n, *aux;
	if(L->inicio == NULL)
		return;
	if(L->inicio->siguiente == NULL)
		return;		
	n = L->inicio;
	
	while(n != NULL)
	{
		aux = n;
		n = n->siguiente;
		free(aux);
	}
	
}

//VERIFICAR NINO REPETIDO Y EXISTE

int verificarNino(const ListaR *L, int identificacion, const char nombre [])
{
	NodoR *nAux = L->inicio;
	
	while(nAux != NULL)
	{
		if(nAux->identificacion == identificacion && strcmp( nAux->nombre, nombre) ==0)
			return 1;
		nAux = nAux->siguiente;		
	}
	return 0;	
}


void ingresarCartas (ListaCartaNino *LC, const ListaR *L, const struct node* root ){
	//Funcion que ingresa la carta de santa	
	
	int identiNino;
	char nomNInC[LONG];
	char juGT [LONG];
	int ano, cual;
	
	printf("Digite la identificacion del niño o niña:  \n\n");
    scanf("%d",&identiNino);
	getchar(); //borrar basura
    
    printf("Digite el nombre del niño o niña:  \n\n");
    gets(nomNInC);
	
	if( verificarNino (L,identiNino, nomNInC) != 1){
		printf("Debe ingresar una identificacion y nombre de nino/nina valido");
		return;
	}
		    
    printf("Digite el anio actual de solicitud de los juguetes: \n");
    scanf("%d",&ano);
	getchar(); //borrar basura
			
	printf("Digite el nombre del juguete a guardar: \n");
	gets(juGT);
	
	if (BuscarJ(root, juGT) == 0){
		printf("No se encontro el juquete");
		return;
	}
	
	if(LC->cantidadJuguetes < 10){	    
	printf("Quieres Agregar los juguetes a tu carta o la lista de deseos? \n1. CARTA PARA SANTA \n2. LISTA DE DESEOS\n\n");
	scanf("%d",&cual);
	getchar(); //borrar basura
	
		if(cual==1 || cual == 2){
			insertarCarta (LC,identiNino, nomNInC, ano, juGT, cual);
			mostrarListaCarta (LC);
		}		
		else {
			printf("Debe ingresar un codigo de seleccion valido");
		}
	}
	
	else{
		printf("Ya no puede agregar mas juguetes a la carta para santa. Oprima  2 para agregar a la lista de deseos\n");
		scanf("%d",&cual);
		getchar(); //borrar basura
		if(cual == 2){
		
			insertarCarta (LC,identiNino, nomNInC, ano, juGT, cual);
			mostrarListaCarta (LC);
		}
		else {
			printf("Debe ingresar un codigo de seleccion valido");
		}
	}
	return; 
	
}



//                                       PRINCIPAL
//-----------------------------------------------------------------------------------------------------------------


int main(void)
{
	ListaR *L;
	L = listaNueva();
	
	ListaC *C;
	C = listaNuevaComportamiento();
	
	struct node* root = NULL;
	root = insert(root,"Barbie",50,"rosada","muneca",3,12,10000);
	root = insert(root,"Peluche",20,"osito","felpa",3,12,1230);
	root = insert(root,"Bicicleta",30,"roja","aire libre",3,18,15000);
	
	//Instancia de Registro Ayudantes de Santa
	ListaDobleAS *Lista;
	Lista = cargarAyudantes ();
	
	//Instancia de Registro Cartas de santa
	ListaCartaNino *LiCa;
	LiCa = listaNuevaCARTA();
	
	
	menu(L,C,root, Lista, LiCa);
}
	
int menu(ListaR *L,ListaC *C,struct node* root, ListaDobleAS *Lista, ListaCartaNino *LiCa){
	
	
	
	int cantidad_Juguetes = 0;
	
	//---------------------------------------MENU--------------------------------------
	char opcion[2];
	
	printf("\n\n--------BIENVENIDO, QUE DESEA HACER?-------- \n\n ELIJA UN NUMERO \n\n");
	
	printf("1. Registro del nino o nina \n");
	printf("2. Modificar informacion del nino o nina \n");
	printf("3. Eliminar registro de nino o nina \n");
	printf("4. Mostrar registros de ninos \n\n");
	
	printf("5. Registro del ayudante de santa\n");
	printf("6. Modificar informacion del ayudante de santa \n");
	printf("7. Eliminar registro de ayudante de santa \n");
	printf("8. Mostrar registros de ayudantes de santa \n\n");
	
	printf("9.  Registro de juguetes\n");
	printf("10. Modificar informacion de juguetes \n");
	printf("11. Eliminar registro de un juguete \n");
	printf("12. Mostrar registros de juguetes \n\n");
	
	printf("13. Registro de comportamientos\n");
	printf("14. Mostrar registros de comportamientos \n\n");
	
	printf("15. Agregar un lugar\n");
	printf("16. Agregar una ruta \n");
	printf("17. Eliminar un lugar \n");
	printf("18. Eliminar una ruta \n");
	printf("19. Modificar un lugar \n");
	printf("20. Modificar una ruta \n");
	printf("21. Mostrar catalogo de domicilios \n");
	
	printf("22. Agregar una carta para santa\n");
	printf("23. Modificar una carta para santa\n");
	printf("24. Eliminar una carta para santa\n");
	printf("25. Consultar una carta para santa\n");
	printf("26. Mostrar listas de carta para santa y deseos\n");
	
	
	
	gets(opcion);	
	
//	--------------------------------------Agregar o registrar nino--------------------------------------
	if (strcmp(opcion,"1")==0){
		
	  int identificacion;
	  char nombre[50];
	  char N_usuario[50];
	  char lugar[50];
	  char correo[50];
	  char fecha_nacimiento[15];
	  int edad;
	  char necesidades_especiales[100];
		
            printf("Digite el nombre completo del niño o niña \n\n");
            gets(nombre);
		    
            printf("Digite la identificacion de %s \n\n",nombre);
            scanf("%d",&identificacion);
		    getchar(); //borrar basura
			
			if (repetir_nino(L,identificacion) == -1)
            	{
				printf("\nEste numero de identificacion ya pertenece a un nino, vuelva a intentar el proceso\n");
				menu(L,C,root, Lista, LiCa);
				}    
		
		    
            printf("Digite nombre de usuario de %s \n\n",nombre);
            gets(N_usuario);
            printf("Digite lugar de procedencia de de %s \n\n",nombre);  //ACA HAY QUE METER RESTRICCION DE QUE ESTE REGISTRADO EN EL CATALOGO
            gets(lugar);
            printf("Digite el correo de %s \n\n",nombre);
            gets(correo);
            printf("Digite la fecha de nacimiento de %s   --FORMATO 04/01/2021-- \n\n",nombre);
            gets(fecha_nacimiento);
            printf("Digite la edad de %s \n\n",nombre);
            scanf("%d",&edad);
		    getchar(); //borrar basura
		    printf("Digite las necesidades especiales del nino o nina \n\n",nombre);
            gets(necesidades_especiales);
            
            insertarNino(L,identificacion,nombre,N_usuario,lugar,correo,fecha_nacimiento,edad,necesidades_especiales);
            
           	mostrarListaIzqDer(L);
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);
        }
//	--------------------------------------Modificar informacion del nino--------------------------------------      
       if (strcmp(opcion,"2")==0){
       	int identificacion, opcion;
		
		printf("\nQue numero de identificador tiene el nino que desea modificar \n\n");
 			scanf("%d",&identificacion);
		    getchar(); //borrar basura
		    
		printf("\nQue informacion desea modificar del nino o nina. Elija un numero \n\n");
		printf(" 1. Lugar de procedencia \n 2. Necesidades Especiales \n 3. Nombre de usuario \n\n");
         	scanf("%d",&opcion);
		    getchar(); //borrar basura;
            
        	ModificarNino(L,identificacion,opcion);
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);
    }
//	--------------------------------------Eliminar registro del nino--------------------------------------    
    if (strcmp(opcion,"3")==0){
    	int identificacion;
		
		printf("\nQue numero de identificador tiene el nino que desea eliminar \n\n");
 			scanf("%d",&identificacion);
		    getchar(); //borrar basura   
            eliminarNino(L,identificacion);
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);

    }
 //	--------------------------------------Mostrar lista registro del nino-------------------------------------   
    if (strcmp(opcion,"4")==0){
		 mostrarListaIzqDer(L);
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);
    }

//	--------------------------------------Registrar a un ayudante de santa------------------------------------- 
	if (strcmp(opcion,"5")==0){
		Lista = agregarAyudantes (Lista);
		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);
    }
    
  //	--------------------------------------Modificar los datos de un ayudante de santa------------------------------------- 
	if (strcmp(opcion,"6")==0){
		modificarAyudante(Lista);
		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);
    }  
  
//	--------------------------------------Eliminar a un ayudante de Santa------------------------------------- 
	if (strcmp(opcion,"7")==0){
		eliminarAyudante(Lista);
		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);
    }
    
//	--------------------------------------Mostrar registros de los ayudantes de Santa------------------------------------- 
	if (strcmp(opcion,"8")==0){
		mostrarListaAS (Lista);
		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);
    }   


//--------------------------------------Agregar juguetes al arbol-------------------------------------   
	if (strcmp(opcion,"9")==0){
		
		
		int codigo;
    	char nombreJ[50];
    	char descripcion[100];
    	char categoria[100];
    	int rangoI;
    	int rangoF;
    	int costo_total;
    	
    	printf("Digite el nombre del juguete a registrar \n\n");
            gets(nombreJ);
        printf("Digite el codigo del juguete a registrar \n\n");
            scanf("%d",&codigo);
		    getchar(); //borrar basura
        printf("Digite la descripcion del juguete a registrar \n\n");
            gets(descripcion);
        printf("Digite la categoria del juguete (DEPORTE, AGUA, MESA...) \n\n");
            gets(categoria);
		    
        printf("Digite la edad minima para utilizar  %s \n\n",nombreJ);
            scanf("%d",&rangoI);
		    getchar(); //borrar basura
		printf("Digite la edad maxima para utilizar  %s \n\n",nombreJ);
            scanf("%d",&rangoF);
		    getchar(); //borrar basura
		printf("Digite el costo total de  %s \n\n",nombreJ);
            scanf("%d",&costo_total);
		    getchar(); //borrar basura
		    
		root = insert(root,nombreJ,codigo, descripcion,categoria,rangoI,rangoF,costo_total); 
		printf("\nLISTA DE JUGUETES\n");
 		printf("____________________________________________________________________________\n");
		inorder(root);
		printf("\n____________________________________________________________________________\n");
		 cantidad_Juguetes = cantidad_Juguetes +1;
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);	
    }

//	--------------------------------------Modificar juguetes arbol--------------------------------------      
       if (strcmp(opcion,"10")==0){
       	char opcion[5];
       	char nombre[100];
			root = insert(root,"Barbie",50,"rosada","muneca",3,12,10000);
		printf("\nQue nombre exacto tiene el juguete que desea modificar \n\n");
 			gets(nombre);
		    
		printf("\nQue informacion desea modificar juguete. Elija un numero ");
			printf("\n\n-------------DATOS A MODIFICAR---------------");
			printf("\n1.Descripcion");
			printf("\n2.Rango de edad recomendado");
			printf("\n3.Costo de fabricacion");
			printf("\n-----------------------------------------------\n");    

         	gets(opcion);
            
        	modificarJuguete(root,nombre,opcion);
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);
    }

//	--------------------------------------Eliminar juguetes del arbol--------------------------------------    
    if (strcmp(opcion,"11")==0){
    	char nombre[50];
		
		printf("\nQue nombre exacto tiene el nino que desea eliminar \n\n");
 			gets(nombre);  
            root = deleteNode(root, nombre);
            printf("\n---JUGUETE ELIMINADO---\n");
        	cantidad_Juguetes = cantidad_Juguetes +1;
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);

    }
 //--------------------------------------Mostrar lista de juguetes------------------------------------- 	
  	if (strcmp(opcion,"12")==0){
       	printf("---------LISTA DE JUGUETES--------\n");
		inorder(root);
		printf("\n----------------------------------\n");
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);

    }

	//--------------------------------------Agregar comportamiento del nino------------------------------------- 

  
  if (strcmp(opcion,"13")==0){
		
	  int IDnino;
	  char nombrePadre[50];
	  char nombreMadre[50];
	  char Des_comportamiento[100];
	  char fecha_Registro[15];
	  char comportamiento[15];
	  int com_opcion;
    	
    	printf("Digite el identificador del nino para registrar su comportamiento \n\n");
            scanf("%d",&IDnino);
		    getchar(); //borrar basura
        printf("Digite el nombre del padre del nino \n\n");
            gets(nombrePadre);
        printf("Digite el nombre de la madre del nino \n\n");
            gets(nombreMadre);
        printf("Digite una descripcion del comportamiento del nino \n\n");
            gets(Des_comportamiento);
        printf("Digite la fecha de registro del comportamiento   --FORMATO 04/01/2021-- \n\n");
            gets(fecha_Registro);
        printf("Elija la clasificacion del comportamiento \n1. BUENO \n2. MALO) \n\n");
    			scanf("%d",&com_opcion);
		    	getchar(); //borrar basura
    			if (com_opcion== 1){
    			strcpy(comportamiento,"BUENO");
    			//aumentar contador
    			}
    			else if (com_opcion== 2){
    			strcpy(comportamiento,"MALO");
    			//aumentar contador
				}
				else{
					printf("opcion no valida\n\n");
				}
            
        insertarNinoC(C,IDnino,nombrePadre,nombreMadre,Des_comportamiento,fecha_Registro,comportamiento);
        mostrarListaComportamiento(C);
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);
  	}
 //--------------------------------------Mostrar lista comportamiento del nino------------------------------------- 	
  	if (strcmp(opcion,"14")==0){
       mostrarListaComportamiento(C);
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);

    }
    
 //--------------------------------------Agregar un lugar------------------------------------- 	
  	if (strcmp(opcion,"15")==0){
  		int cantidad, indice;
        printf("Ingrese la cantidad de lugares a registrar: ");
		scanf("%d", &cantidad);
	
		for (indice = 0; indice!=cantidad; indice++ ){
			ingresarVertice ();
		}
    	printf("\nPresione ENTER para continuar.\n"); 
		getch();
		menu(L,C,root, Lista, LiCa);
    }
    
 //--------------------------------------Agregar una ruta------------------------------------- 	
  	if (strcmp(opcion,"16")==0){
        ingresarArista ();
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);

    }
 //--------------------------------------Eliminar un lugar------------------------------------- 	
  	if (strcmp(opcion,"17")==0){
        eliminarVertice ();
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);

    }
 
 //--------------------------------------Eliminar una ruta------------------------------------- 	
  	if (strcmp(opcion,"18")==0){
        eliminarArista ();
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);

    }
    
  //--------------------------------------Modificar un lugar------------------------------------- 	
  	if (strcmp(opcion,"19")==0){
        //funcion
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);

    } 
  
  //--------------------------------------Modificar una ruta------------------------------------- 	
  	if (strcmp(opcion,"20")==0){
        //funcion
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);

    } 
    
  //--------------------------------------Mostrar catalogo de domicilios------------------------------------- 	
  	if (strcmp(opcion,"21")==0){
        		visualizarGrafo ();
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);

    }
    //--------------------------------------Agregar una carta para santa------------------------------------- 	
  	if (strcmp(opcion,"22")==0){
        		ingresarCartas (LiCa, L, root);
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				menu(L,C,root, Lista, LiCa);
    }
    
	  
	escribirAyudantes (Lista);
	liberarLista (Lista);
	liberarListaCarta (LiCa);
        return 0;
}
