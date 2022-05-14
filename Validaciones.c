#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"
#include "Validaciones.h"
int validacionVacuna(char* vacunado)
{
    int ret = -1;

    if(vacunado != NULL )
    {
        while(*vacunado != 's' && *vacunado != 'n')
        {
            getCharacter(vacunado, "\nError. ingrese una vacuna valida (s - n): ");
        }
        ret = 0;
    }
    return ret;
}
