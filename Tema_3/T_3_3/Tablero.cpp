/**
 * @file Tablero.cpp
 * Archivo con la implementación de la clase Tablero (para un juego de tres en raya)
 * @author algarcia
 * @date 2015-12-17
 */

#include <stdexcept>   // Para utilizar las excepciones estándar
#include "Tablero.h"

/**
 * Inicializa el tablero como vacío
 * @brief Constructor por defecto
 * 
 */
Tablero::Tablero ( )
{
   int i,j;

   for ( i = 0; i < 3; i++ )
   {
      for ( j = 0; j < 3; j++ )
      {
         _tablero[i][j] = '-';
      }
   }
}

/**
 * Copia los valores de las posiciones del tablero tal cual
 * @brief Constructor de copia
 * @param orig Tablero del que se copian los valores
 */
Tablero::Tablero ( const Tablero& orig )
{
   int i,j;

   for ( i = 0; i < 3; i++ )
   {
      for ( j = 0; j < 3; j++ )
      {
         _tablero[i][j] = orig._tablero[i][j];
      }
   }
}

/**
 * @brief Destructor por defecto
 */
Tablero::~Tablero ( )
{
}

/**
 * @brief Método para consultar el valor en una posición del tablero
 * @param f Fila de la posición a consultar. Su valor ha de estar entre 1 y 3
 * @param c Columna de la posición a consultar. Su valor ha de estar entre 1 y 3
 * @return Un carácter ('X', 'O' o '-'), dependiendo de si la posición del
 *         tablero ha sido ocupada por el jugador 1, el 2, o todavía está libre
 * @throws std::out_of_range Si el valor de fila o columna no está en el rango
 *         correcto
 */
char Tablero::getPos ( int f, int c )
{
   if ( ( f < 1 ) || ( f > 3 ) )
   {
      throw std::out_of_range ( "Tablero::getPos: el valor de fila debe estar"
                                " entre 1 y 3" );
   }
   
   if ( ( c < 1 ) || ( c > 3 ) )
   {
      throw std::out_of_range ( "Tablero::getPos: el valor de columna debe"
                                " estar entre 1 y 3" );
   }

   return ( _tablero[f-1][c-1] );
}

/**
 * @brief Método para indicar que un jugador ha ocupado una posición del
 *        tablero
 * @param f Fila de la posición a ocupar. Su valor ha de estar entre 1 y 3
 * @param c Columna de la posición a ocupar. Su valor ha de estar entre 1 y 3
 * @param jugador Tendrá valor 'X' o 'O' (sensible a mayúsculas y minúsculas)
 *        para indicar qué jugador (1 o 2, respectivamente) ha ocupado la
 *        posición
 * @retval 0 Si la partida aún no ha terminado
 * @retval 1 Si el movimiento implica que el jugador en cuestión ha ganado la
 *         partida
 * @retval 2 Si hay un empate
 * @throws std::out_of_range Si los valores de fila o columna no están en el
 *         rango de 1 a 3, o si para identificar al jugador no se utiliza 'X' o
 *         'O'
 * @throws std::runtime_error Si la posición que se intenta ocupar no está
 *         libre (ya ha sido tomada por otro jugador anteriormente)
 */
int Tablero::setPos ( int f, int c, char jugador )
{
   if ( ( f < 1 ) || ( f > 3 ) )
   {
      throw std::out_of_range ( "Tablero::setPos: el valor de fila debe estar"
                                " entre 1 y 3" );
   }
   
   if ( ( c < 1 ) || ( c > 3 ) )
   {
      throw std::out_of_range ( "Tablero::setPos: el valor de columna debe"
                                " estar entre 1 y 3" );
   }
   
   if ( ( jugador != 'X' ) && ( jugador != 'O') )
   {
      throw std::out_of_range ( "Tablero::setPos: el jugador debe ser 'X' o"
                                " 'O'" );
   }
   
   if ( _tablero[f-1][c-1] != '-' )
   {
      throw std::runtime_error ( "Tablero::setPos: la posición no está"
                                 " libre" );
   }
   
   _tablero[f-1][c-1] = jugador;
   
   return ( checkMovimiento ( f-1, c-1 ) );
}

/**
 * Copia los valores almacenados en las posiciones de un tablero en otro
 * @brief Operador de asignación
 * @param orig Objeto del que se copia la información
 * @return Una referencia al propio objeto, para facilitar las asignaciones en
 *         cascada (a=b=c)
 */
Tablero& Tablero::operator= ( const Tablero& orig )
{
   int i,j;

   for ( i = 0; i < 3; i++ )
   {
      for ( j = 0; j < 3; j++ )
      {
         _tablero[i][j] = orig._tablero[i][j];
      }
   }

   return ( *this );
}

/**
 * Comprueba si en la fila, la columna, o en alguna de las diagonales, se ha
 * completado el tres en raya, o si se ha llenado el tablero
 * @brief Método para comprobar si una jugada es ganadora
 * @param f Fila de la jugada a comprobar. El rango de valores es de 0 a 2
 * @param c Columna de la jugada a comprobar. El rango de valores es de 0 a 2
 * @retval 1 Si la jugada ha resultado en una combinación ganadora
 * @retval 0 Si la jugada NO ha resultado en una combinación ganadora
 * @retval 2 Si el tablero se ha llenado y no hay ganador
 */
int Tablero::checkMovimiento (int f, int c)
{
   int contC, contF;
   int i;

   // Como este método es privado, no hago comprobaciones en los rangos de los
   // parámetros

   contC = contF = 1;

   for ( i = 1; i < 3; i++ )
   {
      // Cuenta los valores iguales en la columna
      if ( _tablero[(f + i) % 3][c] == _tablero[f][c] )
      {
         contC++;
      }

      // Cuenta los valores iguales en la fila
      if ( _tablero[f][(c + i) % 3] == _tablero[f][c] )
      {
         contF++;
      }
   }
   
   if ( ( contC == 3 ) || ( contF == 3 ) )
   {
      return ( 1 );
   }

   // Comprueba la diagonal principal
   if ( f == c )
   {
      if ( ( _tablero[0][0] == _tablero[1][1] )
           && ( _tablero[0][0] == _tablero[2][2] ) )
      {
         return ( 1 );
      }
   }
   
   // Comprueba la diagonal secundaria
   if ( (f + c) == 2 )
   {
      if ( ( _tablero[0][2] == _tablero[1][1] )
           && ( _tablero[0][2] == _tablero [2][0] ) )
      {
         return ( 1 );
      }
   }

   // Comprueba si en el tablero quedan posiciones sin ocupar
   i = 0;
   for ( contF = 0; contF < 3; contF++ )
   {
      for ( contC = 0; contC < 3; contC ++ )
      {
         if ( _tablero[contF][contC] == '-' )
         {
            i++;
         }
      }
   }
   
   if ( i == 0 )
   {
      return ( 2 );   // Empate
   }

   return ( 0 );
}

