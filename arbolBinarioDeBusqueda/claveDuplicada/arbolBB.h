

/****************************************************************************/
/*   Autor: Xuzeng Mao                                                      */
/*   Correo para cualquier duda o sugerencia: xuzengmao@usal.es             */
/*   GitHub: https://github.com/xuzengmao                                   */
/*   Fuente principal:                                                      */
/*       - ArbolBB: arbolBB.c arbolBB.h                                     */
/****************************************************************************/


#ifndef __ARBOLBB_H
#define __ARBOLBB_H
	typedef int tipoClave;
	typedef char tipoInfo[20];

	typedef struct tipoNodo {
		tipoClave clave;
		tipoInfo info;
		struct tipoNodo *izq, *der;
	} tipoNodo;

	typedef tipoNodo *ArbolBB;

	int insertar(ArbolBB *raiz, tipoClave clave, tipoInfo info);
	int eliminar(ArbolBB *raiz, tipoClave clave);

	tipoNodo *creaNodo(tipoClave clave, tipoInfo info);
	ArbolBB anula(ArbolBB raiz);
	void preOrden(ArbolBB raiz);	
	void enOrden(ArbolBB raiz);
	void posOrden(ArbolBB raiz);
#endif
