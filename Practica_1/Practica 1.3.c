	/*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
* Author: Erik Y. Nogueira Lopez.
*/

	#include  <stdio.h>

	int main (void) {


		int n;
		int a[100];
        int i;
        int ao[100]; //Variable del arreglo original

        printf("PROGRAMA PARA CREAR UN ARREGLO INVERSO\n");

          do{

        printf("\nIngresa una cantidad (maximo100):");
		scanf("%d" , &n);

            if (n <= 0 || n > 100){ //Restringimos el tamaño del arreglo
                            //No negativos o mayores a 100
        printf("\nError!!!");
        printf("\nVuelva a intentarlo\n");

        }
    } while (n <= 0 || n > 100);

    printf("\nIngrese numeros :");
		for (int i = 0; i < n ; i++) {
			printf ("\nElementos: %d - " ,i);
			scanf("%d", &a[i]);
			ao[i]=a[i];
		}
//Declaramos una variable temp para nuestro bucle
    for (i = 0; i < n/2; i++ ){
        int temp = a[i];
        a[i] = a[n - i -1];
        a[n - i -1] = temp;

        }

        printf("\nLos elementos del arreglo inverso son: ");
                for ( i = 0; i < n; i++) {
                    printf("%d%s", a[i], (i == n - 1) ? "" : ", ");
                }

        printf("\nLos elementos del arreglo original son:");
                for ( i = 0; i < n; i++) {
                    printf("%d%s", ao[i], (i == n - 1) ? "" : ", ");

		}

        printf("\n");
        return 0;
	}

	//Todo tipo de informacion se obtuvo de paginas web, ejemplos de internet.
	//https://labex.io/es/tutorials/c-reverse-an-array-123327
	//https://parzibyte.me/blog/posts/invertir-arreglo-ansi-c/
	//https://youtu.be/_JmyF2JPqwk?si=xVjiFsk8D-UGAiD7
	//https://parzibyte.me/blog/posts/sumar-valores-arreglo-c-obtener-sumatoria/
	//https://www.w3resource.com/c-programming-exercises/array/c-array-exercise-9.php#:~:text=Explicaci%C3%B3n:,elementos%20m%C3%A1ximos%20y%20m%C3%ADnimos%20encontrados.

