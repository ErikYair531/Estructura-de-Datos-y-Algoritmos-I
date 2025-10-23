#include <stdio.h>
#include <stdlib.h>
//----------------------------------------------------------------------------
int main() {
    //Variable para switch
    int mc;
    //Variables para memoria
    int *p = NULL;
    int *pn = NULL;
    int tam = 0 , nTam = 0;
    int f , n ,i;
    //Agregamos otra variable para comparar en Realloc



//----------------------------------------------------------------------------

    printf("Que tipo de memoria quieres utilizar:");
        printf("Malloc(1) , Calloc(2), Realloc(3):");
        scanf("%d", &mc);
// En manera de juntar todos los pasos use switch para organizarlos todos
// en un mismo codigo, asi solo ponemos el tipo de memoria a utilizar en caso
// 1 , 2 o 3

//----------------------------------------------------------------------------
        switch (mc)
        {
        case 1:

    printf("Cuantos elementos desea almacenar con malloc:");
    scanf("%i", &tam);

    p = malloc (tam* sizeof (int));
        for(f=0; f<tam ; f++)
        {
            printf("Ingrese el elemento:");
            scanf("%i", &p[f]);
        }
        printf("Contenido:");
        for(f=0 ; f<tam ; f++)
        {
            printf("%i", p[f]);
            if(f< tam -1){
                printf(",");
            }
        }
        printf("\n");
        free(p);

        printf("\nMemoria liberada correctamente.\n");


            break;
//----------------------------------------------------------------------------
        case 2:

    printf("Cuantos elementos desea almacenar con calloc:");
    scanf("%i", &tam);

    p = calloc (tam ,  sizeof (int));

       printf("\Contenido en 0:");
        for(f=0 ; f<tam ; f++){

            printf("%d", p[f]);
            if(f< tam -1){
                printf(",");
            }
        }
        printf("\n Ingrese nuevo contenido: \n");
        for(f=0 ; f<tam ; f++) {
            printf("%d - ", f + 1);
            scanf("%i", &p[f]);
    }
        printf("\n Contenido ingresado:");
            for(f = 0; f < tam ; f++){
                printf("%i" , p[f]);

                if(f < tam - 1){
                printf(",");
            }

        }
           printf("\n");
            free(p);

            printf("\nMemoria liberada correctamente.\n");

            break;
//----------------------------------------------------------------------------
        case 3:
    printf("\n Espacio de memoria con Realloc");
    printf("\nCuantos elementos desea almacenar con malloc:");
    scanf("%d", &tam);

    //Usamos malloc para asignar
    p = (int *) malloc (tam* sizeof (int));
       // for(f=0; f<tam ; f++)
    if(p == NULL)
        {
            printf("\n ERROR... No asignar memoria.");
            return 1;
        }

          for(i = 0; i < tam ; i++)
        {
        printf("Ingrese el elemento:", i + 1);
            scanf("%d", &p[i]);
        }
        printf("\n Contenido inicial: \n ");
        for(i=0 ; i<tam ; i++)
        {
            printf("%d", p[i]);
            if(i< tam -1)
            printf(",");
        }
           printf("\n");

    //Redimensionamos con realloc
    printf("\n Asigne un nuevo valor al arreglo:");
    scanf("%d", &nTam);

    //Redimensionamos

    pn = (int *) realloc(p, nTam * sizeof(int));
    if (pn == NULL)
    {
        printf("\n ERROR... No se puede redimensionar.");
        free(p);
        return 1;

    }
    //Comparamos
    p = pn ;

    if (nTam > tam)
    {
        printf("\n Ingrese los nuevos valores:\n");
        for(i = tam ; i < nTam; i++)
        {
            printf("Ingrese el elemento:" , i + 1);
            scanf("%d" , &p[i]);
        }
    }

    printf("\n Contenido final del arreglo:");
    for (i = 0; i < nTam ; i++)
    {
        printf("%d", pn[i]);
        if (i < nTam - 1)
        printf(", ");
    }
    printf("\n");

    free(p);

    printf("\nMemoria liberada correctamente.\n");
    break;

       default:
            break;
    }

        return 0 ;
}

//Terminamos, por fin dejamos de surfrir :D

