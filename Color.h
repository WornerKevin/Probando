#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

struct{
    int id;
    char nombreColor[21];

}typedef eColor;

eColor buscarColor(eColor color[],int tam,int id);
#endif // COLOR_H_INCLUDED
