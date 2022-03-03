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
#include "DiscoDuro.h"
#include "PlacaBase.h"

/**
 * @brief Genera una cadena de texto "user-friendly" con los datos de un
 *        componente
 * @param c Referencia al componente a procesar
 * @return Una cadena de texto con la información del componente 
 */
string t36_utils::info ( const Componente& c )
{
   std::stringstream aux;
   
   aux << "Marca: " << c.getMarca () << "\t"
       << "Modelo: " << c.getModelo () << "\t"
       << "S/N: " << c.getNumSerie () << "\t"
       << "Precio: " << c.getPrecio () << " Euros";
   
   return ( aux.str () );
}

/**
 * A la hora de añadir la información de los componentes individuales, utiliza
 * la función t36_utils::info genérica para Componente. En el tema 4 veremos
 * cómo conseguir determinar en tiempo de ejecución cuál es la clase exacta de
 * cada objeto
 * @brief Método para generar un texto con la información de una computadora
 * @param c Referencia a la computadora a procesar
 * @return Un texto con información de la computadora y cada uno de sus
 *         componentes
 */
string t36_utils::info ( const Computadora& c )
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
         aux << "  " << i+1 << ": "
             << info ( c.getPieza (i) ) << std::endl;
      }

      aux << "  Coste de la computadora: " << c.getPrecio ();
   }

   aux << std::endl;

   return ( aux.str () );   
}

/**
 * @brief Método para generar un texto "user-friendly" sobre el disco
 * @param dd Referencia al objeto de clase DiscoDuro a procesar
 * @return Una cadena de texto con la información del disco
 */
string t36_utils::info ( DiscoDuro& dd )
{
   std::stringstream aux;

   aux << "Disco duro. "
       // << info ( dynamic_cast<Componente&> (dd) )   // Lo veremos en el tema 4
       << "Marca: " << dd.getMarca () << "\t"
       << "Modelo: " << dd.getModelo () << "\t"
       << "S/N: " << dd.getNumSerie () << "\t"
       << "Precio: " << dd.getPrecio () << " Euros"
       << std::endl
       << "   Capacidad: " << dd.getCapacidad ()
       << "\tFormato: " << dd.getFormato ();
   
   return ( aux.str () );
}

/**
 * @brief Método para generar un texto "user-friendly" sobre la placa base
 * @param pb Referencia al objeto de clase PlacaBase a procesar
 * @return Una cadena de texto con la información de la placa base
 */
string t36_utils::info ( PlacaBase& pb )
{
   std::stringstream aux;

   aux << "Placa base. "
       // << info ( dynamic_cast<Componente&> (pb) )   // Lo veremos en el tema 4
       << "Marca: " << pb.getMarca () << "\t"
       << "Modelo: " << pb.getModelo () << "\t"
       << "S/N: " << pb.getNumSerie () << "\t"
       << "Precio: " << pb.getPrecio () << " Euros"
       << std::endl
       << "   Factor de forma: " << PlacaBase::ff2string ( pb.getFForma () )
       << "\tNúmero de slots PCIe: " << pb.getNPCIe () << std::endl
       << "   Número de puertos USB: " << pb.getNUSB ()
       << "\tChipset: " << pb.getChipset () << std::endl
       << "   Socket: " << pb.getSocket ();
   
   return ( aux.str () );
}

/**
 * @brief Método para generar un texto "user-friendly" sobre un procesador
 * @param p Referencia al objeto de clase Procesador a procesar
 * @return Una cadena de texto con la información del procesador
 */
string t36_utils::info ( Procesador& p )
{
   std::stringstream aux;

   aux << "Procesador. "
       // << info ( dynamic_cast<Componente&> (p) )   // Lo veremos en el tema 4
       << "Marca: " << p.getMarca () << "\t"
       << "Modelo: " << p.getModelo () << "\t"
       << "S/N: " << p.getNumSerie () << "\t"
       << "Precio: " << p.getPrecio () << " Euros"
       << std::endl
       << "   Arquitectura: " << Procesador::arq2string ( p.getArq () )
       << "\tSocket: " << p.getSocket () << std::endl
       << "   Velocidad en gigahercios: " << p.getVelocidad ();
   
   return ( aux.str () );
}
