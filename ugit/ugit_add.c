/**
 * @file ugit_add.c
 * @brief Comando `add` de µGit: añade archivos al staging (ugit/index.txt).
 *
 * Este archivo contiene la implementación del comando interactivo `ugit add`
 * que permite al usuario seleccionar archivos del directorio de trabajo y
 * guardarlos en el archivo de staging `ugit/index.txt`.
 *
 * @author Andres Barbosa , Ivan Gallardo , Luis Muñoz
 * @date 2025-09-28
 */
#include "ugit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Añade archivos al área de preparación (staging).
 *
 * Funcionalidad:
 * - Muestra una lista simple de archivos del directorio actual (comando `dir /b` en Windows).
 * - Pide al usuario el nombre de un archivo para agregar; repetir hasta introducir 'q'.
 * - Verifica la existencia del archivo antes de añadirlo al archivo `ugit/index.txt`.
 * - Añade el nombre del archivo (una línea por archivo) a `ugit/index.txt`.
 *
 * Comportamiento:
 * - Si `ugit/index.txt` no existe, se crea con modo append.
 * - No se realiza comprobación de duplicados (puede agregarse como mejora).
 *
 * @note
 * - Actualmente usa `system("dir /b")`, que es específico de Windows. Para portabilidad,
 *   reemplazar por una implementación con <dirent.h> en entornos POSIX o una alternativa
 *   disponible en Windows.
 * - Se utiliza `scanf` para leer el nombre; `scanf("%511s", ...)` evita overflow
 *   en la mayoría de los casos, pero **fgets** + saneado es más seguro para entradas
 *   con espacios o caracteres especiales.
 * - La función asume que los archivos a añadir están en el directorio de trabajo actual.
 *
 * @warning
 * - Si el usuario introduce rutas con subdirectorios ('carpeta/archivo.txt'), se
 *   intentará abrir exactamente esa ruta. Asegúrate de que las rutas relativas sean válidas.
 *
 * @return void
 */

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
            printf("El archivo %s no existe o no se puede abrir.\n", filename);
        }
    }

    fclose(add_file);
    printf("\nFinalizado. Archivos en seguimiento: ugit/index.txt\n");
}
