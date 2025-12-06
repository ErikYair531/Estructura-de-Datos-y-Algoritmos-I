#include <stdio.h>
#include <stdlib.h>

/*---------------------------------------------------------------------------*/

struct Nodo {
    int dato;
    struct Nodo *siguiente;
    struct Nodo *anterior;
};


void insertarInicio(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) return; 
    nuevo->dato = valor;
    nuevo->anterior = NULL;
    nuevo->siguiente = *inicio;

    if (*inicio != NULL) {
        (*inicio)->anterior = nuevo;
    }
    *inicio = nuevo;
}

void insertarFinal(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) return;
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (*inicio == NULL) {
        nuevo->anterior = NULL;
        *inicio = nuevo;
        return;
    }

    struct Nodo *temp = *inicio;
    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }
    temp->siguiente = nuevo;
    nuevo->anterior = temp;
}

void recorrerAdelante(struct Nodo *inicio) {
    if (inicio == NULL) {
        printf("lista vacia\n");
        return;
    }
    struct Nodo *temp = inicio;
    printf("Adelante ");
    while (temp != NULL) {
        printf("%d - ", temp->dato);
        temp = temp->siguiente;
    }
    printf("NULL\n");
}


void recorrerAtras(struct Nodo *inicio) {
    if (inicio == NULL) {
        printf("lista vacia\n");
        return;
    }
    struct Nodo *temp = inicio;

    while (temp->siguiente != NULL) {
        temp = temp->siguiente;
    }
    printf("Atras ");
    while (temp != NULL) {
        printf("%d -> ", temp->dato);
        temp = temp->anterior;
    }
    printf("NULL\n");
}

void eliminar(struct Nodo **inicio, int valor) {
    struct Nodo *actual = *inicio;


    if (actual == NULL) return;

   
    while (actual != NULL && actual->dato != valor) {
        actual = actual->siguiente;
    }

    if (actual == NULL) {
        printf("Valor %d no encontrado para eliminar.\n", valor);
        return;
    }

    if (actual == *inicio) {
        *inicio = actual->siguiente;
        if (*inicio != NULL) {
            (*inicio)->anterior = NULL;
        }
    } else {
       
        actual->anterior->siguiente = actual->siguiente;
        if (actual->siguiente != NULL) {
            actual->siguiente->anterior = actual->anterior;
        }
    }

    printf("Eliminado- %d\n", actual->dato);
    free(actual);
}


void liberar(struct Nodo *inicio) {
    struct Nodo *actual = inicio;
    struct Nodo *siguiente;
    while (actual != NULL) {
        siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    printf("\nMemoria liberada correctamente\n");
}


void insertarFinalCircular(struct Nodo **inicio, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) return;
    nuevo->dato = valor;

    if (*inicio == NULL) {
        *inicio = nuevo;
        (*inicio)->siguiente = *inicio;
        (*inicio)->anterior = *inicio;
        return;
    }

    struct Nodo *ultimo = (*inicio)->anterior;
    
    nuevo->siguiente = *inicio;
    nuevo->anterior = ultimo;
    
    ultimo->siguiente = nuevo;
    (*inicio)->anterior = nuevo;
}

void recorrerCircular(struct Nodo *inicio) {
    if (inicio == NULL) {
        printf("lista circular vacia\n");
        return;
    }
    struct Nodo *temp = inicio;
    printf("Lista Circular: ");
    do {
        printf("%d <-> ", temp->dato);
        temp = temp->siguiente;
    } while (temp != inicio);
    printf("Inicio (%d)\n", inicio->dato);
}


void eliminarCircular(struct Nodo **inicio, int valor) {
    if (*inicio == NULL) return;

    struct Nodo *actual = *inicio;
    while (actual->dato != valor && actual->siguiente != *inicio) {
        actual = actual->siguiente;
    }
    
    if (actual->dato != valor) {
        printf("Valor %d no encontrado en la lista circular.\n", valor);
        return;
    }

    if (actual == *inicio && actual->siguiente == *inicio) {
        free(actual);
        *inicio = NULL;
        printf("\nMemoria liberada.\n");
        return;
    }

    actual->anterior->siguiente = actual->siguiente;
    actual->siguiente->anterior = actual->anterior;

    if (actual == *inicio) {
        *inicio = actual->siguiente;
    }
    
    printf("\n Eliminado de lista circular: %d\n", actual->dato);
    free(actual);
}
/*---------------------------------------------------------------------------*/
/*Programa principal*/
/*---------------------------------------------------------------------------*/
int main() {
    struct Nodo *listaA = NULL;
    struct Nodo *listaB_circular = NULL;
    int num_valores, valor;

    
/*---------------------------------------------------------------------------*/
    printf("PARTE A\n");

    
    printf("¿Cuántos valores desea insertar al inicio? ");
    scanf("%d", &num_valores);
    for (int i = 0; i < num_valores; i++) {
        printf("Ingrese valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarInicio(&listaA, valor);
    }
    recorrerAdelante(listaA);

   
    printf("¿Cuántos valores desea insertar al final? ");
    scanf("%d", &num_valores);
    for (int i = 0; i < num_valores; i++) {
        printf("Ingrese valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarFinal(&listaA, valor);
    }
    recorrerAdelante(listaA);

    recorrerAdelante(listaA);
    recorrerAtras(listaA);

    printf("\nIngrese un valor a eliminar de la lista A: ");
    scanf("%d", &valor);
    eliminar(&listaA, valor);
    recorrerAdelante(listaA);

    liberar(listaA);
    listaA = NULL;

/*---------------------------------------------------------------------------*/
    printf("\nPARTE B\n");

    printf("¿Cuántos valores desea insertar en la lista circular? ");
    scanf("%d", &num_valores);
    for (int i = 0; i < num_valores; i++) {
        printf("\nIngrese valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarFinalCircular(&listaB_circular, valor);
    }

    recorrerCircular(listaB_circular);

    printf("Ingrese un valor a eliminar de la lista circular: ");
    scanf("%d", &valor);
    eliminarCircular(&listaB_circular, valor);
    
    if (listaB_circular != NULL) {
       recorrerCircular(listaB_circular);
    }

    return 0;
    }
    
 
