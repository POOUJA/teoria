/** 
 * @file utils.h
 * @author algarcia
 *
 * @date 20 de enero de 2016
 */

#ifndef UTILS_H
#define UTILS_H

#include <string>

#include "Computadora.h"
#include "Componente.h"
#include "DiscoDuro.h"
#include "PlacaBase.h"
#include "Procesador.h"

using std::string;

namespace t36_utils
{
   string info ( const Componente& c );
   string info ( const Computadora& c );
   string info ( DiscoDuro& dd );
   string info ( PlacaBase& pb );
   string info ( Procesador& p );
}

#endif   /* UTILS_H */

