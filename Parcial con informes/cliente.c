#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "juegos.h"

#ifndef CLIENTE_C_INCLUDED
#define CLIENTE_C_INCLUDED



/** \brief  Inicializa todos los clientes en 1.
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \return  nada.
 *
 */
void inicializarCliente(eCliente vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}


/** \brief  Menu de opciones
 *

 * \return  Retorna la opcion elegida.
 *
 */
int menu()
{
    int option;




    printf("***CLIENTES***\n\n\n\n");
    printf("1.Alta \n");
    printf("2.Modificar \n");
    printf("3.Baja \n");
    printf("4.Listar clientes ordenados \n");
    printf("5.Alta de alquiler \n");
    printf("6.Listar alquileres\n");
    printf("7.Informes\n");
    getInt(&option,"Ingrese opcion\n","Reingrese opcion\n",1,9,3);

    return option;

}

/** \brief  Busca el espacio libre del cliente
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \return  0 si funciono -1 si no.
 *
 */
int buscarLibreCliente(eCliente vec[], int tam)
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

/** \brief  Busca el cliente por ID.
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma  e id a buscar
 * \return  0 si funciono -1 si no.
 *
 */
int buscarPorIdCliente(eCliente vec[],int leg, int tam)
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


/** \brief  Carga el array de cliente
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \return  0 si funciono. -1 si no funciono.
 *
 */
