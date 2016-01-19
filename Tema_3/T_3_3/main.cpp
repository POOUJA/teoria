/**
 * @file main.cpp
 * Archivo con la función principal para el juego del tres en raya clásico
 * @author algarcia
 * @date 2015-12-17
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "TicTacToe.h"
#include "utils.h"

using namespace std;

/**
 * Se hace uso de la clase TicTacToe para llevar el control de la partida. Se
 * capturan las excepciones que esa clase puede lanzar, para que no haya
 * finalizaciones inesperadas del programa
 * @brief Función principal para el juego del tres en raya clásico
 */
int main ( int argc, char** argv )
{
   bool partidaTerminada = false;
   int fila, columna;
   TicTacToe* partida = new TicTacToe ();
   
   partida->setJugador1 ( "Pepe" );
   partida->setJugador2 ( "Manolo" );
   
   while ( !partidaTerminada )
   {
      cout << info ( *partida );
      cout << "Turno de " << partida->getSiguiente () << endl;
      cout << "Fila: ";
      cin >> fila;
      cout << "Columna: ";
      cin >> columna;
      try
      {
         partidaTerminada = partida->movimiento (fila, columna);
      }
      catch ( std::out_of_range ex )
      {
         cout << "==============================================" << endl
              << "La posición no es correcta. Inténtelo de nuevo" << endl
              << "==============================================" << endl;
      }
      catch ( std::invalid_argument ex )
      {
         cout << "=================================================" << endl
              << "La posición ya estaba ocupada. Inténtelo de nuevo" << endl
              << "=================================================" << endl;
      }
   }

   cout << info ( *partida );
   cout << "Ganador: " << partida->getAnterior ();

   // IMPORTANTE: no olvidar el liberar los recursos del heap utilizados   
   delete ( partida );
   partida = 0;

   return 0;
}

