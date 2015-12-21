/* 
 * File:   TicTacToe.h
 * Author: algarcia
 *
 * Created on 17 de diciembre de 2015, 16:13
 */

#ifndef TICTACTOE_H
#define	TICTACTOE_H

#include "Tablero.h"

class TicTacToe
{
   private:
      string _jugadores[2];
      int _turno;
      Tablero *_t;      

   public:
      TicTacToe ( );
      TicTacToe ( const TicTacToe& orig );
      TicTacToe ( const string& jugador1, const string& jugador2 );
      virtual ~TicTacToe ( );
      void setJugador1 ( const string& j1 );
      void setJugador2 ( const string& j2 );
      const string getJugador1 ();
      const string getJugador2 ();
      const string getSiguiente ();
      const string getAnterior ();
      const string getInfoTablero ();
      bool movimiento ( int f, int c );
};

#endif	/* TICTACTOE_H */

