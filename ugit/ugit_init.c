#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void crear_versions() {

	//Si carpeta existe, copiar, sino, crearla y luego copiar
	if ( system( "mkdir versions" ) == 0 ) {
		printf("Carpeta 'versions' creada exitosamente. \n");
	} else {
		printf("La carpeta 'versions' ya existe. \n");
	}


}
