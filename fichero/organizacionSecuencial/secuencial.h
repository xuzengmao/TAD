

/****************************************************************************/
/*   Autor: Xuzeng Mao                                                      */
/*   Correo para cualquier duda o sugerencia: xuzengmao@usal.es             */
/*   GitHub: https://github.com/xuzengmao                                   */
/*   Fuente principal:                                                      */
/*       - Fichero: secuencial.c secuencial.h                               */
/****************************************************************************/


#ifndef __SECUENCIAL_H
    #define __SECUENCIAL_H


    /*   BLOQUE modificable por el usuario, obligatorio:                    *
     *     -> Typedef con identificador RegistroFichSec: para el tipo de    *
     *     registro del fichero.                                            *
     *     -> Typedef con identificador ClaveRegFichSec: para el tipo de    *
     *     clave del registro para la búsqueda.                             *
     *     -> Función tipo imprimirRegSec: para imprimir un registro.       *
     *     -> Función tipo compararRegSecConClave: para comparar una clave  *
     *     con un registro.                                                 */

    #ifndef ALUMNO
        #define ALUMNO
        typedef struct {
            char dni[9];
            char nombre[19];
            char ape1[19];
            char ape2[19];
            char provincia[11];
        } Alumno;
    #endif

    typedef Alumno RegistroFichSec;
    typedef char *ClaveRegFichSec;

    void imprimirReg(Alumno *reg, int *cont);
    int compararRegConClave(Alumno *reg, char *clave);

    /* FIN BLOQUE */


    typedef void (*ImprimirRegSec) (RegistroFichSec *reg, int *cont);
    typedef int (*CompararRegSecConClave) (RegistroFichSec *reg, 
                                           ClaveRegFichSec clave);


    /*   Funciones para el uso del usuario. */

    int leerFichSec(char *fich, ImprimirRegSec fImprimir);
    int buscarRegFichSec(FILE *fp, CompararRegSecConClave fComparar, 
                         RegistroFichSec *reg, ClaveRegFichSec clave);
    int insertarRegFichSec(char *fich, RegistroFichSec *reg);
#endif
