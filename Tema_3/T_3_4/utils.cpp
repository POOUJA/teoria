/** 
 * @file utils.cpp
 * @author algarcia
 * 
 * @date 19 de enero de 2016
 */

#include <sstream>   // Para utilizar stringstream
#include "utils.h"

/**
 * @brief Función para obtener información extendida de una dependencia
 * @param d Referencia a la dependencia a tratar
 * @return Una cadena de texto con los datos de la dependencia
 */
string info ( const Dependencia& d )
{
   std::stringstream ss;
   
   ss << d.getNombre () << ", " << d.getSuperficie () << " metros cuadrados, ";

   if ( d.estaLimpia () == true )
   {
      ss << "limpia";
   }
   else
   {
      ss << "sucia";
   }

   return ( ss.str () );
}

/**
 * @brief Función para obtener un texto informativo sobre las características de
 *        la vivienda
 * @param v Referencia a la vivienda a tratar
 * @return Un texto con información detallada de la vivienda y sus habitaciones
 */
string info ( Vivienda& v )
{
   std::stringstream ss;
   int i;
   float sup;
   sup = v.getSuperficie ();
   
   ss << "Vivienda ubicada en " << v.getDireccion () << std::endl
      << "Número de habitaciones: " << v.getNumDependencias () << std::endl
      << "Superficie total: " << sup << " metros cuadrados" << std::endl
      << "Habitaciones:" << std::endl;

   for ( i = 1; i <= v.getNumDependencias (); i++ )
   {
      ss << info ( v.getDependencia (i) ) << std::endl;
   }

   return ( ss.str () );
}
