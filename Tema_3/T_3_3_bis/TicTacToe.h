/**
 * @file TicTacToe.h
 * Archivo con la declaración de la clase TicTacToe, para gestionar una partida
 * de tres en raya clásico
 * @author algarcia
 * @date 2015-12-17
 */

#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "Tablero.h"

/**
 * Ejemplo de composición: la partida crea el tablero y lo gestiona. Al
 * destruirse la partida, el tablero también se destruye.
 * @brief Clase para gestionar una partida de tres en raya clásico
 */
class TicTacToe
{
   private:
      string _jugadores[2];   ///< Nombres de los jugadores
      int _turno = 0;             ///< Almacena a qué jugador le toca mover (0 ó 1)
      Tablero _t;            ///< Tablero de juego

   public:
      TicTacToe ( );
      TicTacToe ( const TicTacToe& orig );
      TicTacToe ( const string& jugador1, const string& jugador2 );
      virtual ~TicTacToe ( );
      void setJugador1 ( const string& j1 );
      void setJugador2 ( const string& j2 );
      string getJugador1 ();
      string getJugador2 ();
      string getSiguiente ();
      string getAnterior ();
      Tablero& getTablero ();
      int movimiento ( int f, int c );
      TicTacToe& operator= ( const TicTacToe& orig );
};

#endif	/* TICTACTOE_H */

