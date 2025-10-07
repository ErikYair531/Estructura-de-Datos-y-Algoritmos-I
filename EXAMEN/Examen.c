#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int i;
    int agregar;
    float *cal = NULL;
    float suma = 0;
    float promedio = 0;

    printf("Numero de estudiantes a registrar: ");
    scanf("%d", &n);

    cal = (float*) malloc(n * sizeof(float));
    if (cal == NULL) {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        do {
            printf("Calificacion del estudiante %d: ", i + 1);
              scanf("%f", &cal[i]);
           if (cal[i] < 0 || cal[i] > 10) {
                printf("Error: Tu calificacion debe de ser entre 0 y 10.\n");
            }
        } while (cal[i] < 0 || cal[i] > 10);
        suma += cal[i];
    }

    promedio = suma / n;
      printf("Promedio inicial: %f\n", promedio);

    printf("Deseas agregar mas estudiantes? si presione (1) , no presione (0): ");
      scanf("%d", &agregar);

    if (agregar > 0) {
        int nuevo_tamano = n + agregar;
        float *temp = realloc(cal, nuevo_tamano * sizeof(float));

        if (temp == NULL) {
            printf("Error: no se pudo ampliar la memoria.\n");
              free(cal);
            return 1;
        }

        cal = temp;

        for (i = n; i < nuevo_tamano; i++) {
            do {
            printf("Calificacion del nuevo estudiante %d: ", i + 1);
                scanf("%f", &cal[i]);
            if (cal[i] < 0 || cal[i] > 10) {
                    printf("Error: Tu calificacion debe de ser entre 0 y 10.\n");
                 }
            } while (cal[i] < 0 || cal[i] > 10);
     }

        suma = 0;
        for (i = 0; i < nuevo_tamano; i++) {
            suma += cal[i];
    }
        promedio = suma / nuevo_tamano;

        printf("\nCalificaciones registradas:\n");
            for (i = 0; i < nuevo_tamano; i++) {
            printf("Estudiante %d: %f\n", i + 1, cal[i]);
        }
        printf("Promedio general: %f\n", promedio);
    } else {
        printf("\n Calificaciones registradas:\n");
            for (i = 0; i < n; i++) {
            printf("Estudiante %d: %f\n", i + 1, cal[i]);
    }
        printf("Promedio: %f", promedio);
    }

        free(cal);
    printf("Memoria liberada con exito...\n");

    return 0;
}
