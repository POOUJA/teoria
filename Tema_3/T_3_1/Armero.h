/* 
 * File:   Armero.h
 * Author: algarcia
 *
 * Created on 21 de octubre de 2015, 16:12
 */

#ifndef ARMERO_H
#define	ARMERO_H

#include <string>
#include "Arma.h"

using namespace std;

class Armero
{
   private:
      int    energia;
      string nombre;
      int    maxPoderArma;

   public:
      Armero ( );
      Armero ( string nNombre, int nMPArma = 100 );
      Armero ( const Armero& orig );
      virtual ~Armero ( );
      void setEnergia ( int nEnergia );
      int getEnergia ( ) const;
      void setNombre ( string nNombre );
      string getNombre ( ) const;
      void setMaxPoderArma ( int nMaxPoderArma );
      int getMaxPoderArma ( ) const;
      Arma *creaArma ( string nombreArma );
      int ataque ();
      string info () const;
};

#endif	/* ARMERO_H */

