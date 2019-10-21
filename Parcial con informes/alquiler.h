#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "juegos.h"

#ifndef ALQUILER_H_INCLUDED
#define ALQUILER_H_INCLUDED




typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int id;
    int idJuego;
    int idCliente;
    eFecha fecha;
    int isEmpty;
}eAlquiler;






void inicializarAlquiler(eAlquiler vec[], int tam);
int altaAlquiler(eAlquiler vec[], int tam,eJuego vecJ[],int tamJ,eCliente vecC[],int tamC,int idAlqui);
int buscarLibreAlquiler(eAlquiler vec[], int tam);
int buscarPorIdAlquiler(eAlquiler vec[],int leg, int tam);
int altaAlquilerConId(eAlquiler vec[], int tam, eAlquiler auxL,eFecha fecha);
int imprimirAlquiler(eAlquiler vec[],int tam,eJuego vecJ[],int tamJ,eCliente vecC[],int tamC);
void mostrarUnAlquiler(eAlquiler vec,eJuego vecJ,eCliente vecC);





#endif // ALQUILER_H_INCLUDED






