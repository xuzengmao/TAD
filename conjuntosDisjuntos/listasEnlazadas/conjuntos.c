

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

	for (i = 0; i < MAXIMO; i++) {
		C[i].primero = malloc(sizeof(tipoCelda));
		C[i].ultimo = C[i].primero;
		C[i].primer->elemento = i;
		C[i].sig = NULL;
	}
}


tipoElemento buscar(particion C, tipoElemento x) {
	tipoCelda *aux;
	int i;

	for (i = 0; i < MAXIMO; i++) {
		aux = C[i].primero;

		while (aux != NULL) {
			if (aux->elemento == x)
				return i;

			aux = aux->sig;
		}
	}

	return -1;
}


void unir(particion C, tipoElemento x, tipoElemento y) {
	int a, b;

	if ( x != -1 && y != -1 && x != y) {
		C[x].ultimo->sig = C[y].primero;
		C[x].ultimo = C[y].ultimo;
		C[y].primero = C[y].ultimo = NULL;
	}
}


void verParticion(particion C) {
	tipoCelda *aux;
	int i;

	for (i = 0; i < MAXIMO; i++) {
		aux = C[i].primero;

		if (aux != NULL)
			printf("\n\nClase equivalencia representante %d: ", i);

		while (aux != NULL) {
			printf("%d ", aux->elemento);
			aux = aux->sig;
		}
	}
}


void verClaseEquivalencia(particion C, tipoElemento x) {
	int representante;
	tipoCelda *aux;

	representante = buscar(C, x);
	printf("\n\nClase de Equivalencia de %d cuyo representante es %d: ", x, representante);
	aux = C[representante].primero;

	while (aux) {
		printf(" %d ", aux->elemento);
		aux = aux->sig;
	}

	printf("\n\n");
}
