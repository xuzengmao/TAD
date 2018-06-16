

/****************************************************************************/
/*   Autor: Xuzeng Mao                                                      */
/*   Correo para cualquier duda o sugerencia: xuzengmao@usal.es             */
/*   GitHub: https://github.com/xuzengmao                                   */
/*   Fuente principal:                                                      */
/*       - Fichero: secuencial.c secuencial.h                               */
/****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "secuencial.h"


/*   BLOQUE modificable por el usuario. */

void imprimirReg(Alumno *reg, int *cont) {
    printf("\t %d %s %s %s %s %s\n\n", (*cont)++,
                                        reg->dni,
                                        reg->nombre,
                                        reg->ape1,
                                        reg->ape2,
                                        reg->provincia);
}


int compararRegConClave(Alumno *reg, char *clave) {
    return strcmp(reg->dni, clave);

}

/* FIN BLOQUE */


