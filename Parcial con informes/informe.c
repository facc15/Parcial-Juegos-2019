
#include <stdio.h>
#include <stdlib.h>
#include "informe.h"
#include "utn.h"
#include "cliente.h"
#include "alquiler.h"
#include "categoria.h"
#include "juegos.h"

#ifndef INFORME_C_INCLUDED
#define INFORME_C_INCLUDED


/** \brief  Menu de informes
 *

 * \return  Retorna la opcion elegida.
 *
 */
int menuInforme()
{
    int option;




    printf("***INFORMES***\n\n\n\n");
    printf("1.Mostrar juegos de categoria de mesa \n");
    printf("2.Mostrar alquileres efectuados por algun cliente  \n");
    printf("3.Mostrar el total de todos los importes pagados por cliente seleccionado \n");
    printf("4.Listar los clientes que no alquilaron juegos\n");
    printf("5.Listar juegos que no han sido alquilados \n");
    printf("6.\n");
    printf("7.\n");
    getInt(&option,"Ingrese opcion\n","Reingrese opcion\n",1,15,3);

    return option;

}

/** \brief  Imprime todos los juegos de mesa
 *
 * \param   Recibe el array de juego y su tamaño.
 * \param   Recibe el array de categoria y su tamaño.
 * \return  0 si funciono. -1 si no funciono
 *
 */
int mostrarJuegosMesa(eJuego vec[],int tamJ,eCategoria vecC[],int tamCa)
{
    char descripcion[20];
    printf("Juegos de mesa\n");
    printf("--------------\n\n");
    for(int i=0;i<tamJ;i++)
    {
        for(int j=0;j<tamCa;j++)
        {
            if(vec[i].idCategoria==vecC[j].id)
            {
                cargarDescripcionCategoria(vecC,tamCa,vec[i].idCategoria,descripcion);

                if(strcmp(descripcion,"mesa")==0)
                {
                    mostrarUnJuegoMesa(vec[i],vecC,tamCa);
                }
            }
        }




    }

    return 0;
}



/** \brief  Imprime un juego de mesa
 *
 * \param   Recibe tipo estructura en una posicion
 * \param   Recibe el array de categoria y su tamaño.
 * \return  nada
 *
 */
void mostrarUnJuegoMesa(eJuego vec,eCategoria vecC[],int tamCa)
{
    char descripcion[20];


    cargarDescripcionCategoria(vecC,tamCa,vec.id,descripcion);

    printf("%d   %s    %s\n",vec.id,vec.descripcion,descripcion);
}



/** \brief  Imprime todos los alquileres de un cliente seleccionado
 *
 * \param   Recibe el array de alquiler y su tamaño.
 * \param   Recibe el array de cliente y su tamaño.
 * \param   Recibe el array de juego y su tamaño.
 * \return  nada
 *
 */
void mostrarAlquileresPorCliente(eAlquiler vecA[],int tamA,eCliente vecC[],int tamC,eJuego vecJ[],int tamJ)
{
    int idCli;

    imprimirCliente(vecC,tamC);

    getInt(&idCli,"Ingrese cliente \n","Reingrese cliente\n",100,110,3);
    system("cls");


    for(int i=0;i<tamC;i++)
    {
        if(vecC[i].id==idCli)
        {
            mostrarUnCliente(vecC[i]);
        }
    }
    printf("\nLISTA DE ALQUILERES\n");
    printf("----------------\n");
    for(int i=0;i<tamA;i++)
    {
        if(vecA[i].isEmpty==0 && vecA[i].idCliente==idCli)
        {
            for(int j=0;j<tamJ;j++)
            {
                if(vecA[i].idJuego== vecJ[j].id)
                {
                    mostrarAlquilerPorCliente(vecA[i],vecJ[j]);

                }
            }


        }
    }




}


/** \brief  Imprime un alquiler de un cliente seleccionado
 *
 * \param   Recibe estructura de alquiler en una posicion
 * \param   Recibe estructura de juego en una posicion
 * \return  nada
 *
 */
