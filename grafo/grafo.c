

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
#include "fuenteAuxiliar/pila.h"
#include "fuenteAuxiliar/monticulo.h"
#include "fuenteAuxiliar/conjuntos.h"

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


int buscarVerticeGradoCeroNoOrdenTop(Grafo *g) {
	int i;

	for (i = 1; i <= g->orden; i++)
		if (!g->directorio[i].gradoEntrada && !g->directorio[i].ordenTop)
			return i;

	return -1;
}


int ordenTopBasico(Grafo *g) {
	int orden, v, w;
	pArco p;

	for (orden = 1; orden <= g->orden; orden++) {
		if (-1 == (v = buscarVerticeGradoCeroNoOrdenTop(g)))
			return -1;

		g->directorio[v].ordenTop = orden;
		p = g->directorio[v].lista;

		while (p != NULL) {
			w = p->v;
			g->directorio[w].gradoEntrada--;
			p = p->sig;
		}
	}

	return 0;
}


int ordenTop(Grafo *g) {
	int orden, v, w;
	Cola c;
	pArco p;

	colaCreaVacia(&c);

	for (v = 1; v <= g->orden; v++)
		if (!g->directorio[v].gradoEntrada)
			colaInserta(&c, v);

	orden = 1;

	while (!colaVacia(&c)) {
		v = colaSuprime(&c);
		g->directorio[v].ordenTop = orden++;
		p = g->directorio[v].lista;

		while (p != NULL) {
			w = p->v;

			if (!--g->directorio[w].gradoEntrada)
				colaInserta(&c, w);

			p = p->sig;
		}
	}

	if (orden == g->orden)
		return 0;

	return -1;
}


void caminosBasico(Grafo *g, int vInicio) {
	int distanciaActual;
	int v, w;
	pArco p;

	g->directorio[vInicio].distancia = g->directorio[vInicio].anterior = 0;

	for (distanciaActual = 0; distanciaActual < g->orden; distanciaActual++)
		for (v = 1; v <= g->orden; v++)
			if (!g->directorio[v].alcanzado && g->directorio[v].distancia == distanciaActual) {
				g->directorio[v].alcanzado = 1;
				p = g->directorio[v].lista;

				while (p != NULL) {
					w = p->v;

					if (g->directorio[w].distancia == INF) {
						g->directorio[w].distancia = g->directorio[v].distancia + 1;
						g->directorio[w].anterior = v;
					}

					p = p->sig;
				}
			}
}


void caminos(Grafo *g, int vInicio) {
	pArco p;
	int v, w;
	Cola c;

	g->directorio[vInicio].distancia = g->directorio[vInicio].anterior = 0;
	colaCreaVacia(&c);
	colaInserta(&c, vInicio);

	while (!colaVacia(&c)) {
		v = colaSuprime(&c);
		p = g->directorio[v].lista;

		while (p != NULL) {
			w = p->v;

			if (g->directorio[w].distancia == INF) {
				g->directorio[w].distancia = g->directorio[v].distancia + 1;
				g->directorio[w].anterior = v;
				colaInserta(&c, w);
			}

			p = p->sig;
		}
	}
}


int buscarVerticeDistanciaMinimaNoAlcanzado(Grafo *g) {
	int i, distanciaMinima = INF + 1, v = -1;

	for (i = 1; i <= g->orden; i++)
		if (!g->directorio[i].alcanzado && g->directorio[i].distancia < distanciaMinima) {
			distanciaMinima = g->directorio[i].distancia;
			v = i;
		}

	return v;
}


void dijkstraBasico(Grafo *g, int vInicio) {
	pArco p;
	int i, v, w;

	g->directorio[vInicio].distancia = g->directorio[vInicio].anterior = 0;

	for (i = 1; i <= g->orden; i++) {
		v = buscarVerticeDistanciaMinimaNoAlcanzado(g);
		g->directorio[v].alcanzado++;
		p = g->directorio[v].lista;

		while (p != NULL) {
			w = p->v;

			if (!g->directorio[w].alcanzado)
				if (g->directorio[v].distancia + p->peso < g->directorio[w].distancia) {
					g->directorio[w].distancia = g->directorio[v].distancia + p->peso;
					g->directorio[w].anterior = v;
				}

			p = p->sig;
		}
	}
}


void dijkstra(Grafo *g, int vInicio) {
	pArco p;
	int i, v, w, coste;
	Monticulo m;
	tipoElemento x;

	g->directorio[vInicio].distancia = g->directorio[vInicio].anterior = 0;
	iniciarMonticulo(&m);
	x.clave = 0;
	x.informacion.v = vInicio;
	insertar(&m, x);

	while (!vacioMonticulo(m)) {
		eliminarMinimo(&m, &x);

		if (!g->directorio[x.informacion.v].alcanzado) {
			v = x.informacion.v;
			g->directorio[v].alcanzado++;
			p = g->directorio[v].lista;

			while (p != NULL) {
				w = p->v;

				if (!g->directorio[w].alcanzado) {
					coste = g->directorio[v].distancia + p->peso;

					if (coste < g->directorio[w].distancia) {
						g->directorio[w].distancia = coste;
						g->directorio[w].anterior = v;
						x.clave = coste;
						x.informacion.v = w;
						insertar(&m, x);
					}
				}

				p = p->sig;
			}
		}
	}
}


int costeYTrayectoria(Grafo *g, int vInicio, int vFin) {
	Pila p;
	int w;

	if (g->directorio[vFin].distancia != INF) {
		pilaCreaVacia(&p);
		w = vFin;

		while (w) {
			pilaInserta(&p, w);
			w = g->directorio[w].anterior;
		}

		while(!pilaVacia(&p))
			printf (" -> %d", pilaSuprime(&p));
	}

	return g->directorio[vFin].distancia;
}


