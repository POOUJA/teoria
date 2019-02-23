/**
 * @file Guerrero.h
 * Archivo con la declaración de la clase Guerrero
 * @author algarcia
 * @date 2015-12-31
 */

#ifndef GUERRERO_H
#define GUERRERO_H

#include <string>
#include "Arma.h"

using std::string;

/**
 * @brief Clase para representar los guerreros del juego.
 * 
 * Ejemplo de asociación con cardinalidad variable. Cada guerrero está asociado
 * con una cantidad de armas, y antes de destruir un objeto de clase Guerrero,
 * es necesario desarmarle primero con los métodos Guerrero::desarmar
 */
class Guerrero
{
   public:
      /// Número máximo de armas que puede tener un guerrero
      static const int _MAX_ARMAS_ = 10;
   
   private:
      string _nombre = "";                 ///< Nombre del guerrero
      int _energia = 1000;   ///< Energía vital. Un valor menor o igual a cero implica muerte
      Arma *_armamento[_MAX_ARMAS_];   ///< A través de este atributo se establece la asociación
      int _numArmas = 0;   ///< Número de armas que tiene el guerrero en cada momento

      /// Factor a aplicar para calcular el valor de los ataques
      static constexpr double _FACTOR_ATAQUE_ = 0.001; // en C++11 los flotantes constantes deben ser del tipo constexpr

      int calculaMaxPoder ( int valorBase );

   public:
      Guerrero ( );
      Guerrero ( string nNombre, int nEnergia );
      Guerrero ( const Guerrero& orig );
      virtual ~Guerrero ( );
      void addArma ( Arma* nArma );
      Arma& getArma ( int cual ) const;
      int getNumArmas () const;
      void setEnergia ( int nEnergia );
      int getEnergia ( ) const;
      int getMaxPoder ();
      void setNombre ( string nNombre );
      string getNombre ( ) const;
      Arma *desarmar ( int cual );
      int desarmar ( Arma* (&armas)[_MAX_ARMAS_] );
      int ataque ( int armaElegida );
      Guerrero& operator= ( const Guerrero& orig );
};

#endif	/* GUERRERO_H */

