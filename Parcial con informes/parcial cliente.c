#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"

#define tamCli 10


int main()
{
    eCliente cliente[tamCli];

    char salir='s';


    inicializarCliente(cliente,tamCli);
    hardCodearClienteConId(cliente,tamCli);

    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            system("cls");
            altaCliente(cliente,tamCli);
            system("pause");
            break;
        case 2:
            system("cls");
            modificaCliente(cliente,tamCli);
            system("pause");

            break;
        case 3:
            system("cls");
            bajaCliente(cliente,tamCli);
            system("pause");
            break;
        case 4:
            system("cls");
            ordenarClientes(cliente,tamCli);

            system("pause");
            break;
        case 5:
            system("cls");
            imprimirCliente(cliente,tamCli);
            system("pause");

            break;
        case 6:
            system("cls");
            system("pause");
            break;
        case 7:
            system("cls");

            system("pause");

            break;
        case 8:
            system("cls");

            system("pause");
            break;
        case 9:
            system("cls");

            system("pause");

        default:
            {
                printf("Error, opcion invalida\n");
            }
        }

        system("cls");
    }while(salir=='s');




    return 0;
}
