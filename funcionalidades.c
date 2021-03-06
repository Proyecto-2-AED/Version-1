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
//---------REGISTRO NI�@------------------

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
	char identificacionAS [MAX];
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
        printf("\nEL NI�@ CON IDENTIFICADOR %d SI ESTA REGISTRADO \n\n", identificador);
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
            printf("Digite las nuevas necesidades del ni�o o ni�a \n\n");
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
   		 {printf("\nEL NI�@ CON IDENTIFICADOR %s NO ESTA REGISTRADO \n\n", identificador);}

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
NodoC* crearNodoComportamiento( int IDnino,char nombrePadre[],char nombreMadre[],char Des_comportamiento[],char fecha_Registro[],char comportamiento[])
{
	NodoC *nuevo;
	nuevo = (NodoC *) malloc(sizeof(NodoC));
	nuevo->anterior = NULL;
	nuevo->siguiente = NULL;
	
	nuevo->IDnino = IDnino;	
	strcpy(nuevo->nombrePadre,nombrePadre);
	strcpy(nuevo->nombreMadre,nombreMadre);
	strcpy(nuevo->Des_comportamiento,Des_comportamiento);
	strcpy(nuevo->fecha_Registro,fecha_Registro);
	strcpy(nuevo->comportamiento,comportamiento);
	
	return nuevo;
}



//INSERTAR DATOS EN LA LISTA DOBLE COMPORTAMIENTO

void insertarNinoC(ListaC *C, int IDnino,char nombrePadre[],char nombreMadre[],char Des_comportamiento[],char fecha_Registro[],char comportamiento[])
{
	if(C->inicio == NULL) //Valida si la lista est? vac?a
	{
		//Inserta al inicio de la lista
		C->inicio = crearNodoComportamiento(IDnino,nombrePadre,nombreMadre,Des_comportamiento,fecha_Registro,comportamiento);
		C->final = C->inicio;
		return;
	}
	
	//Inserta el dato al final de la lista, no necesita un ciclo porque tiene el puntero final
	C->final->siguiente = crearNodoComportamiento(IDnino,nombrePadre,nombreMadre,Des_comportamiento,fecha_Registro,comportamiento);
	C->final->siguiente->anterior = C->final;
	C->final = C->final->siguiente;
}


//MOSTRAR LISTA DOBLE REGISTRO DEL NIN@
void mostrarListaComportamiento(const ListaC *C)
{
	NodoC *i;
	printf("____________________________________________________________________________\n");
	printf("LISTA DE COMPORTAMIENTOS DE NINOS Y NINAS: \n\n");
	for(i = C->inicio; i!= NULL; i = i->siguiente){
	
		printf("IDENTIFICACION DEL NINO: %d \n", i->IDnino);
		printf("NOMBRE DEL PADRE: %s \n", i->nombrePadre);
		printf("NOMBRE DE LA MADRE: %s \n", i->nombreMadre);
		printf("FECHA DE REGISTRO: %s \n", i->fecha_Registro);
		printf("DESCRIPCION DEL COMPORTAMIENTO: %s \n", i->Des_comportamiento);
		printf("COMPORTAMIENTO: %s \n\n\n", i->comportamiento);
		}
	printf("____________________________________________________________________________\n");
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

/* Dada una b�squeda binaria no vac�a del
�rbol, devuelve el nodo
con el valor de clave m�nimo encontrado en
este arb�l. Tenga en cuenta que el
no es necesario buscar en todo el �rbol. */
struct node* minValueNode(struct node* node)
{
	struct node* current = node;

	/* bucle hacia abajo para encontrar la hoja m�s a la izquierda*/
	while (current && current->left != NULL)
		current = current->left;

	return current;
}

/* Dado un �rbol de b�squeda binario
y una llave, esta funci�n
elimina la clave y
devuelve la nueva ra�z*/
struct node* deleteNode(struct node* root, char nombrex[])
{
	// caso base
	if (root == NULL)
		return root;

// Si la clave a eliminar
// es m�s peque�o que el de la ra�z
// clave, luego se encuentra en el sub�rbol izquierdo
	if (strcmp(nombrex,root->nombre) < 0)
		root->left = deleteNode(root->left,nombrex);


// Si la clave a eliminar
// es mayor que la ra�z
// clave, luego se encuentra en el sub�rbol derecho
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
// (el m�s peque�o en el sub�rbol derecho)
		struct node* temp = minValueNode(root->right);

		
// Copiar el orden
// contenido del sucesor de este nodo
		strcpy(root->nombre, temp->nombre);

		//borrar el sucesor de este nodo
		root->right = deleteNode(root->right, temp->nombre);
	}
	return root;
}

