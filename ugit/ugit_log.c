/**
 * @file ugit_log.c
 * @brief Implementación del comando `log` de µGit.
 *
 * Lee y muestra el contenido del archivo de historial de commits ubicado en:
 *   ugit/commits.log
 *
 * Cada línea de `commits.log` representa un commit registrado por `cmd_commit`.
 * Esta función simplemente imprime el contenido tal cual, mostrando el historial
 * completo desde el commit más antiguo al más reciente (orden del archivo).
 *
 * @note Si prefieres ver los commits en orden inverso (más reciente primero),
 *       deberías leer todo el archivo en memoria y recorrerlo al revés o almacenar
 *       los registros en una estructura y ordenarlos.
 *
 * @author Andres Barbosa , Ivan Gallardo , Luis Muñoz
 * @date 2025-09-28
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ugit.h"

/**
 * @brief Muestra el historial de commits.
 *
 * Abre el archivo "ugit/commits.log" en modo lectura y muestra línea por línea su contenido.
 * Si el archivo no existe o no puede abrirse, imprime un mensaje indicando que no hay commits.
 *
 * Comportamiento:
 *  - Si `commits.log` existe: imprime encabezado y luego cada línea del archivo.
 *  - Si no existe: imprime "No hay commits registrados.".
 *
 * @return void
 *
 * @note Para mejorar:
 *  - Añadir paginación si el archivo es muy grande.
 *  - Formatear la salida para parecerse más al estilo `git log`.
 * @author Andres Barbosa , Ivan Gallardo , Luis Muñoz
 * @date 2025-09-28
 * 
 */
void cmd_log() {
    FILE *log_file = fopen("ugit/commits.log", "r");
    char line[1024];

    if (log_file == NULL) {
        printf("No hay commits registrados.\n");
        return;
    }

    printf("=== Historial de commits ===\n");
    while (fgets(line, sizeof(line), log_file)) {   
        printf("%s", line);
    }
    fclose(log_file);
}

