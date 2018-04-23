

/****************************************************************************/
/*   Autor: Xuzeng Mao                                                      */
/*   Correo para cualquier duda o sugerencia: xuzengmao@usal.es             */
/*   GitHub: https://github.com/xuzengmao                                   */
/*   Fuente: cola.c cola.h                                                  */
/****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "cola.h"


int colaCreaVacia(Cola *c) {
	if (c == NULL)
		return -1;

	(*c).tamagno = 0;
	(*c).frente = 0;
	(*c).fondo = MAX - 1;
	return 0;
}


int colaVacia(Cola *c) {
	if ((*c).tamagno == 0)
		return 1;

	return 0;
}


int colaInserta(Cola *c, tipoElemento elemento) {
	if (c == NULL)
		return -1;

	if ((*c).tamagno == MAX)
		return -2;

	if ((*c).fondo == MAX - 1)
		(*c).fondo = 0;
	else
		(*c).fondo++;

	(*c).elementos[(*c).fondo] = elemento;
	(*c).tamagno++;
	return 0;
}


tipoElemento colaSuprime(Cola *c) {
	tipoElemento valor;

	if (c != NULL && !colaVacia(c)) {
		valor = (*c).elementos[(*c).frente];

		if((*c).frente == MAX -1)
			(*c).frente = 0;
		else
			(*c).frente++;
		
		(*c).tamagno--;
		return valor;
	}
}
