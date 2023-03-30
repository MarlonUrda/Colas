//Marlon Urdaneta C.I:30.763.460
#include<stdio.h>
#include <stdlib.h>
#include<limits.h>

struct nodo {
    int precio;
    struct nodo* sig ;
};

struct cola {
    struct  nodo  *primero, *ultimo;
};

struct  nodo *crearNodo (int precio){
    struct nodo * nuevo =  (struct nodo*) malloc( sizeof (struct  nodo ));

    nuevo->precio = precio;
    nuevo->sig  = NULL;
    return nuevo;
};

struct cola  * crearCola(){
    struct cola * nuevac = (struct cola*)  malloc (sizeof (struct cola));
    nuevac ->primero = nuevac->ultimo=NULL;
    return  nuevac;
};

void  enCola ( int precio, struct cola** nuevac ){

    struct nodo* nuevo =  crearNodo(precio);
    if((*nuevac )->primero == NULL){
        (*nuevac )->primero = (*nuevac )->ultimo = nuevo;
     return;
    };

    (*nuevac )->ultimo->sig = nuevo;
    (*nuevac) ->ultimo= nuevo;
}


int fueraCola( struct cola ** nuevac){
	

	struct nodo *eliminado = (*nuevac)->primero;
    int precio = eliminado->precio;
     
	(*nuevac) ->primero = eliminado->sig;

    if((*nuevac)->primero==NULL){
    	(*nuevac)->ultimo = NULL;
    }

    free(eliminado);

    return precio;
}

void mostrar ( struct cola ** nuevac){
    if ( (*nuevac )->primero==NULL) return ;
    
    printf("Primer precio de venta: %d \n Precio de venta actual: %d \n", (*nuevac )->primero->precio, (*nuevac )->ultimo->precio );

    struct nodo* actual  = (*nuevac )->primero;

    while(actual){
        printf ("%d,  ", actual->precio);
        actual = actual ->sig;
    }

    printf ("\n----------\n ");


}

int main (){
	
	printf("Precio de venta de zapatos Adidas: \n");
	
    struct cola  * c = crearCola();
    enCola(45, &c);
    enCola(30, &c);
    enCola(18, &c);
    enCola(20, &c);

    mostrar( &c);

    for( int i = 0; i < 5 ; i++){
        printf("Precio anterior: %d \n", fueraCola(&c));
        mostrar(&c);
    };

    return 0;
};
