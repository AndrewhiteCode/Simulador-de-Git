#include "ugit.h"
#include <stdio.h>
#include <stdlib.h>

void cmd_version() {
    printf("=== Contenido de 'versions' ===\n");
    system("dir versions /b");
    printf("=== Fin del contenido ===\n");
}
