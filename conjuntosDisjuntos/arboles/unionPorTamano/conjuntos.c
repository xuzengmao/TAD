

/****************************************************************************/
/*   Autor: Xuzeng Mao                                                      */
/*   Correo para cualquier duda o sugerencia: xuzengmao@usal.es             */
/*   GitHub: https://github.com/xuzengmao                                   */
/*   Fuente principal:                                                      */
/*       - Conjuntos: conjuntos.c conjuntos.h                               */
/****************************************************************************/


#include <stdio.h>
#include <stdlib.h>

#include "conjuntos.h"


void crea(particion C) {
    int i;

    for (i = 0; i < MAXIMO; i++)
        C[i] = -1;
}


tipoElemento buscar(particion C, tipoElemento x) {
    if (x < 0 || x >= MAXIMO)
        return -1;

    if (C[x] < 0)
        return x;

    return buscar(C, C[x]);
}


void unir(particion C, tipoElemento x, tipoElemento y) {
    if (x != -1 && y != -1 && x != y)
        if (C[x] <= C[y]) {
            C[x] += C[y];
            C[y] = x;
        } else {
            C[y] += C[x];
            C[x] = y;
        }
}


void verParticion(particion C) {
    int i;

    printf("\n");

    for (i = 0; i < MAXIMO; i++)
        printf("|%2d", C[i]);

    printf("| contenido vector\n");

    for (i = 0; i < MAXIMO; i++)
        printf("---");

    printf("\n");

    for (i = 0; i < MAXIMO; i++)
        printf(" %2d", i);

    printf("  indice vector\n\n");
}

