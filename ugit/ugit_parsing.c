#include "ugit.h"
#include <string.h>
#include <stdio.h>

void parse_command(int argc, char *argv[]) {
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
    else {
        printf("Comando desconocido: %s\n", argv[1]);
        printf("Comandos disponibles: init, add, commit, version\n");
    }
}
