

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
#include "cola.h"


int colaCreaVacia(Cola *c) {
    if (c == NULL)
        return -1;

    (*c).fondo = NULL;
    (*c).frente = NULL;
    return 0;
}


int colaVacia(Cola *c) {
    if ((*c).frente == NULL)
        return 1;

    return 0;
}


int colaInserta(Cola *c, tipoElemento elemento) {
    tipoCelda *nuevo;

    if (c == NULL)
        return -1;

    if (NULL == (nuevo = malloc(sizeof(tipoCelda))))
        return -2;
    
    (*nuevo).elemento = elemento;
    (*nuevo).sig = NULL;

    if ((*c).frente == NULL)
        (*c).frente = nuevo;
    else
        (*(*c).fondo).sig = nuevo;

    (*c).fondo = nuevo;
    return 0;
}


tipoElemento colaSuprime(Cola *c) {
    tipoElemento valor;
    tipoCelda * aBorrar;

    if (c != NULL && !colaVacia(c)) {
        valor = (*(*c).frente).elemento;
        aBorrar = (*c).frente;
        
        if (c->fondo == c->frente)
            c->fondo = NULL;
        
        (*c).frente = (*(*c).frente).sig;
        free(aBorrar);
        return valor;
    }
}
