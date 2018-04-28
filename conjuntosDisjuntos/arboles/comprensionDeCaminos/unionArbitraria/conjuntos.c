

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
		C[i] = i;
}


tipoElemento buscar(particion C, tipoElemento x) {
	if (x < 0 || x >= MAXIMO)
		return -1;

	if (C[x] == x)
		return x;

	C[x] = buscar(C, C[x]);
	return C[x];
}


void unir(particion C, tipoElemento x, tipoElemento y) {
	if (x != -1 && y != -1)
		C[y] = x;
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

