

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


#ifndef __GRAFOS_H
#define __GRAFOS_H

#include "fuenteAuxiliar/monticulo.h"

#define N 10
#define INF 999999

typedef struct arco {
	int v;
	int peso;
	struct arco *sig;
} arco;

typedef arco *pArco;

typedef struct {
	int alcanzado;
	int gradoEntrada;
	int ordenTop;
	int distancia;
	int peso;
	int anterior;
	pArco lista;
} vertices;

typedef struct {
	vertices directorio[N];
	int orden;
} Grafo;

void profundidad(Grafo *g, int vInicio);
void profundidadMejorado(Grafo *g, int vInicio);

void amplitud(Grafo *g, int vInicio);
void amplitudMejorado(Grafo *g, int vInicio);

int buscarVerticeGradoCeroNoOrdenTop(Grafo *g);
int ordenTopBasico(Grafo *g);
int ordenTop(Grafo *g);

void caminosBasico(Grafo *g, int vInicio);
void caminos(Grafo *g, int vInicio);

int buscarVerticeDistanciaMinimaNoAlcanzado(Grafo *g);
void dijkstraBasico(Grafo *g, int vInicio);
void dijkstra(Grafo *g, int vInicio);

int costeYTrayectoria(Grafo *g, int vInicio, int vFin);
void todosCaminosMin(Grafo *g, int vInicio);

int buscarVerticeCostoMinimoNoAlcanzado(Grafo *g);
void construirMonticuloDeAristas(Grafo *g, Monticulo *m);
void aceptarArista (Grafo *g, tipoElemento x);
Grafo *crearArbolDeExpansion(Grafo *g);
Grafo *primBasico(Grafo *g);
Grafo *prim(Grafo *g);
Grafo *kruskal(Grafo *g);

void iniciar(Grafo *g);
void verGrafo(Grafo *g);
void liberarListas(Grafo *g);

#endif
