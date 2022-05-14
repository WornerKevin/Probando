#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Fecha.h"
#include "input.h"

int pedirFecha(int* dia, int* mes, int* anio)
{
    int ret = -1;
    int diaF;
    int mesF;
    int anioF;

    if(dia != NULL && mes != NULL && anio != NULL)
    {
        printf("\nIngrese el dia: ");
        scanf("%d", &diaF);
        while(diaF < 1 || diaF > 31)
        {
            printf("\nError. Ingrese el dia: ");
            scanf("%d", &diaF);
        }
        printf("\nIngrese el mes: %d/", diaF);
        scanf("%d", &mesF);
        while(mesF < 1 || mesF > 12)
        {
            printf("\nError. Ingrese el mes: %d/", diaF);
            scanf("%d", &mesF);
        }
        printf("\nIngrese el anio: %d/%d/", diaF,mesF);
        scanf("%d", &anioF);
        while(anioF < 1950 || anioF > 2022)
        {
            printf("\nError. Ingrese el anio: %d/%d/", diaF,mesF);
            scanf("%d", &anioF);
        }
        *dia = diaF;
        *mes = mesF;
        *anio = anioF;
        ret = 0;
    }

    return ret;
}
