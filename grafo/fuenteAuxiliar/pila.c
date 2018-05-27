

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
#include "pila.h"


int pilaCreaVacia(Pila *p) {
    if (p == NULL)
        return -1;

    *p = NULL;
    return 0;
}


int pilaVacia(Pila *p) {
    if (*p == NULL)
        return 1;

    return 0;
}


int pilaInserta(Pila *p, tipoElementoP elemento) {
    tipoCelda * nuevo;

    if (p == NULL) 
        return -1;

    if (NULL == (nuevo = malloc(sizeof(tipoCelda))))
        return -2;

    (*nuevo).elemento = elemento;
    (*nuevo).sig = *p;
    *p = nuevo;
    return 0;
}


tipoElementoP pilaSuprime(Pila *p) {
    tipoElementoP valor;
    tipoCelda * aBorrar;

    if (p != NULL && !pilaVacia(p)) {
        valor = (**p).elemento;
        aBorrar = *p;
        *p = (**p).sig;
        free(aBorrar);
        return valor;
    }
}
