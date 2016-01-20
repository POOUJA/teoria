/** 
 * @file utils.cpp
 * @author algarcia
 * 
 * @date 20 de enero de 2016
 */

#include <sstream>   // Para utilizar stringstream
#include "utils.h"
#include "Componente.h"
#include "Computadora.h"

/**
 * @brief Genera una cadena de texto "user-friendly" con los datos de un
 *        componente
 * @param c Referencia al componente a procesar
 * @return Una cadena de texto con la información del componente 
 */
string info ( const Componente& c )
{
   std::stringstream aux;
   
   aux << "Marca: " << c.getMarca () << "\t"
       << "Modelo:" << c.getModelo () << "\t"
       << "S/N: " << c.getNumSerie () << "\t"
       << "Precio: " << c.getPrecio () << " Euros";
   
   return ( aux.str () );
}

/**
 * @brief Método para generar un texto con la información de una computadora
 * @param c Referencia a la computadora a procesar
 * @return Un texto con información de la computadora y cada uno de sus
 *         componentes
 */
string info ( const Computadora& c )
{
   std::stringstream aux;
   int i, nPiezas;

   aux << "- Computadora marca " << c.getMarca ()
       << ", modelo " << c.getModelo () << std::endl
       << "  Comprada el año " << c.getCompradoEn ();

   nPiezas = c.getNPiezas ();

   if ( nPiezas > 0 )
   {
      aux << std::endl
          << "  Compuesta por " << nPiezas
          << " componentes:" << std::endl;

      for ( i = 0; i < nPiezas; i++ )
      {
         aux << "  " << i+1 << ": " << info ( c.getPieza (i) ) << std::endl;
      }
   }

   aux << std::endl;

   return ( aux.str () );   
}