void mostrarAlquilerPorCliente(eAlquiler vecA,eJuego vecJ)
{

   printf("%d  %8s  %d/%d/%d   \n",vecA.id,vecJ.descripcion,vecA.fecha.dia,vecA.fecha.mes,vecA.fecha.anio);

}


/** \brief  Imprime todos los importes de un cliente seleccionado
 *
 * \param   Recibe el array de alquiler y su tamaño.
 * \param   Recibe el array de cliente y su tamaño.
 * \param   Recibe el array de juego y su tamaño.
 * \return  nada
 *
 */
void mostrarImportesPorCliente(eAlquiler vecA[],int tamA,eCliente vecC[],int tamC,eJuego vecJ[],int tamJ)
{
    int total=0;
    int idCli;
    int index;

    imprimirCliente(vecC,tamC);
    getInt(&idCli,"Ingrese cliente: \n","Reingrese cliente: \n",100,130,3);

    index=buscarPorIdCliente(vecC,idCli,tamC);


    if(index==-1)
    {
        printf("no hay lugar\n");

    }
    else
    {
        for(int i=0;i<tamA;i++)
        {
            if(vecA[i].idCliente==idCli && vecA[i].isEmpty==0)
            {
                for(int j=0;j<tamJ;j++)
                {
                    if(vecA[i].idJuego==vecJ[j].id)
                    {
                        total=total+vecJ[j].importe;
                    }
                }
            }
        }
    }
    printf("el importe total del cliente es %d\n",total);

}

/** \brief  Imprime los clientes que no alquilaron
 *
 * \param   Recibe el array de alquiler y su tamaño.
 * \param   Recibe el array de cliente y su tamaño.
 * \return  nada
 *
 */
void listarClientesQueNoAlquilaron(eCliente vecC[],int tamC,eAlquiler vecA[],int tamA)
{
    printf("***Clientes sin alquilar***\n\n");
    printf("ID     Apellido   Nombre \n");
    printf("--     -----      ------  \n\n");

    for(int i=0;i<tamC;i++)
    {
        if(vecC[i].isEmpty==0)
        {
            if(tienePedidoAlquiler(vecC[i].id,vecA,tamA)==0)
            {
                mostrarUnCliente(vecC[i]);
            }

        }

    }

}

/** \brief  anida el id ingresado con el array ingresado
 *
 * \param   Recibe el array de alquiler y su tamaño.
 * \param   Recibe id.
 * \return  1 si alquilaron. 0 si no alquilaron.
 *
 */
int tienePedidoAlquiler(int id,eAlquiler vecA[],int tamA)
{

    for(int i=0;i<tamA;i++)
    {
        if(vecA[i].idCliente==id)
        {
            return 1;
        }
    }
    return 0;
}



/** \brief  Imprime todos los juegos sin alquilar
 *
 * \param   Recibe el array de alquiler y su tamaño.
 * \param   Recibe el array de juego y su tamaño.
 * \return  nada
 *
 */
void listarJuegosSinAlquilar(eJuego vecJ[],int tamJ,eAlquiler vecA[],int tamA)
{
    printf("***Juegos sin alquilar***\n\n");
    printf("ID        JUEGO\n");
    printf("--        -----\n\n");

    for(int i=0;i<tamJ;i++)
    {
        if(tienePedidoJuego(vecJ[i].id,vecA,tamA)==0)
        {
            listarJuego(vecJ[i]);
        }
    }
}

/** \brief  Anida el array con el id ingresado
 *
 * \param   Recibe el array de alquiler y su tamaño.
 * \param   Recibe el id.
 * \return  1 si esta alquilado. 0 si no esta alquilado.
 *
 */
int tienePedidoJuego(int id,eAlquiler vecA[],int tamA)
{

    for(int i=0;i<tamA;i++)
    {
        if(vecA[i].idJuego==id)
        {
            return 1;
        }
    }
    return 0;
}






