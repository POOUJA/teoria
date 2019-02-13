/**
 * @file Armero.h
 * Archivo con la declaración de la clase Armero
 * @author algarcia
 * @date 2015-10-21
 */

#ifndef ARMERO_H
#define ARMERO_H

#include <string>
#include "Arma.h"

using std::string;

/**
 * @brief Clase para representar los armeros del juego
 * 
 * Ejemplo de dependencia. El armero crea armas, pero no existe más relación
 * entre el armero y el arma durante el juego, más allá del instante de la
 * creación del objeto de clase Arma.
 */
class Armero final
{
   private:
      int    _energia=1000;        ///< Energía vital del armero. Un valor negativo implica muerte
      string _nombre="";         ///< Nombre del armero
      int    _maxPoderArma=100;   ///< Máximo poder destructivo de las armas creadas. Debe ser > 0

   public:
      Armero ( ) = default;
      Armero ( string nNombre);
      Armero ( string nNombre, int nMPArma);
      Armero ( const Armero& orig );
      virtual ~Armero ( );
      void setEnergia ( int nEnergia );
      int getEnergia ( ) const;
      void setNombre ( string nNombre );
      string getNombre ( ) const;
      void setMaxPoderArma ( int nMaxPoderArma );
      int getMaxPoderArma ( ) const;
      Arma* creaArma ( string nombreArma );
      int ataque ();
      Armero& operator= ( const Armero& orig );
};

#endif	/* ARMERO_H */

