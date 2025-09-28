/**
 * @file ugit.c
 * @brief Punto de entrada de µGit.
 *
 * Simplemente delega el parsing de comandos a parse_command().
 * @author Andres Barbosa , Ivan Gallardo , Luis Muñoz
 * @date 2025-09-28
 * 
 */
#include "ugit.h"
#include <stdio.h>
/**
 * @brief Programa principal.
 *
 * @param argc Conteo de argumentos.
 * @param argv Vector de argumentos.
 * @return 0 en salida normal.
 */

int main(int argc, char *argv[]) {
    parse_command(argc, argv); // Llama al parser
    return 0;
}