//podrian TOMARLOOOOOOO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void listarClientesXAlquileres(eCliente vecC[],int tamC,eAlquiler vecA[],int tamA)
{
    int contador=0;

    for(int i=0;i<tamC;i++)
    {
        if(vecC[i].isEmpty==0)
        {
            contador=tieneMayorAlquiler(vecC[i].id,vecA,tamA);
        }
        if(contador>3)
        {
            mostrarUnCliente(vecC[i]);
        }

    }

}

void listarClientesConMasAlquileres(eCliente vecC[],int tamC,eAlquiler vecA[],int tamA)
{
    int contador[tamC];
    int flag=0;
    int mayor=0;
    printf("***Cliente con mas alquileres***\n\n");
    printf("ID    Apellido    Nombre\n");
    printf("--    ------      ------\n");

    for(int i=0;i<tamC;i++)
    {
        if(vecC[i].isEmpty==0)
        {
            contador[i]=tieneMayorAlquiler(vecC[i].id,vecA,tamA);

                if(mayor<contador[i] || flag==0)
                {
                    mayor=contador[i];
                    flag=1;
                }

        }

    }

    for(int i=0;i<tamC;i++)
    {
        if(mayor==contador[i])
        {
              mostrarUnCliente(vecC[i]);

        }
    }

}



int tieneMayorAlquiler(int id,eAlquiler vecA[],int tamA)
{
    int contador=0;

    for(int i=0;i<tamA;i++)
    {
        if(vecA[i].isEmpty==0 && vecA[i].idCliente==id)
        {
            contador++;
        }
    }

    return contador;
}

//azar
void listarMujeresQueAlquilaronJuegos(eCliente vecC[],int tamC,eAlquiler vecA[],int tamA,eJuego vecJ[],int tamJ,
                                      eCategoria vecCa[],int tamCa)
{
    printf("Mujeres con juegos de azar\n\n\n");
    for(int i=0;i<tamC;i++)
    {
        for(int j=0;j<tamA;j++)
        {
            if(vecC[i].isEmpty==0 && vecC[i].id==vecA[j].idCliente && vecC[i].sexo=='f')
            {
                for(int k=0;k<tamJ;k++)
                {
                    if(vecJ[k].id==vecA[j].idJuego)
                    {
                        for(int f=0;f<tamCa;f++)
                        {
                            if(vecJ[k].idCategoria==vecCa[f].id)
                            {
                                if(vecCa[f].id==11)
                                {
                                    mostrarMujeresConJuegos(vecC[i],vecCa[f],vecJ[k]);
                                }
                            }
                        }


                    }
                }
            }
        }
    }

}

void mostrarMujeresConJuegos(eCliente vecC,eCategoria vecCa,eJuego vecJ)
{
    printf("%s     %s    %s     %s\n",vecC.nombre,vecC.apellido,vecJ.descripcion,vecCa.descripcion);


}



void listarClientesPorFecha(eCliente vecC[],int tamC,eAlquiler vecA[],int tamA)
{
    eAlquiler auxL;
    int index;

    getInt(&auxL.fecha.dia,"Ingrese dia: \n","Reingrese dia: \n",1,31,3);
    getInt(&auxL.fecha.mes,"Ingrese mes: \n","Reingrese mes: \n",1,12,3);
    getInt(&auxL.fecha.anio,"Ingrese anio: \n","Reingrese anio: \n",2000,2019,3);

    index=buscarPorFechaAlquiler(vecA,auxL,tamA);

    if(index==-1)
    {
        printf("No hay alquileres\n");
    }
    else
    {
        printf("ID    APELLIDO    NOMBRE\n");
        printf("--    --------   ------- \n");
        for(int i=0;i<tamC;i++)
        {
            if(vecC[i].id==vecA[index].idCliente)
            {
                mostrarUnCliente(vecC[i]);
            }
        }


    }

}

int buscarPorFechaAlquiler(eAlquiler vec[],eAlquiler auxL, int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].fecha.anio == auxL.fecha.anio &&
           vec[i].fecha.mes==auxL.fecha.mes &&
           vec[i].fecha.dia==auxL.fecha.dia)
        {
            indice = i;
            break;
        }
    }
    return indice;
}






#endif // INFORME_C_INCLUDED
