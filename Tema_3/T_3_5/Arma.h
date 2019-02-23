/**
 * @file Arma.h
 * Archivo con la declaración de la clase Arma
 * @author algarcia
 * @date 2015-12-31
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
      int    _poder = 0;    ///< Poder para infligir daño del arma. Ha de ser >= 0
      string _nombre = "";   ///< Nombre del arma para identificarla

   public:
      Arma ( ) = default;
      Arma ( const Arma& orig );
      Arma ( const string nNombre, const int nPoder );
      Arma ( const string nNombre );
      virtual ~Arma ( );
      void setNombre ( string nNombre );
      string getNombre ( ) const;
      void setPoder ( int nPoder );
      int getPoder ( ) const;
      Arma& operator= ( const Arma& orig );
};

#endif	/* ARMA_H */

