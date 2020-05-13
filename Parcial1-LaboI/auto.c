#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "auto.h"


void inicializarAutos(eAuto vec[], int tam)
{
    for(int i=0; i<tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

//---------------------------------------------------------------------------------------------------

int buscarLibre(eAuto vec[], int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

//---------------------------------------------------------------------------------------------------

int altaAuto(int idx, eAuto vec[], int tam)
{
    int todoOk = 0;
    int indice = buscarLibre(vec, tam);
    eAuto auxAuto;

    system("cls");

    printf("***** Alta Cliente *****\n\n");

    if(indice == -1)
    {
        printf("Sistema completo\n\n");
    }
    else
    {
        auxAuto.id = idx;

        printf("Ingrese patente: ");
        fflush(stdin);
        scanf("%d", &auxAuto.patente);

        utn_getEntero(&auxAuto.idMarca, 2, "Ingrese Id Marca (1000-1005): ", "Error. vuelva a intentarlo: \n", 1000, 1005);

        utn_getEntero(&auxAuto.idColor, 2, "Ingrese Id Color (5000-5005): ", "Error, vuelva a intentarlo: \n", 5000, 5005);

        utn_getEntero(&auxAuto.modelo, 2, "Ingrese modelo (1890-2020): ", "Error, vuelve a intentarlo: \n", 1890, 2020);

        auxAuto.isEmpty = 0;

        vec[indice] = auxAuto;
        todoOk = 1;

        printf("Alta excitosa\n");

    }

    return todoOk;
}

//---------------------------------------------------------------------------------------------------

void mostrarAuto(eAuto x)
{
    printf("%d  %d   %d  %d   %d   \n", x.id, x.patente, x.idMarca, x.idColor, x.modelo);
}

//---------------------------------------------------------------------------------------------------

void mostrarAutos(eAuto vec[], int tam)
{
    int flag = 0;
    system("cls");
    printf("***** Listado de Autos *****\n");
    printf("  Id      Patente     ID Marca       ID Color    Modelo  \n\n");
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            mostrarAuto(vec[i]);
            flag = 1;
        }
    }
    if(flag == 0)
    {
        printf("*** No hay autos que listar ***\n");
    }
}

//---------------------------------------------------------------------------------------------------

int buscarAuto(int patente, eAuto vec[], int tam)
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].patente == patente && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

//---------------------------------------------------------------------------------------------------

