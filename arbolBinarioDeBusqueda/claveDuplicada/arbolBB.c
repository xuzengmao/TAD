

/****************************************************************************/
/*   Autor: Xuzeng Mao                                                      */
/*   Correo para cualquier duda o sugerencia: xuzengmao@usal.es             */
/*   GitHub: https://github.com/xuzengmao                                   */
/*   Fuente principal:                                                      */
/*       - ArbolBB: arbolBB.c arbolBB.h                                     */
/****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbolBB.h"


int insertar(ArbolBB *raiz, tipoClave clave, tipoInfo info) {
    tipoNodo *nuevo;

    if (*raiz == NULL) {
        if (NULL == (*raiz = creaNodo(clave, info)))
            return -1;

        return 0;
    }

    if (clave < (*raiz)->clave)
        return insertar(&(*raiz)->izq, clave, info);

    if (clave > (*raiz)->clave)
        return insertar(&(*raiz)->der, clave, info);

    if (NULL == (nuevo = creaNodo(clave, info)))
        return -1;

    nuevo->izq = (*raiz)->izq;
    (*raiz)->izq = nuevo;
    return 0;
}


int eliminar(ArbolBB *raiz, tipoClave clave) {
    ArbolBB aux, ant, aBorrar;
    int nVeces = 0;

    if (*raiz == NULL)
        return 0;

    if (clave < (*raiz)->clave)
        return eliminar(&(*raiz)->izq, clave);

    if (clave > (*raiz)->clave)
        return eliminar(&(*raiz)->der, clave);

    aux = *raiz;
    
    while (aux->izq != NULL && aux->izq->clave == clave) {
        aBorrar = aux->izq;
        aux->izq = aux->izq->izq;
        nVeces++;
        free(aBorrar);
    }

    if (aux->der == NULL)
        *raiz = aux->izq;
    else if (aux->izq == NULL)
        *raiz = aux->der;
    else {
        ant = aux;
        aux = aux->der;

        while (aux->izq) {
            ant = aux;
            aux = aux->izq;
        }

        (*raiz)->clave = aux->clave;
        strcpy ((*raiz)->info, aux->info);

        if (ant == *raiz)
            ant->der = aux->der;
        else
            ant->izq = aux->der;
    }

    nVeces++;
    free(aux);
    return nVeces;
}


tipoNodo *creaNodo(tipoClave clave, tipoInfo info) {
    tipoNodo *nuevo;

    if (NULL == (nuevo = malloc(sizeof(tipoNodo))))
        return NULL;

    nuevo->clave = clave;
    strcpy(nuevo->info, info);
    nuevo->izq = nuevo->der = NULL;
}


ArbolBB anula(ArbolBB raiz) {
    if (raiz)
        return NULL;

    raiz->izq = anula(raiz->izq);
    raiz->der = anula(raiz->der);
    free(raiz);
    return NULL;
}


void preOrden(ArbolBB raiz){
    if (raiz) {
        printf("%d %s \n", raiz->clave, raiz->info);
        preOrden(raiz->izq);
        preOrden(raiz->der);
    }
}


void enOrden(ArbolBB raiz) {
    if (raiz) {
        enOrden(raiz->izq);
        printf("%d %s \n", raiz->clave, raiz->info);
        enOrden(raiz->der); 
    }
}


void posOrden(ArbolBB raiz) {
    if (raiz) {
        posOrden(raiz->izq);
        posOrden(raiz->der);
        printf("%d %s \n", raiz->clave, raiz->info);
    }
}
