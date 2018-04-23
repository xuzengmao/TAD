

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


#ifndef __ARBOL_H
#define __ARBOL_H

typedef char tipoInfo;

typedef struct tipoNodo {
	tipoInfo info;
	struct tipoNodo *izq, *der;
} tipoNodo;

typedef tipoNodo *Arbol;

Arbol creaNodo(tipoInfo info);
Arbol anula(Arbol raiz);

void preOrden(Arbol raiz);
void enOrden(Arbol raiz);
void postOrden(Arbol raiz);
void amplitud(Arbol raiz);


#endif
