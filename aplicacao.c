#include "aplicacao.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

void VeTopoInt(Pilha* pilha) {
    void* item = Top(pilha);
    printf("Topo int");
    printf("topo: %d\n", ((ItemInt*)Top(pilha))->info);
}

void VeTopoFlo(Pilha* pilha) {
    void* item = Top(pilha);
    printf("Topo Float");
    printf("topo: %f\n", ((ItemFloat*)Top(pilha))->info);
}

void VeTopoChar(Pilha* pilha) {
    printf("Topo char");
    printf("%s\n", ((ItemChar*)Top(pilha))->info);
}



void EsvaziaPilhaInt(Pilha* pilha) {
    while(!IsEmpty(pilha)) {
        printf("%d\n", ((ItemInt*)Pop(pilha))->info);
    }
}

void EsvaziaPilhaFlo(Pilha* pilha) {
    while(!IsEmpty(pilha)) {
        printf("%f\n", ((ItemFloat*)Pop(pilha))->info);
    }
}

void EsvaziaPilhaChar(Pilha* pilha) {
    while(!IsEmpty(pilha)) {
        printf("%s\n",((ItemChar*)Pop(pilha))->info);
    }
}

void addElementoInt(int* v, Pilha* p) {
 //   ItemInt* i = (ItemInt*) malloc(sizeof(ItemInt));
   // i->info = v;
    //printf("%d\n", i->info);
    Push((void*) v, p);
}
void addElementoChar(char* s, Pilha* p) {
//    ItemChar* i = (ItemChar*) malloc(sizeof(ItemChar));
  //  strcpy(i->info, s);
    //printf("%s\n", s);
    Push((void*) s, p);
}

void addElementoFlo(float* vf, Pilha* p) {
//    ItemChar* i = (ItemChar*) malloc(sizeof(ItemChar));
  //  strcpy(i->info, s);
    //printf("%s\n", s);
    Push((void*) vf, p);
}

int main()
{
    //vai precisar de um vetor pra salvar os tipos armazenados na fila
    Pilha* P1 = Init(sizeof(ItemInt));
    Pilha* P2 = Init(sizeof(ItemChar));
    Pilha* P3 = Init(sizeof(ItemFloat));
    printf("Pilha de Inteiros: \n");
    int valor = 7;
    int valor2 = 6;
    int valor3 = 5;
    int valor4 = 4;
    printf("conteudo vari: %d\n",valor);
    printf("endereco vari: %p\n",&valor);
    addElementoInt(&valor, P1);
    Pop(P1);

    addElementoInt(&valor2, P1);
    addElementoInt(&valor3, P1);
    addElementoInt(&valor4, P1);
    valor4 = 100;
    printf("Elementos da Pilha de Inteiros: \n");

    EsvaziaPilhaInt(P1);

    printf("\n\n");
    printf("Pilha de String: \n");

    printf("Elementos da Pilha de String: \n");
    addElementoChar("A", P2);

    VeTopoChar(P2);
    addElementoChar("B", P2);
    Pop(P2);
    addElementoChar("C", P2);
    VeTopoChar(P2);
    addElementoChar("D", P2);

    EsvaziaPilhaChar(P2);

    printf("Pilha de Float: \n");
    float valor5 = 7.14;
    float valor6 = 6.50;
    float valor7 = 5.45;
    float valor8 = 4.89;
    addElementoFlo(&valor5, P3);
    Pop(P3);
    addElementoFlo(&valor6, P3);
    addElementoFlo(&valor7, P3);
    addElementoFlo(&valor8, P3);
    printf("Elementos da Pilha de Float: \n");

    EsvaziaPilhaFlo(P3);

    return 0;
}
