#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Harcodeo.h"
#include "Mascota.h"
#include "Trabajo.h"

int hardcode(eMascota* list, int tamList, eTrabajo* vec, int* id, int* contador)
{
    int ret = -1;
    eMascota mascotaHarcodeada[] = {
        {0, "Chimi", 1003, 5000, 11, 's'},
        {0, "Pipi", 1003, 5001, 3, 'n'},
        {0, "Roco", 1003, 5002, 1, 'n'},
        {0, "Ema", 1001, 5002, 5, 's'},
        {0, "Copito", 1000, 5000, 1, 's'}
    };
    eTrabajo trabajoHarcodeado[] = {
        {0, 0, 20000,{11,10,2001}},
        {0, 1, 20001,{5,7,2010}},
        {0, 2, 20001,{5,7,2010}},
        {0, 3, 20002,{11,10,2001}},
        {0, 4, 20002,{11,10,2001}}
    };

    if(list != NULL && tamList > 0 && id != NULL)
    {
        for(int i=0; i < 5; i++)
        {
          list[i] = mascotaHarcodeada[i];
          vec[i] = trabajoHarcodeado[i];
          list[i].id = *id;
          vec[i].id = *id;
          *id = *id + 1;
          *contador = *contador +1;
        }
        ret = 0;
    }
    return ret;
}