void todosCaminosMin(Grafo *g, int vInicio) {
	int i, distancia;

	for (i = 1; i <= g->orden; i++) {
		printf("\nDe %d a %d:", vInicio, i);
		distancia = costeYTrayectoria(g, vInicio, i);
		
		if (distancia != INF)
			printf(" | Camino de coste %d.", distancia);
		else
			printf("No existe camino.");
	}
}


int buscarVerticeCostoMinimoNoAlcanzado(Grafo *g) {
	int i, costoMinimo = INF + 1, v = -1;

	for (i = 1; i <= g->orden; i++)
		if (!g->directorio[i].alcanzado && g->directorio[i].peso < costoMinimo) {
			costoMinimo = g->directorio[i].peso;
			v = i;
		}

	return v;
}


void construirMonticuloDeAristas(Grafo *g, Monticulo *m) {
	int i;
	pArco p;
	tipoElemento x;

	iniciarMonticulo(m);

	for (i = 1; i <= g->orden; i++) {
		p = g->directorio[i].lista;

		while (p != NULL) {
			x.clave = p->peso;
			x.informacion.v = i;
			x.informacion.w = p->v;
			insertar(m, x);
			p = p->sig;
		}
	}
}

void aceptarArista(Grafo *g, tipoElemento x) {
	pArco p;
	int i;

	if (NULL == (p = malloc(sizeof(arco)))) {
		liberarListas(g);
		free(g);
		g = NULL;
	} else {
		p->v = x.informacion.w;
		p->peso = x.clave;
		p->sig = g->directorio[x.informacion.v].lista;
		g->directorio[x.informacion.v].lista = p;

		if (NULL == (p = malloc(sizeof(arco)))) {
			liberarListas(g);
			free(g);
			g = NULL;
		} else {
			p->v = x.informacion.v;
			p->peso = x.clave;
			p->sig = g->directorio[x.informacion.w].lista;
			g->directorio[x.informacion.w].lista = p;
		}
	}
}


Grafo *crearArbolDeExpansion(Grafo *g) {
	Grafo *arbol;
	tipoElemento x;
	int i;

	if (NULL == (arbol = calloc(1, sizeof(Grafo))))
		return NULL;

	arbol->orden = g->orden;

	for (i = 1; i <= g->orden; i++) {
		x.clave = g->directorio[i].peso;
		x.informacion.v = i;
		x.informacion.w = g->directorio[i].anterior;

		if (x.informacion.w) {
			aceptarArista(arbol, x);
			
			if (arbol == NULL)
				return NULL;
		}
	}

	return arbol;
}

Grafo *primBasico(Grafo *g) {
	pArco p;
	int i, v, w;
	int vInicio = 1;

	g->directorio[vInicio].peso = g->directorio[vInicio].anterior = 0;

	for (i = 1; i <= g->orden; i++) {
		v = buscarVerticeCostoMinimoNoAlcanzado(g);
		g->directorio[v].alcanzado++;
		p = g->directorio[v].lista;

		while (p != NULL) {
			w = p->v;

			if (!g->directorio[w].alcanzado)
				if (g->directorio[w].peso > p->peso) {
					g->directorio[w].peso = p->peso;
					g->directorio[w].anterior = v;
				}
		
			p = p->sig;
		}
	}

	return crearArbolDeExpansion(g);
}


Grafo *prim(Grafo *g) {
	pArco p;
	int i, v, w;
	Monticulo m;
	tipoElemento x;
	int vInicio = 1;

	g->directorio[vInicio].peso = g->directorio[vInicio].anterior = 0;
	iniciarMonticulo(&m);
	x.clave = 0;
	x.informacion.v = vInicio;
	insertar(&m, x);

	while (!vacioMonticulo(m)) {
		eliminarMinimo(&m, &x);

		if (!g->directorio[x.informacion.v].alcanzado) {
			v = x.informacion.v;
			g->directorio[v].alcanzado++;
			p = g->directorio[v].lista;

			while (p != NULL) {
				w = p->v;

				if (!g->directorio[w].alcanzado) {
					if (p->peso < g->directorio[w].peso) {
						g->directorio[w].peso = p->peso;
						g->directorio[w].anterior = v;
						x.clave = p->peso;
						x.informacion.v = w;
						insertar(&m, x);
					}
				}

				p = p->sig;
			}
		}
	}

	return crearArbolDeExpansion(g);
}


Grafo *kruskal(Grafo *g) {
	Monticulo m;
	int nAristasAceptadas = 0;
	particion C;
	tipoConjunto conjuntoV, conjuntoW;
	tipoElemento x;
	Grafo *arbolExp;

	if (NULL == (arbolExp = calloc(1, sizeof(Grafo))))
		return NULL;

	arbolExp->orden = g->orden;

	crea(C);
	construirMonticuloDeAristas(g, &m);

	while (nAristasAceptadas < g->orden - 1) {
		if (-1 == eliminarMinimo(&m, &x)) {
			liberarListas(arbolExp);
			free(arbolExp);
			return NULL;
		}
		
		conjuntoV = buscar(C, x.informacion.v);
		conjuntoW = buscar(C, x.informacion.w);

		if (conjuntoV != conjuntoW) {
			unir(C, conjuntoV, conjuntoW);
			nAristasAceptadas++;
			aceptarArista(arbolExp, x);
			
			if (arbolExp == NULL)
				return NULL;
		}
	}

	return arbolExp;
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
			printf(" %2d |", g->directorio[i].peso);

		printf(" %2d |",g->directorio[i].anterior);

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
