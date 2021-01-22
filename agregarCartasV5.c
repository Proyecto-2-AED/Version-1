 //------------------------LIBRERIAS-------------------------------
#include <stdio.h> //entrada y salida de datos
#include <stdlib.h> //gestion de memoria
#include <string.h>  //manipulacion de strings

#define LONG 40
#define MAX 200
#define BIG 2000

//------------------------ESTRUCTURAS CARTA DE SANTA-------------------------------
typedef struct NodoCarta NodoCarta; //estructura de la carta
typedef struct ListaCartaNino ListaCartaNino; //estructura de los puntero inicio y final
typedef struct NodoDeseo NodoDeseo; //
typedef struct ListaDeseo ListaDeseo; //

struct NodoCarta
{
	char idNinoC [LONG];
	char nombreNInoC[LONG];
	int anio;
	char juguete1 [LONG], juguete2 [LONG], juguete3 [LONG], juguete4 [LONG], juguete5 [LONG], juguete6 [LONG], juguete7 [LONG];
	char juguete8 [LONG], juguete9 [LONG], juguete10 [LONG];
	char estado1 [LONG], estado2 [LONG], estado3 [LONG], estado4 [LONG], estado5 [LONG], estado6 [LONG], estado7 [LONG], estado8 [LONG];
	char estado9 [LONG], estado10 [LONG];
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
	char estado [LONG];
	NodoDeseo *siguiente;
	NodoDeseo *anterior; 
};

struct ListaDeseo{
	NodoDeseo *inicio;
	NodoDeseo *final;
};


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
	strcpy(nuevo->estado, "Solicitado");
			
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
	
		printf("NOMBRE: %s| ESTADO: %S \n", i->nombreJuguete, i->estado);
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


//-----------------------------------------------------
//------------TODO SOBRE CARTA DE SANTA-----------------

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
NodoCarta* crearNodoCARTA(ListaCartaNino *Li, const char idNiC [], const char nombreNIC[], int aNio, const char jugueteD [], int piCual)
{
	NodoCarta *nuevo, auxiliar;
	
	nuevo = (NodoCarta *) malloc(sizeof(NodoCarta));
	nuevo->anterior = NULL;
	nuevo->siguiente = NULL;	
	strcpy(nuevo->idNinoC, idNiC);
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

void insertarCarta(ListaCartaNino *L,const char idNC [LONG], const char nombreNC[LONG], int aNi, const char juGuetD [LONG], int pCual)
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
	
		printf("ID Nino/Nina: %s | Nombre Nino/Nina: %s | Anio: %d | \n", i->idNinoC, i->nombreNInoC, i->anio);
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


void ingresarCartas (ListaCartaNino *LC){
	//Funcion que ingresa la carta de santa	
	
	int identiNino;
	char nomNInC[LONG];
	char juGT [LONG];
	int ano, cual;
	
	printf("Digite la identificacion del niño o niña:  \n\n");
    scanf("%d",&identiNino);
	getchar(); //borrar basura
	
    //funcion que valida si ced existe
    //debe retornar el nombre para ponerlo abajo
    //condicionales
    
    printf("Digite el nombre del niño o niña:  \n\n");
    gets(nomNInC);
		    
    printf("Digite el anio actual de solicitud de los juguetes: \n");
    scanf("%d",&ano);
	getchar(); //borrar basura
			
	printf("Digite el nombre del juguete a guardar: \n");
	gets(juGT);
	//funcion que busca en el arbol de juguetes
	//if( existe juguete) {
		//imprime info}
	//else{
	// imprime info que juguete no existe}
	//finaliza
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

/*void modificarCarta (ListaCartaNino *LC, int pModiSelec){
	if (pModiSelec == 1){
		strcpy(aux->juguete1,modiJugue);
	}
	else if(pModiSelec == 2){
		strcpy(aux->juguete2,modiJugue);
	}
	else if(pModiSelec == 3){
		strcpy(aux->juguete3,modiJugue);
	}
	else if(pModiSelec == 4){
		strcpy(aux->juguete4,modiJugue);
	}
	else if(pModiSelec == 5){
		strcpy(aux->juguete5,modiJugue);
	}
	else if(pModiSelec == 6){
		strcpy(aux->juguete6,modiJugue);
	}
	else if(pModiSelec == 7){
		strcpy(aux->juguete7,modiJugue);
	}
	else if(pModiSelec == 8){
		strcpy(aux->juguete8,modiJugue);
	}
	else if(pModiSelec == 9){
		strcpy(aux->juguete9,modiJugue);
	}
	else if(pModiSelec == 10){
		strcpy(aux->juguete10,modiJugue);
	}
	else{
		printf("Debe ingresar un codigo de seleccion valido")
	}
	
}


void editarCarta(ListaCartaNino *LC){
	int idCartaModi, anioCartaModi, modiSelec, modiLisSe;
	char modiJugue [LONG];
	NodoCarta *aux = LC->inicio;
	
	printf("Ingrese la identificacion del nino/nina: ");
	scanf("%d",&idCartaModi);
	getchar(); //borrar basura
	
	printf("Ingrese el anio de la carta: ");
	scanf("%d",&anioCartaModi);
	getchar(); //borrar basura
	
	
	printf("Desea incorporar nuevos juguetes por \n1. REGISTRO DE JUGUETES \n2. LISTA DE DESEOS");
	scanf("%d",&modiLisSe);
	getchar(); //borrar basura
	
	if(modiLisSe == 1){
		mostrarListaCarta (LC);
		printf("Digite el numero de juguete a editar: ");
		scanf("%d",&modiSelec);
		getchar(); //borrar basura
	
		printf("Ingrese el juguete a incorporar: ");
		//Aqui va la funcion que busca en el arbol
		gets(modiJugue);
	}
	else if ( modiLisSe == 2){
		mostrarListaCarta (LC);
		printf("Digite el numero de juguete a editar: ");
		scanf("%d",&modiSelec);
		getchar(); //borrar basura
		
		
	}
	
	
	
	return;
}*/

int main(void){
	ListaCartaNino *LiCa;
	LiCa = listaNuevaCARTA();
	ingresarCartas (LiCa);
	
	liberarListaCarta (LiCa);
}
	
    
