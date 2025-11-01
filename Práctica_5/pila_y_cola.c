#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

/*------------------------------------------------------------------------------*/
//Estructura de una pila

typedef struct
{
    int items[MAX_SIZE];
    int tope;
} Pila;
//Inciciamo la pila en (tope = - 1)
void inicializarPila(Pila *p)
{
    p -> tope = - 1;
    printf("\n \t PILA INICIALIZADA (VACIA) \n");
}
//Variable para la pila vacia o pila llena
int pilaVacia(Pila *p)
{
    return p ->tope == -1;
}

int pilaLLena(Pila *p) {
    return p->tope == MAX_SIZE - 1;
}
//Estructura para meter  / sacar elementos
void push(Pila *p, int elemento) {
    if (pilaLLena (p)) {
        printf("Error: Pila llena... %d.\n", elemento);
    } else {

        p->tope++;
        p->items[p->tope] = elemento;
        printf("\n  Elemento insertado %d. ", elemento);
    }
}

int pop(Pila *p) {
    if (pilaVacia(p)) {
        printf("Error: Pila vacia... \n");
        return -1;
    } else {
        int elemento = p->items[p->tope];
        p->tope--;
        return elemento;
    }
}

void mostrarPila(Pila *p) {
    printf("\n Estado (Tope -> %d): ", p->tope);
    for (int i = 0; i <= p->tope; i++) {
        printf("%d ", p->items[i]);
    }

}

//----------------------------------------------------------------------------------------------------
//Estructura de una cola

typedef struct {
    int items[MAX_SIZE];
    int frente;
    int final;
    int contador;
} Cola;


void inicializarCola(Cola *c) {
    c->frente = 0;
    c->final = -1;
    c->contador = 0;
    printf("\n \t COLA INICIALIZADA (VACIA)\n");
}

int colaVacia(Cola *c) {
    return c->contador == 0;
}

int colaLLena(Cola *c) {
    return c->contador == MAX_SIZE;
}

void enqueue(Cola *c, int elemento) {
    if (colaLLena(c)) {
        printf("Error: Cola llena %d.\n", elemento);

    } else {
        c->final = (c->final + 1) % MAX_SIZE;
        c->items[c->final] = elemento;
        c->contador++;
        printf("ENQUEUE: Insertado %d. ", elemento);
    }
}

int dequeue(Cola *c) {
    if (colaVacia(c)) {
        printf("Error: Cola vacia. No se puede extraer.\n");
        return -1;

    } else {
        int elemento = c->items[c->frente];
        c->frente = (c->frente + 1) % MAX_SIZE;
        c->contador--;
        return elemento;
    }
}

void mostrarCola(Cola *c) {
    printf(" \n \t Estado de la Cola \n \t Frente = %d \n \t Final = %d \n \t Cont = %d  \n ", c->frente, c->final, c->contador);

    if (!colaVacia(c)) {
        int i = c->frente;
        int count = 0;
        while (count < c->contador) {
            printf("%d ", c->items[i]);
            i = (i + 1) % MAX_SIZE;
            count++;
        }
    }

}
/*Para poder limpiar el buffer usamos funciones auxiliares*/
void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int entero(const char *mensaje, int max) {
    int num, check;
    printf("%s (Maximo %d): ", mensaje, max);
    check = scanf("%d", &num);

    while (check != 1 || num < 1 || num > max) {
        printf(" \n Error... Por favor ingrese valores entre (1 y %d): ", max);
        limpiar_buffer();
        check = scanf("%d", &num);
    }
    limpiar_buffer();
    return num;
}

/*PROGRAMA*/

int main() {
    Pila p;
    Cola c;
    int elementos, elemento_salido;
    int pila_salida[MAX_SIZE];
    int cola_salida[MAX_SIZE];
    int cont_pila = 0;
    int cont_cola = 0;


    inicializarPila(&p);
    mostrarPila(&p);


    elementos = entero("\n Cuantos elementos quiere apilar: ", MAX_SIZE);

    printf("\n Insertando elementos en la Pila (PUSH) \n");
    for (int i = 0; i < elementos; i++) {
        push(&p, (i + 1) * 10);
        mostrarPila(&p);
    }


    int max_pop = elementos; // Solo se pueden desapilar los que se insertaron
    elementos = entero("\n Cuantos elementos quiere desapilar: ", max_pop);

    printf(" \n Extrayendo elementos de la Pila (POP)\n");
    for (int i = 0; i < elementos; i++) {
        elemento_salido = pop(&p);
        if (elemento_salido != -1) {
            printf("\n Salio el elemento %d. ", elemento_salido);
            pila_salida[cont_pila++] = elemento_salido;
        }
        mostrarPila(&p);
    }
    printf("\n");
    inicializarCola(&c);
    mostrarCola(&c);

    elementos = entero("\n Cuantos elementos quiere encolar:", MAX_SIZE);

    printf(" \nInsertando elementos en la Cola \n");
    for (int i = 0; i < elementos; i++) {
        enqueue(&c, (i + 1) * 10);
        mostrarCola(&c);
    }

    int max_dequeue = elementos;
    elementos = entero("\n Cuantos elementos quiere desencolar:", max_dequeue);

    printf("\nExtrayendo elementos de la Cola \n");
    for (int i = 0; i < elementos; i++) {
        elemento_salido = dequeue(&c);
        if (elemento_salido != -1) {
            printf(" \n DEQUEUE: Salio el elemento %d. ", elemento_salido);
            cola_salida[cont_cola++] = elemento_salido;
        }
        mostrarCola(&c);
    }

/*------------------------------------------------------------------------------*/


    printf("\n\t RESULTADOS PILA y COLA\n");

    printf("\n PILA \n");
    for (int i = 0; i < cont_pila; i++) {
        printf("%d ", pila_salida[i]);
    }


    printf("\n \n COLA \n ");
    for (int i = 0; i < cont_cola; i++) {
        printf("%d ", cola_salida[i]);
    }


    return 0;
}



/*Por temas practicos usaremos multiplos de 10 para lo elementos de la pila y de la cola*/
