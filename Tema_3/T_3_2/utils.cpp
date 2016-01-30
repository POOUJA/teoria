/** 
 * @file utils.cpp
 * @author algarcia
 * 
 * @date 15 de enero de 2016
 */

#include <sstream>
#include <stdexcept>   // Para utilizar stringstream
#include "utils.h"

/**
 * @brief Función para generar una cadena "user-friendly" de información
 * @param f Referencia al equipo de F1 del que se extrae la información
 * @return Una cadena de texto incluyendo la información del equipo y los
 *         pilotos que lo forman
 */
string t32_utils::info ( F1team& t )
{
   std::stringstream aux;

   aux << "Equipo "
       << t.getNombre ()
       << std::endl
       << "Pilotos: ";

   try
   {
      aux << t.getP1 ().getNombre ()
          << " y "
          << t.getP2 ().getNombre ()
          << std::endl
          << "Puntos en el campeonato de constructores: "
          << t.getPtosConstructores ();
   }
   catch ( std::runtime_error re )
   {
      aux << "Equipo de nueva creación. Sin datos de pilotos todavía";
   }

   return ( aux.str () );
}

/**
 * @brief Función para generar una cadena "user-friendly" de información
 * @param p Referencia al piloto del que se extrae la información
 * @return Una cadena de texto incluyendo los valores de los atributos del
 *         objeto 
 */
string t32_utils::info ( Piloto &p )
{
   std::stringstream aux;
   
   aux << "Soy un piloto de Fórmula 1. Mi nombre es "
       << p.getNombre ()
       << " y llevo acumulados "
       << p.getPuntos ()
       << " en el campeonato actual";

   return ( aux.str () );
}

