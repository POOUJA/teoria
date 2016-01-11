/**
 * @file Tablero.h
 * Archivo con la declaración de la clase Tablero (para un juego de tres en raya)
 * @author algarcia
 * @date 2015-12-17
 */

#ifndef TABLERO_H
#define	TABLERO_H

#include <string>

using std::string;

/**
 * El tablero es de tamaño 3x3, como el utilizado en el clásico juego del tres
 * en raya (tic-tac-toe en inglés). El tablero almacena las posiciones que van
 * ocupando los jugadores 'X' y 'O', y calcula si hay un ganador.
 * 
 * En los métodos de interfaz, las posiciones del tablero se direccionan por
 * fila y columna; ambos valores tendrán que estar necesariamente en el rango
 * [1,3].
 * @brief Tablero para un juego de tres en raya
 */
class Tablero
{
   private:
      char _tablero[3][3];   ///< Posiciones

      bool checkMovimientoGanador ( int f, int c );

   public:
      Tablero ( );
      Tablero ( const Tablero& orig );
      virtual ~Tablero ( );
      char getPos ( int f, int c );
      bool setPos ( int f, int c, char jugador );
      string info ();
      Tablero& operator= ( const Tablero& orig );
};

#endif	/* TABLERO_H */

