/**
 * @file ugit.h
 * @brief Cabecera pública de µGit: prototipos de comandos y utilidades.
 *
 * Este archivo declara las funciones públicas que implementan los comandos
 * principales del mini-sistema de control de versiones µGit (init, add, commit,
 * log, version, checkout) así como la función de routing parse_command y la
 * utilidad copiar_archivo que es reutilizada por varios módulos.
 *
 * Incluye guardias para evitar inclusiones múltiples.
 *
 * @author Andres Barbosa , Ivan Gallardo , Luis Muñoz
 * @date 2025-09-28
 */

#ifndef UGIT_H
#define UGIT_H

/**
 * @brief Inicializa el repositorio µGit.
 *
 * Crea la carpeta de trabajo (por ejemplo "ugit/") y los archivos base necesarios
 * (index.txt, commits.log). Debe poder llamarse varias veces sin provocar error
 * si el repositorio ya existe.
 */
void cmd_init();

/**
 * @brief Añade archivos al área de preparación (staging).
 *
 * Implementación típica: interactivo o con argumento para añadir uno o varios
 * archivos, y guarda los nombres en "ugit/index.txt".
 */
void cmd_add();

/**
 * @brief Crea un commit a partir de los archivos en staging.
 *
 * Comportamiento esperado:
 *  - Crea una carpeta de commit (p.ej. ugit/commitN).
 *  - Copia los archivos listados en ugit/index.txt a la carpeta del commit.
 *  - Registra el commit en ugit/commits.log y genera ugit/commitN/filelist.txt.
 */
void cmd_commit();

/**
 * @brief Muestra el historial de commits registrado.
 *
 * Normalmente lee y muestra el contenido de "ugit/commits.log".
 */
void cmd_log();

/**
 * @brief Muestra información o un listado simple del contenido de la carpeta ugit.
 *
 * Puede usarse para mostrar commits existentes, archivos en staging, etc.
 */
void cmd_version();

/**
 * @brief Restaura los archivos desde un commit identificado por número.
 *
 * @param commit_num Número del commit a restaurar (ej: 1 => ugit/commit1).
 *
 * @note La implementación actual espera que exista ugit/commit<commit_num>/filelist.txt
 *       con la lista de archivos a restaurar.
 */
void cmd_checkout(int commit_num);

/**
 * @brief Interpreta los argumentos de la línea de comandos y ejecuta el comando.
 *
 * @param argc Número de argumentos.
 * @param argv Vector de argumentos (argv[0] es el nombre del ejecutable).
 *
 * Ejemplo de uso: parse_command(argc, argv);
 */
void parse_command(int argc, char *argv[]);

/**
 * @brief Copia un archivo de origen a destino en modo binario.
 *
 * Utilidad reutilizable por commit, checkout y otras operaciones que necesiten
 * duplicar archivos byte-a-byte.
 *
 * @param origen Ruta del archivo fuente.
 * @param destino Ruta del archivo destino (se crea/reescribe).
 * @return int Devuelve 0 si la copia fue exitosa, -1 en caso de error.
 */
int copiar_archivo(const char *origen, const char *destino);

#endif // UGIT_H
