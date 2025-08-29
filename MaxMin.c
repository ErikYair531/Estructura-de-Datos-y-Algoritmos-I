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

        printf("PROGRAMA BUSCAR EL MAXIMO Y MINIMO DE UN ARREGLO\n");

          do{

        printf("\nIngresa una cantidad (maximo100):");
		scanf("%d" , &n);

            if (n <= 0 || n > 100){ //Restringimos el tamaño del arreglo
                            //No negativos o mayores a 100
        printf("\nError!!!");
        printf("\nVuelva a intentarlo\n");

        }
    } while (n <= 0 || n > 100);

        printf("\nIngrese numeros : \n");
		for (int i = 0; i < n ; i++) {
			printf ("\nElementos: %d - " ,i);
			scanf("%d", &a[i]);
		}

    // En esta parte declaramos las variables para max y min

    int max = a[0], posicionMax = 0;
    int min = a[0], posicionMin = 0;

    //Comparamos elementos
    //Usamos un if para que vaya recorriendo los elementos
    for(i = 1; i < n; i++){
        if (a[i] > max){
                max = a[i];
                posicionMax = i;

        }
        if (a[i] < min){
                min = a[i];
                posicionMin = i;
        }


    }


        printf("\nLos elementos del arreglo son: ");
                for ( i = 0; i < n; i++) {
                    printf("%d%s", a[i], (i == n - 1) ? "" : ", ");


		}
		//Imprimimos los maximos y minimos abajo de la declaracion de los elementos

        printf("\n\nEl elemento maximo es: %d (posicion)%d", max, posicionMax);

        printf("\nEl elemento minimo es: %d (posicion)%d", min, posicionMin);

        printf("\n");

    return 0;
    }
