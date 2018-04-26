

/****************************************************************************/
/*   Autor: Xuzeng Mao                                                      */
/*   Correo para cualquier duda o sugerencia: xuzengmao@usal.es             */
/*   GitHub: https://github.com/xuzengmao                                   */
/*   Fuente: pila.c pila.h                                                  */
/****************************************************************************/


#ifndef __PILA_H
#define __PILA_H

typedef int tipoElemento;

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
