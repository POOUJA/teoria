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
Arma::Arma ( ): _nombre("---"), _poder(0)
{
}

/**
 * @brief Constructor de copia
 * 
 * Cambia el nombre del objeto nuevo, añadiéndole " - 2" al final, para que se
 * distinga del original
 * @param orig Objeto del que se copian los atributos
 */
Arma::Arma ( const Arma& orig ): _poder(orig._poder)
{
   _nombre = orig._nombre + " - 2";   // Para evitar dos armas con el mismo nombre
}

/**
 * @brief Constructor parametrizado
 * 
 * Comprueba que el nuevo valor para Arma::poder sea >= 0
 * @param nNombre Texto a asignar como nombre del arma. No se hacen comprobaciones
 * @param nPoder Valor de poder para la nueva arma
 * @throws std::invalid_argument Si el valor de nPoder es < 0
 */
Arma::Arma (const string nNombre, const int nPoder): _nombre(nNombre),
                                                     _poder (nPoder)
{
   if ( nPoder < 0 )
   {
      throw std::invalid_argument ( "Arma::Arma: el poder ha de ser >= 0" );
   }
}

/**
 * @brief Destructor
 */
Arma::~Arma ( )
{
}

/**
 * @brief Modificador para el atributo Arma::_nombre
 * @param nNombre Nuevo nombre para el arma. No se hacen comprobaciones sobre él
 */
void Arma::setNombre ( string nNombre )
{
   this->_nombre = _nombre;
}

/**
 * @brief Observador para el atributo Arma::_nombre
 * @return El nombre asignado al arma
 */
string Arma::getNombre ( ) const
{
   return _nombre;
}

/**
 * @brief Modificador para el atributo Arma::_poder
 * @param nPoder Nuevo valor de poder para el arma. Se hace la comprobación de
 *        que su valor sea >= 0
 * @throws std::invalid_argument Si el valor de nPoder es < 0
 */
void Arma::setPoder ( int nPoder )
{
   if ( nPoder >= 0 )
   {
      this->_poder = nPoder;
   }
   else
   {
      throw std::invalid_argument ( "Arma::setPoder: el valor ha de ser >= 0" );
   }
}

/**
 * @brief Observador para el atributo Arma::_poder
 * @return El poder de destrucción del arma
 */
int Arma::getPoder ( ) const
{
   return _poder;
}

/**
 * @brief Información del arma
 * @return Devuelve una cadena de texto conteniendo los valores de los atributos
 *         del arma
 */
string Arma::info () const
{
   std::stringstream aux;
   
   aux << "Soy un arma. Mi nombre es "
       << _nombre
       << " y mi poder es de "
       << _poder
       << " puntos";

   return ( aux.str () );
}

/**
 * En este caso, no asigna el nombre, para evitar dos armas con el mismo nombre
 * @brief Operador de asignación
 * @param orig Objeto del que se copian los atributos
 * @return Una referencia al propio objeto, necesaria para poder hacer
 *         asignaciones en cadena (a=b=c)
 */
Arma& Arma::operator = (const Arma& orig)
{
   this->_poder = orig._poder;
   
   return ( *this );
}