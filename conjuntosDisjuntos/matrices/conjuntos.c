

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
	return C[x];
}


void unir(particion C, tipoElemento x, tipoElemento y) {
	int i;

	for (i = 0; i < MAXIMO; i++)
		if (C[i] == C[y])
			C[i] = C[x];
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
		printf("%2d", i);

	printf("  indices vector\n\n");
}


void verClaseEquivalencia(particion C, tipoElemento x) {
	int i, representante;

	representante = buscar(C, x);
	printf("\n\nClase de Equivalencia de %d cuyo representante es %d: ", x, representante);

	for (i = 0; i < MAXIMO; i++)
		if (C[i] == representante)
			printf("%d ", i);

	printf("\n");
}
