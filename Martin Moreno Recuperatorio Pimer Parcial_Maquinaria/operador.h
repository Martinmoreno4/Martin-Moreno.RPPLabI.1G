#ifndef OPERADOR_H_INCLUDED
#define OPERADOR_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eOperador;

#endif // OPERADOR_H_INCLUDED


void mostrarOperador(eOperador operador);
int mostrarOperadores(eOperador operadores[], int tam);
int validarIdOperador(eOperador operadores[], int tam, int id);
int obtenerDescripcionOperador(eOperador operadores[], int tam, int id, char descripcion[]);
