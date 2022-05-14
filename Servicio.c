#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Servicio.h"

eServicio buscarServicio(eServicio vecServ[],int tamServ,int id)
{
    eServicio auxServicio;

	if(vecServ != NULL && tamServ > -1 && id > -1)
	{
		for(int i = 0; i<tamServ;i++)
		{
			if(vecServ[i].id == id)
			{
				auxServicio = vecServ[i];
			}
		}
	}
	return auxServicio;
}
