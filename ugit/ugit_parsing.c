#include <stdio.h>
#include <string.h>

// Funciones "vacías" para que completes después
void cmd_init() {
    printf("[ugit] Inicializando repositorio...\n");
    // TODO: crear carpeta .ugit
}

void cmd_add(const char *archivo) {
    printf("[ugit] Agregando archivo: %s\n", archivo);
    // TODO: guardar referencia del archivo
}

void cmd_commit() {
    printf("[ugit] Creando commit...\n");
    // TODO: copiar archivos agregados a carpeta de commits
}

void cmd_version() {
    printf("[ugit] Listando versiones...\n");
    // TODO: mostrar archivos de la carpeta commits
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: ugit <comando> [opciones]\n");
        return 1;
    }

    if (strcmp(argv[1], "init") == 0) {
        cmd_init();
    }
    else if (strcmp(argv[1], "add") == 0) {
        if (argc < 3) {
            printf("Uso: ugit add <archivo>\n");
            return 1;
        }
        cmd_add(argv[2]);
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

    return 0;
}
