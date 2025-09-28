#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ugit.h"

void cmd_log() {
    FILE *log_file = fopen("ugit/commits.log", "r");
    char line[1024];

    if (log_file == NULL) {
        printf("No hay commits registrados aún.\n");
        return;
    }

    printf("=== Historial de commits ===\n");
    while (fgets(line, sizeof(line), log_file)) {   
        printf("%s", line);
    }
    fclose(log_file);
}
