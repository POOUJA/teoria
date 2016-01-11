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
      string _nombre;     ///< Nombre del guerrero
      int _energia;       ///< Energía vital. Un valor menor o igual a cero implica muerte
      Arma *_armamento;   ///< A través de este atributo se establece la asociación

      /// Factor a aplicar para calcular el valor de los ataques
      static const double _FACTOR_ATAQUE_ = 0.001;
      
      int calculaMaxPoder ( int valorBase );

   public:
      Guerrero ( );
      Guerrero ( string nNombre, int nEnergia=1000 );
      Guerrero ( const Guerrero& orig );
      virtual ~Guerrero ( );
      void setArmamento ( Arma* nArmamento );
      Arma* getArmamento ( ) const;
      void setEnergia ( int nEnergia );
      int getEnergia ( ) const;
      void setNombre ( string nNombre );
      string getNombre ( ) const;
      Arma *desarmar ();
      int ataque ();
      string info ();
      Guerrero& operator= ( const Guerrero& orig );
};

#endif	/* GUERRERO_H */

