

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


/*   Funciones para el uso del usuario. */

int leerFichSec(char *fich, ImprimirRegSec fImprimir) {
    FILE *fp;
    RegistroFichSec reg;
    int cont = 0;

    if (fich == NULL) {
        #ifdef DEBUG
            fprintf(stderr, "ERROR:secuencial.c:leerFichSec: el parametro "
                            "\"fich\" es NULL.\n");
        #endif

        return -1;
    }

    if (fImprimir == NULL) {
        #ifdef DEBUG
            fprintf(stderr, "ERROR:secuencial.c:leerFichSec: el parametro "
                            "\"fImprimir\" es NULL.\n");
        #endif

        return -2;
    }

    if (NULL == (fp = fopen(fich, "rb"))) {
        #ifdef DEBUG
            fprintf(stderr, "ERROR:secuencial.c:leerFichSec: error al abrir "
                            "el fichero.\n");
        #endif
               
        return -3;
    }

    while (fread(&reg, sizeof(RegistroFichSec), 1, fp))
        fImprimir(&reg, &cont);

    fclose(fp);
    return cont;
}


int buscarRegFichSec(FILE *fp, CompararRegSecConClave fComparar, 
                     RegistroFichSec *reg, ClaveRegFichSec clave)
{
    int cont = 0;

    if (fp == NULL) {
        #ifdef DEBUG
            fprintf(stderr, "ERROR:secuencial.c:buscarRegFichSec: el "
                            "parametro \"fp\" es NULL.\n");
        #endif

        return -2;
    }

    if (fComparar == NULL) {
        #ifdef DEBUG
            fprintf(stderr, "ERROR:secuencial.c:buscarRegFichSec: el "
                            "parametro \"fComparar\" es NULL.\n");
        #endif

        return -3;
    }

    if (reg == NULL) {
        #ifdef DEBUG
            fprintf(stderr, "ERROR:secuencial.c:buscarRegFichSec: el "
                            "parametro \"reg\" es NULL.\n");
        #endif

        return -4;
    }

    fseek(fp, 0, SEEK_SET);

    while (fread(reg, sizeof(RegistroFichSec), 1, fp)) {
        if (!fComparar(reg, clave))
            return cont;

        cont++;
    }

    return -1;
}


int insertarRegFichSec(char *fich, RegistroFichSec *reg) {

}
