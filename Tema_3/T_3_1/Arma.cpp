/**
 * @file Arma.cpp
 * Archivo con la definición de los métodos de la clase Arma
 * @author algarcia
 * @date 2015-10-21
 */

#include "Arma.h"
#include <sstream>     // Para usar stringstream
#include <stdexcept>   // Para usar std::out_of_range

/**
 * @brief Constructor por defecto
 * 
 * Fija el poder a 0, y el nombre a "---"
 */
Arma::Arma ( ): nombre("---"), poder(0)
{
}

/**
 * @brief Constructor de copia
 * 
 * Cambia el nombre del objeto nuevo, añadiéndole " - 2" al final, para que se
 * distinga del original
 * @param orig Objeto del que se copian los atributos
 */
Arma::Arma ( const Arma& orig ): poder(orig.poder)
{
   nombre = orig.nombre + " - 2";   // Para evitar dos armas con el mismo nombre
}

/**
 * @brief Constructor parametrizado
 * 
 * Comprueba que el nuevo valor para Arma::poder sea >= 0
 * @param nNombre Texto a asignar como nombre del arma. No se hacen comprobaciones
 * @param nPoder Valor de poder para la nueva arma
 * @exception std::out_of_range Si el valor de nPoder es < 0
 */
Arma::Arma (const string nNombre, const int nPoder): nombre(nNombre)
{
   if ( nPoder >= 0 )
   {
      poder = nPoder;
   }
   else
   {
      throw std::out_of_range ( "Arma::Arma: el valor ha de ser >= 0" );
   }
}

/**
 * @brief Destructor
 */
Arma::~Arma ( )
{
}

/**
 * @brief Modificador para el atributo Arma::nombre
 * @param nNombre Nuevo nombre para el arma. No se hacen comprobaciones sobre él
 */
void Arma::setNombre ( string nNombre )
{
   this->nombre = nombre;
}

/**
 * @brief Observador para el atributo Arma::nombre
 * @return El nombre asignado al arma
 */
string Arma::getNombre ( ) const
{
   return nombre;
}

/**
 * @brief Modificador para el atributo Arma::poder
 * @param nPoder Nuevo valor de poder para el arma. Se hace la comprobación de
 *        que su valor sea >= 0
 * @exception std::out_of_range Si el valor de nPoder es < 0
 */
void Arma::setPoder ( int nPoder )
{
   if ( nPoder >= 0 )
   {
      this->poder = nPoder;
   }
   else
   {
      throw std::out_of_range ( "Arma::setPoder: el valor ha de ser >= 0" );
   }
}

/**
 * @brief Observador para el atributo Arma::poder
 * @return El valor del atributo Arma::poder
 */
int Arma::getPoder ( ) const
{
   return poder;
}

/**
 * @brief Información del objeto
 * @return Devuelve una cadena de texto conteniendo los valores de los atributos
 *         del objeto
 */
string Arma::info () const
{
   std::stringstream aux;
   string resultado;
   
   aux << "Soy un arma. Mi nombre es "
       << nombre
       << " y mi poder es de "
       << poder
       << " puntos";

   getline ( aux, resultado );
   return ( resultado );
}