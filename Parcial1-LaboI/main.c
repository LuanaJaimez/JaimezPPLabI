#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "auto.h"
#define TAM 5

int menu();

int main()
{
    char seguir = 's';
    char confirma;

    int proximoIdAuto = 1000;
    int proximoId = 1000;

    eMarca listaMarca[5] =
    {
        {1000, "Renault"},
        {1001, "Fiat"},
        {1002, "Ford"},
        {1003, "Chevrolet"},
        {1004, "Peugeot"}
    };

    eColor listaColor[5] =
    {
        {5000, "Negro"},
        {5001, "Blanco"},
        {5002, "Gris"},
        {5003, "Rojo"},
        {5004, "Azul"}
    };

    eServicio lavados[4] =
    {
        {20000, "Lavado", 250},
        {20001, "Pulido", 300},
        {20002, "Encerado", 400},
        {20003, "Completo", 600}
    };

    eAuto listaAuto[TAM];


    eTrabajo listaTrabajo[TAM];

    inicializarAutos(listaAuto, TAM);

    do{
            switch(menu())
            {
            case 'a':
                if(altaAuto(proximoIdAuto, listaAuto, TAM) == 1)
                {
                    proximoIdAuto++;
                }
                break;
            case 'b':
                modificarAuto(listaAuto, TAM);
                break;
            case 'c':
                bajaAuto(listaAuto, TAM);
                break;
            case 'd':
                mostrarAutos(listaAuto, TAM);
                break;
            case 'e':
                mostrarMarcas(listaMarca, 5);
                break;
            case 'f':
                mostrarColores(listaColor, 5);
                break;
            case 'g':
                mostrarServicios(lavados, 4);
                break;
            case 'h':
                altaTrabajo(proximoId, listaTrabajo, 5, lavados, 4, listaAuto, TAM);
                //listarAlmuerzos(almuerzos, TAMAL, comidas, TAMCOM, lista, TAM);
                break;
            case 'i':
                mostrarTrabajos(listaTrabajo, 5);
                break;
            case 'j':
                printf("Confirme salida: ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma == 's')
                {
                    seguir = 'n';
                }
                break;
            }

            system("pause");

    }while(seguir == 's');

    return 0;
}

//---------------------------------------------------------------------------------------------------

int menu()
{
    char opcion;

    system("cls");
    printf("***** Lavadero de Autos *****\n\n");
    printf("A. Alta Auto\n");
    printf("B. Modificar Auto\n");
    printf("C. Baja Auto\n");
    printf("D. Listar Autos\n");
    printf("E. Listar Marcas\n");
    printf("F. Listar Colores\n");
    printf("G. Listar Servicios\n");
    printf("H. Alta Trabajo\n");
    printf("I. Listar Trabajos\n");
    printf("J. Salir\n");
    printf("\nElija una opcion: ");
    //fflush(stdin);
    scanf("%c", &opcion);
    return opcion;
}


