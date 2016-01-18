/**
 * @file Piloto.h
 * Archivo con la declaración de la clase Piloto
 * @author algarcia
 * @date 2015-12-09
 */

#ifndef PILOTO_H
#define	PILOTO_H

#include <string>

using std::string;

/**
 * @brief Representación básica de un piloto de Fórmula 1
 */
class Piloto
{
   private:
      string _nombre;   ///< Nombre del piloto
      int _puntos;      ///< Puntos en la clasificación de pilotos del mundial

   public:
      Piloto ( );
      Piloto ( const Piloto& orig );
      Piloto ( const string nNombre, const int nPuntos );
      virtual ~Piloto ( );
      void resetPuntos ();
      void addPuntos ( int puntosCarrera );
      int getPuntos ( ) const;
      void setNombre ( string nNombre );
      string getNombre ( ) const;
      Piloto& operator= ( const Piloto& orig );
};

#endif	/* PILOTO_H */

