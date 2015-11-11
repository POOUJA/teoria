/** Utilidades para entrada/salida de ejemplares del catálogo por Consola
 * @file   util_ejemplar.cpp
 * @author jrbalsas@ujaen.es
 *
 * @date 18 de octubre de 2015
 */


#ifndef UTIL_CATALOGO_H
#define	UTIL_CATALOGO_H

#include "Catalogo.h"
#include "Ejemplar.h"
#include "Libro.h"
#include "Revista.h"

/**Funciones de utilidad para entrada/salida de Ejemplares por consola*/
namespace utilCatalogo {

    void visualiza(Catalogo &catalogo);
    void visualiza(Ejemplar &ejemplar);
    void visualiza(Ejemplar *ejemplar);
    void visualiza(Libro &libro);
    void visualiza(Revista &revista);

}
#endif	/* UTIL_EJEMPLAR_H */

