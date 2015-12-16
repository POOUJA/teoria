/* 
 * File:   Vivienda.h
 * Author: algarcia
 *
 * Created on 11 de diciembre de 2015, 18:21
 */

#ifndef VIVIENDA_H
#define	VIVIENDA_H

#define _MAX_HAB_ 10   ///< Número máximo de habitaciones en una vivienda

#include "Dependencia.h"

class Vivienda
{
   private:
      string _direccion;                      ///< Calle, número, piso...
      Dependencia *salon;

   public:
      Vivienda ( );
      Vivienda ( const Vivienda& orig );
      virtual ~Vivienda ( );
};

#endif	/* VIVIENDA_H */

