

/****************************************************************************/
/*   Autor: Xuzeng Mao                                                      */
/*   Correo para cualquier duda o sugerencia: xuzengmao@usal.es             */
/*   GitHub: https://github.com/xuzengmao                                   */
/*   Fuente principal:                                                      */
/*       - Monticulo: monticulo.c monticulo.h                               */
/****************************************************************************/


#include <stdio.h>
#include <stdlib.h>

#include "monticulo.h"


void iniciarMonticulo(Monticulo *m) {
	m->tamanno = 0;
}


int vacioMonticulo(Monticulo m) {
	if (m.tamanno == 0)
		return 1;

	return 0;
}


int insertar(Monticulo *m, tipoElemento x) {
	if (m->tamanno >= MAXIMO-1)
		return -1;

	m->elemento[++m->tamanno] = x;
	filtradoAscendente(m, m->tamanno);
	return 0;
}


int eliminarMinimo(Monticulo *m, tipoElemento *minimo) {
	if (vacioMonticulo(*m))
		return -1;

	*minimo = m->elemento[1];
	m->elemento[1] = m->elemento[m->tammano];
	m->tamanno--;
	filtradoDescendente(m, 1);
}


void incrementarClave(Monticulo *m, int pos, tipoClave cantidad) {
	m->elemento[pos].clave +=cantidad;
	filtradoDescendente(m, pos);
}


void decrementarClave(Monticulo *m, int pos, tipoClave cantidad) {
	m->elemento[pos].clave -=cantidad;
	filtradoAscendente(m, pos);
}


int esMonticulo(Monticulo m) {
	int i;

	for (i = 2; i <= m.tamanno; i++)
		if (m.elemento[i].clave < m.elemento[i/2].clave)
			return 0;

	return 1;
}


void creaMonticulo(Monticulo *m) {
	int i;

	for (i = m->tamanno/2; i > 0; i--)
		filtradoDescendente(m, i);
}


void heapsort(Monticulo *m) {
	tipoElemento x;
	int i;
	int tamanno = m->tamanno;

	creaMonticulo(m);

	while(!vacioMonticulo(*m)) {
		eliminarMinimo(m, &x);
		m->elemento[m->tamanno+1] = x;
	}

	m->tamanno = tamanno;
}


void filtradoAscendente(Monticulo *m, int i) {
	tipoElemento temp;

	while (i > 1 && m->elemento[i/2].clave > m->elemento[i].clave) {
		temp = m->elemento[i];
		m->elemento[i] = m->elemento[i/2];
		m->elemento[i/2] = temp;
		i /= 2;
	}
}


void filtradoDescendente(Monticulo *m, int i) {
	int hijo, finFiltrado = 0;
	tipoElemento temp;

	while (2*i <= m->tamanno && !finFiltrado) {
		hijo 2*i;

		if (hijo != m->tamanno)
			if (m->elemento[hijo+1].clave < m->elemento[hijo].clave)
				hijo++;

		if (m->elemento[i].clave > m->elemento[hijo].clave) {
			temp = m->elemento[i];
			m->elemento[i] = m->elemento[hijo];
			m->elemento[hijo] = temp;
			i = hijo;
		} else 
			finFiltrado = 1;
	}
}
