

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


#ifndef __PILA_H
#define __PILA_H

typedef int tipoElementoP;

#ifndef TIPO_CELDA
#define TIPO_CELDA

typedef struct tipoCelda { 
    tipoElementoP elemento; 
    struct tipoCelda * sig; 
    } tipoCelda;
    
#endif
    
typedef tipoCelda * Pila;

int pilaCreaVacia(Pila *p);
int pilaVacia(Pila *p);
int pilaInserta(Pila *p,tipoElementoP elemento);
tipoElementoP pilaSuprime(Pila *p);


#endif
