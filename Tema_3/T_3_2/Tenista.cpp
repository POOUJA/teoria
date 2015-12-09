/* 
 * File:   Tenista.cpp
 * Author: algarcia
 * 
 * Created on 9 de diciembre de 2015, 12:12
 */

#include "Tenista.h"
#include <sstream>     // Para usar stringstream
#include <stdexcept>   // Para usar std::out_of_range

Tenista::Tenista ( ): nombre ("---"), ranking (99999)
{
}

Tenista::Tenista ( const Tenista& orig ): ranking ( orig.ranking )
{
   nombre = orig.nombre + " - 2";
}

Tenista::Tenista ( const string nNombre, const int nRanking ): nombre (nNombre)
{
   if ( nRanking > 0 )
   {
      ranking = nRanking;
   }
   else
   {
      throw std::out_of_range ( "El valor de ranking no puede ser negativo o cero" );
   }
}

Tenista::~Tenista ( )
{
}

void Tenista::setRanking ( int nRanking )
{
   if ( nRanking > 0 )
   {
      this->ranking = nRanking;
   }
   else
   {
      throw std::out_of_range ( "El valor de ranking no puede ser negativo o cero" );
   }
}

int Tenista::getRanking ( ) const
{
   return ranking;
}

void Tenista::setNombre ( string nNombre )
{
   this->nombre = nNombre;
}

string Tenista::getNombre ( ) const
{
   return nombre;
}

string Tenista::info () const
{
   std::stringstream aux;
   string resultado;
   
   aux << "Soy un tenista. Mi nombre es "
       << nombre
       << " y estoy en el puesto "
       << ranking
       << " del ranking";
   getline ( aux, resultado );
   return ( resultado );
}