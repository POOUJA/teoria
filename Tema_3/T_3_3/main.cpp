/* 
 * File:   main.cpp
 * Author: algarcia
 *
 * Created on 17 de diciembre de 2015, 16:12
 */

#include <cstdlib>
#include <iostream>

#include "TicTacToe.h"

using namespace std;

/*
 * 
 */
int main ( int argc, char** argv )
{
   bool partidaTerminada = false;
   int fila, columna;
   TicTacToe *partida = new TicTacToe ();
   
   
   partida->setJugador1 ( "Pepe" );
   partida->setJugador2 ( "Manolo" );
   
   while ( !partidaTerminada )
   {
      cout << partida->getInfoTablero ();
      cout << "Turno de " << partida->getSiguiente () << endl;
      cout << "Fila: ";
      cin >> fila;
      cout << "Columna: ";
      cin >> columna;
      partidaTerminada = partida->movimiento (fila, columna);
   }

   cout << partida->getInfoTablero ();
   cout << "Ganador: " << partida->getAnterior ();
   
   delete ( partida );
   partida = 0;

   return 0;
}

