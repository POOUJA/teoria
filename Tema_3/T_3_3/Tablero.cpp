/* 
 * File:   Tablero.cpp
 * Author: algarcia
 * 
 * Created on 17 de diciembre de 2015, 16:13
 */

#include <stdexcept>
#include <sstream>

#include "Tablero.h"

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

Tablero::~Tablero ( )
{
}

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

bool Tablero::setPos ( int f, int c, char jugador )
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
      throw std::invalid_argument ( "Tablero::setPos: la posición no está"
                                    " libre" );
   }
   
   _tablero[f-1][c-1] = jugador;
   
   return ( checkMovimientoGanador ( f-1, c-1 ) );
}

string Tablero::info ()
{
   std::stringstream aux;
   int f;

   aux << "-------------"
       << std::endl;

   for ( f = 0; f < 3; f++ )
   {
      aux << "| "
          << _tablero[f][0] << " | "
          << _tablero[f][1] << " | "
          << _tablero[f][2] << " |"
          << std::endl
          << "-------------"
          << std::endl;
   }

   return ( aux.str () );
}

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

bool Tablero::checkMovimientoGanador (int f, int c)
{
   int contC, contF, contSlash, contBackslash;
   int i;
   
   contC = contF = contSlash = contBackslash = 1;
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
      
      // Cuenta los valores iguales en la diagonal principal
      if ( _tablero[(f + i) % 3][(c + i) % 3] == _tablero[f][c] )
      {
         contSlash++;
      }
      
      // Cuenta los valores iguales en la diagonal secundaria
      if ( _tablero[(f + i) % 3][(c - i + 3) % 3] == _tablero[f][c] )
      {
         contBackslash++;
      }
   }
   
   if ( ( contC == 3 )
        || ( contF == 3 )
        || ( contSlash == 3 )
        || ( contBackslash == 3 ) )
   {
      return ( true );
   }

   return ( false );
}

