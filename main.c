#include <stdio.h>
#include <stdlib.h>

#define TAMLIST 10
#define TAMT 500
#define TAMTIPO 5
#define TAMCOLOR 5
#define TAMSERV 3

#include "menu.h"
#include "Tipo.h"
#include "Color.h"
#include "Servicio.h"
#include "Mascota.h"
#include "Trabajo.h"
#include "Harcodeo.h"

    eTipo tipos[TAMTIPO] = {
        {1000, "Ave"},
        {1001, "Perro"},
        {1002, "Roedor"},
        {1003, "Gato"},
        {1004, "Pez"}
        };

    eColor colores[TAMCOLOR] = {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Rojo"},
        {5003, "Gris"},
        {5004, "Azul"}
        };

    eServicio servicios[TAMSERV] = {
        {20000, "Corte", 450},
        {20001, "Desparacitado", 800},
        {20002, "Castrado", 600}
        };


int main()
{
    eMascota mascotas[TAMLIST];
    eTrabajo trabajos[TAMT];

    int opcion;
    int id = 0;
    int contadorMascotas = 0;
    initMascota(mascotas, TAMLIST); //INICIALIZO TODO EL ARRAY DE LA ESTRUCTURA MASCOTAS
    //hardcode(mascotas, TAMLIST, trabajos, &id, &contadorMascotas);
    printf("\n\t***BIENVENIDO AL PROGRAMA***\n");
    do
    {

       menu(&opcion);
        switch(opcion)
        {
            case 1:
                if(contadorMascotas < TAMLIST)
                {
                    AltaMascota(mascotas, TAMLIST, &id, trabajos);
                    contadorMascotas++;
                    system("pause");
                }
                else
                {
                    printf("\nNo hay lugar\n");
                }
            break;
            case 2:
                if(contadorMascotas > 0)
                {
                    modificarMascotas(mascotas, TAMLIST, trabajos, TAMT, tipos, TAMTIPO, colores, TAMCOLOR, servicios, TAMSERV);
                }
                else
                {
                    printf("\nNo se cargaron mascotas.");
                }

            break;
            case 3:
                if(contadorMascotas > 0)
                {
                    listarMascotas(mascotas, TAMLIST, trabajos, TAMT, tipos, TAMTIPO, colores, TAMCOLOR, servicios, TAMSERV);
                    EliminarMascota(mascotas, TAMLIST);
                    contadorMascotas--;
				}
				else
				{
					printf("No hay mascotas para eliminar\n");
				}
            break;
            case 4:
                if(contadorMascotas > 0)
                {
                    sortMascotas(mascotas, TAMLIST);
                    listarMascotas(mascotas, TAMLIST, trabajos, TAMT, tipos, TAMTIPO, colores, TAMCOLOR, servicios, TAMSERV);
                    system("pause");
                }
                    else
                    {
                        printf("\nNo hay mascotas cargadas.\n");
                    }
            break;
            case 5:
                if(contadorMascotas > 0)
                {
                    listarTipo(tipos, TAMTIPO, mascotas, TAMLIST);
                    system("pause");
                }
                    else
                    {
                        printf("\nNo hay mascotas cargadas.\n");
                    }
                break;
        }
    }while(opcion != 6);
    printf("\n\tSALISTE EXITOSAMENTE DEL PROGRAMA");
    return 0;
}
