/**
 * @file Tenista.h
 * Archivo con la declaración de la clase Tenista
 * @author algarcia
 * @date 2015-12-09
 */

#ifndef TENISTA_H
#define	TENISTA_H

#include <string>

using std::string;

/**
 * @brief Representación básica de un tenista profesional
 */
class Tenista
{
   private:
      string nombre;   ///< Nombre del tenista
      int ranking;     ///< Posición en el ranking oficial

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
      Tenista& operator= ( const Tenista& orig );
};

#endif	/* TENISTA_H */

