#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>


#ifndef FILA_PUBLICO_H
#define FILA_PUBLICO_H

typedef struct mFilas Fila;

Fila* cria();
int destroi(Fila* fila);
int estaVazia(Fila* fila);
int estaCheia(Fila* fila);
int enfilera(void *ponteiroItem, int tamanhoItem, Fila* fila);
int desenfilera(Fila* fila);
int getProximo (Fila* fila, void *elemento);

#endif
