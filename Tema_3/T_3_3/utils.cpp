/** 
 * @file utils.cpp
 * @author algarcia
 * 
 * @date 15 de enero de 2016
 */

#include "utils.h"
#include <sstream>

/**
 * @brief Función para generar una representación en modo texto del estado del
 *        tablero
 * @return Un texto multilínea que representa el tablero, con 'X' representando
 *         las celdas ocupadas por el jugador 1, y 'O' para el jugador 2
 */
string info ( Tablero& t )
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
 * @brief Función para consultar visualmente el estado de la partida
 * @return Un texto con los jugadores, a quién le toca el siguiente turno, y 
 *         una representación en modo texto del estado del tablero, en la que
 *         las posiciones libres están señaladas con '-', las ocupadas por el
 *         jugador 1 con 'X', y las ocupadas por el jugador 2 con 'O'
 */
string info ( TicTacToe& ttt )
{
   std::stringstream aux;
   
   aux << "Jugador 1: " << ttt.getJugador1 () << std::endl
       << "Jugador 2: " << ttt.getJugador2 () << std::endl;
      *********
   return ( _t->info () );
}

