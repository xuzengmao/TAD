

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


tipoNodo *creaNodo(tipoClave clave, tipoInfo info) {
	tipoNodo *nuevo;

	if (NULL == (nuevo) = malloc(sizeof(tipoNodo)))
		return NULL;

	nuevo->clave = clave;
	nuevo->info = info;
	nuevo->izq = nuevo->der = NULL;
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
