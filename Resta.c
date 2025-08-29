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


		int n; //Variable del tamaño del arreglo
		int a[100];//Valor maximo del tamaño del arreglo
		int resta = 0;//Variable para la resta del arreglo
		int i;//Variable para bucle

        printf("PROGRAMA PARA LA RESTA DE LOS ELEMENTOS DE UN ARREGLO\n");

            do{

        printf("\n Ingresa una cantidad (maximo100):");
		scanf("%d" , &n);

		if (n <= 0 || n > 100){ //Restringimos el tamaño del arreglo
                            //No negativos o mayores a 100
        printf("\nError!!!");
        printf("\nVuelva a intentarlo\n");



                }
            }while(n <= 0 || n > 100);



		printf("\nIngrese la cantidad de numeros por elemento: \n");
            for ( i = 0; i < n ; i++){


			printf ("\nElementos: %d - " ,i );
			scanf("%d", &a[i]);
			resta -= a[i]; //Realizamos la resta de los elementos para despues solo impimir

            }

		printf("\nLos elementos del arreglo son: ");
            for (i = 0 ; i < n ; i++) {
			printf("%d%s", a[i], (i == n - 1) ? "" : " , ");


		}
        printf("\n\nLa resta de los elementos: %d\n", resta);


        return 0;

    }

