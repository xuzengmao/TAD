

/****************************************************************************/
/*   Autor: Xuzeng Mao                                                      */
/*   Correo para cualquier duda o sugerencia: xuzengmao@usal.es             */
/*   GitHub: https://github.com/xuzengmao                                   */
/*   Fuente principal:                                                      */
/*       - Grafo: grafo.c grafo.h                                           */
/*   Fuente auxiliar:                                                       */
/*       - Pila: pila.c pila.h                                              */
/*       - Cola: cola.c cola.h                                              */
/*       - Monticulo: monticulo.c monticulo.h                               */
/*       - Conjuntos: conjuntos.c conjuntos.h                               */
/****************************************************************************/


#include <stdio.h>
#include <stdlib.h>

#include "conjuntos.h"


void crea(particion C) {
	int i;

	for (i = 0; i < MAX; i++)
		C[i] = -1;
}


tipoElementoC buscar(particion C, tipoElementoC x) {
	if (x < 0 || x >= MAX)
		return -1;

	if (C[x] < 0)
		return x;

	C[x] = buscar(C, C[x]);
	return C[x];
}


void unir(particion C, tipoElementoC x, tipoElementoC y) {
	if (x != -1 && y != -1 && x != y)
		if (C[x] < C[y]) 
			C[y] = x;
		if (C[y] < C[x])
			C[x] = y;
		else {
			C[x]--;
			C[y] = x;
		}
}


void verParticion(particion C) {
	int i;

	printf("\n");

	for (i = 0; i < MAX; i++)
		printf("|%2d", C[i]);

	printf("| contenido vector\n");

	for (i = 0; i < MAX; i++)
		printf("---");

	printf("\n");

	for (i = 0; i < MAX; i++)
		printf(" %2d", i);

	printf("  indice vector\n\n");
}

