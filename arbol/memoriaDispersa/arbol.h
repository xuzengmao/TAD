

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

int altura(Arbol raiz);
int numNodos(Arbol raiz);
int sustituye(Arbol raiz, tipoInfo x, tipoInfo y);
int numNodosHoja(Arbol raiz);
int numNodosInternos(Arbol raiz);
int numHijoUnico(Arbol raiz);
Arbol buscarMax(Arbol raiz);
Arbol buscarMin(Arbol raiz);
int similares(Arbol r1, Arbol r2);
int equivalentes(Arbol r1, Arbol r2);
Arbol especular(Arbol raiz);

#endif
