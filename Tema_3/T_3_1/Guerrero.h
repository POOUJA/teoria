/** 
 * @brief Definición de la clase Guerrero
 *
 *        Programación Orientada a Objetos. Curso 2015-2016. Ejemplo T_3_1
 * @file Guerrero.h
 * @author algarcia
 *
 * @date 20 de octubre de 2015, 13:58
 */

#ifndef GUERRERO_H
#define	GUERRERO_H

#include <string>
#include "Arma.h"

/// Factor a aplicar para calcular el valor de los ataques
#define _FACTOR_ATAQUE_ 0.001

using namespace std;

/**
 * @brief Clase para representar los guerreros del juego.
 * 
 * Ejemplo de asociación. Cada guerrero está asociado con su arma
 * 
 */
class Guerrero
{
   private:
      string nombre;     ///< Nombre del guerrero
      int energia;       ///< Energía vital. Un valor menor o igual a cero implica muerte
      Arma *armamento;   ///< A través de este atributo se establece la asociación

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
      string info () const;
};

#endif	/* GUERRERO_H */

