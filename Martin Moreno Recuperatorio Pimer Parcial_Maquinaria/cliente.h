#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    int dni;
    char nombre[20];
    char apellido[20];
    int isEmpty;
}eCliente;

#endif // CLIENTE_H_INCLUDED
int inicializarCliente(eCliente clientes[], int tam);
int clienteBuscarLibre(eCliente clientes[], int tam);
int altaCliente(eCliente clientes[], int tam, int id);
void mostrarCliente(eCliente clientes);
int buscarCliente(eCliente clientes[], int tam, int id);
int mostrarClientes(eCliente clientes[], int tam);
int modificarCliente(eCliente clientes[], int tam);
int bajaClientes(eCliente clientes[], int tam);

