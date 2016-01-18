/** 
 * @brief Módulo con funciones de utilidad
 * @file utils.h
 * @author algarcia
 * 
 * @date 15 de enero de 2016
 */

#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "Arma.h"
#include "Armero.h"
#include "Guerrero.h"

using std::string;

string info ( const Arma& a );
string info ( const Armero& a );
string info ( Guerrero& g );

#endif   /* UTILS_H */

