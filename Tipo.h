#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

#include "Mascota.h"

struct{
    int id;
    char descripcion[21];

}typedef eTipo;

eTipo buscarTipo(eTipo tipo[],int tamTipo,int id);
int listarTipoMascota(eTipo list[],int tam, eMascota vec[], int tamM);

#endif // TIPO_H_INCLUDED
