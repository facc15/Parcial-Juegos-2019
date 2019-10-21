#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "alquiler.h"
#include "juegos.h"

#ifndef ALQUILER_C_INCLUDED
#define ALQUILER_C_INCLUDED



/** \brief  Inicializa todos los alquilere en 1.
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \return  nada.
 *
 */
void inicializarAlquiler(eAlquiler vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}


/** \brief  Busca el espacio libre del alquiler
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \return  0 si funciono -1 si no.
 *
 */
int buscarLibreAlquiler(eAlquiler vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief  Busca el alquiler por ID.
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma  e id a buscar
 * \return  0 si funciono -1 si no.
 *
 */
int buscarPorIdAlquiler(eAlquiler vec[],int leg, int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].id == leg && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


/** \brief  Carga el array de alquiler
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \return  0 si funciono. -1 si no funciono.
 *
 */
int altaAlquiler(eAlquiler vec[], int tam,eJuego vecJ[],int tamJ,eCliente vecC[],int tamC,int idAlqui)
{
	eAlquiler auxL;
	int retorno = -1;
	eFecha fecha;

	printf("ALTA\n");
	if (buscarLibreAlquiler(vec, tam) == -1)
    {
		printf("ERROR,No hay mas lugar  para ingresar \n ");
	}
	else
    {
        imprimirJuego(vecJ,tamJ);
        if(getInt(&auxL.idJuego,"Ingrese id de juego: \n","Reingrese id de juego:\n",100,500,3)==0)
        {
        system("cls");

        imprimirCliente(vecC,tamC);
            if(getInt(&auxL.idCliente,"Ingrese id de cliente: \n","Reingrese id de cliente: \n",100,2000,3)==0)
            {


                if(getInt(&fecha.dia,"Ingrese dia: \n","Reingrese dia: \n",1,31,3)==0)
                {
                    if(getInt(&fecha.mes,"Ingrese mes: \n","Reingrese mes: \n",1,12,3)==0)
                    {
                        if(getInt(&fecha.anio,"Ingrese anio: \n","Reingrese anio: \n",2000,2050,3)==0)
                        {
                             auxL.id=idAlqui;
                             altaAlquilerConId(vec,tam,auxL,fecha);
                                printf("Alta exitosa\n");
                                retorno = 0;

                        }

                    }

                }

            }

        }
    }


    if (retorno != 0)
    {
        printf("Error al cargar los datos\n");
    }
    return retorno;
}

/** \brief  da de alta el alquiler
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma y un auxiliar
 * \return  0 si funciona, -1 si no 0.
 *
 */
int altaAlquilerConId(eAlquiler vec[], int tam, eAlquiler auxL,eFecha fecha)
{
	int retorno = -1;
	int index;
	if(vec!=NULL && tam>0){
		index = buscarLibreAlquiler(vec,tam);
		if(index>=0){
			vec[index] = auxL;
			vec[index].isEmpty = 0;
			vec[index].fecha=fecha;
			retorno = 0;
		}
	}
	return retorno;
}



/** \brief  Imprime todos los alquileres
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \return  0 si funciono. -1 si no funciono
 *
 */
int imprimirAlquiler(eAlquiler vec[],int tam,eJuego vecJ[],int tamJ,eCliente vecC[],int tamC)
{

   int flag=-1;
    printf("ID     JUEGO           NOMBRE      APELLIDO     FECHA DE ALQUILER\n");
    printf("--     ------          ------      --------     ----------------- \n\n");

   for(int i=0;i<tam;i++)
   {
       for(int j=0;j<tamJ;j++)
       {
           if(vec[i].idJuego==vecJ[j].id && vec[i].isEmpty==0)
           {
               for(int k=0;k<tamC;k++)
               {
                   if(vec[i].idCliente==vecC[k].id)
                   {
                       mostrarUnAlquiler(vec[i],vecJ[j],vecC[k]);
                       flag=0;
                   }
               }

           }
       }
   }

    if (flag==-1)
    {
        system("cls");
        printf("\nNo hay alquileres que mostrar\n");
    }
    return flag;
}



/** \brief  Imprime un solo alquiler
 *
 * \param   Recibe la Estructura en una posicion
 * \return  nada.
 *
 */
void mostrarUnAlquiler(eAlquiler vec,eJuego vecJ,eCliente vecC)
{
    if(vec.isEmpty==0 && vecC.isEmpty==0)
    {
    printf("%d   %10s   %9s %15s    %d/%d/%d\n",vec.id,vecJ.descripcion,vecC.nombre,vecC.apellido,vec.fecha.dia,vec.fecha.mes,vec.fecha.anio);

    }

}







#endif // ALQUILER_C_INCLUDED
