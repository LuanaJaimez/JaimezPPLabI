#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;

}eFecha;

typedef struct
{
    int id;
    int patente;
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;

}eAuto;

typedef struct
{
    int id;
    char descripcion[20];

}eMarca;

typedef struct
{
    int id;
    char nombreColor[20];

}eColor;

typedef struct
{
    int id;
    char descripcion[25];
    int precio;

}eServicio;

typedef struct
{
    int id;
    int patente;
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

#endif // AUTO_H_INCLUDED


void inicializarAutos(eAuto vec[], int tam);
int buscarLibre(eAuto vec[], int tam);
int altaAuto(int idx, eAuto vec[], int tam);
void mostrarAuto(eAuto x);
void mostrarAutos(eAuto vec[], int tam);
int buscarAuto(int patente, eAuto vec[], int tam);
void modificarAuto(eAuto vec[], int tam);
int menuModificar();
void mostrarMarcas(eMarca vec[], int tam);
void mostrarColores(eColor vec[], int tam);
void mostrarServicios(eServicio vec[], int tam);
void bajaAuto(eAuto vec[], int tam);
int altaTrabajo(int idx, eTrabajo vec[], int tam, eServicio lavados[], int tamSer, eAuto autos[], int tamAu);
void mostrarTrabajo(eTrabajo x);
void mostrarTrabajos(eTrabajo vec[], int tam);
