#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 100  // Asumimos un máximo de 100 columnas para simplificar

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <ruta_archivo>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return 1;
    }

    char line[1024];
    int sums[MAX_COLUMNS] = {0};
    int counts[MAX_COLUMNS] = {0};
    int column_count = 0;

    // Leer línea por línea
    while (fgets(line, sizeof(line), file)) {
        int col_index = 0;
        char *token = strtok(line, " \t\n");

        // Procesar cada número en la línea
        while (token != NULL) {
            int num;
            if (sscanf(token, "%d", &num) == 1) {
                if (col_index >= column_count) {
                    column_count = col_index + 1;  // Incrementar el número conocido de columnas
                }
                sums[col_index] += num;
                counts[col_index]++;
            }
            token = strtok(NULL, " \t\n");
            col_index++;
        }
    }

    fclose(file);

    // Mostrar la suma y el promedio para cada columna
    for (int i = 0; i < column_count; i++) {
        if (counts[i] > 0) {
            double average = (double)sums[i] / counts[i];
            printf("Columna %d: Suma = %d, Promedio = %.2f\n", i + 1, sums[i], average);
        } else {
            printf("Columna %d: No hay números\n", i + 1);
        }
    }

    return 0;
}
