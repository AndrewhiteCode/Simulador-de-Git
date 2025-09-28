#include "ugit.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
