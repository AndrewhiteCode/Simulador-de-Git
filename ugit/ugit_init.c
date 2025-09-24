#include "ugit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cmd_init() {
    if (system("mkdir versions") == 0) {
        printf("Carpeta 'versions' creada exitosamente.\n");
    } else {
        printf("La carpeta 'versions' ya existe.\n");
    }
}


