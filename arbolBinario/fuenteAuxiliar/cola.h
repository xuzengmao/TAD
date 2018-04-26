

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


#ifndef __COLA_H
#define __COLA_H

#include "../arbol.h"

typedef Arbol tipoElemento;

#ifndef TIPO_CELDA
#define TIPO_CELDA

typedef struct tipoCelda { 
	tipoElemento elemento; 
	struct tipoCelda * sig; 
	} tipoCelda;
	
#endif

typedef struct {
        tipoCelda *frente, *fondo;
} Cola;

int colaCreaVacia(Cola *c);
int colaVacia(Cola *c);
int colaInserta(Cola *c, tipoElemento elemento);
tipoElemento colaSuprime(Cola *c);

#endif
