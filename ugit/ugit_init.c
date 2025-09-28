/**
 * @file ugit_init.c
 * @brief Implementación del comando `init` de µGit.
 *
 * Crea la carpeta de repositorio `ugit/` si no existe. Esta versión usa la llamada
 * al sistema `system("mkdir ugit")` para crear la carpeta; en Windows esto delega
 * al intérprete de comandos del sistema.
 *
 * @note
 * - La función no modifica archivos internos (index.txt, commits.log). Se recomienda
 *   ejecutar `ugit init` antes de usar `add` o `commit`.
 * - El uso de `system("mkdir ...")` es simple y funciona en entornos Windows/CMD.
 *   Para una implementación más portable se podría usar `_mkdir()` (Windows) o
 *   `mkdir(path, mode)` (POSIX) en lugar de `system`.
 *
 * @author Andres Barbosa , Ivan Gallardo , Luis Muñoz
 * @date 2025-09-28
 */

#include "ugit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Inicializa el repositorio local creando la carpeta `ugit`.
 *
 * Ejecuta el comando del sistema para crear la carpeta `ugit`. Si el comando devuelve
 * 0 se asume que la carpeta fue creada correctamente; en caso contrario se asume que
 * la carpeta ya existía o hubo un error.
 *
 * @return void
 *
 * @warning
 * - Este método no comprueba errores detallados (p. ej. permisos). Para manejo de errores
 *   más robusto se recomienda comprobar errno o usar llamadas nativas de creación de directorios.
 */
void cmd_init() {
    if (system("mkdir ugit") == 0) {
        printf("Carpeta Ugit creada exitosamente.\n");
    } else {
        printf("La carpeta Ugit ya existe.\n");
    }
}
