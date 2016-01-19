/** 
 * @brief Declaración del módulo de utilidades
 * @file utils.h
 * @author algarcia
 *
 * @date 15 de enero de 2016
 */

#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "Tablero.h"
#include "TicTacToe.h"

using std::string;

string info ( Tablero& t );
string info ( TicTacToe& ttt );

#endif   /* UTILS_H */

