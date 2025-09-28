/**
 * @file ugit_checkout.c
 * @brief Implementación del comando `checkout` de µGit.
 *
 * Contiene la lógica para restaurar (checkout) los archivos guardados en un
 * commit previo. Cada commit tiene un archivo `filelist.txt` dentro de su carpeta
 * (por ejemplo `ugit\commit1\filelist.txt`) que lista los nombres de los archivos
 * incluidos en ese commit. El proceso de checkout copia cada uno de esos archivos
 * desde la carpeta del commit al directorio de trabajo actual.
 *
 * @note Esta implementación asume commits sencillos (sin subcarpetas internas)
 *       y que `filelist.txt` existe dentro de cada `ugit\commitN\`.
 * @author Andres Barbosa , Ivan Gallardo , Luis Muñoz
 * @date 2025-09-28
 */

#include "ugit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include <errno.h>

#define BUF_SIZE 8192

/**
 * @brief Restaura todos los archivos listados en filelist.txt dentro del commit.
 *
 * Lee `commit_folder\filelist.txt` línea por línea y copia cada archivo listado
 * desde `commit_folder\<archivo>` hacia el directorio de trabajo (ruta simple:
 * `<archivo>`). Utiliza la función auxiliar `copiar_archivo` para realizar la
 * copia binaria.
 *
 * @param commit_folder Ruta a la carpeta del commit (ej: "ugit\\commit1").
 *
 * @return void
 *
 * @note
 * - Si `filelist.txt` no existe o no se puede abrir, la función imprime un
 *   mensaje de error y retorna sin realizar copias.
 * - Los saltos de línea CR/LF se eliminan antes de procesar cada entrada.
 * - Esta función NO crea carpetas destino; asume que los archivos se restauran
 *   en el directorio de trabajo actual.
 */
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

/**
 * @brief Realiza el checkout de un commit identificado por número.
 *
 * Construye la ruta `ugit\commit<commit_num>` y verifica su existencia.
 * Para comprobar existencia utiliza `_mkdir`: si la llamada a `_mkdir` tiene
 * éxito significa que la carpeta no existía (por lo tanto el commit no existe);
 * en ese caso elimina la carpeta temporal creada por `_mkdir` y reporta error.
 *
 * Si la carpeta existe, llama a `restaurar_commit()` para copiar los archivos
 * listados en `filelist.txt` hacia el directorio actual.
 *
 * @param commit_num Número del commit a restaurar (ej: 1 => ugit\commit1).
 *
 * @return void
 *
 * @note
 * - Este método de verificación (usar _mkdir para testear existencia) funciona
 *   pero puede parecer poco intuitivo; sin embargo mantiene la lógica previa
 *   sin modificar implementación original.
 * - Si el commit no existe o está incompleto (sin filelist.txt) se imprimirá
 *   un mensaje de error y no se realizará ninguna modificación en el directorio.
 * - Depende de la función `copiar_archivo` declarada en `ugit.h`.
 */
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
