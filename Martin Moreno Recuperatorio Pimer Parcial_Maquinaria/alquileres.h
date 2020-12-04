#ifndef ALQUILERES_H_INCLUDED
#define ALQUILERES_H_INCLUDED
#include "cliente.h"
#include "operador.h"

typedef struct
{
    int id;
    eCliente cliente;
    int idEquipo;
    int tiempoEstimado;
    int tiempoReal;
    int idOperadores;
    int estado;
    int isEmpty;
}eAlquileres;

#endif // ALQUILERES_H_INCLUDED

//ingresar cliente, lo que se le alquile, cantidad de horas
//finalizar alquiler, buscas el alquiler, poner cantidad de horas reales
int altaAlquilerNuevo(eAlquileres alquileres[], int tam, eCliente clientes[], int tamC, eOperador operadores[], int tamO, int id);
int altaAlquilerTerminado(eAlquileres alquileres[], int tam, eCliente clientes[], int tamC, eOperador operadores[], int tamO);
void mostrarAlquiler(eAlquileres alquileres);
int mostrarAlquileres(eAlquileres alquileres[], int tam);
