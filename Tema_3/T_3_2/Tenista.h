/* 
 * File:   Tenista.h
 * Author: algarcia
 *
 * Created on 9 de diciembre de 2015, 12:12
 */

#ifndef TENISTA_H
#define	TENISTA_H

#include <string>

using std::string;

class Tenista
{
   private:
      string nombre;
      int ranking;

   public:
      Tenista ( );
      Tenista ( const Tenista& orig );
      Tenista ( const string nNombre, const int nRanking );
      virtual ~Tenista ( );
      void setRanking ( int nRanking );
      int getRanking ( ) const;
      void setNombre ( string nNombre );
      string getNombre ( ) const;
      string info ( ) const;
};

#endif	/* TENISTA_H */

