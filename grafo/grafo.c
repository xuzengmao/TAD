

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


#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"
#include "fuenteAuxiliar/cola.h"

void profundidad(Grafo *g, int vInicio) {
	pArco p;
	int w;

	printf("%d ", vInicio);
	g->directorio[vInicio].alcanzado = 1;
	p = g->directorio[vInicio].lista;

	while (p != NULL) {
		w = p->v;

		if (!g->directorio[w].alcanzado)
			profundidad(g, w);

		p = p->sig;
	}
}


void profundidadMejorado(Grafo *g, int vInicio) {
	int i;

	profundidad(g, vInicio);

	for (i = 1; i <= g->orden; i++)
		if (!g->directorio[i].alcanzado)
			profundidad(g, i);
}


void amplitud(Grafo *g, int vInicio) {
	pArco p;
	Cola c;
	int w;

	colaCreaVacia(&c);
	colaInserta(&c, vInicio);

	while (!colaVacia(&c)) {
		w = colaSuprime(&c);

		if (!g->directorio[w].alcanzado) {
			printf("%d ", w);
			g->directorio[w].alcanzado = 1;
			p = g->directorio[w].lista;

			while (p != NULL) {
				w = p->v;
				colaInserta(&c, w);
				p = p->sig;
			}
		}
	}
}


void amplitudMejorado(Grafo *g, int vInicio) {
	int i;

	amplitud(g, vInicio);

	for (i = 1; i <= g->orden; i++)
		if (!g->directorio[i].alcanzado)
			amplitud(g, i);
}


void iniciar(Grafo *g) {
	int i, j, w;
	pArco p;

	for (i = 1; i <= g->orden; i++) {
		g->directorio[i].alcanzado = 0;
		g->directorio[i].ordenTop = 0;
		g->directorio[i].distancia = INF;
		g->directorio[i].peso = INF;
		g->directorio[i].anterior = 0;

		w = 0;

		for (j = 1; j <= g->orden; j++) {
			p = g->directorio[j].lista;

			while (p != NULL) {
				if (p->v == i)
					w++;

				p = p->sig;
			}
		}

		g->directorio[i].gradoEntrada = w;
	}
}


void verGrafo(Grafo *g) {
	int i;
	pArco p;

	printf("\nGrafo (orden %d)\n\n", g->orden);
	printf("       alc gEnt oTop dist peso ant \n");
	printf("     +----+----+----+----+----+----+\n");

	for (i = 1; i <=g->orden; i++) {
		printf("  %2d | %2d | %2d | %2d |", i, g->directorio[i].alcanzado, g->directorio[i].gradoEntrada, g->directorio[i].ordenTop);

		if (g->directorio[i].distancia == INF)
			printf("  * |");
		else
			printf(" %2d |", g->directorio[i].distancia);

		if (g->directorio[i].peso == INF)
			printf("  * |");
		else
			printf(" %2d |", g->directorio[i].anterior);

		p = g->directorio[i].lista;

		while (p != NULL) {
			printf(" ->%2d,%2d", p->v, p->peso);
			p = p->sig;
		}

		printf("\n");
	}

	printf("     +----+----+----+----+----+----+\n\n");
}


void liberarListas(Grafo *g) {
	pArco p, aBorrar;
	int i;

	for (i = 1; i <= g->orden; i++) {
		p = g->directorio[i].lista;
		g->directorio[i].lista = NULL;

		while (p != NULL) {
			aBorrar = p;
			p = p->sig;
			free(aBorrar);
		}
	}
}
