/**
 * @file Vivienda.h
 * Archivo con la declaración de la clase Vivienda
 * @author algarcia
 * @date 2015-12-11
 */

#ifndef VIVIENDA_H
#define	VIVIENDA_H

#include "Dependencia.h"

/**
 * Ejemplo de composición con cardinalidad variable: una vivienda está formada
 * por varias dependencias. La destrucción de la vivienda implica necesariamente
 * la destrucción de todas las dependencias que la componen
 * @brief Representación de una vivienda con sus habitaciones
 */
class Vivienda
{
   public:
      /// Número máximo de habitaciones en una vivienda
      static const int _MAX_HAB_ = 10;

   private:
      string _direccion;                       ///< Calle, número, piso...
      Dependencia *_habitaciones[_MAX_HAB_];   ///< Habitaciones
      int _numH;                               ///< Número de habitaciones
      
      int repasaDependencias ();

   public:
      Vivienda ( );
      Vivienda ( const Vivienda& orig );
      Vivienda ( string direccion );
      virtual ~Vivienda ( );
      int addDependencia ( string nombre, float superficie, bool estaLimpia );
      int borraDependencia ( string nombre );
      int borraDependencia ( int cual );
      int borraDependencias ( string nombre );
      const Dependencia& getDependencia ( int cual );
      void limpiaDependencia ( int cual );
      void ensuciaDependencia ( int cual );
      void limpiezaGeneral ();
      float getSuperficie ();
      void setDireccion ( string nDireccion );
      string getDireccion ( ) const;
      int getNumDependencias () const;
      Vivienda& operator= ( const Vivienda& orig );
};

#endif	/* VIVIENDA_H */

