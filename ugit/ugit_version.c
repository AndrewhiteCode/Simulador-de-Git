/**
 * @file ugit_version.c
 * @brief Implementación del comando `version` de µGit.
 *
 * Proporciona un listado simple del contenido de la carpeta de repositorio `ugit/`.
 * Actualmente usa el comando del sistema `dir /b` (Windows) para mostrar los nombres
 * de los elementos dentro de `ugit/`.
 *
 * @note
 * - Esta implementación es intencionalmente simple y orientada a Windows.
 *   Para portabilidad a sistemas POSIX se recomienda usar <dirent.h>.
 * - No modifica el estado del repositorio; es una operación de solo lectura visual.
 *
 * @author Andres Barbosa , Ivan Gallardo , Luis Muñoz
 * @date 2025-09-28
 */

#include "ugit.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Muestra un listado simple del contenido de la carpeta `ugit`.
 *
 * Comportamiento:
 *  - Imprime un encabezado, ejecuta `dir ugit /b` para listar los nombres de archivos
 *    y directorios dentro de `ugit/` en formato "bare" (solo nombres), y luego imprime
 *    un pie indicando el fin del listado.
 *
 * @return void
 *
 * @warning
 * - Usa `system("dir ugit /b")`, por lo que la salida y la disponibilidad dependen del
 *   intérprete de comandos de Windows. En otros sistemas, cambia por `ls` o implementa
 *   una lectura directa del directorio para portabilidad.
 */
void cmd_version() {
    printf("=== Contenido de Ugit Version ===\n");
    system("dir ugit /b");
    printf("=== Fin del contenido ===\n");
}
