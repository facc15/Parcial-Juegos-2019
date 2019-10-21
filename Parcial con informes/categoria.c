#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "categoria.h"
#include "utn.h"


/** \brief  Imprime todas las categorias
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \return  nada
 *
 */
void imprimirCategorias(eCategoria vecC[], int tamC)
{
    system("cls");
    printf("**** Lista de Categorias *****\n\n");

    for(int i=0; i<tamC; i++)
    {
        mostrarCategoria(vecC[i]);
    }
    system("pause");
}

/** \brief  Imprime una categoria
 *
 * \param   Recibe un tipo estructura en una posicion
 * \return  nada
 *
 */
void mostrarCategoria(eCategoria vecC)
{
    printf("%5d %27s\n", vecC.id, vecC.descripcion);

}

/** \brief  Carga la descripcion de la categoria
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \param  un auxiliar char
 * \return  0 si funciono. -1 si no funciono
 *
 */
int cargarDescripcionCategoria(eCategoria vecC[],int tamC,int id,char descripcion[])
{
    int todoOk = 0;

    for(int i = 0;i<tamC;i++)
    {
        if(vecC[i].id == id)
        {
            strcpy(descripcion,vecC[i].descripcion);
            todoOk = 1;
            break;
        }
    }
    return todoOk;
}
