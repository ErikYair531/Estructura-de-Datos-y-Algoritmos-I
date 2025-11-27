#include <stdio.h>
#include <stdlib.h>

/*Usamos el pseudo en forma de comentario para ordenar cada liena
de código*/

int max(int a , int b){

	return (a > b) ? a:b;

}

//Funcion MaximoRecur (Array, izquierdo, derecho);

int max_recursivo(int arr[], int izq, int der){

	//Si izq == der Entonces;

	if (izq== der){
	//Retonar Array [izq];
    return arr[izq];

}


	//Si izq +1 == der entonces;

	if(izq +1 == der){

		//Retonar Maximo(Array[izq] , Array [der]);

		return max(arr[izq], arr[der]);

	}


//Medio = (izq + der) / 2

int medio = izq + (der - izq) / 2;

//MaximoIzquierdo = MaximoRecur (Arr , izq , medio);

int max_izq = max_recursivo(arr, izq, medio);

//MaximoDerecho = MaximoRecur (Arr, medio + 1, der);

int max_der = max_recursivo(arr, medio +1 , der);



	//Retornar Max(maximoIzquierdo , maxDerecho);

	return max (max_izq, max_der);

//Fin// Incio del programa

}



int main()  {

	int n;

    printf("Ingresa el tamano de la lista:");

    scanf("%d" ,&n);


int lista[n];


printf("Ingresa los elementos:\n");

    for(int i = 0; i < n; i++){

	scanf("%d", &lista[i]);

}

    if (n > 0) {

    int resultado = max_recursivo(lista, 0, n - 1);
    printf("El valor maximo es: %d\n", resultado);

 } else {

 printf("La lista esta vacia.\n");

 }

return 0;


}

