/* 
 * File:   TicTacToe.cpp
 * Author: algarcia
 * 
 * Created on 17 de diciembre de 2015, 16:13
 */

#include "TicTacToe.h"

TicTacToe::TicTacToe ( ): _jugadores{"---","---"}, _t(new Tablero()), _turno(1)
{
   // NOTA: si la inicialización del array _jugadores da errores al compilar,
   // ha de incluirse aquí. Es una característica reciente de C++ que algunos
   // compiladores no soportan todavía
}

TicTacToe::TicTacToe ( const TicTacToe& orig ): _jugadores{orig._jugadores[0],
                                                           orig._jugadores[1]},
                                                _t( new Tablero(*orig._t) ),
                                                _turno(orig._turno)
{
   // NOTA: si la inicialización del array _jugadores da errores al compilar,
   // ha de incluirse aquí. Es una característica reciente de C++ que algunos
   // compiladores no soportan todavía
}

TicTacToe::TicTacToe ( const string& jugador1, const string& jugador2 )
{
   
}

TicTacToe::~TicTacToe ( )
{
}

void TicTacToe::setJugador1 ( const string& j1 )
{
}

void TicTacToe::setJugador2 ( const string& j2 )
{
}

const string TicTacToe::getSiguiente ()
{
}

const string TicTacToe::getAnterior ()
{
}

const string TicTacToe::getInfoTablero ()
{
}

bool TicTacToe::movimiento ( int f, int c )
{
}