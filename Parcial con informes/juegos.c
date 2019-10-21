#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "juegos.h"


/** \brief  Imprime todos los juegos
 *
 * \param   Recibe el array de juego y su tamaño.
 * \return  0 si funciona. -1 si no.
 *
 */
int imprimirJuego(eJuego vec[],int tam)
{

   int flag=-1;
    printf("ID     Descripcion         importe\n");
    printf("--     ------              ----- \n\n");
    for(int i=0; i<tam; i++)
    {

        printf("%d    %14s       %2.f\n",vec[i].id,vec[i].descripcion,vec[i].importe);
            flag=0;


    }
    if (flag==-1)
    {
        system("cls");
        printf("\nNo hay juegos que mostrar\n");
    }
    return flag;
}


/** \brief  Imprime un juego
 *
 * \param   Recibe estructura tipo juego en una posicion.
 * \return  nada
 *
 */
void listarJuego(eJuego vecJ)
{
    printf("%d    %8s\n",vecJ.id,vecJ.descripcion);
}
