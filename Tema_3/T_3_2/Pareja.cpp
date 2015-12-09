/* 
 * File:   Pareja.cpp
 * Author: algarcia
 * 
 * Created on 9 de diciembre de 2015, 12:12
 */

#include <sstream>
#include <stdexcept>
#include "Pareja.h"

Pareja::Pareja ( ): t1 (NULL), t2 (NULL), ranking (99999)
{
}

Pareja::Pareja ( const Pareja& orig ): t1 (orig.t1), t2 (orig.t2),
                                       ranking (orig.ranking)
{
}

Pareja::Pareja ( Tenista *nT1, Tenista *nT2, int nRanking ): t1 (nT1), t2 (nT2)
{
   if ( nRanking > 0 )
   {
      ranking = nRanking;
   }
   else
   {
      throw std::out_of_range ( "El ranking no puede ser negativo o cero" );
   }
}

Pareja::Pareja ( Tenista &nT1, Tenista &nT2, int nRanking )
{
}

Pareja::~Pareja ( )
{
}

void Pareja::setRanking ( int ranking )
{
   this->ranking = ranking;
}

int Pareja::getRanking ( ) const
{
   return ranking;
}

void Pareja::setT2 ( Tenista* t2 )
{
   this->t2 = t2;
}

Tenista* Pareja::getT2 ( ) const
{
   return t2;
}

void Pareja::setT1 ( Tenista* t1 )
{
   this->t1 = t1;
}

Tenista* Pareja::getT1 ( ) const
{
   return t1;
}

string Tenista::info () const
{
   
}