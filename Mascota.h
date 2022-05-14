#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED
#include "Trabajo.h"
#include "Servicio.h"
#include "Tipo.h"
#include "Color.h"
struct{
    int id;
    char nombre[21];
    int idTipo;
    int idColor;
    int edad;
    char vacunado;
    int isEmpty;
}typedef eMascota;

/* FUNCIONES ABM*/
int initMascota(eMascota* list, int tam);
int buscarLibreMascota(eMascota list[],int tam);
int buscarMascota(eMascota list[],int tam, int id);
int addMascota(eMascota* list,eTrabajo* vec,int tamMasc,int* id,int idTipo,int idColor,char nombre[],int edad,char vacunado,int idServicio,int dia,int mes,int anio);
int AltaMascota(eMascota* list, int tamMasc, int* id, eTrabajo* vec);
int removeMascota(eMascota* list, int tam, int id);
int EliminarMascota(eMascota* list, int tam);
int modificarMascotas(eMascota* list,int tam, eTrabajo* vec,int tamT,eTipo vecTipo[],int tamTipo,eColor vecColor[],int tamColor,eServicio vecServ[],int tamServ);
int sortMascotas(eMascota* list, int tam);
/* FUNCIONES LISTAR */
int printMascota(eMascota list, int tam,eTrabajo vec[],int tamT,eTipo vecTipo[],int tamTipo,eColor vecColor[],int tamColor,eServicio vecServ[],int tamServ);
int listarMascotas(eMascota list[],int tam, eTrabajo vec[],int tamT,eTipo vecTipo[],int tamTipo,eColor vecColor[],int tamColor,eServicio vecServ[],int tamServ);

#endif // MASCOTA_H_INCLUDED
