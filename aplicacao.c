#include "aplicacao.h"
#include "pilha.c"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

int main()
{
    int ret; // para os retornos
    int i; // para os "for"
    int intSaida; // para os valores retirados das pilhas
    pPilha pilhaSaida; // para retirar as pilhas da fila

    // OK - Crie uma fila circular c/ 3 posições
    printf("AÇÃO - Crie uma fila circular c/ 3 posições\n\n");
    Fila* minhaFila = cria();
    printf("Fila criada\n");

    // OK - Crie 1 pilha c/ 10 posições
    printf("AÇÃO - Crie 1 pilha c/ 10 posições\n\n");
    pPilha pilha1;
    ret = criapilha(&pilha1,10,sizeof(int));
    if (!ret) {
        printf ("ERRO cria pilha 1!\n");
    } else printf ("Pilha 1 criada!\n");

    // OK - Empilhe (0,1, ... 8)
    printf("AÇÃO - Empilhe (0,1, ... 8)\n\n");
    for (i=0; i<=8; i++){
        ret = empilha(pilha1, &i);
        if (!ret) {
            printf ("ERRO empilha valor %d!\n", i);
        } else printf ("Valor %d empilhado!\n", i);

    }

    // OK - enfileire a pilha
    printf("AÇÃO - enfileire a pilha\n\n");
    ret = enfilera(&pilha1, sizeof(pilha1), minhaFila);
    if (!ret) {
        printf ("ERRO enfilera pilha 1!\n");
    } else printf ("Valor pilha 1 enfilerado!\n");

    // OK - Crie 1 pilha c/ 10 posições
    printf("AÇÃO - Crie 1 pilha c/ 10 posições\n\n");
    pPilha pilha2;
    ret = criapilha(&pilha2,10,sizeof(int));
    if (!ret) {
        printf ("ERRO cria pilha 2!\n");
    } else printf ("Pilha 2 criada!\n");

    // OK - Empilhe (8,7, ... 0)
    printf("AÇÃO - Empilhe (8,7, ... 0)\n\n");
    for (i=8; i>=0; i--){
        ret = empilha(pilha2, &i);
        if (!ret) {
            printf ("ERRO empilha valor %d!\n", i);
        } else printf ("Valor %d empilhado!\n", i);

    }

    // OK - enfileire a pilha
    printf("AÇÃO - enfileire a pilha\n\n");
    ret = enfilera(&pilha2, sizeof(pilha2), minhaFila);
    if (!ret) {
        printf ("ERRO enfilera pilha 2!\n");
    } else printf ("Valor pilha 2 enfilerado!\n");

    // OK - Desempilhe 4 elementos
    printf("AÇÃO - Desempilhe 4 elementos\n\n");
    getProximo(minhaFila, &pilhaSaida);
    for (i = 1; i<=4; i++){
        ret = desempilha(pilhaSaida, &intSaida);
        if (!ret)
            printf ("ERRO desempilha %d...\n", intSaida);
        else
            printf ("OK desempilha %d\n", intSaida);
    }

    // OK - desenfileire a pilha
    printf("AÇÃO - desenfileire a pilha\n\n");
    ret = desenfilera(minhaFila);
    if (!ret) {
        printf ("ERRO desenfilera pilha 1!\n");
    } else printf ("Valor pilha 1 desenfilerado!\n");

    // OK - Imprima o topo da pilha retornada
    printf("AÇÃO - Imprima o topo da pilha retornada\n\n");
    getProximo(minhaFila, &pilhaSaida);
    ret = topo(pilhaSaida,&i);
    if (!ret)
        printf ("ERRO topo ...\n");
    else
        printf ("OK topo %d\n", i);
        for (i = 1; i<=4; i++){
        ret = desempilha(pilhaSaida, &intSaida);
        if (!ret)
            printf ("ERRO desempilha %d...\n", intSaida);
        else
            printf ("OK desempilha %d\n", intSaida);
    }

    // OK - Desenfileire a pilha
    printf("AÇÃO - Desenfileire a pilha\n\n");
    ret = desenfilera(minhaFila);
    if (!ret) {
        printf ("ERRO desenfilera pilha 2!\n");
    } else printf ("Valor pilha 2 desenfilerado!\n");

    // OK - Destrua a pilha
    printf("AÇÃO - Destrua a pilha\n\n");
    ret = destroipilha(&pilhaSaida);
    if (!ret) {
        printf ("ERRO destroi pilha 2!\n");
    } else printf ("Pilha 2 destruida!\n");

    // OK - Destrua a fila
    printf("AÇÃO - Destrua a fila\n\n");
    ret = destroi(minhaFila);
    if (!ret) {
        printf ("ERRO destroi fila 2!\n");
    } else printf ("Fila destruida!\n");

    return 0;
}
