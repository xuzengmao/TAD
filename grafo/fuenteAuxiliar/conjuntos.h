

/****************************************************************************/
/*   Autor: Xuzeng Mao                                                      */
/*   Correo para cualquier duda o sugerencia: xuzengmao@usal.es             */
/*   GitHub: https://github.com/xuzengmao                                   */
/*   Fuente principal:                                                      */
/*       - Grafo: grafo.c grafo.h                                           */
/*   Fuente auxiliar:                                                       */
/*       - Pila: pila.c pila.h                                              */
/*       - Cola: cola.c cola.h                                              */
/*       - Monticulo: monticulo.c monticulo.h                               */
/*       - Conjuntos: conjuntos.c conjuntos.h                               */
/****************************************************************************/


#ifndef __CONJUNTOS_H
#define __CONJUNTOS_H

#define MAXIMO 16

typedef int particion[MAXIMO];
typedef int tipoConjunto;
typedef int tipoElementoC;

void crea(particion C);
tipoElementoC buscar(particion C, tipoElementoC x);
void unir(particion C, tipoElementoC x, tipoElementoC y);

void verParticion(particion C);

#endif
