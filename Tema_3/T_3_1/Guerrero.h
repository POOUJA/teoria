/**
 * @file Guerrero.h
 * Archivo con la declaración de la clase Guerrero
 * @author algarcia
 * @date 2015-10-20
 */

#ifndef GUERRERO_H
#define GUERRERO_H

#include <string>
#include "Arma.h"

using std::string;

/**
 * @brief Clase para representar los guerreros del juego.
 * 
 * Ejemplo de asociación. Cada guerrero está asociado con su arma, y antes de
 * destruir un objeto de clase Guerrero, es necesario desarmarle primero con
 * el método Guerrero::desarmar
 */
class Guerrero
{
   private:
      string _nombre="----";     ///< Nombre del guerrero
      int _energia=1000;       ///< Energía vital. Un valor menor o igual a cero implica muerte
      Arma *_armamento=nullptr;   ///< A través de este atributo se establece la asociación

      /// Factor a aplicar para calcular el valor de los ataques
      static constexpr double _FACTOR_ATAQUE_ = 0.001; //constexpr necesario en c++11 para asignar float o double a un atributo const

      int calculaMaxPoder ( int valorBase );
      
   public:
      Guerrero ( ) = default;
      Guerrero ( string nNombre);
      Guerrero ( string nNombre, int nEnergia);
      Guerrero ( const Guerrero& orig );
      virtual ~Guerrero ( );
      void setArmamento ( Arma* nArmamento );
      const Arma& getArmamento ( );
      void setEnergia ( int nEnergia );
      int getEnergia ( ) const;
      int getMaxPoder ();
      void setNombre ( string nNombre );
      string getNombre ( ) const;
      Arma* desarmar ();
      int ataque ();
      Guerrero& operator= ( const Guerrero& orig );
};

#endif	/* GUERRERO_H */

