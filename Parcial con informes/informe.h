#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "alquiler.h"
#include "cliente.h"

#ifndef INFORME_H_INCLUDED
#define INFORME_H_INCLUDED




int menuInforme(void);
int mostrarJuegosMesa(eJuego vec[],int tamJ,eCategoria vecC[],int tamCa);
void mostrarUnJuegoMesa(eJuego vec,eCategoria vecC[],int tamCa);

void mostrarAlquileresPorCliente(eAlquiler vecA[],int tamA,eCliente vecC[],int tamC,eJuego vecJ[],int tamJ);
void mostrarAlquilerPorCliente(eAlquiler vecA,eJuego vecJ);

void mostrarImportesPorCliente(eAlquiler vecA[],int tamA,eCliente vecC[],int tamC,eJuego vecJ[],int tamJ);

void listarClientesQueNoAlquilaron(eCliente vecC[],int tamC,eAlquiler vecA[],int tamA);
void listarJuegosSinAlquilar(eJuego vecJ[],int tamJ,eAlquiler vecA[],int tamA);

int tienePedidoAlquiler(int id,eAlquiler vecA[],int tamA);
int tienePedidoJuego(int id,eAlquiler vecA[],int tamA);







void listarClientesXAlquileres(eCliente vecC[],int tamC,eAlquiler vecA[],int tamA);
int tieneMayorAlquiler(int id,eAlquiler vecA[],int tamA);

void listarClientesConMasAlquileres(eCliente vecC[],int tamC,eAlquiler vecA[],int tamA);



void mostrarMujeresConJuegos(eCliente vecC,eCategoria vecCa,eJuego vecJ);
void listarMujeresQueAlquilaronJuegos(eCliente vecC[],int tamC,eAlquiler vecA[],int tamA,eJuego vecJ[],int tamJ,
                                      eCategoria vecCa[],int tamCa);



 void listarClientesPorFecha(eCliente vecC[],int tamC,eAlquiler vecA[],int tamA);
 int buscarPorFechaAlquiler(eAlquiler vec[],eAlquiler auxL, int tam);












#endif // INFORME_H_INCLUDED
