

/****************************************************************************/
/*   Autor: Xuzeng Mao                                                      */
/*   Correo para cualquier duda o sugerencia: xuzengmao@usal.es             */
/*   GitHub: https://github.com/xuzengmao                                   */
/*   Fuente: cola.c cola.h                                                  */
/****************************************************************************/


#ifndef __COLA_H
#define __COLA_H

#define MAX 100

typedef int tipoElemento;

typedef struct {
    int tamagno;
    int frente, fondo;
    tipoElemento elementos[MAX];
    } Cola;


int colaCreaVacia(Cola *c);
int colaVacia(Cola *c);
int colaInserta(Cola *c, tipoElemento elemento);
tipoElemento colaSuprime(Cola *c);

#endif
