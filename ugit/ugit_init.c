#include "ugit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cmd_init() {
    if (system("mkdir ugit") == 0) {
        printf("Carpeta 'ugit' creada exitosamente.\n");
    } else {
        printf("La carpeta 'ugit' ya existe.\n");
    }
}
