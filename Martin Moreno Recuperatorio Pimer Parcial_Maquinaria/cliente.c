#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cliente.h"
#include "biblioteca.h"

/** \brief inicializa una estructura liberando todos los espacios posibles, cambiando todos los valores de isEmpty a 1
 *
 * \param clientes[] eCliente
 * \param tam int
 * \return int
 *
 */
int inicializarCliente(eCliente clientes[], int tam)
{
    int todoOk= 0;

    if( clientes != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            clientes[i].isEmpty = 1;
        }
        todoOk=1;
    }
    return todoOk;
}

/** \brief das de a alta a un cliente
 *
 * \param clientes[] eCliente
 * \param tam int
 * \param id int
 * \return int
 *
 */
int altaCliente(eCliente clientes[], int tam, int id)
{
    int todoOk=0;
    int dniAux=0;
    char nombreAux[20];
    int nombreValido=0;
    char apellidoAux[20];
    int apellidoValido=0;

    int indice=0;
    eCliente nuevoCliente;

    if(clientes!=NULL && tam>0 && id>0)
    {
        printf("** Alta De Cliente **\n\n");

        indice=clienteBuscarLibre(clientes, tam);

        if(indice==-1)
        {
            printf("no hay lugar libre");
        }
        else
        {
            dniAux=getInt("ingrese el DNI:");
            while(dniAux>99999999 || dniAux<10000000)
            {
                dniAux=getInt("el dni deve ser un numero de 8 digitos, ingrese DNI\n");
            }
            nuevoCliente.dni=dniAux;

            nombreValido=getStringLetras("\ningrese el Nombre:", nombreAux);
            while(nombreValido==0)
            {
                nombreValido=getStringLetras("\nel nombre debe ser solo con letras, ingrese nombre:", nombreAux);
            }
            strcpy(nuevoCliente.nombre, nombreAux);

            apellidoValido=getStringLetras("\ningrese el Apellido:", apellidoAux);
            while(apellidoValido==0)
            {
                apellidoValido=getStringLetras("\nel nombre debe ser solo con letras, ingrese Apellido:", apellidoAux);
            }
            strcpy(nuevoCliente.apellido, apellidoAux);

            nuevoCliente.id=id;
            nuevoCliente.isEmpty=0;

            clientes[indice] = nuevoCliente;
            todoOk = 1;
        }


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
int clienteBuscarLibre(eCliente clientes[], int tam)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {
        if(clientes[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief muestra a un cliente
 *
 * \param clientes eCliente
 * \param tam int
 * \return void
 *
 */
void mostrarCliente(eCliente clientes)
{
    printf("%04d %08d %10s %10s", clientes.id, clientes.dni, clientes.nombre, clientes.apellido);
}

/** \brief muestra atodos los clientes en una struct
 *
 * \param clientes[] eCliente
 * \param tam int
 * \return int
 *
 */
int mostrarClientes(eCliente clientes[], int tam)
{
    int todoOk=0;
    int flag=0;

    if(clientes!=NULL && tam>0)
    {
        printf("      Id   dni       Nombre     Apellido\n");
        printf("----------------------------------------\n");

        for(int i= 0; i < tam; i++)
        {
            if(clientes[i].isEmpty == 0)
            {
                mostrarCliente(clientes[i]);
                flag = 1;
            }
        }
        if( flag == 0)
        {
            printf("No hay clientes para mostrar\n");
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}

/** \brief busca un cliente en una estructura a partir del id ingresado, devolviendo su indice
 *
 * \param clientes[] eCliente
 * \param tam int
 * \param id int
 * \return int
 *
 */
int buscarCliente(eCliente clientes[], int tam, int id)
{
    int indice=0;
    if(clientes!=NULL && tam>0 && id>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(clientes[i].id==id)
            {
                indice=i;
            }
        }
    }
    return indice;
}

/** \brief se ingresa el id de un cliente para poder modificar su nombre y apellido
 *
 * \param clientes[] eCliente
 * \param tam int
 * \return int
 *
 */
int modificarCliente(eCliente clientes[], int tam)
{
    int todoOk=0;
    int idAux=0;
    int indice=0;

    char auxNombre[20];
    int nombreValido=0;
    char auxApellido[20];
    int apellidoValido=0;

    char confirma ='s';

    if(clientes!=NULL && tam>0)
    {
        mostrarClientes(clientes, tam);
        idAux=getInt("ingrese id del cliente a modificar");
        todoOk=1;
        indice=buscarCliente(clientes, tam, idAux);
        if(indice==-1)
        {
            printf("no existe esa id");
        }
        else
        {
            nombreValido=getStringLetras("\n ingrese el nuevo nombre:", auxNombre);
            while(nombreValido==0)
            {
                nombreValido=getStringLetras("\n invalido, ingrese el nuevo nombre:", auxNombre);
            }

            apellidoValido=getStringLetras("\n ingrese el nuevo apellido:", auxApellido);
            while(apellidoValido==0)
            {
                apellidoValido=getStringLetras("\n invalido, ingrese el nuevo apellido:", auxApellido);
            }

            printf("Confirme cambio: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                strcpy(clientes[indice].nombre, auxNombre);
                strcpy(clientes[indice].apellido, auxApellido);
                todoOk = 1;
            }
            else
            {
                todoOk = 2;
            }
        }
    }

    return todoOk;
}


int bajaClientes(eCliente clientes[], int tam)
{
    int todoOk=0;
    int idAux=0;
    int indice=0;

    char confirma ='s';

    if(clientes!=NULL && tam>0)
    {
        mostrarClientes(clientes, tam);
        idAux=getInt("ingrese id del cliente a dar de Baja");
        todoOk=1;
        indice=buscarCliente(clientes, tam, idAux);
        if(indice==-1)
        {
            printf("no existe esa id");
        }
        else
        {
            printf("      Id   dni       Nombre     Apellido\n");
            printf("----------------------------------------\n");
            mostrarCliente(clientes[indice]);

            printf("Confirme Baja: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                clientes[indice].isEmpty=1;
                todoOk = 1;
            }
            else
            {
                todoOk = 2;
            }
        }
    }

    return todoOk;
}
