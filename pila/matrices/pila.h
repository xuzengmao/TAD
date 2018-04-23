

/****************************************************************************/
/*   Autor: Xuzeng Mao                                                      */
/*   Correo para cualquier duda o sugerencia: xuzengmao@usal.es             */
/*   GitHub: https://github.com/xuzengmao                                   */
/*   Fuente: pila.c pila.h                                                  */
/****************************************************************************/


#ifndef __PILA_H
#define __PILA_H

#define MAX 100

typedef int tipoElemento;

typedef struct {
    int tope;
    tipoElemento elementos[MAX];
} Pila;
	
int pilaCreaVacia(Pila *p);
int pilaVacia(Pila *p);
int pilaInserta(Pila *p, tipoElemento elemento);
tipoElemento pilaSuprime(Pila *p);

#endif
