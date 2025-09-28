// ugit_add.c
#include "ugit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cmd_add() {
    char filename[512];
    FILE *check, *add_file;

    printf("Archivos disponibles en el directorio actual:\n");
    // lista simple (Windows): dir /b
    system("dir /b");

    add_file = fopen("ugit/index.txt", "a"); // index en ugit/
    if (add_file == NULL) {
        printf("No se pudo abrir ugit/index.txt. ¿Ejecutaste ugit init?\n");
        return;
    }

    while (1) {
        printf("\nIngrese un archivo a agregar (q para terminar): ");
        if (scanf("%511s", filename) != 1) break;

        if (strcmp(filename, "q") == 0) {
            break;
        }

        check = fopen(filename, "rb");
        if (check != NULL) {
            // Agregar solo el nombre (no comprobamos duplicados aquí para simplicidad)
            fprintf(add_file, "%s\n", filename);
            fclose(check);
            printf("Archivo '%s' agregado al staging (ugit/index.txt).\n", filename);
        } else {
            printf("El archivo '%s' no existe o no se puede abrir.\n", filename);
        }
    }

    fclose(add_file);
    printf("\nFinalizado. Archivos en seguimiento: ugit/index.txt\n");
}
