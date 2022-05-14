#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Trabajo.h"
#include "Mascota.h"
#include "Tipo.h"
#include "input.h"

eTrabajo buscarTrabajo(eTrabajo vec[],int tamT,int id)
{
	eTrabajo auxTrabajo;

	if(vec != NULL && tamT > -1 && id > -1)
	{
		for(int i = 0 ; i<tamT ; i++)
		{
			if(vec[i].id == id)
			{
				auxTrabajo = vec[i];
			}
		}
	}
	return auxTrabajo;
}
/*int cargarDescripcionTrabajo(eTrabajo vec[], int tam, int id, char descripcion[])
{
    int ret = -1;
    int indice;

    buscarTrabajo(vec,tam, id,&indice);

    if(descripcion != NULL && indice != -1 )
    {
       strcpy(descripcion, vec[indice].idServicio);
       ret = 0;
    }
  return ret;
}*/
