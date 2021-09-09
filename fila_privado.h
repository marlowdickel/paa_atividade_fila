#include "fila_publico.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

#ifndef PILHA_PRIVADO_H
#define PILHA_PRIVADO_H

#define TAM_MAX 4
#define TRUE 1
#define FALSE 0

 struct mFilas{
    void* itens[TAM_MAX];
    int tamanhos[TAM_MAX];//armazena tamanho pra usar na liberação de memória
    int proximoLugar;//aponta para a posição da fila que receberá o próximo valor
    int inicio; //aponta o inicio da fila, ou seja, a "frente" dela
} typedef Fila;

int incrementa(int i); //função que gerencia o incremento pra voltar ao 0 se estourar o tamanho
#endif
