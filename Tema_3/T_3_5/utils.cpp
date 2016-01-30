/**
 * @brief Implementación de las fuciones del módulo de utilidades
 * @file utils.cpp
 * @author algarcia
 * 
 * @date 19 de enero de 2016
 */

#include <sstream>   // Para utilizar stringstream
#include "utils.h"


/**
 * @brief Información de un arma
 * @param a Referencia al arma de la que se quiere la información
 * @return Devuelve una cadena de texto conteniendo los valores de los atributos
 *         del arma
 */
string t35_utils::info ( const Arma& a )
{
   std::stringstream aux;
   
   aux << "Soy un arma. Mi nombre es "
       << a.getNombre ()
       << " y mi poder es de "
       << a.getPoder ()
       << " puntos";

   return ( aux.str () );
}

/**
 * @brief Información del armero
 * @param a Referencia al armero del que se quiere la información
 * @return Devuelve una cadena de texto conteniendo los valores de los atributos
 *         del objeto
 */
string t35_utils::info ( const Armero& a )
{
   std::stringstream aux;
   
   aux << "Soy armero. Mi nombre es "
       << a.getNombre ()
       << ", mi energía es "
       << a.getEnergia ()
       << " y puedo producir armas de hasta "
       << a.getMaxPoderArma ()
       << " puntos de poder";

   return ( aux.str () );
}

/**
 * @brief Información del guerrero
 * @return Devuelve una cadena de texto conteniendo los valores de los atributos
 *         del objeto
 */
string t35_utils::info ( Guerrero& g )
{
   std::stringstream aux;
   int i, nArmas;
   
   nArmas = g.getNumArmas ();
   aux << "Soy guerrero. Mi nombre es "
       << g.getNombre ()
       << ", mi energía es "
       << g.getEnergia ()
       << " y tengo "
       << nArmas
       << " armas";
   
   if ( nArmas > 0 )
   {
      aux << ":"
          << std::endl
          << "-------------------------"
          << std::endl;

      for ( i = 1; i <= nArmas; i++ )
      {
         aux << "\t"
             << info ( g.getArma (i) )
             << std::endl;
      }
      
      aux << "-------------------------";
   }

   aux << std::endl
       << "Puedo producir ataques de hasta "
       << g.getMaxPoder ()
       << " puntos de poder";

   return ( aux.str () );
}


