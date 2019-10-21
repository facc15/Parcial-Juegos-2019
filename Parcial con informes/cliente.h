#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"

#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    char sexo;
    char telefono[20];
    char domicilio[50];

    int isEmpty;
}eCliente;



int menu(void);


void inicializarCliente(eCliente vec[], int tam);
int altaCliente(eCliente vec[], int tam,int idCli);
int altaClienteConId(eCliente vec[], int tam, eCliente auxL);
int buscarLibreCliente(eCliente vec[], int tam);
int buscarPorIdCliente(eCliente vec[],int leg, int tam);
int imprimirCliente(eCliente vec[],int tam);
void mostrarUnCliente(eCliente vec);
int hardCodearClienteConId(eCliente vec[],int tam);
int bajaCliente(eCliente vec[], int tam);
void ordenarClientes(eCliente vec[], int tam);
int modificaCliente(eCliente vec[], int tam);

#endif // CLIENTE_H_INCLUDED