int altaCliente(eCliente vec[], int tam,int idCli)
{
	eCliente auxL;
	int retorno = -1;
	printf("ALTA\n");
	if (buscarLibreCliente(vec, tam) == -1)
    {
		printf("ERROR,No hay mas lugar  para ingresar \n ");
	}
	else
    {
		if (getNameOrLastName(auxL.nombre, "Ingrese nombre\n", "Error\n", 0, 50, 3)!= -1)
        {
			if (getNameOrLastName(auxL.apellido, "Ingrese apellido\n", "Error\n", 0,50, 3) == 0)
            {

               if( getChar(&auxL.sexo, "Ingrese el sexo: \n", "Error. Reingrese f o m: \n", 'f', 'm',3)==0)
               {
                 if(getPhone(auxL.telefono,"Ingrese telefono: \n","Reingrese telefono: \n",8,14,3)==0)
                 {
                     auxL.id=idCli;

                        if (altaClienteConId(vec,tam,auxL)== 0)
                        {
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

/** \brief  da de alta el cliente
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma y un auxiliar
 * \return  0 si funciona, -1 si no 0.
 *
 */
int altaClienteConId(eCliente vec[], int tam, eCliente auxL)
{
	int retorno = -1;
	int index;
	if(vec!=NULL && tam>0){
		index = buscarLibreCliente(vec,tam);
		if(index>=0){
			vec[index] = auxL;
			vec[index].isEmpty = 0;
			retorno = 0;
		}
	}
	return retorno;
}



/** \brief  Imprime todos los clientes
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \return  0 si funciono. -1 si no funciono
 *
 */
int imprimirCliente(eCliente vec[],int tam)
{

   int flag=-1;
    printf("ID     APELLIDO  NOMBRE\n");
    printf("--     ------    ----- \n\n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarUnCliente(vec[i]);
            flag=0;
        }

    }
    if (flag==-1)
    {
        printf("\nNo hay clientes que mostrar\n");
    }
    return flag;
}



/** \brief  Imprime un solo cliente
 *
 * \param   Recibe la Estructura en una posicion
 * \return  nada.
 *
 */
void mostrarUnCliente(eCliente vec)
{
    printf("%d  %8s   %8s \n",
           vec.id,
           vec.apellido,
           vec.nombre);
}


/** \brief  Modifica los campos del cliente
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \return  0 si funciono. -1 si funciono.
 *
 */
int modificaCliente(eCliente vec[], int tam)
{
    int index;
    int id;
    int validacion = -1;
    int option;
    //int option;

    printf("MODIFICACION DE CLIENTES\n\n");;
    imprimirCliente(vec,tam);
    getInt(&id,"\nIngrese ID a modificar: \n","Reingrese ID valido: \n",100,1000,3);

    index=buscarPorIdCliente(vec,id,tam);

    if(index!=-1)
    {
        system("cls");
        mostrarUnCliente(vec[index]);
        printf("\n1.Modificar nombre\n");
        printf("2.Domicilio\n");
        printf("3.Telefono\n");
        printf("Ingrese opcion: \n");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                printf("Ingrese nombre nuevo: \n");
                fflush(stdin);
                gets(vec[index].nombre);
                printf("MODIFICACION EXITOSA!!!\n");
                validacion=0;
                break;
            case 2:
                printf("Ingrese domicilio nuevo: \n");
                 fflush(stdin);
                gets(vec[index].domicilio);
                printf("MODIFICACION EXITOSA!!!\n");
                validacion=0;
                break;
            case 3:
                getString(vec[index].telefono,"Ingrese telefono a modificar: \n","Reingrese telefono \n",1,20,3);
                printf("MODIFICACION EXITOSA!!!\n");
                validacion=0;
                break;
            default:
                {
                    printf("Error al modificar\n");
                }

        }


    }
    else
    {
        validacion = -1;
    }


    return validacion;
}



/** \brief  hardcodeo de clientes
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \return  0.
 *
 */
int hardCodearClienteConId(eCliente vec[],int tam)
{
    eCliente bCliente[]=
    {
        {100,"Yago","Rodi",'m',"4222-1055","Rivadavia 2000",0},
        {101,"Camila","Bulnes",'f',"4227-0085","Huergo 2059",0},
        {102,"Martin","Otero",'m',"4222-3942","Paso 249",0},
        {103,"Gabriel","Aguilar",'m',"4222-0631","Corrientes 2938",0},
        {104,"Diego","Doallo",'m',"1161028639","Malaver 297",0},
        {105,"Silvana","Martinez",'f',"4254-6275","Chilavert 2094",0},
        {106,"Ramona","Lopez",'f',"4226-2624","Galli 20",0},
        {107,"Juan","Octal",'m',"4205-7414","Libertador 1010",0},
        {108,"Sebastian","Kaiser",'m',"4222-3019","Mitre 2950",0},
        {109,"Nicolas","Cobos",'m',"4230-1324","Arenales 29",0},
        {110,"Gonzalo","Castelli",'m',"1156537467","Hudson 15",0},
        {111,"Roxana","Rodriguez",'f',"4225-6474","Alem 294",0},
        {112,"Florencia","Romo",'f',"113710198","Colon 250",0},
        {113,"Hugo","Sinche",'m',"4206-7894","Alsina 20",0},
        {114,"Franco","Morales",'m',"4209-4875","Mitre 750",0},
        {115,"Fabiana","Acuna",'f',"4204-5078","Pavon 20",0},
        {116,"Juan","Martinez",'m',"4205-4029","Don Orione 2529",0},
        {117,"Jacinto","Lopez",'m',"4205-1029","Ayolas 2640",0}
    };


        for(int i = 0; i<tam;i++)
        {
            vec[i] = bCliente[i];

        }

    return 0;
}

/** \brief  Da de baja logica el cliente
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \return  0 si funciono. -1 si funciono.
 *
 */
int bajaCliente(eCliente vec[], int tam)
{
    int todoOk = 0;
    int legajo;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Cliente *****\n\n");

    imprimirCliente(vec,tam);
    getInt(&legajo,"Ingrese legajo a dar de baja\n","Reingrese legajo a dar de baja\n",100,1000,3);

    indice = buscarPorIdCliente(vec,legajo,tam);

    if( indice == -1)
    {
        printf("No existe el musico con ese legajo\n\n");

    }
    else
    {
        mostrarUnCliente(vec[indice]);
        printf("\nConfirma baja?");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa!!!\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }

    return todoOk;
}



/** \brief  Ordena los clientes
 *
 * \param   Recibe la Estructura
 * \param   Tamaño de la misma
 * \return  nada.
 *
 */
void ordenarClientes(eCliente vec[], int tam)
{
    eCliente auxCliente;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if(strcmp(vec[i].apellido,vec[j].apellido)>0)
            {
                auxCliente = vec[i];
                vec[i] = vec[j];
                vec[j] = auxCliente;
            }
            else if(strcmp(vec[i].apellido,vec[j].apellido)==0)
            {
                if(strcmp(vec[i].nombre,vec[j].nombre)>0)
                {
                auxCliente = vec[i];
                vec[i] = vec[j];
                vec[j] = auxCliente;
                }

            }
        }
    }
    printf("Clientes Ordenados\n\n");
}


#endif // CLIENTE_C_INCLUDED
