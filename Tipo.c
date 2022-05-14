#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Mascota.h"
#include "Tipo.h"
#include "input.h"

eTipo buscarTipo(eTipo tipo[],int tamTipo,int id)
{
	eTipo auxTipo;

	if(tipo != NULL && tamTipo > -1 && id > -1)
	{
		for(int i = 0; i<tamTipo;i++)
		{
			if(tipo[i].id == id)
			{
				auxTipo = tipo[i];
			}
		}
	}
	return auxTipo;
}
int listarTipoMascota(eTipo list[],int tam, eMascota vec[], int tamM)
{
	int ret = -1;
	eTipo auxTipo;

	if(list != NULL && tam > 0 && tamM > 0 && vec != NULL)
	{
		printf("ID     |     TIPO");
		for(int i=0;i<tam;i++)
		{

			if(vec[i].isEmpty == 0)
			{
				auxTipo = buscarTipo(list, tam, vec[i].idTipo);
				printf("\n %2d   | %20s\n",
				vec[i].idTipo,
				auxTipo.descripcion);

			}
		}
		ret= 0;
	}

	return ret;
}
