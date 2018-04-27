

/****************************************************************************/
/*   Autor: Xuzeng Mao                                                      */
/*   Correo para cualquier duda o sugerencia: xuzengmao@usal.es             */
/*   GitHub: https://github.com/xuzengmao                                   */
/*   Fuente principal:                                                      */
/*       - Conjuntos: conjuntos.c conjuntos.h                               */
/****************************************************************************/


#ifndef __CONJUNTOS_H
#define __CONJUNTOS_H

#define MAXIMO 16

typedef int tipoElemento;

typedef int particion[MAXIMO];
typedef int tipoConjunto;
typedef int tipoElemento;

void crea(particion C);
tipoElemento buscar(particion C, tipoElemento x);
void unir(particion C, tipoElemento x, tipoElemento y);

void verParticion(particion C);

#endif