BuscarJ(struct node* actual, char juguete[]){
	
while(actual != NULL){
	if(strcmp(juguete,actual->nombre)== 0){
		printf("ENCONTRADO!");
		printf("\n---------------------------------------------------------------");
		printf("\nNOMBRE DEL JUGUETE %s\nCODIGO DEL JUGUETE JU%d\nDESCRIPCION %s\nCATEGORIA %s\nRANGO DE EDAD %d-%d\nCOSTO TOTAL JUGUETE %d",actual->nombre,actual->codigo,actual->descripcion,actual->categoria,actual->rangoI,actual->rangoF,actual->costo_total);
		printf("\n---------------------------------------------------------------");
		break;}
		
	else if(strcmp(juguete, actual->nombre)> 0) actual = actual->left; 
    else if(strcmp(juguete, actual->nombre)< 0) actual = actual->right;
}
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
				printf("\nNuevo costo de fabricaci�n:");
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

NodoAS* crearNodoAS( const char idAS [MAX], const char nomAS [MAX], const char puAS [MAX], const char funAS [MAX], const char fechaIAS [MAX] )
{
	NodoAS *nuevo;
	nuevo = (NodoAS *) malloc(sizeof(NodoAS));
	nuevo->anterior = NULL;
	nuevo->siguiente = NULL;
	strcpy (nuevo->identificacionAS, idAS);
	strcpy (nuevo->nombreAS, nomAS);
	strcpy (nuevo->puestoAS, puAS);
	strcpy (nuevo->funcionesAS, funAS);
	strcpy (nuevo->fechaInicioAS, fechaIAS);
	return nuevo;
}

//Inserta un dato a una lista doble

void insertarDato(ListaDobleAS *L, const char identiAS [MAX], const char nombAS [MAX], const char puesAS [MAX], const char funciAS [MAX], const char fechaIniAS [MAX])
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
		printf("id_Ayudante: %s |Nombre: %s |Puesto: %s |Funciones: %s |Fecha de inicio laboral: %s\n", i->identificacionAS, i->nombreAS, i->puestoAS, i->funcionesAS, i->fechaInicioAS);
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

void corregirID (char idAS [MAX], const ListaDobleAS *L){
	NodoAS *auxiliar;
	int contador = 1;
	
	for (auxiliar = L->inicio; auxiliar != NULL ;  auxiliar =auxiliar->siguiente){
		
		if ( strcmp (auxiliar->identificacionAS, idAS) == 0 ){
			contador++;
			idAS[3] = contador + '0';
			printf("\nEl contador va por %d", contador);
			printf("\nEl nuevo id es: %s", idAS);
			
		}
		else {
			contador++;
			printf("\nEl contador va por %d", contador);
		}
	}
	free(auxiliar);
}

//Funcion para agregar Ayudantes de santa 
ListaDobleAS *agregarAyudantes (ListaDobleAS *LD){
	
	char ideAS [MAX];
	char nomBAS [MAX];
	char puesTAS [MAX];
	char funcIAS [MAX];
	char fechaInAS [MAX];
	int puesto;
	int dia;
	int mes;
	int anio;
	int tamano = LD->tamanoAS;
	
	char text[] = "AS- ";
	
	ListaDobleAS *ListaA;
	//ListaA = cargarRequerimientos ();
	//int tamano = tamanoListaReque (ListaR);
	tamano = tamano+1;
	
    text[3] = tamano + '0';
    strcpy (ideAS, text);
	
	corregirID(ideAS, LD);
	
	
	char palabra [MAX];

	printf ("-------- Ingrese los datos del ayudante de Santa -------- \n");
	
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
int esIdValido (ListaDobleAS *L, const char id [MAX]){
	NodoAS *auxiliar;
	
	for (auxiliar = L->inicio; auxiliar != NULL; auxiliar = auxiliar->siguiente){
		if (  strcmp (auxiliar->identificacionAS, id) == 0){
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
	char idModificar [MAX];
	int puesto;
	
	printf("Ingrese la identificacion del ayudante de Santa: ");
	scanf("%s", idModificar);
	
	
	
	if ( esIdValido (L, idModificar) == 0 ){
		printf("Debe ingresar una identificacion valida");
		return;
	}
	
	for (auxiliar = L->inicio; auxiliar!= NULL; auxiliar = auxiliar->siguiente){
		if( strcmp(auxiliar->identificacionAS, idModificar) == 0 ){
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
	char idEliminar [MAX];
	
	//Valida si la lista esta vacia
	if(L->inicio == NULL)
	{
		printf("La lista esta vacia...\n");	
		return;	
	}
	else
	{
		printf("Ingrese la identificacion del ayudante de Santa: ");
		scanf("%s", idEliminar);
	
		if ( esIdValido (L, idEliminar) == 0 ){
			printf("Debe ingresar una identificacion valida");
			return;
		}
		
//Si el nodo a eliminar esta al inicio de la lista
		if(strcmp(L->inicio->identificacionAS, idEliminar ) == 0) {
		aux = L->inicio;
		printf("El ayudante con identificacion %s ha sido eliminado \n", aux->identificacionAS);
		
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
				if( strcmp(aux->identificacionAS, idEliminar ) == 0) {
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
			printf("El ayudante con identificacion %s ha sido eliminado \n", aux->identificacionAS);
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
	
	char idAS [MAX];
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
				strcpy(idAS,token);
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
			fprintf(punteroArchivo,"%s\t",auxiliar->identificacionAS);
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

//M�todos del grafo Cat�logos para lugares de domicilio 

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
         printf("Error: El grafo est� vacio\n");
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
	
	menu(L,C,root);
}
	
int menu(ListaR *L,ListaC *C,struct node* root){
	ListaDobleAS *Lista;
	Lista = cargarAyudantes ();
	
	
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
		
            printf("Digite el nombre completo del ni�o o ni�a \n\n");
            gets(nombre);
		    
            printf("Digite la identificacion de %s \n\n",nombre);
            scanf("%d",&identificacion);
		    getchar(); //borrar basura
			
			if (repetir_nino(L,identificacion) == -1)
            	{
				printf("\nEste numero de identificacion ya pertenece a un nino, vuelva a intentar el proceso\n");
				return menu(L,C,root);
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
				return menu(L,C,root);
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
				return menu(L,C,root);
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
				return menu(L,C,root);

    }
 //	--------------------------------------Mostrar lista registro del nino-------------------------------------   
    if (strcmp(opcion,"4")==0){
		 mostrarListaIzqDer(L);
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				return menu(L,C,root);;
    }

//	--------------------------------------Registrar a un ayudante de santa------------------------------------- 
	if (strcmp(opcion,"5")==0){
		Lista = agregarAyudantes (Lista);
		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				return menu(L,C,root);
    }
    
  //	--------------------------------------Modificar los datos de un ayudante de santa------------------------------------- 
	if (strcmp(opcion,"6")==0){
		modificarAyudante(Lista);
		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				return menu(L,C,root);
    }  
  
//	--------------------------------------Eliminar a un ayudante de Santa------------------------------------- 
	if (strcmp(opcion,"7")==0){
		eliminarAyudante(Lista);
		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				return menu(L,C,root);
    }
    
//	--------------------------------------Mostrar registros de los ayudantes de Santa------------------------------------- 
	if (strcmp(opcion,"8")==0){
		mostrarListaAS (Lista);
		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				return menu(L,C,root);
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
				return menu(L,C,root);
		
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
				return menu(L,C,root);
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
				return menu(L,C,root);

    }
 //--------------------------------------Mostrar lista de juguetes------------------------------------- 	
  	if (strcmp(opcion,"12")==0){
       	printf("---------LISTA DE JUGUETES--------\n");
		inorder(root);
		printf("\n----------------------------------\n");
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				return menu(L,C,root);

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
				return menu(L,C,root);
  	}
 //--------------------------------------Mostrar lista comportamiento del nino------------------------------------- 	
  	if (strcmp(opcion,"14")==0){
       mostrarListaComportamiento(C);
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				return menu(L,C,root);

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
		return menu(L,C,root);
    }
    
 //--------------------------------------Agregar una ruta------------------------------------- 	
  	if (strcmp(opcion,"16")==0){
        ingresarArista ();
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				return menu(L,C,root);

    }
 //--------------------------------------Eliminar un lugar------------------------------------- 	
  	if (strcmp(opcion,"17")==0){
        eliminarVertice ();
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				return menu(L,C,root);

    }
 
 //--------------------------------------Eliminar una ruta------------------------------------- 	
  	if (strcmp(opcion,"18")==0){
        eliminarArista ();
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				return menu(L,C,root);

    }
    
  //--------------------------------------Modificar un lugar------------------------------------- 	
  	if (strcmp(opcion,"19")==0){
        //funcion
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				return menu(L,C,root);

    } 
  
  //--------------------------------------Modificar una ruta------------------------------------- 	
  	if (strcmp(opcion,"20")==0){
        //funcion
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				return menu(L,C,root);

    } 
    
  //--------------------------------------Mostrar catalogo de domicilios------------------------------------- 	
  	if (strcmp(opcion,"21")==0){
        		visualizarGrafo ();
           		printf("\nPresione ENTER para continuar.\n"); 
				getch();
				return menu(L,C,root);

    }  
    
	escribirAyudantes (Lista);
	liberarLista (Lista);
        return 0;
}
