#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/*---------------------------------------------------------*/

typedef struct {
    int datos[MAX];
    int inicio;
    int final;
    int tam;
} ColaCircular;

void inicializarColaCircular(ColaCircular *c) {
    c->inicio = 0;
    c->final = 0;
    c->tam = 0;
    printf("\nCola circular inicializada\n");
}

int colaCircularVacia(ColaCircular *c) {
    return c->tam == 0;
}

int colaCircularLlena(ColaCircular *c) {
    return c->tam == MAX;
}

void enqueueCircular(ColaCircular *c, int valor) {
    if (colaCircularLlena(c)) {
        printf("\nError... Cola circular llena (no se puede insertar %d)\n", valor);
        return;
    }
    c->datos[c->final] = valor;
    c->final = (c->final + 1) % MAX;
    c->tam++;
    printf("Encolado: %d\n", valor);
}

int dequeueCircular(ColaCircular *c) {
    if (colaCircularVacia(c)) {
        printf("\nError... Cola circular vacía\n");
        return -1;
    }
    int valor = c->datos[c->inicio];
    c->inicio = (c->inicio + 1) % MAX;
    c->tam--;
    return valor;
}

int peekCircular(ColaCircular *c) {
    if (colaCircularVacia(c)) {
        printf("\nCola vacía\n");
        return -1;
    }
    return c->datos[c->inicio];
}

void imprimirColaCircular(ColaCircular *c) {
    printf("\nCola Circular (tam=%d): ", c->tam);
    if (colaCircularVacia(c)) {
        printf("Vacía\n");
        return;
    }
    int i = c->inicio;
    for (int count = 0; count < c->tam; count++) {
        printf("%d ", c->datos[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

/*---------------------------------------------------------*/

typedef struct {
    int datos[MAX];
    int frente;
    int tam;
} ColaDoble;

void inicializarColaDoble(ColaDoble *d) {
    d->frente = 0;
    d->tam = 0;
    printf("\nCola Doble inicializada\n");
}

int colaDobleVacia(ColaDoble *d) {
    return d->tam == 0;
}

int colaDobleLlena(ColaDoble *d) {
    return d->tam == MAX;
}

int indiceFinal(ColaDoble *d) {
    return (d->frente + d->tam - 1 + MAX) % MAX;
}

void insert_frente(ColaDoble *d, int valor) {
    if (colaDobleLlena(d)) {
        printf("\nError... Cola doble llena (no se puede insertar %d)\n", valor);
        return;
    }
    d->frente = (d->frente - 1 + MAX) % MAX;
    d->datos[d->frente] = valor;
    d->tam++;
    printf("Insertado al frente: %d\n", valor);
}

void insert_indice(ColaDoble *d, int valor) {
    if (colaDobleLlena(d)) {
        printf("\nError... Cola doble llena (no se puede insertar %d)\n", valor);
        return;
    }
    int fin = (d->frente + d->tam) % MAX;
    d->datos[fin] = valor;
        d->tam++;
    printf("Insertado al final: %d\n", valor);
}

int eliminar_frente(ColaDoble *d) {
    if (colaDobleVacia(d)) {
        printf("\nError... Cola doble vacía\n");
        return -1;
}
    int valor = d->datos[d->frente];
    d->frente = (d->frente + 1) % MAX;
    d->tam--;
    return valor;
}

int eliminar_indice(ColaDoble *d) {
    if (colaDobleVacia(d)) {
        printf("\nError... Cola doble vacía\n");
        return -1;
}
    int fin = indiceFinal(d);
    int valor = d->datos[fin];
    d->tam--;
    return valor;
}

void imprimirColaDoble(ColaDoble *d) {
    printf("\nCola Doble (frente=%d, tam=%d): ", d->frente, d->tam);
    if (colaDobleVacia(d)) {
        printf("Vacía\n");
        return;
    }
    int i = d->frente;
    for (int count = 0; count < d->tam; count++) {
        printf("%d ", d->datos[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

/*                   PROGRAMA PRINCIPAL                   */

int main() {
    ColaCircular cc;
    inicializarColaCircular(&cc);

    enqueueCircular(&cc, 10);
     enqueueCircular(&cc, 20);
    enqueueCircular(&cc, 30);
    imprimirColaCircular(&cc);

    printf("Desencolado: %d\n", dequeueCircular(&cc));
    imprimirColaCircular(&cc);

    enqueueCircular(&cc, 40);
    enqueueCircular(&cc, 50);
    imprimirColaCircular(&cc);

    ColaDoble cd;
    inicializarColaDoble(&cd);

    insert_frente(&cd, 10);
    insert_indice(&cd, 20);
    insert_indice(&cd, 30);
    insert_frente(&cd, 40);
    imprimirColaDoble(&cd);

    printf("Eliminado frente: %d\n", eliminar_frente(&cd));
    printf("Eliminado final: %d\n", eliminar_indice(&cd));
    imprimirColaDoble(&cd);

    insert_frente(&cd, 50);
    insert_indice(&cd, 60);
    imprimirColaDoble(&cd);

return 0;
}
