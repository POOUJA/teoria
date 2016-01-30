/**
 * @brief Implementación del módulo de utilidades
 * @file utils.cpp
 * @author algarcia
 * 
 * @date 15 de enero de 2016
 */

#include <sstream>   // Para utilizar stringstream
#include "utils.h"

/**
 * @brief Función para generar una representación en modo texto del estado de un
 *        tablero
 * @param t Referencia al tablero del que se obtiene la información
 * @return Un texto multilínea que representa el tablero, con 'X' representando
 *         las celdas ocupadas por el jugador 1, y 'O' para el jugador 2
 */
string t33_utils::info ( Tablero& t )
{
   std::stringstream aux;
   int f;

   aux << "-------------"
       << std::endl;

   for ( f = 1; f < 4; f++ )
   {
      aux << "| "
          << t.getPos (f,1) << " | "
          << t.getPos (f,2) << " | "
          << t.getPos (f,3) << " |"
          << std::endl
          << "-------------"
          << std::endl;
   }

   return ( aux.str () );
}

/**
 * @brief Función para consultar visualmente el estado de una partida
 * @param ttt Referencia a la partida de la que se obtiene la información
 * @return Un texto con los jugadores, a quién le toca el siguiente turno, y 
 *         una representación en modo texto del estado del tablero, en la que
 *         las posiciones libres están señaladas con '-', las ocupadas por el
 *         jugador 1 con 'X', y las ocupadas por el jugador 2 con 'O'
 */
string t33_utils::info ( TicTacToe& ttt )
{
   std::stringstream aux;
   
   aux << "Jugador 1 (X): " << ttt.getJugador1 () << ".\t"
       << "Jugador 2 (O): " << ttt.getJugador2 () << std::endl
       << "Estado actual del tablero:" << std::endl
       << info ( ttt.getTablero () );
   return ( aux.str () );
}

