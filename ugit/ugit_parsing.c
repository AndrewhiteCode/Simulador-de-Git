#include "ugit.h"
#include <string.h>
#include <stdio.h>

void parse_command(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: ugit <comando>\n");
        return;
    }

    if (strcmp(argv[1], "init") == 0) {
        cmd_init();
   /* } else if (strcmp(argv[1], "version") == 0) {
        cmd_version();
    } else if (strcmp(argv[1], "add") == 0) {
        if (argc < 3) {
            printf("Falta archivo a añadir\n");
        } else {
            cmd_add(argv[2]);
        }
    } else if (strcmp(argv[1], "commit") == 0) {
        cmd_commit();*/
    } else {
        printf("Comando desconocido: %s\n", argv[1]);
    }
}
