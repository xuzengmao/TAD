

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

#ifndef TIPO_CELDA
#define TIPO_CELDA

typedef struct tipoCelda {
	tipoElemento elemento;
	struct tipoCelda *sig;
} tipoCelda;

#endif

typedef struct {
	tipoCelda *primero, *ultimo;
} tipoLista;

typedef tipoLista particion[MAXIMO];
typedef int tipoConjunto;

void crea(particion C);
tipoElemento buscar(particion C, tipoElemento x);
void unir(particion C, tipoElemento x, tipoElemento y);

void verParticion(particion C);
void verClaseEquivalencia(particion C, tipoElemento x);
void liberarParticion(particion C);

#endif
