
#include <stdio.h>

int main(void) {

    int a[5] = {2, 4, 6, 8, 10};
    int *p = a; // p apunta a a[0]

        printf("1) a[1] = %d\n", a[1]); //Imprime el valor 4, imprime el segundo valor del arreglo

        printf("2) *(a+3) = %d\n", *(a+3)); //Imprime el valor 8, si (a) esta en la posicion 0
                                            //ahora se va a la tercera posicion donde esta el 8

        printf("3) *p++ = %d\n", *p++); //Imprime el valor 2, apunta al valor en el que esta p
                                        //y recorre a p

        printf("4) *++p = %d\n", *++p); //Imprime el valor 6, aumenta un posicion de p y muestra
                                        //el valor al que ahora apunta

        printf("5) p[1] = %d\n", p[1]); //Imprime 8, como en uno de los codigos que vimos en el lab. si a *++p se le aumento una posicion
                                        //con p¨[1] igual se le aumenta una posicion, hice la prueba con dicho codigo y el proceso es el indicado

        printf("6) *(p+=2) = %d\n", *(p+=2)); //Si p se queda en 8 y se le suma un 2 es igual a 10

        printf("7) p - a = %ld\n", p - a); //Imprime la distancia entre p y a, si p es igual a 10 y a es 0 el valor de la distancia entre p y a es 4


    return 0;

}


