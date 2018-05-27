

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


#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
#include "fuenteAuxiliar/cola.h"
#include "fuenteAuxiliar/pila.h"


Arbol creaNodo(tipoInfo info) {
    tipoNodo *nuevo;

    if (NULL == (nuevo = (tipoNodo *) malloc(sizeof(tipoNodo))))
        return NULL;

    nuevo->info = info;
    nuevo->izq = nuevo->der = NULL;
    return nuevo;
}


Arbol anula(Arbol raiz) {
    if (raiz == NULL)
        return NULL;

    raiz->izq = anula(raiz->izq);
    raiz->der = anula(raiz->der);
    free(raiz);
    return NULL;
}


void preOrden(Arbol raiz) {
    if (raiz != NULL) {
        printf("%c ", raiz->info);
        preOrden(raiz->izq);
        preOrden(raiz->der);
    }
}


void enOrden(Arbol raiz) {
    if (raiz != NULL) {
        enOrden(raiz->izq);
        printf("%c ", raiz->info);
        enOrden(raiz->der);
    }
}


void postOrden(Arbol raiz) {
    if (raiz != NULL) {
        postOrden(raiz->izq);
        postOrden(raiz->der);
        printf("%c ", raiz->info);
    }
}


void amplitud(Arbol raiz) {
    Cola c;
    Arbol nodo;

    colaCreaVacia(&c);
    nodo = raiz;

    if (raiz != NULL)
        colaInserta(&c, nodo);

    while (!colaVacia(&c)) {
        nodo = colaSuprime(&c);
        printf("%c ", nodo->info);

        if (nodo->izq != NULL)
            colaInserta(&c, nodo->izq);

        if (nodo->der != NULL)
            colaInserta(&c, nodo->der);
    }
}


int altura(Arbol raiz) {
    int izq, der;

    if (raiz == NULL)
        return -1;

    izq = altura(raiz->izq);
    der = altura(raiz->der);

    if (izq < der)
        return 1 + der;

    return 1 + izq;
}


int numNodos(Arbol raiz) {
    if (raiz == NULL)
        return 0;

    return 1 + numNodos(raiz->izq) + numNodos(raiz->der);
}


int sustituye(Arbol raiz, tipoInfo x, tipoInfo y) {
    int cont = 0;

    if (raiz == NULL)
        return 0;

    if (raiz->info == x) {
        raiz->info = y;
        cont++;
    }

    return cont + sustituye(raiz->izq, x, y) + sustituye(raiz->der, x, y);
}


int numNodosHoja(Arbol raiz) {
    if (raiz == NULL)
        return 0;

    if (raiz->izq == NULL && raiz->der == NULL)
        return 1;

    return numNodosHoja(raiz->izq) + numNodosHoja(raiz->der);
}


int numNodosInternos(Arbol raiz) {
    if (raiz == NULL)
        return 0;

    if (raiz->izq == NULL && raiz->der == NULL)
        return 0;

    return 1 + numNodosInternos(raiz->izq) + numNodosInternos(raiz->der);
}


int numHijoUnico(Arbol raiz) {
    int cont = 0;

    if (raiz == NULL)
        return 0;

    if (raiz->izq != NULL && raiz->der == NULL ||
        raiz->izq == NULL && raiz->der != NULL)
        cont++;

    return cont + numHijoUnico(raiz->izq) + numHijoUnico(raiz->der);
}


Arbol buscarMax(Arbol raiz) {
    Arbol izq, der;

    if (raiz == NULL)
        return NULL;

    izq = buscarMax(raiz->izq);
    der = buscarMax(raiz->der);

    if (izq != NULL && izq->info > raiz->info) {
        if (der != NULL && der->info > izq->info)
            return der;

        return izq;
    }

    if (der != NULL && der->info > raiz->info)
        return der;

    return raiz;
}


Arbol buscarMin(Arbol raiz) {
    Arbol izq, der;

    if (raiz == NULL)
        return NULL;

    izq = buscarMin(raiz->izq);
    der = buscarMin(raiz->der);

    if (izq != NULL && izq->info < raiz->info) {
        if (der != NULL && der->info < izq->info)
            return der;

        return izq;
    }

    if (der != NULL && der->info < raiz->info)
        return der;

    return raiz;
}


int similares(Arbol r1, Arbol r2) {
    if (r1 == NULL && r2 == NULL)
        return 1;

    if (r1 == NULL && r2 != NULL || r1 != NULL && r2 == NULL)
        return 0;

    if (!similares(r1->izq, r2->izq))
        return 0;

    return similares(r1->der, r2->der);
}


int equivalentes(Arbol r1, Arbol r2) {
    if (r1 == NULL && r2 == NULL)
        return 1;

    if (r1 == NULL && r2 != NULL || r1 != NULL && r2 == NULL)
        return 0;

    if (r1->info != r2->info)
        return 0;

    if (!equivalentes(r1->izq, r2->izq))
        return 0;

    return equivalentes(r1->der, r2->der);
}


Arbol especular(Arbol raiz) {
    Arbol temp;

    if (raiz == NULL)
        return NULL;

    temp = creaNodo(raiz->info);
    temp->der = especular(raiz->izq);
    temp->izq = especular(raiz->der);
    return temp;
}
