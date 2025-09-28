#ifndef UGIT_H
#define UGIT_H

// Declaraciones de funciones
void cmd_init();
void cmd_add();
void cmd_commit();
void cmd_log();
void cmd_version();
void cmd_checkout(int commit_num);
void parse_command(int argc, char *argv[]);
int copiar_archivo(const char *origen, const char *destino);

#endif


