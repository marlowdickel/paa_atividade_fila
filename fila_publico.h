#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>


#ifndef PILHA_PUB_H
#define PILHA_PUB_H

typedef struct mFilas Fila;

Fila* cria();
int destroi(Fila* fila);
int estaVazia(Fila* fila)
int estaCheia(Fila* fila)
int empilha(void *ponteiroItem, int tamanhoItem, Fila* fila)
int desempilha(Fila* fila)
void* getProximo(Fila* fila)

/*
typedef struct mPilhas Pilha;

Pilha* Init(int tItem);
void Destroy(Pilha* pilha);
int IsEmpty(Pilha* pilha);
int IsFull(Pilha* pilha);
void Push(void *ponteiroItem, Pilha* pilha);
void* Pop(Pilha* pilha);
void* Top(Pilha* pilha);
*/
#endif
