/** 
 * @brief Declaración de las funciones del módulo de utilidades
 * @file utils.h
 * @author algarcia
 *
 * @date 19 de enero de 2016
 */

#ifndef UTILS_H
#define UTILS_H

#include "Arma.h"
#include "Armero.h"
#include "Guerrero.h"

using std::string;

namespace t35_utils
{
   string info ( const Arma& a );
   string info ( const Armero& a );
   string info ( Guerrero& g );
}

#endif   /* UTILS_H */

