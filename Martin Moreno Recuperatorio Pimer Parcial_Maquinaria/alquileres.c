#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "alquileres.h"
#include "biblioteca.h"

#define AMOLADORA 0
#define MEZCLADORA 1
#define TALADRO 2

#define ALQUILADO 0
#define FINALIZADO 1

    int id;
    eCliente cliente;
    int idEquipo;
    int tiempoEstimado;
    int tiempoReal;
    int idOperadores;
    int estado;
    int isEmpty;

/** \brief muestra alquiler
 *
 * \param alquileres eAlquileres
 * \return void
 *
 */
void mostrarAlquiler(eAlquileres alquileres)
{
    printf("%4d  %10s  %5d  %5d  %5d  %5d  %5d", alquileres.id, alquileres.cliente.nombre ,alquileres.idEquipo, alquileres.tiempoEstimado, alquileres.tiempoReal, alquileres.idOperadores, alquileres.estado);
}

/** \brief muestra alquileres en estructura
 *
 * \param alquileres[] eAlquileres
 * \param tam int
 * \return int
 *
 */
int mostrarAlquileres(eAlquileres alquileres[], int tam)
{
    int todoOk=0;
    int flag=0;

    if(alquileres!=NULL && tam>0)
    {
        printf("      Id   cliente    equipo   tiempo-estimado tiempo-real  operadores  estado\n");
        printf("----------------------------------------\n");

        for(int i= 0; i < tam; i++)
        {
            if(alquileres[i].isEmpty == 0)
            {
                mostrarAlquiler(alquileres[i]);
                flag = 1;
            }
        }
        if( flag == 0)
        {
            printf("No hay alquileres para mostrar\n");
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}

/** \brief busca el primer lugar libre en una estructura clientes
 *
 * \param clientes[] eCliente
 * \param tam int
 * \return int devuelve el primer indice libre
 *
 */
int alquilerBuscarLibre(eAlquileres alquileres[], int tam)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(alquileres[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief se da de alta un alquiler y se lo asigna a un cliente
 *
 * \param alquileres[] eAlquileres
 * \param tam int
 * \param clientes eCliente
 * \param tamC int
 * \param id int
 * \return int
 *
 */
int altaAlquilerNuevo(eAlquileres alquileres[], int tam, eCliente clientes[], int tamC, eOperador operadores[], int tamO, int id)
{
    int todoOk=0;
    int indice=0;
    int idAuxCliente=0;
    int indiceCliente =0;
    int idEquipoAux=0;
    int tiempoEstimadoAux=0;
    int idOperadorAux=0;
    eAlquileres alquilerAux;

    if(alquileres!=NULL && tam>0 && clientes!=NULL && tamC>0)
    {
        indice=alquilerBuscarLibre(alquileres, tam);
        if(indice==-1)
        {
            printf("no hay lugar libre\n");
        }
        else
        {
            mostrarClientes(clientes, tam);
            idAuxCliente=getInt("ingrese id del cliente para alta de alquiler");
            todoOk=1;
            indiceCliente=buscarCliente(clientes, tam, idAuxCliente);
            if(indiceCliente==-1)
            {
                printf("no existe esa id");
            }
            else
            {

                idEquipoAux = getInt("seleccione equipo");
                while(idEquipoAux<0 || idEquipoAux>2)
                {
                    idEquipoAux = getInt("seleccione equipo valido");
                }

                mostrarOperadores(operadores, tam);
                idOperadorAux=getInt("seleccione operador");
                while(!validarIdOperador(operadores, tamO, idOperadorAux))
                {
                    idOperadorAux = getInt("seleccione operador valido");
                }

                tiempoEstimadoAux=getInt("ingrese tiempo estimado en dias, no puede ser mas de un mes");
                while(tiempoEstimadoAux>31 || tiempoEstimadoAux<0)
                {
                    tiempoEstimadoAux=getInt("ingrese tiempo estimado en dias, no puede ser mas de un mes");
                }
                alquilerAux.cliente=clientes[indiceCliente];
                alquilerAux.estado=ALQUILADO;
                alquilerAux.idEquipo=idEquipoAux;
                alquilerAux.idOperadores=idOperadorAux;
                alquilerAux.tiempoEstimado=tiempoEstimadoAux;
                alquilerAux.id=id;
                alquilerAux.isEmpty=0;

                alquileres[indice]=alquilerAux;
                todoOk=1;

            }
        }


    }
    return todoOk;
}

/** \brief se da de alta un alquiler y se lo asigna a un cliente
 *
 * \param alquileres[] eAlquileres
 * \param tam int
 * \param clientes eCliente
 * \param tamC int
 * \param id int
 * \return int
 *
 */
int altaAlquilerTerminado(eAlquileres alquileres[], int tam, eCliente clientes[], int tamC, eOperador operadores[], int tamO)
{
    int todoOk=0;
    int indiceAlquiler=0;
    int idAlquiler;
    int tiempoReal=0;

    if(alquileres!=NULL && tam>0 && clientes!=NULL && tamC>0)
    {

        mostrarAlquileres(alquileres, tam);

        idAlquiler=getInt("ingrese id de alquiler a terminar");

        for(int i=0; i<tam; i++)
        {
            if(alquileres[i].id==idAlquiler)
            {
                indiceAlquiler=i;
            }
        }
        if(indiceAlquiler==0)
        {
            printf("no se encontro el alquiler");
        }
        else
        {
            alquileres[indiceAlquiler].estado=FINALIZADO;
            tiempoReal=getInt("ingrese tiempo real en dias, no puede ser mas de un mes");
            while(tiempoReal>31 || tiempoReal<0)
            {
                tiempoReal=getInt("ingrese tiempo real en dias, no puede ser mas de un mes");
            }
            todoOk=1;
        }


    }
    return todoOk;
}
