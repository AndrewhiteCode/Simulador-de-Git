#include "ugit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <errno.h>

#define BUF_SIZE 8192

static void restaurar_commit(const char *commit_folder) {

    FILE *filelist = NULL;
    char path[512];

    sprintf(path, "%s\\filelist.txt", commit_folder);
    filelist = fopen(path, "r");

    if (!filelist) {
        printf("No se encontró listado de archivos en %s\n", commit_folder);
        return;
    }

    char filename[512];
    while (fgets(filename, sizeof(filename), filelist)) {
    
        size_t len = strlen(filename);
        if (len > 0 && (filename[len-1] == '\n' || filename[len-1] == '\r')) {
            filename[len-1] = '\0';
            len--;
        }
        if (len == 0) continue;

        char srcpath[1024];
        char destpath[1024];

        sprintf(srcpath, "%s\\%s", commit_folder, filename);
        sprintf(destpath, "%s", filename);  

        if (copiar_archivo(srcpath, destpath) == 0) {
            printf("Restaurado: %s\n", filename);
        } else {
            printf("Error restaurando: %s\n", filename);
        }
    }

    fclose(filelist);
}

void cmd_checkout(int commit_num) {
    char commit_folder[512];
    sprintf(commit_folder, "ugit\\commit%d", commit_num);

  
    if (_mkdir(commit_folder) == 0) {
        
        printf("El commit %d no existe.\n", commit_num);
        rmdir(commit_folder); 
        return;
    }

    printf("Restaurando commit %d...\n", commit_num);
    restaurar_commit(commit_folder);
    printf("Checkout de commit %d completado.\n", commit_num);
}
