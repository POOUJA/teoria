/* 
 * File:   Arma.h
 * Author: algarcia
 *
 * Created on 21 de octubre de 2015, 16:12
 */

#ifndef ARMA_H
#define	ARMA_H

#include <string>

using namespace std;

class Arma
{
   private:
      int    poder;
      string nombre;

   public:
      Arma ( );
      Arma ( const Arma& orig );
      Arma ( const string nNombre, const int nPoder=0 );
      virtual ~Arma ( );
      void setNombre ( string nNombre );
      string getNombre ( ) const;
      void setPoder ( int nPoder );
      int getPoder ( ) const;
      string info () const;
};

#endif	/* ARMA_H */

