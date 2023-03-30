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
    struct cola * c = (struct cola*)  malloc (sizeof (struct cola));
    c ->primero = c->ultimo=NULL;
    return  c;
};

void  enCola ( int precio, struct cola** c ){

    struct nodo* nuevo =  crearNodo(precio);
    if((*c )->primero == NULL){
        (*c )->primero = (*c )->ultimo = nuevo;
     return;
    };

    (*c )->ultimo->sig = nuevo;
    (*c) ->ultimo= nuevo;
}


int fueraCola( struct cola ** c){
	if( (*c )->primero==NULL  )  return INT_MIN;

	struct nodo *eliminado = (*c)->primero;
    int precio = eliminado->precio;
     
	(*c) ->primero = eliminado->sig;

    if((*c)->primero==NULL){
    	(*c)->ultimo = NULL;
    }

    free(eliminado);

    return precio;
}

void mostrar ( struct cola ** c){
    if ( (*c )->primero==NULL) return ;
    
    printf("Primer precio de venta: %d \n Precio de venta actual: %d \n", (*c )->primero->precio, (*c )->ultimo->precio );

    struct nodo* actual  = (*c )->primero;

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
        printf("precio anterior %d \n", fueraCola(&c));
        mostrar(&c);
    };

    return 0;
};
