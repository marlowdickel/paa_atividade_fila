#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include "fila_publico.h"

#ifndef APLICACAO_H
#define APLICACAO_H

typedef struct {
    int info;
} ItemInt;

typedef struct {
    char info[255];
} ItemChar;

typedef struct {
    float info;
} ItemFloat;

#endif
