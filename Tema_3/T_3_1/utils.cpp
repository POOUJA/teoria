/** 
 * @brief Módulo con funciones de utilidad
 * @file utils.cpp
 * @author algarcia
 * 
 * @date 15 de enero de 2016
 */

#include "utils.h"
#include <sstream>


/**
 * @brief Información del arma
 * @return Devuelve una cadena de texto conteniendo los valores de los atributos
 *         del arma
 */
string info ( const Arma& a )
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
 * @return Devuelve una cadena de texto conteniendo los valores de los atributos
 *         del objeto
 */
string info ( const Armero& a )
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
string info ( Guerrero& g )
{
   std::stringstream aux;
   
   aux << "Soy guerrero. Mi nombre es "
       << g.getNombre ()
       << ", mi energía es "
       << g.getEnergia ()
       << " y puedo producir ataques de hasta "
       << g.calculaMaxPoder ( g.getArmamento ()->getPoder () )
       << " puntos de poder";

   return ( aux.str () );
}

