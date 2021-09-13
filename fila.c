#include "fila_privado.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

Fila* cria() {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    if (fila){
        fila->proximoLugar = 0;
        fila->inicio = -1;
        int i;
        for(i=0; i < TAM_MAX; i++)
        {
            fila->tamanhos[i] = malloc(sizeof(int));
            if(fila->tamanhos[i] == NULL)
            {
                for(--i;i>0;i--)
                {
                    free(fila->tamanhos[i]);
                }
                free(fila->tamanhos);
                free(fila);
                fila = NULL;
                printf("Não criou a Fila\n");
            }
        }
    } else {
        printf("Não criou a Fila\n");
    }
    return fila;
}

int destroi(Fila* fila) {
    int i;
    if(!estaVazia(fila)){
        for(i=0;i<TAM_MAX;i++){
            if (fila->tamanhos[i]!=NULL){
                free(fila->itens[i]);
            }
        }
    }
    free(fila);
    //printf("Destroi a Fila\n");
    return TRUE;
}

int estaCheia(Fila* fila) {
    //printf("prox: %d\n", fila->proximoLugar);
    //printf("inicio: %d\n", fila->inicio);
    if (fila->proximoLugar == fila->inicio){
        //printf("t \n");
        return TRUE;
    } else {
        //printf("f \n");
        return FALSE;
    }
}

int estaVazia(Fila* fila) {
    if (fila->inicio == -1){
        return TRUE;
    } else {
        return FALSE;
    }
}

int enfilera(void *ponteiroItem, int tamanhoItem, Fila* fila){
    //printf("ponteiroitem: %d\n", ponteiroItem);
    //printf("ponteiro valor: %d\n", (int) &ponteiroItem);
    if (!estaCheia(fila)) {
        fila->itens[fila->proximoLugar] = (void*) malloc(tamanhoItem);
        fila->tamanhos[fila->proximoLugar] = tamanhoItem;
        memcpy(fila->itens[fila->proximoLugar], ponteiroItem, tamanhoItem);
//        printf("Na fila: %d\n", fila->itens[fila->proximoLugar]);
//        printf("ponteiroItem: %d\n", ponteiroItem);
        if(fila->inicio == -1){
            fila->inicio = fila->proximoLugar;
        }
        fila->proximoLugar = incrementa(fila->proximoLugar);
//        printf("inicio vai para: %d\n", fila->inicio);
//        printf("proximo vai para: %d\n", fila->proximoLugar);
        return TRUE;
    } else {
        return FALSE;
    }
}

int desenfilera(Fila* fila) {
    if (!estaVazia(fila)) {
        fila->tamanhos[fila->inicio] = NULL;
        free(fila->itens[fila->inicio]);
        fila->inicio = incrementa(fila->inicio);
        if(fila->proximoLugar == fila->inicio){
            fila->inicio = -1;
        }
 //       printf("inicio ao desenf vai para: %d\n", fila->inicio);
 //       printf("proximo ao desenf vai para: %d\n", fila->proximoLugar);
        return TRUE;
    } else return FALSE;
}

int getProximo (Fila* fila, void *elemento){
    if(estaVazia(fila)) return FALSE;
    memcpy(elemento,fila->itens[fila->inicio],fila->tamanhos[fila->inicio]);
    return TRUE;
}

int incrementa(int i){
    //       printf("incrementa recebeu: %d\n", i);
    if (i==TAM_MAX-1){
        return 0;
    }
    return i+1;
}
