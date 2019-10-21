#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "alquiler.h"
#include "informe.h"
#include "juegos.h"
#include "categoria.h"


#define tamCli 18
#define tamJue 10
#define tamAlq 15
#define tamCat 5


int main()
{
    eCliente cliente[tamCli];
    eAlquiler alquiler[tamAlq];
    int idCli=1000;
    int idAlqui=1000;

    char salir='s';



    inicializarCliente(cliente,tamCli);
    inicializarAlquiler(alquiler,tamAlq);
    hardCodearClienteConId(cliente,tamCli);

    eJuego juego[tamJue]=
    {
        {100,"Loteria",1000,11},
        {101,"Poker",3000,10},
        {102,"Dados",2500,11},
        {103,"Ajedrez",5000,12},
        {104,"Teg",3500,12},
        {105,"El mago",3500,14},
        {106,"Backgammon",3200,10},
        {107,"Domino",1500,11},
        {108,"Gallito",1000,13},
        {109,"Reversi",2500,12}

    };

    eCategoria categoria[tamCat]=
    {
        {10,"mesa"},
        {11,"azar"},
        {12,"estrategia"},
        {13,"salon"},
        {14,"magia"}
    };

    eAlquiler alquilerH[tamAlq]=
    {
        {1000,100,106,{17,3,2019},0},
        {1001,103,106,{15,3,2018},0},
        {1002,104,109,{15,5,2019},0},
        {1003,105,103,{14,3,2019},0},
        {1004,106,109,{02,3,2018},0},
        {1005,105,110,{17,3,2019},0},
        {1006,103,114,{14,9,2019},0},
        {1007,104,103,{17,4,2018},0},
        {1008,106,112,{05,9,2019},0},
        {1009,107,101,{02,1,2018},0},
        {1010,109,109,{17,8,2019},0},
        {1011,104,116,{03,2,2018},0},
        {1012,101,114,{11,7,2019},0},
        {1013,106,111,{14,3,2019},0},
        {1014,107,105,{26,11,2019},0}

    };


    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            system("cls");
            if(altaCliente(cliente,tamCli,idCli)==0)
            {
                idCli++;
            }
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
            imprimirCliente(cliente,tamCli);

            system("pause");
            break;
        case 5:
            system("cls");
            if(altaAlquiler(alquiler,tamAlq,juego,tamJue,cliente,tamCli,idAlqui)==0)
            {
                idAlqui++;

            }
            system("pause");

            break;
        case 6:
            system("cls");
            imprimirAlquiler(alquilerH,tamAlq,juego,tamJue,cliente,tamCli);
            system("pause");
            break;
        case 7:
            system("cls");
            switch(menuInforme())
            {
                case 1: mostrarJuegosMesa(juego,tamJue,categoria,tamCat);

                break;
                case 2:
                    mostrarAlquileresPorCliente(alquilerH,tamAlq,cliente,tamCli,juego,tamJue);

                    break;
                case 3:
                    system("cls");
                    mostrarImportesPorCliente(alquilerH,tamAlq,cliente,tamCli,juego,tamJue);


                    break;
                case 4:

                    listarClientesQueNoAlquilaron(cliente,tamCli,alquilerH,tamAlq);

                    break;
                case 5:
                    listarJuegosSinAlquilar(juego,tamJue,alquilerH,tamAlq);
                    break;
                case 6:
                    listarClientesXAlquileres(cliente,tamCli,alquilerH,tamAlq);
                    break;
                case 7:
                    listarClientesConMasAlquileres(cliente,tamCli,alquilerH,tamAlq);
                    break;
                case 8:
                    listarMujeresQueAlquilaronJuegos(cliente,tamCli,alquilerH,tamAlq,juego,tamJue,categoria,tamCat);
                    break;
                case 9:
                    listarClientesPorFecha(cliente,tamCli,alquilerH,tamAlq);
                    break;
                case 10:
                    break;
                case 11:
                    break;
                case 12:
                    break;
                case 13:
                    break;
                case 14:
                    break;
                case 15:
                    break;
                    default:
                        {
                            printf("error, opcion invalida\n");
                        }
            }
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
