

/****************************************************************************/
/*   Autor: Xuzeng Mao                                                      */
/*   Correo para cualquier duda o sugerencia: xuzengmao@usal.es             */
/*   GitHub: https://github.com/xuzengmao                                   */
/*   Fuente principal:                                                      */
/*       - Arbol: arbol.c arbol.h                                           */
/*   Fuente auxiliar:                                                       */
/*       - Cola: cola.c cola.h                                              */
/*       - Pila: pila.c pila.h                                              */
/****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
#include "fuenteAuxiliar/cola.h"
#include "fuenteAuxiliar/pila.h"


Arbol creaNodo(tipoInfo info) {
	tipoNodo *nuevo;

	if (NULL == (nuevo = (tipoNodo *) malloc(sizeof(tipoNodo))))
		return NULL;

	nuevo->info = info;
	nuevo->izq = nuevo->der = NULL;
	return nuevo;
}


Arbol anula(Arbol raiz) {
	if (raiz == NULL)
		return NULL;

	raiz->izq = anula(raiz->izq);
	raiz->der = anula(raiz->der);
	free(raiz);
	return NULL;
}


void preOrden(Arbol raiz) {
	if (raiz != NULL) {
		printf("%c ", raiz->info);
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}


void enOrden(Arbol raiz) {
	if (raiz != NULL) {
		enOrden(raiz->izq);
		printf("%c ", raiz->info);
		enOrden(raiz->der);
	}
}


void postOrden(Arbol raiz) {
	if (raiz != NULL) {
		postOrden(raiz->izq);
		postOrden(raiz->der);
		printf("%c ", raiz->info);
	}
}


void amplitud(Arbol raiz) {
	Cola c;
	Arbol nodo;

	colaCreaVacia(&c);
	nodo = raiz;

	if (raiz != NULL)
		colaInserta(&c, nodo);

	while (!colaVacia(&c)) {
		nodo = colaSuprime(&c);
		printf("%c ", nodo->info);

		if (nodo->izq != NULL)
			colaInserta(&c, nodo->izq);

		if (nodo->der != NULL)
			colaInserta(&c, nodo->der);
	}
}

