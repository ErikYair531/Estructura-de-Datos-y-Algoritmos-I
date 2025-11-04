#include <stdio.h>
#include <stdlib.h>


/*Base del programa*/

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;

} Nodo;

void insertarInicio(Nodo ** cabeza, int valor){
    Nodo* nuevoNodo = (Nodo*) malloc (sizeof(Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo ->siguiente = *cabeza;
    *cabeza = nuevoNodo;
    printf("Insertando %d al inicio: \n", valor);
}


void recorrer(Nodo* cabeza){

    Nodo* actual = cabeza;
    printf("Lista:");
    while (actual != NULL){
        printf("%d. ", actual->dato);
        actual  = actual -> siguiente;
    }

}
void eliminar(Nodo** cabeza, int valor){
    Nodo* actual = *cabeza;
    Nodo* anterior = NULL;

    while (actual != NULL && actual -> dato != valor){
        anterior = actual;
        actual = actual ->siguiente;


    }
    if (actual == NULL){
        printf("\nValor %d no encontrado: \n", valor);
        return;
    }
    if (anterior == NULL){
        *cabeza = actual ->siguiente;
    } else {

        anterior->siguiente = actual ->siguiente;
    }
    free(actual);
    printf("Valor eliminado \n");


}

/*Para evitar que se llene la memoria o que halla valores no deseados*/

void liberar (Nodo * cabeza){
    Nodo *actual;
    while (cabeza != NULL){
        actual = cabeza;
        cabeza= cabeza ->siguiente;
        free(actual);
    }
    printf(" Memoria liberada con exito...");


}
/*----------------------------------------------*/

typedef struct NodoCircular {
    int dato;
    struct NodoCircular *siguiente;
} NodoCircular;

    void insertarCircular (NodoCircular ** cabeza, NodoCircular ** ultimo, int valor){
    NodoCircular *nuevo = (NodoCircular*) malloc (sizeof(NodoCircular));
    nuevo ->dato = valor;

    if (*cabeza == NULL){
        *cabeza = nuevo;
        *ultimo = nuevo;
        nuevo ->siguiente = nuevo;
        } else {
            nuevo ->siguiente = *cabeza;
            (*ultimo) ->siguiente = nuevo;
            *cabeza = nuevo;

        }
        printf("Insertando %d al inicio: \n", valor);
    }



void recorrerCircular(NodoCircular* cabeza){
    if(cabeza == NULL){
        printf("Lista circular vacia\n");
        return;
    }

    NodoCircular* actual = cabeza;
    printf("\nLista circular:\n");
    do{
        printf("%d. ", actual ->dato);
        actual = actual -> siguiente;
    }
    while (actual != cabeza);
        printf("Regresa al inicio\n ");
    }


void eliminarCircular(NodoCircular** cabeza, NodoCircular **ultimo, int valor){

    if (*cabeza == NULL){
        printf("Lista vacia\n");
        return;
    }

    NodoCircular* actual = *cabeza;
    NodoCircular* anterior = *ultimo;
    int encontrado = 0;

    do {
        if (actual->dato == valor) {
            encontrado = 1;
            break;
        }
        anterior = actual;
        actual = actual->siguiente;
    } while (actual != *cabeza);

    if (!encontrado) {
        printf("Valor %d no encontrado.\n", valor);
        return;
    }

    if (actual == *cabeza) {
        if (*cabeza == *ultimo) {
            *cabeza = NULL;
            *ultimo = NULL;
        } else {
            *cabeza = actual->siguiente;
            (*ultimo)->siguiente = *cabeza;
        }
    } else if (actual == *ultimo) {
        *ultimo = anterior;
        (*ultimo)->siguiente= *cabeza;
    } else {
        anterior->siguiente = actual->siguiente;
    }
    free(actual);
    printf("Valor %d eliminado de la lista circular\n", valor);

}



/*--------------Programa Principal--------------*/
int main () {

    Nodo* cabeza = NULL;
    int n, valor;
    int i;


    printf("\t\n LISTA \n");
    printf("Cuantos valores desea insertar\n");

    scanf("%d", &n);

    for (i = 0; i < n; i++){
        printf("\nValor %d:", i + 1);
        scanf("%d", &valor);
        insertarInicio(&cabeza, valor);
        recorrer(cabeza);
    }

    printf("\nIngrese valor a eliminar:\n");
    scanf("%d", &valor);
    eliminar(&cabeza, valor);
    recorrer(cabeza);
    liberar(cabeza);

    printf("\t\n LISTA CIRCULAR \n");

    NodoCircular *cabezaCircular = NULL;
    NodoCircular *ultimo = NULL;

    printf("\nCuantos valores desea insertar\n");
    scanf("%d", &n);

    for (i = 0; i < n; i++){
        printf("\nValor %d:", i + 1);
        scanf("%d", &valor);
        insertarCircular(&cabezaCircular, &ultimo, valor);
        recorrerCircular(cabezaCircular);
    }

    printf("\nIngrese un valor a eliminar:");
    scanf("%d", &valor);
    eliminarCircular(&cabezaCircular, &ultimo, valor);
    recorrerCircular(cabezaCircular);

   return 0;


}




