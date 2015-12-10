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
      throw std::out_of_range ( "El ranking tiene que ser positivo" );
   }
}

Pareja::Pareja ( Tenista &nT1, Tenista &nT2, int nRanking ): t1 (&nT1), t2 (&nT2)
{
   if ( nRanking > 0 )
   {
      ranking = nRanking;
   }
   else
   {
      throw std::out_of_range ( "El ranking tiene que ser positivo" );
   }
}

Pareja::~Pareja ( )
{
   t1 = NULL;
   t2 = NULL;
}

void Pareja::setRanking ( int nRanking )
{
   if ( nRanking > 0 )
   {
      this->ranking = nRanking;
   }
   else
   {
      throw std::out_of_range ( "El valor de ranking tiene que ser positivo" );
   }
}

int Pareja::getRanking ( ) const
{
   return ranking;
}

void Pareja::setT2 ( Tenista* nT2 )
{
   this->t2 = nT2;

   if ( t2 == NULL )
   {
      ranking = 99999;
   }
}

Tenista* Pareja::getT2 ( ) const
{
   return t2;
}

void Pareja::setT1 ( Tenista* nT1 )
{
   this->t1 = nT1;
   
   if ( t1 == NULL )
   {
      ranking = 99999;
   }
}

Tenista* Pareja::getT1 ( ) const
{
   return t1;
}

string Pareja::info () const
{
   std::stringstream aux;
   string resultado;

   if ( ( t1 != NULL ) && ( t2 != NULL ) )
   {
      aux << "Somos una pareja, formada por "
          << t1->getNombre ()
          << " y "
          << t2->getNombre ()
          << ". Nuestro ranking es "
          << ranking;
   }
   else
   {
      if ( t1 == NULL )
      {
         if ( t2 == NULL )
         {
            aux << "Esta pareja está vacía";
         }
         else
         {
            aux << "En esta pareja falta el primer integrante. El segundo es "
                << t2->getNombre ();
         }
      }
      else
      {
         // t2 es necesariamente distinto de NULL en este caso
         aux << "En esta pareja falta el segundo integrante. El primero es "
             << t1->getNombre ();
      }
   }

   getline ( aux, resultado );
   return ( resultado );
}

Pareja& Pareja::operator = (const Pareja& orig)
{
   this->ranking = orig.ranking;
   
   return ( *this );
}