void modificarAuto(eAuto vec[], int tam)
{
    int patente;
    int indice;
    char seguir = 's';
    char confirma;
    int nuevoColor;
    int nuevoModelo;

    system("cls");
    printf("***** Modificar Auto *****\n\n");

    printf("Ingrese patente: ");
    scanf("%d", &patente);

    indice = buscarAuto(patente, vec, tam);

    if(indice == -1)
    {
        printf("No hay registro de un auto con la patente: %s\n", patente);
    }
    else
    {
        printf("  Id      Patente     ID Marca       ID Color    Modelo  \n");
        mostrarAuto(vec[indice]);

//SUBMENU QUE PERMITE MODIFICAR COLOR Y MARCA---------------------------------------------------
    do{
        switch(menuModificar())
        {
        case 1:
            printf("\nModifica Color?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                printf("Ingrese nuevo color: ");
                scanf("%d", &nuevoColor);

                vec[indice].idColor = nuevoColor;
                printf("Se ha actualizado el color con exito\n\n");
            }
            else
            {
                printf("Se ha cancelado la operacion\n\n");
            }
            break;
        case 2:
            printf("\nModifica Modelo?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                printf("Ingrese nuevo modelo: ");
                scanf("%d", &nuevoModelo);

                vec[indice].modelo = nuevoModelo;
                printf("Se ha actualizado el modelo con exito\n\n");
            }
            else
            {
                printf("Se ha cancelado la operacion\n\n");
            }
            break;
        case 3:
            printf("Confirme salida: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            system("pause");
        }

    }while(seguir == 's');
    }
}

//---------------------------------------------------------------------------------------------------

int menuModificar()
{
    int opcion;

    printf("***** Modificar Color/Modelo *****\n\n");
    printf("1. Modificar Color\n");
    printf("2. Modificar Modelo\n");
    printf("3. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

//---------------------------------------------------------------------------------------------------

void mostrarMarcas(eMarca vec[], int tam)
{
    system("cls");
    printf("***** Listado de Marcas *****\n");
    printf(" ID Marca     Descripcion \n\n");
    for(int i=0; i<tam; i++)
    {
        printf("  %d       %10s \n", vec[i].id, vec[i].descripcion);
    }
}

//---------------------------------------------------------------------------------------------------

void mostrarColores(eColor vec[], int tam)
{
    system("cls");
    printf("***** Listado de Colores *****\n");
    printf(" ID Color    Descripcion \n\n");
    for(int i=0; i<tam; i++)
    {
        printf("  %d       %10s  \n", vec[i].id, vec[i].nombreColor);
    }
}

//---------------------------------------------------------------------------------------------------

void mostrarServicios(eServicio vec[], int tam)
{
    system("cls");
    printf("***** Listado de Servicios *****\n");
    printf(" ID Servicio   Descripcion   Precio  \n\n");
    for(int i=0; i<tam; i++)
    {
        printf("  %d        %10s      %d  \n", vec[i].id, vec[i].descripcion, vec[i].precio);
    }
}

//---------------------------------------------------------------------------------------------------

void bajaAuto(eAuto vec[], int tam)
{
    int patente;
    int indice;
    char confirma;

    system("cls");
    printf("***** Baja Auto *****\n\n");

    printf("Ingrese patente: ");
    scanf("%d", &patente);

    indice = buscarAuto(patente, vec, tam);

    if(indice == -1)
    {
        printf("No hay registro de un auto con la patente: %d\n", patente);
    }
    else
    {
        mostrarAuto(vec[indice]);

        printf("\nConfirma baja?: ");
        fflush(stdin);
        scanf("%c", &confirma);
        if(confirma == 's')
        {
            vec[indice].isEmpty = 1;
            printf("Se ha realizado la baja con exito\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }

}

//---------------------------------------------------------------------------------------------------

int altaTrabajo(int idx, eTrabajo vec[], int tam, eServicio lavados[], int tamSer, eAuto autos[], int tamAu)
{
    int todoOk = 0;
    eTrabajo auxTrabajo;

    system("cls");

    printf("***** Alta Trabajo *****\n\n");

    auxTrabajo.id = idx;

    mostrarAutos(autos, tamAu);
    printf("Ingrese patente: ");
    fflush(stdin);
    scanf("%d", &auxTrabajo.patente);

    mostrarServicios(lavados, tamSer);
    printf("Ingrese ID servicio: ");
    fflush(stdin);
    scanf("%d", &auxTrabajo.idServicio);

    printf("Ingrese fecha dd/mm/aaaa: ");
    fflush(stdin);
    scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);

    auxTrabajo.isEmpty = 0;
    todoOk = 1;


    printf("Alta excitosa\n");


    return todoOk;
}

//---------------------------------------------------------------------------------------------------

void mostrarTrabajo(eTrabajo x)
{
    printf("%d  %d   %d  %d/%d/%d   \n", x.id, x.patente, x.idServicio, x.fecha.dia, x.fecha.mes, x.fecha.anio);
}

//---------------------------------------------------------------------------------------------------

void mostrarTrabajos(eTrabajo vec[], int tam)
{
    system("cls");
    printf("***** Listado de Trabajos *****\n");
    printf("  Id      Patente     ID Servicio     Fecha  \n\n");
        for(int i=0; i<tam; i++)
    {
        printf("%d  %d   %d  %d/%d/%d   \n", vec[i].id, vec[i].patente, vec[i].idServicio, vec[i].fecha.dia, vec[i].fecha.mes, vec[i].fecha.anio);
    }
}
