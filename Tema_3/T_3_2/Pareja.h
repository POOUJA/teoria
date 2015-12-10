/* 
 * File:   Pareja.h
 * Author: algarcia
 *
 * Created on 9 de diciembre de 2015, 12:12
 */

#ifndef PAREJA_H
#define	PAREJA_H

#include "Tenista.h"

class Pareja
{
   private:
      Tenista *t1;
      Tenista *t2;
      int ranking;

   public:
      Pareja ( );
      Pareja ( const Pareja& orig );
      Pareja ( Tenista *nT1, Tenista *nT2, int nRanking );
      Pareja ( Tenista &nT1, Tenista &nT2, int nRanking );
      virtual ~Pareja ( );
      void setRanking ( int nRanking );
      int getRanking ( ) const;
      void setT2 ( Tenista* nT2 );
      Tenista* getT2 ( ) const;
      void setT1 ( Tenista* nT1 );
      Tenista* getT1 ( ) const;
      string info ( ) const;
};

#endif	/* PAREJA_H */

