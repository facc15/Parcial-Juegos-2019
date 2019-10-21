
#ifndef JUEGOS_H_INCLUDED
#define JUEGOS_H_INCLUDED

#include "categoria.h"

typedef struct
{
    int id;
    char descripcion[50];
    float importe;
    int idCategoria;

}eJuego;


int imprimirJuego(eJuego vec[],int tam);
void listarJuego(eJuego vecJ);






#endif // JUEGOS_H_INCLUDED
