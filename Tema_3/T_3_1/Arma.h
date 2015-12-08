/**
 * @file Arma.h
 * Archivo con la declaración de la clase Arma
 * @author algarcia
 * @date 2015-10-21
 */

#ifndef ARMA_H
#define ARMA_H

#include <string>

using std::string;

/**
 * @brief Representación de armas para un juego simple
 */
class Arma
{
   private:
      int    poder;    ///< Poder para infligir daño del arma. Ha de ser >= 0
      string nombre;   ///< Nombre del arma para identificarla

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

