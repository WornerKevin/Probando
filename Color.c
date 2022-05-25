#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Color.h"

eColor buscarColor(eColor color[],int tam,int id)
{
	eColor auxColor;

	if(color != NULL && tam > -1 && id > -1)
	{
		for(int i = 0; i<tam;i++)
		{
			if(color[i].id == id)
			{
				auxColor = color[i];
				list[i].idCliente = *idCliente;
			}
		}
	}
	return auxColor;
}
