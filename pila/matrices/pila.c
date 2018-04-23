

/****************************************************************************/
/*   Autor: Xuzeng Mao                                                      */
/*   Correo para cualquier duda o sugerencia: xuzengmao@usal.es             */
/*   GitHub: https://github.com/xuzengmao                                   */
/*   Fuente: cola.c cola.h                                                  */
/****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "pila.h"


int pilaCreaVacia(Pila *p) {
	if (p == NULL)
		return -1;

	(*p).tope = -1;
	return 0;
}


int pilaVacia(Pila *p) {
	if ((*p).tope == -1)
		return 1;

	return 0;
}


int pilaInserta(Pila *p, tipoElemento elemento) {
	if (p == NULL) 
		return -1;

	if ((*p).tope == MAX-1)
		return -2;

	(*p).tope++;
	(*p).elementos[(*p).tope] = elemento;
	return 0;
}


tipoElemento pilaSuprime(Pila *p) {
	tipoElemento valor;

	if (p != NULL && !pilaVacia(p)) {
		valor = (*p).elementos[(*p).tope];
		(*p).tope--;
		return valor;
	}
}
