#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "biblioteca.h"
#include "cliente.h"
#include "alquileres.h"
#include "operador.h"

#define TAM 5
#define TAM_A 10
#define TAM_O 5


int menu();
 //estructura operador id nombre hardcodear 3 operadores
 //estructura alquiler
 int main()
{
    char seguir='s';
    char confirma ='s';
    int proximoIdCliente = 1000;
    int proximoIdAlquiler = 5000;
    int flagAltaCliente=1;
    int modificarAux=0;
    int bajaAux=0;

    eCliente clientes[TAM];
    eAlquileres alquileres[TAM_A];

    eOperador operadores[TAM_O]=
    {
        {1000, "Martin"},
        {1001, "Ricardo"},
        {1002, "Maria"},
        {1003, "Alfredo"},
        {1004, "Juana"},
    };

    if(inicializarCliente(clientes, TAM)==0)
    {
        printf("Clientes inicializadas con exito\n");
    }
    else
    {
        printf("problema al inicializar\n");
    }

    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            if(altaCliente(clientes, TAM, proximoIdCliente))
            {
                printf("alta exitosa\n\n");
                proximoIdCliente++;
                flagAltaCliente=0;
            }
            else
            {
                printf("problemas con el alta\n\n");
            }
            break;

        case 2:
            system("cls");
            if(flagAltaCliente==0)
            {
                modificarAux=modificarCliente(clientes,TAM);
                if(modificarAux==1)
                {
                    printf("modificacion lograda\n\n");
                }
                else if(modificarAux==2)
                {
                    printf("modificacion cancelada\n\n");
                }
                else
                {
                    printf("error con la modificacion\n\n");
                }
            }
            else
            {
                printf("se tiene que dar de alta a almenos un cliente\n\n");
            }
            break;

        case 3:
            system("cls");
            if(flagAltaCliente==0)
            {
                bajaAux=bajaClientes(clientes,TAM);
                if(bajaAux==1)
                {
                    printf("baja lograda\n\n");
                }
                else if(bajaAux==2)
                {
                    printf("baja cancelada\n\n");
                }
                else
                {
                    printf("error con la baja\n\n");
                }
            }
            else
            {
                printf("se tiene que dar de alta a almenos un cliente\n\n");
            }
            break;

        case 4:
            system("cls");
            if(flagAltaCliente==0)
            {
                if(altaAlquilerNuevo(alquileres, TAM_A, clientes, TAM,operadores, TAM_O, proximoIdAlquiler))
                {
                    printf("alta exitosa\n");
                    proximoIdAlquiler++;
                }
                else
                {
                    printf("error con alta \n");
                }

            }
            else
            {
                printf("se tiene que dar de alta a almenos un cliente\n\n");
            }
            break;

        case 5:
            system("cls");
            if(flagAltaCliente==0)
            {
                altaAlquilerTerminado(alquileres, TAM_A, clientes, TAM, operadores, TAM_O);
            }
            else
            {
                printf("se tiene que dar de alta a almenos un cliente\n\n");
            }
            break;

        case 6:
            system("cls");
            if(flagAltaCliente==0)
            {

            }
            else
            {
                printf("se tiene que dar de alta a almenos un cliente\n\n");
            }
            break;

        case 7:
            printf("Desea salir?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }
            break;

        default:
            printf("valor invalido\n");
            break;
        }
        system("pause");

    }while(seguir=='s');

    return 0;
}

int menu()
{
    int opcion;
    system("cls");

    printf("   Lavadero de Autos   \n\n");
    printf("1 ALTA DEL CLIENTE\n");
    printf("2 MODIFICAR DATOS DEL CLIENTE\n");
    printf("3 BAJA DEL CLIENTE\n");
    printf("4 NUEVO ALQUILER\n");
    printf("5 FIN DEL ALQUILER\n");
    printf("6 INFORMAR\n");
    printf("7 Salir\n\n");
    fflush(stdin);
    opcion = getInt("Ingrese opcion: ");

    return opcion;
}
