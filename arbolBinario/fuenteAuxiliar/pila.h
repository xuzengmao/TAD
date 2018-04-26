

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


#ifndef __PILA_H
#define __PILA_H

#include "../arbol.h"

typedef Arbol tipoElemento;

#ifndef TIPO_CELDA
#define TIPO_CELDA

typedef struct tipoCelda { 
	tipoElemento elemento; 
	struct tipoCelda * sig; 
	} tipoCelda;
	
#endif
	
typedef tipoCelda * Pila;

int pilaCreaVacia(Pila *p);
int pilaVacia(Pila *p);
int pilaInserta(Pila *p,tipoElemento elemento);
tipoElemento pilaSuprime(Pila *p);


#endif
