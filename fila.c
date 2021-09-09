#include "fila_privado.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

Fila* cria(int tItem) {
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    if (fila){
        fila->proximoLugar = 0;
        fila->inicio = NULL;
        int i;
        for(i=0; i < TAM_MAX; i++)
        {
            fila->tamanhos[i] = malloc(sizeof(int));
            //fila->tipos[i] = malloc(10 * sizeof(char));
            if(fila->tamanhos[i] == NULL)
            {
                for(--i;i>0;i--)
                {
                    free(fila->tamanhos[i]);
                    //free(fila->tipos[i]);
                }
                free(fila->tamanhos);
                //free(fila->tipos);
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

int destroi(Fila* fila) {//não alterado corpo
    int i;
    if(!IsEmpty(fila)){
        for(i=0;i<fila->topo;i++){
            free(fila->itens[i]);
        }
    }
    free(fila);
    printf("Destroi a Fila\n");
}

int estaCheia(Fila* fila) {
    if (fila->proximoLugar == fila->inicio) return TRUE;
    else return FALSE;
}

int estaVazia(Fila* fila) {
    if (fila->inicio == NULL) return TRUE;
    else return FALSE;
}

int empilha(void *ponteiroItem, int tamanhoItem, Fila* fila){
    if (!estaCheia(fila)) {
        fila->itens[fila->proximoLugar] = (void*) malloc(tamanhoItem);
        fila->tamanhos[fila->proximoLugar] = tamanhoItem;
        memcpy(fila->itens[fila->proximoLugar], ponteiroItem, tamanhoItem);
        if(fila->inicio==NULL)
            fila->inicio = fila->proximoLugar;
        incrementa(fila->proximoLugar);
        return TRUE;
    } else {
        return FALSE;
    }
}

int desempilha(Fila* fila) {
    if (!estaVazia(fila)) {
        fila->tamanhos[fila->inicio]) = NULL;
        free(fila->itens[fila->inicio]);
        incrementa(fila->inicio);
        if(fila->proximoLugar == fila->inicio){
            fila->inicio = NULL;
        }
        return TRUE;
        /*
        void* elRemovido = malloc(fila->tamItem);
        memcpy(elRemovido, fila->itens[fila->topo - 1], fila->tamItem);
        fila->topo--;
        return elRemovido;
        */
    } else return FALSE;
}

void* getProximo(Fila* fila) {//não alterado corpo
    if (!IsEmpty(fila)) {
        void* elTopo = malloc(fila->tamItem);
        memcpy(elTopo, fila->itens[fila->topo - 1], fila->tamItem);
        return elTopo;
    } else return NULL;

}

int incrementa(int i){
    if (i==TAM_MAX-1){
        return 0;
    }
    return i++;
}
