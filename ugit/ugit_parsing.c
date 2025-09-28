/**
 * @file ugit_parsing.c
 * @brief Enrutador de comandos para µGit.
 *
 * parse_command interpreta los argumentos pasados en la línea de comandos (argc/argv)
 * y llama a la función correspondiente para ejecutar el comando solicitado.
 *
 * Comandos soportados:
 *  - init      : inicializa el repositorio (cmd_init)
 *  - add       : añade archivos al staging (cmd_add)
 *  - commit    : crea un commit a partir del staging (cmd_commit)
 *  - version   : lista contenido/versions (cmd_version)
 *  - log       : muestra historial de commits (cmd_log)
 *  - checkout  : restaura un commit por número (cmd_checkout <num>)
 *
 * @note
 * - Esta función es el único punto que interpreta argv; las funciones concretas
 *   para cada comando (cmd_init, cmd_add, ...) están implementadas en otros
 *   módulos del proyecto.
 * - La interpretación de parámetros adicionales es mínima (por ejemplo,
 *   checkout espera un número en argv[2]). Mejoras futuras podrían parsear
 *   opciones tipo `-m "mensaje"` para commit, flags, etc.
 * @author Andres Barbosa , Ivan Gallardo , Luis Muñoz
 * @date 2025-09-28
 * 
 */

#include "ugit.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Interpreta los argumentos de la línea de comandos y ejecuta el comando.
 *
 * @param argc Número de argumentos.
 * @param argv Vector con los argumentos (argv[0] es el nombre del programa).
 *
 * @return void
 */
void parse_command(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: ugit <comando> [opciones]\n");
        return;
    }

    if (strcmp(argv[1], "init") == 0) {
        cmd_init();
    } 
    else if (strcmp(argv[1], "add") == 0) {
        cmd_add();
    } 
    else if (strcmp(argv[1], "commit") == 0) {
        cmd_commit();
    } 
    else if (strcmp(argv[1], "version") == 0) {
        cmd_version();
    } 
    else if (strcmp(argv[1], "log") == 0) {
        cmd_log();
    } 
    else if (strcmp(argv[1], "checkout") == 0) {
        if (argc < 3) {
            printf("Uso: ugit checkout <num_commit>\n");
        } else {
            int num = atoi(argv[2]);
            if (num <= 0) {
                printf("Número de commit inválido: %s\n", argv[2]);
            } else {
                cmd_checkout(num);
            }
        }
    } 
    else {
        printf("Comando desconocido: %s\n", argv[1]);
        printf("Comandos disponibles: init, add, commit, version, log, checkout\n");
    }
}
