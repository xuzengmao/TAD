

/****************************************************************************/
/*   Autor: Xuzeng Mao                                                      */
/*   Correo para cualquier duda o sugerencia: xuzengmao@usal.es             */
/*   GitHub: https://github.com/xuzengmao                                   */
/*   Fuente principal:                                                      */
/*       - ArbolBB: arbolBB.c arbolBB.h                                     */
/****************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "arbolBB.h"


int insertar(ArbolBB *raiz, tipoClave clave) {
	if (*raiz == NULL) {
		if (NULL == (*raiz = malloc(sizeof(tipoNodo))))
			return -1;

		(*raiz)->clave = clave;
		(*raiz)->info = 1;
		return 0;
	}

	if (clave < (*raiz)->clave)
		return insertar(&(*raiz)->izq, clave);

	if (clave > (*raiz)->clave)
		return insertar(&(*raiz)->der, clave);

	(*raiz)->info++;
	return 0;
}


int buscar(ArbolBB raiz, tipoClave clave, tipoNodo **nodo) {
	if (raiz == NULL) {
		*nodo = NULL;
		return 0;
	}

	if (clave < raiz->clave)
		return buscar(raiz->izq, clave, nodo);

	if (clave > raiz->clave)
		return buscar(raiz->der, clave, nodo);

	*nodo = raiz;
	return raiz->info;
}


int eliminar(ArbolBB *raiz, tipoClave clave) {

}


tipoNodo *creaNodo(tipoClave clave, tipoInfo info) {
	tipoNodo *nuevo;

	if (NULL == (nuevo = malloc(sizeof(tipoNodo))))
		return NULL;

	nuevo->clave = clave;
	nuevo->info = info;
	nuevo->izq = nuevo->der = NULL;
}


ArbolBB anula(ArbolBB raiz) {
	if (raiz)
		return NULL;

	raiz->izq = anula(raiz->izq);
	raiz->der = anula(raiz->der);
	free(raiz);
	return NULL;
}


void preOrden(ArbolBB raiz){
	if (raiz) {
		printf("%d %d \n", raiz->clave, raiz->info);
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}


void enOrden(ArbolBB raiz) {
	if (raiz) {
		enOrden(raiz->izq);
		printf("%d %d \n", raiz->clave, raiz->info);
		enOrden(raiz->der);	
	}
}


void posOrden(ArbolBB raiz) {
	if (raiz) {
		posOrden(raiz->izq);
		posOrden(raiz->der);
		printf("%d %d \n", raiz->clave, raiz->info);
	}
}
