#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

struct{
    int id;
    char descripcion[26];
    float precio;

}typedef eServicio;

eServicio buscarServicio(eServicio vecServ[],int tamServ,int id);

#endif // SERVICIO_H_INCLUDED
