#include "ugit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cmd_init() {
	if (system("mkdir .ugit") == 0) {
		printf("Carpeta '.ugit' creada exitosamente.\n");

		if (system("touch .ugit/add.txt") == 0) {
			printf("Archivo 'add.txt' creado exitosamente.\n");
		} else {
			printf("Error al crear el archivo 'add.txt'.\n");
		}

		if (system("mkdir .ugit/versions") == 0) {
			printf("Carpeta '.ugit/versions' creada exitosamente.\n");
		} else {
			printf("Error al crear la carpeta '.ugit/versions'.\n");
		}
	} else {
		printf("La carpeta '.ugit' ya existe.\n");
	}
}
