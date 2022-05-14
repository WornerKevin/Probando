#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED
#include "Servicio.h"
#include "Fecha.h"
struct{
    int id;
    int idMascota;
    int idServicio;
    eFecha fecha;

}typedef eTrabajo;
eTrabajo buscarTrabajo(eTrabajo vec[],int tamT,int id);
#endif // TRABAJO_H_INCLUDED
