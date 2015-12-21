/* 
 * File:   TicTacToe.cpp
 * Author: algarcia
 * 
 * Created on 17 de diciembre de 2015, 16:13
 */

#include "TicTacToe.h"

TicTacToe::TicTacToe ( ): _jugadores{"p1","p2"}, _t(new Tablero()), _turno(0)
{
   // NOTA: si la inicialización del array _jugadores da errores al compilar,
   // ha de incluirse aquí. Es una característica reciente de C++ que algunos
   // compiladores no soportan todavía
   
   /*
    * _jugadores[0] = "p1";
    * _jugadores[1] = "p2";
    */
}

TicTacToe::TicTacToe ( const TicTacToe& orig ): _jugadores{orig._jugadores[0],
                                                           orig._jugadores[1]},
                                                _t( new Tablero(*orig._t) ),
                                                _turno(orig._turno)
{
   // NOTA: si la inicialización del array _jugadores da errores al compilar,
   // ha de incluirse aquí. Es una característica reciente de C++ que algunos
   // compiladores no soportan todavía

   /*
    * _jugadores[0] = orig.jugadores[0];
    * _jugadores[1] = orig.jugadores[1];
    */
}

TicTacToe::TicTacToe ( const string& jugador1,
                       const string& jugador2 ): _jugadores{jugador1, jugador2},
                                                 _t( new Tablero()), _turno(0)
{
   // NOTA: si la inicialización del array _jugadores da errores al compilar,
   // ha de incluirse aquí. Es una característica reciente de C++ que algunos
   // compiladores no soportan todavía

   /*
    * _jugadores[0] = jugador1;
    * _jugadores[1] = jugador2;
    */
}

TicTacToe::~TicTacToe ( )
{
   delete _t;
   _t = 0;
}

void TicTacToe::setJugador1 ( const string& j1 )
{
   _jugadores[0] = j1;
}

void TicTacToe::setJugador2 ( const string& j2 )
{
   _jugadores[1] = j2;
}

const string TicTacToe::getJugador1 ()
{
   return ( _jugadores[0] );
}

const string TicTacToe::getJugador2 ()
{
   return ( _jugadores[1] );
}

const string TicTacToe::getSiguiente ()
{
   return ( _jugadores[_turno] );
}

const string TicTacToe::getAnterior ()
{
   if ( _turno == 0 )
   {
      return ( _jugadores[1] );
   }

   return ( _jugadores[0] );
}

const string TicTacToe::getInfoTablero ()
{
   return ( _t->info () );
}

bool TicTacToe::movimiento ( int f, int c )
{
   char marca;
   bool resultado;

   // Dependiendo de a quién le toca mover, cambia la marca y el siguiente turno
   if ( _turno == 0 )
   {
      marca = 'X';
      _turno = 1;
   }
   else
   {
      marca = 'O';
      _turno = 0;
   }

   resultado = _t->setPos ( f, c, marca );

   return ( resultado );
}