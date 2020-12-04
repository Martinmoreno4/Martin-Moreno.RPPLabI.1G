#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "operador.h"
void mostrarOperador(eOperador operador)
{
    printf(" %4d    %10s", operador.id, operador.descripcion);
}

int mostrarOperadores(eOperador operadores[], int tam)
{
    int todoOk=0;
    if(operadores!=NULL && tam>0)
    {
        printf("          operadores          \n");
        printf("------------------------------\n");
        printf("   id        Descripcion\n");
        for(int i=0;i<tam;i++)
        {
          mostrarOperador(operadores[i]);
        }
        todoOk=1;
        printf("\n\n");
    }
    return todoOk;
}

/** \brief valida el id ingresado
 *
 * \param operadores[] eOperador
 * \param tam int
 * \param id int
 * \return int
 *
 */
int validarIdOperador(eOperador operadores[], int tam, int id)
{
    int esValido = 0;

    if( operadores != NULL && tam >0 && id >= 1000)
    {
        for(int i=0; i<tam; i++)
        {
            if(operadores[i].id == id)
            {
                esValido = 1;
                break;
            }
        }
    }
    return esValido;
}

/** \brief obtiene descripcion a partir de id
 *
 * \param operadores[] eOperador
 * \param tam int
 * \param id int
 * \param descricpion[] char
 * \return int
 *
 */
int obtenerDescripcionOperador(eOperador operadores[], int tam, int id, char descripcion[])
{
    int error = 1;
    if(operadores !=NULL && tam > 0 && id >= 1000 && descripcion!=NULL)
    {
        for(int i=0; i < tam; i++)
        {
            if(operadores[i].id == id)
            {

                strcpy(descripcion, operadores[i].descripcion);
                error=0;
                break;
            }
        }
    }
    return error;
}
