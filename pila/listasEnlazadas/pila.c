

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

	*p = NULL;
	return 0;
}


int pilaVacia(Pila *p) {
	if (*p == NULL)
		return 1;

	return 0;
}


int pilaInserta(Pila *p, tipoElemento elemento) {
	tipoCelda * nuevo;

	if (p == NULL) 
		return -1;

	if (NULL == (nuevo = malloc(sizeof(tipoCelda))))
		return -2;

	(*nuevo).elemento = elemento;
	(*nuevo).sig = *p;
	*p = nuevo;
	return 0;
}


tipoElemento pilaSuprime(Pila *p) {
	tipoElemento valor;
	tipoCelda * aBorrar;

	if (p != NULL && !pilaVacia(p)) {
		valor = (**p).elemento;
		aBorrar = *p;
		*p = (**p).sig;
		free(aBorrar);
		return valor;
	}
}
