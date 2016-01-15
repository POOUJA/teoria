/** 
 * @file utils.cpp
 * @author algarcia
 * 
 * @date 15 de enero de 2016
 */

#include <sstream>
#include "utils.h"

/**
 * @brief Función para generar una cadena "user-friendly" de información
 * @return Una cadena de texto incluyendo la información del equipo y los
 *         pilotos que lo forman
 */
string info ( F1team& t )
{
   std::stringstream aux;

   if ( ( t.getP1 () != 0 ) && ( t.getP2 () != 0 ) )
   {
      aux << "Equipo "
          << t.getNombre ()
          << std::endl
          << "Pilotos: "
          << t.getP1 ()->getNombre ()
          << " y "
          << t.getP2 ()->getNombre ()
          << std::endl
          << "Puntos en el campeonato de constructores: "
          << t.getPtosConstructores ();
   }
   else
   {
      aux << "Equipo de nueva creación. Sin datos todavía";
   }

   return ( aux.str () );
}

/**
 * @brief Función para generar una cadena "user-friendly" de información
 * @return Una cadena de texto incluyendo los valores de los atributos del
 *         objeto 
 */
string info ( Piloto &p )
{
   std::stringstream aux;
   
   aux << "Soy un piloto de Fórmula 1. Mi nombre es "
       << p.getNombre ()
       << " y llevo acumulados "
       << p.getPuntos ()
       << " en el campeonato actual";

   return ( aux.str () );
}

