#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Mascota.h"
#include "Trabajo.h"
#include "Servicio.h"
#include "Tipo.h"
#include "Color.h"

#include "input.h"

#include "Fecha.h"

#include "Validaciones.h"

int initMascota(eMascota* list, int tam)
{
    int ret = -1;
    if(list != NULL && tam > 0)
    {
		for(int i=0; i<tam; i++)
		{
			list[i].id = -1;
			list[i].isEmpty = 1;
		}
        ret = 0;
    }
    return ret;
}
int buscarLibreMascota(eMascota list[],int tam)
{
	int ret= -1;

	if(list != NULL && tam > 0)
	{
		for(int i = 0; i < tam ;i++)
		{
			if(list[i].isEmpty == 1)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}

int buscarMascota(eMascota list[],int tam, int id)
{
	int ret= -1;

	if(list != NULL && tam > 0)
	{
		for(int i = 0; i < tam ;i++)
		{
			if(list[i].isEmpty == 0 && list[i].id == id)
			{
				ret = i;
				break;
			}
		}
	}
	return ret;
}

int addMascota(eMascota* list, eTrabajo* vec,int tamMasc,int* id,int idTipo,int idColor,char nombre[],int edad,char vacunado,int idServicio,int dia,int mes,int anio)
{
    int ret = -1;
    int i;
    if(list != NULL && id != NULL && tamMasc > 0)
    {
        i =buscarLibreMascota(list,tamMasc);
        if(i != -1)
        {
            list[i].id = *id;
            list[i].idTipo = idTipo;
            list[i].idColor = idColor;
            list[i].edad = edad;
            list[i].vacunado = vacunado;
            strcpy(list[i].nombre, nombre);
            vec[i].idServicio = idServicio;
            vec[i].idMascota = *id;
            vec[i].fecha.dia = dia;
            vec[i].fecha.mes = mes;
            vec[i].fecha.anio = anio;

            list[i].isEmpty = 0;
            ret = 0;
        }

    }
    return ret;
}
int AltaMascota(eMascota* list, int tamMasc, int* id, eTrabajo* vec)
{
    int ret = -1;

    int idTipo;
    int idColor;
    char vacunado;
    char nombre[21];
    int edad;

    int idServicio;
    int dia;
    int mes;
    int anio;

    if(list != NULL && tamMasc> 0)
    {
        printf("\nID = %d\n", *id);
        getString(nombre, "\nIngrese el nombre: ", "\nError. Vuelva a ingresar el nombre: ", 20);
        getInteger(&idTipo,"\n1000-Ave\n1001-Perro\n1002-Roedor\n1003-Gato\n1004-Pez\nIngrese el tipo: ",
                   "\nError. Vuelva a ingresar el tipo: ", 1000, 1004);
        getInteger(&idColor, "\n5000-Negro\n5001-Blanco\n5002-Rojo\n5003-Gris\n5004-Azul\nIngrese el color: ",
                    "\nError. Vuelva a ingresar el color: ", 5000, 5004);
        getCharacter(&vacunado, "\nIngrese si esta vacunado(s o n): ");
        validacionVacuna(&vacunado);
        getInteger(&edad, "\nIngrese la edad: ", "\nError. Vuelva a ingresar una edad valida", 1, 50);
        getInteger(&idServicio, "\n20000-Corte $450\n20001-Desparacitado $800\n20002-Castrado $600\nIngrese el servicio: ",
                    "\nError. Vuelva a ingresar el servicio: ", 20000, 20002);
        pedirFecha(&dia, &mes, &anio);
        addMascota(list, vec, tamMasc, id, idTipo, idColor, nombre,edad, vacunado, idServicio, dia, mes, anio);
        *id = *id + 1;
        printf("\nSe creo Exitosamente.\n");
        ret = 0;
    }
    return ret;
}

int printMascota(eMascota list, int tam, eTrabajo vec[],int tamT,eTipo vecTipo[],int tamTipo,eColor vecColor[],int tamColor,eServicio vecServ[],int tamServ)
{
	eTipo auxTipo;
	eColor auxColor;
	eServicio auxServicio;
	if(vec != NULL && vecTipo != NULL && vecColor != NULL && vecServ != NULL)
    {
		auxTipo = buscarTipo(vecTipo, tamTipo, list.idTipo);
		auxColor = buscarColor(vecColor,tamColor, list.idColor);
		auxServicio = buscarServicio( vecServ, tamServ, vec->idServicio);

        printf("%2d  \t|%10s\t|   %10s   |   %9s  |  %2d           |  %c            | %2d/%2d/%2d     |   %10s\n",
                list.id,
                list.nombre,
                auxTipo.descripcion,
                auxColor.nombreColor,
                list.edad,
                list.vacunado,
                vec->fecha.dia, vec->fecha.mes, vec->fecha.anio,
                auxServicio.descripcion);
    }

	return 0;
}
int listarMascotas(eMascota list[],int tam, eTrabajo vec[],int tamT,eTipo vecTipo[],int tamTipo,eColor vecColor[],int tamColor,eServicio vecServ[],int tamServ)
{
    int ret = -1;
    if(list != NULL && tam > 0)
    {
        system("cls");
        printf("ID\t|   Nombre \t|   Tipo  \t|   Color \t|  Edad \t|   Vacunado \t| \tFecha\t |  Servicio|\n");
        printf("--------|---------------|---------------|---------------|---------------|---------------|----------------|-----------|\n");
        for(int i=0; i < tam; i++)
        {
            if( !list[i].isEmpty )
            {
               printMascota(list[i], tam ,vec,tamT,vecTipo,tamTipo,vecColor,tamColor,vecServ,tamServ);
            }
        }
        printf("\n\n");

        ret = 0;
    }
    return ret;
}
int removeMascota(eMascota* list, int tam, int id)
{
    int ret = -1;

    if(list != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(list[i].id == id)
            {
                list[i].isEmpty = 1;
                ret = 0;
                break;
            }
        }
    }

    return ret;
}
int EliminarMascota(eMascota* list, int tam)
{
    int ret = -1;
    int id;
    int i = -1;
    if(list != NULL && tam > 0)
    {
        printf("\nIngrese el ID de la Mascota que desea eliminar: ");
        scanf("%d", &id);
        i = removeMascota(list, tam, id);
        if(i == 0)
        {
            printf("\nMascota eliminada correctamente.");
            ret = 0;
        }
            else
            {
                printf("ERROR. El ID ingresado no existe.");
            }



    }
    return ret;
}
int modificarMascotas(eMascota* list,int tam, eTrabajo* vec,int tamT,eTipo vecTipo[],int tamTipo,eColor vecColor[],int tamColor,eServicio vecServ[],int tamServ)
{
    eMascota mascotaModificada;
    //eTrabajo trabajoModificado;
    int ret = -1;
    int id;
    int opcion;
    int i = -1;

    if(list != NULL && tam > 0)
    {
        listarMascotas(list, tam, vec, tamT,vecTipo, tamTipo, vecColor, tamColor, vecServ, tamServ);
        printf("\nIngrese el numero de ID de la Mascota: ");
        scanf("%d", &id);
        i = buscarMascota(list, tam, id);
        if(i != -1)
        {
            mascotaModificada = list[i];
            //trabajoModificado = vec[i];
            printf("\nID = %d\n", id);
            /*getInteger(&opcion, "\nMODIFICAR:\n1-Nombre\n2-Tipo\n3-Color\n4-Vacunado\n5-Edad\n6-Fecha\n7-Servicio\nIngrese la opcion: ",
                       "\nError, ingrese una opcion valida: ", 1, 7);*/
            getInteger(&opcion, "\nMODIFICAR:\n1-Tipo\n2-Vacunado\n3-Atras\nIngrese la opcion: ",
                       "\nError, ingrese una opcion valida: ", 1,3);
            switch(opcion)
            {
                case 1:
                    getInteger(&mascotaModificada.idTipo,"\n1000-Ave\n1001-Perro\n1002-Roedor\n1003-Gato\n1004-Pez\nIngrese el tipo: ",
                   "\nError. Vuelva a ingresar el tipo: ", 1000, 1004);
                break;
                case 2:
                    getCharacter(&mascotaModificada.vacunado, "\nIngrese si esta vacunado(s o n): ");
                    break;
                case 3:
                    system("pause");
                    break;
                /*case 1:
                    getString(mascotaModificada.nombre, "\nIngrese el nombre: ", "\nError. Vuelva a ingresar el nombre: ", 20);
                    break;
                case 2:
                    getInteger(&mascotaModificada.idTipo,"\n1000-Ave\n1001-Perro\n1002-Roedor\n1003-Gato\n1004-Pez\nIngrese el tipo: ",
                   "\nError. Vuelva a ingresar el tipo: ", 1000, 1004);
                    break;
                case 3:
                    getInteger(&mascotaModificada.idColor, "\n5000-Negro\n5001-Blanco\n5002-Rojo\n5003-Gris\n5004-Azul\nIngrese el color: ",
                    "\nError. Vuelva a ingresar el color: ", 5000, 5004);
                    break;
                case 4:
                    getCharacter(&mascotaModificada.vacunado, "\nIngrese si esta vacunado(s o n): ");
                    break;
                case 5:
                    getInteger(&mascotaModificada.edad, "\nIngrese la edad: ", "\nError. Vuelva a ingresar una edad valida", 1, 50);
                    break;
                case 6:
                    getInteger(&trabajoModificado.idServicio, "\n20000-Corte $450\n20001-Desparacitado $800\n20002-Castrado $600\nIngrese el servicio: ",
                    "\nError. Vuelva a ingresar el servicio: ", 20000, 20002);
                    break;
                case 7:
                    getInteger(&trabajoModificado.fecha.dia,"Ingrese dia: \n","Error.Reingrese dia: \n",1,31);
                    getInteger(&trabajoModificado.fecha.mes,"Ingrese mes: \n","Error.Reingrese mes: \n",1,12);
                    getInteger(&trabajoModificado.fecha.anio,"Ingrese anio: \n","Error.Reingrese anio: \n",1950,2022);
                    break;*/
            }
            if(opcion != 3)
            {
                list[i] = mascotaModificada;
                //vec[i] = trabajoModificado;
                printf("\nSe modifico Exitosamente.\n");
                ret = 0;
            }

        }
        else
        {
            printf("\nError. El ID ingresado no existe.\n");
        }
    }
        return ret;
}

int sortMascotas(eMascota* list, int tam)
{
    int ret = -1;
    eMascota aux;
    int j;
    int i;
    if(list != NULL && tam > 0)
    {
        for(i = 0; i < tam -1; i++)
        {
            for(j = i+1; j < tam; j++)
            {
                if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    if((list[i].idTipo == list[j].idTipo && strcmp(list[i].nombre, list[j].nombre)== 1 )|| list[i].idTipo > list[j].idTipo)
                    {
                        aux = list[i];
                        list[i] = list[j];
                        list[j] = aux;
                    }
                }
            }
        }
        ret = 0;
    }
    return ret;
}
