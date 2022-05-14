#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

int menu(int* respuesta)
{
	int ret = -1;
	int r;

	if(respuesta != NULL)
	{
		printf("\n1-ALTA MASCOTA\n");
		printf("2-MODIFICAR MASCOTA\n");
		printf("3-BAJA MASCOTA\n");
		printf("4-LISTAR MASCOTAS\n");
		printf("5-LISTAR TIPOS\n");
		printf("Ingrese una opcion: ");
		r = scanf("%d", respuesta);
		while(r==0 || *respuesta > 6)
		{
			printf("Error, reingrese una opcion valida: ");
			fflush(stdin);
			r = scanf("%d", respuesta);
		}
		ret=0;
	}
	return ret;
}
