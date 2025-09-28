#include "ugit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>   
#include <errno.h>

#define BUF_SIZE 8192

// copia binaria de archivo (source -> dest). Devuelve 0 si OK, -1 si error.
static int copiar_archivo(const char *origen, const char *destino) {
    FILE *fsrc = fopen(origen, "rb");
    if (!fsrc) return -1;
    FILE *fdst = fopen(destino, "wb");
    if (!fdst) { fclose(fsrc); return -1; }

    char buf[BUF_SIZE];
    size_t n;
    while ((n = fread(buf, 1, BUF_SIZE, fsrc)) > 0) {
        fwrite(buf, 1, n, fdst);
    }

    fclose(fsrc);
    fclose(fdst);
    return 0;
}

void cmd_commit() {
    FILE *index = fopen("ugit/index.txt", "r");
    if (!index) {
        printf("No hay staging (ugit/index.txt). Usa 'ugit add' primero.\n");
        return;
    }

    // Determinar nuevo número de commit buscando el primer commitN que no exista
    int commit_num = 1;
    char commit_folder[512];
    while (1) {
        sprintf(commit_folder, "ugit\\commit%d", commit_num);
        if (_mkdir(commit_folder) == 0) {
            // carpeta creada correctamente -> este será el commit
            break;
        } else {
            if (errno == EEXIST) {
                // existe, probar siguiente número
                commit_num++;
                continue;
            } else {
                printf("Error creando carpeta de commit '%s' (errno=%d)\n", commit_folder, errno);
                fclose(index);
                return;
            }
        }
    }

    // Leer cada línea del index y copiar el archivo al commit_folder
    char filename[512];
    int copied = 0;
    while (fgets(filename, sizeof(filename), index) != NULL) {
        // quitar salto de línea
        size_t len = strlen(filename);
        if (len > 0 && (filename[len-1] == '\n' || filename[len-1] == '\r')) {
            filename[len-1] = '\0';
            len--;
            if (len>0 && filename[len-1] == '\r') { filename[len-1] = '\0'; len--; }
        }
        if (len == 0) continue;

        char destpath[1024];
        // construir destino
        sprintf(destpath, "%s\\%s", commit_folder, filename);

        if (copiar_archivo(filename, destpath) == 0) {
            printf("Copiado: %s -> %s\n", filename, destpath);
            copied++;
        } else {
            printf("Fallo al copiar: %s (se omite)\n", filename);
        }
    }

    fclose(index);

    // Limpiar index (staging) para el próximo commit
    index = fopen("ugit/index.txt", "w");
    if (index) fclose(index);

    printf("Commit creado: %s (archivos copiados: %d)\n", commit_folder, copied);
}
