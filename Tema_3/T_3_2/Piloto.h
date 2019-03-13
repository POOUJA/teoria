/**
 * @file Piloto.h
 * Archivo con la declaración de la clase Piloto
 * @author algarcia
 * @date 2015-12-09
 */

#ifndef PILOTO_H
#define	PILOTO_H

#include <string>

/**
 * @brief Representación básica de un piloto de Fórmula 1
 */
class Piloto
{
   private:
      std::string _nombre = "";   ///< Nombre del piloto
      int _puntos = 0;            ///< Puntos en la clasificación de pilotos del mundial

   public:
      Piloto ( ) = default;
      Piloto ( const Piloto& orig );
      Piloto ( const std::string nNombre, const int nPuntos );
      virtual ~Piloto ( );
      void resetPuntos ();
      void addPuntos ( int puntosCarrera );
      int getPuntos ( ) const;
      void setNombre ( std::string nNombre );
      std::string getNombre ( ) const;
      Piloto& operator= ( const Piloto& orig );
};

#endif	/* PILOTO_H */

