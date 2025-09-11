#include <stdio.h>

int main(void) {

int numeros[4] = {5, 10, 15, 20};
int *p = numeros;

    printf("1) numeros[2] = %d\n", numeros[2]);

    printf("2) *(p+2) = %d\n", *(p+2));

    printf("3) *p = %d\n", *p); //se cambio las variables se elemino el p++; y se trato de asimilar al codigo de la practica
                               
    printf("4) *p = %d\n", p[1]); //asi entendi que esta liena agrega una salto al arreglo y muestra el valor que tiene
//No estoy del todo seguro si asi sea, pero fue lo que más logica me dio. 

return 0;

}
