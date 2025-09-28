#include "ugit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>   
#include <errno.h>
#include <time.h>   

#define BUF_SIZE 8192

int copiar_archivo(const char *origen, const char *destino) {
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

    int commit_num = 1;
    char commit_folder[512];
    while (1) {
        sprintf(commit_folder, "ugit\\commit%d", commit_num);
        if (_mkdir(commit_folder) == 0) {
            break; 
        } else {
            if (errno == EEXIST) {
                commit_num++;
                continue;
            } else {
                printf("Error creando carpeta de commit '%s' (errno=%d)\n", commit_folder, errno);
                fclose(index);
                return;
            }
        }
    }

    char filelist_path[512];
    sprintf(filelist_path, "%s\\filelist.txt", commit_folder);
    FILE *filelist = fopen(filelist_path, "w");
    if (!filelist) {
        printf("Error creando filelist.txt en %s\n", commit_folder);
        fclose(index);
        return;
    }

    char filename[512];
    int copied = 0;
    while (fgets(filename, sizeof(filename), index) != NULL) {
        size_t len = strlen(filename);
        if (len > 0 && (filename[len-1] == '\n' || filename[len-1] == '\r')) {
            filename[len-1] = '\0';
            len--;
            if (len>0 && filename[len-1] == '\r') { filename[len-1] = '\0'; len--; }
        }
        if (len == 0) continue;

        char destpath[1024];
        sprintf(destpath, "%s\\%s", commit_folder, filename);

        if (copiar_archivo(filename, destpath) == 0) {
            fprintf(filelist, "%s\n", filename); 
            printf("Copiado: %s -> %s\n", filename, destpath);
            copied++;
        } else {
            printf("Fallo al copiar: %s (se omite)\n", filename);
        }
    }

    fclose(filelist);
    fclose(index);

    index = fopen("ugit/index.txt", "w");
    if (index) fclose(index);

    FILE *log_file = fopen("ugit/commits.log", "a");
    if (log_file) {
        time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);
        char fecha[64];
        strftime(fecha, sizeof(fecha), "%Y-%m-%d %H:%M:%S", tm_info);

        fprintf(log_file, "commit %d | Fecha: %s | Archivos: %d\n",
                commit_num, fecha, copied);

        fclose(log_file);
    }

    printf("Commit creado: %s (archivos copiados: %d)\n", commit_folder, copied);
}
