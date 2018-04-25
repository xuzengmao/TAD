

/****************************************************************************/
/*   Autor: Xuzeng Mao                                                      */
/*   Correo para cualquier duda o sugerencia: xuzengmao@usal.es             */
/*   GitHub: https://github.com/xuzengmao                                   */
/*   Fuente principal:                                                      */
/*       - Monticulo: monticulo.c monticulo.h                               */
/****************************************************************************/


#ifndef __MONTICULO_H
#define __MONTICULO_H

#define MAXIMO 100

typedef int tipoClave;
typedef int tipoInfo;

typedef struct {
	tipoClave clave;
	tipoInfo informacion;
} tipoElemento;

typedef struct {
	tipoElemento elemento[MAXIMO];
	int tamanno;
} Monticulo;

void iniciarMonticulo(Monticulo *m);
int vacioMonticulo(Monticulo m);
int insertar(Monticulo *m, tipoElemento x);
int eliminarMinimo(Monticulo *m, tipoElemento *minimo);
void incrementarClave(Monticulo *m, int pos, tipoClave cantidad);
void decrementarClave(Monticulo *m, int pos, tipoClave cantidad);
int esMonticulo(Monticulo m);
void creaMonticulo(Monticulo *m);
void heapsort(Monticulo *m);

void filtradoAscendente(Monticulo *m, int i);
void filtradoDescendente(Monticulo *m, int i);

#endif
