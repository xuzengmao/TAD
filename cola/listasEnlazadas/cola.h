

/****************************************************************************/
/*   Autor: Xuzeng Mao                                                      */
/*   Correo para cualquier duda o sugerencia: xuzengmao@usal.es             */
/*   GitHub: https://github.com/xuzengmao                                   */
/*   Fuente: cola.c cola.h                                                  */
/****************************************************************************/


#ifndef __COLA_H
#define __COLA_H

typedef int tipoElemento;

#ifndef TIPO_CELDA
#define TIPO_CELDA

typedef struct tipoCelda { 
	tipoElemento elemento; 
	struct tipoCelda * sig; 
	} tipoCelda;
	
#endif

typedef struct {
        tipoCelda *frente, *fondo;
} Cola;

int colaCreaVacia(Cola *c);
int colaVacia(Cola *c);
int colaInserta(Cola *c, tipoElemento elemento);
tipoElemento colaSuprime(Cola *c);

#endif
