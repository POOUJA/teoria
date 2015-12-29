/**
 * @file Dependencia.cpp
 * Archivo con la implementación de la clase Dependencia
 * @author algarcia
 * @date 2015-12-11
 */

#include <stdexcept>
#include <sstream>

#include "Dependencia.h"

/**
 * Inicializa una dependencia con superficie 0, nombre "---" y sucia
 * @brief Constructor por defecto
 */
Dependencia::Dependencia ( ): _nombre ("---"), _superficie(0), _limpia (false)
{
}

/**
 * @brief Constructor de copia
 * @param orig
 */
Dependencia::Dependencia ( const Dependencia& orig ): _nombre (orig._nombre),
                                                      _superficie (orig._superficie),
                                                      _limpia (orig._limpia)
{
}

/**
 * Crea una nueva dependencia con los valores que se le pasan como parámetros
 * @brief Constructor parametrizado
 * @param nombre Nombre de la nueva dependencia
 * @param superficie Superficie. Debe ser un número positivo
 * @param estaLimpia Indica si la dependencia está limpia o no
 * @throws std::invalid_argument Si la superficie de la dependencia no es un
 *         número positivo
 */
Dependencia::Dependencia ( string nombre, float superficie,
                           bool estaLimpia ): _nombre (nombre),
                           _superficie (superficie), _limpia (estaLimpia)
{
   if ( superficie <= 0)
   {
      throw std::invalid_argument ( "Dependencia::Dependencia: la superficie debe"
                                    " ser un número positivo" );
   }
}

/**
 * @brief Destructor por defecto
 */
Dependencia::~Dependencia ( )
{
}

/**
 * @brief Método para cambiar el estado de limpieza de la habitación
 * @throws std::runtime_error Si se intenta limpiar una habitación que ya está
 *         limpia
 */
void Dependencia::limpiar ()
{
   if ( _limpia == false )
   {
      _limpia = true;
   }
   else
   {
      throw std::runtime_error ( "Dependencia::limpiar: se intenta limpiar una"
                                 " habitación que ya está limpia" );
   }
}

/**
 * @brief Observador del estado de limpieza de la dependencia
 * @retval true  Si la dependencia está limpia
 * @retval false Si la dependencia está sucia
 */
bool Dependencia::estaLimpia () const
{
   return _limpia;
}

/**
 * @brief Modificador de la superficie de la dependencia
 * @param nSuperficie Nuevo valor de superficie a asignar. Ha de ser positivo
 * @throws std::invalid_argument Si el valor de la superficie no es un número
 *         positivo
 */
void Dependencia::setSuperficie ( float nSuperficie )
{
   if ( nSuperficie > 0 )
   {
      this->_superficie = nSuperficie;
   }
   else
   {
      throw std::invalid_argument ( "Dependencia::setSuperficie: el valor de"
                                    " superficie ha de ser un número positivo" );
   }
}

/**
 * @brief Método para consultar la superficie de la dependencia
 * @return El valor de superficie de la dependencia
 */
float Dependencia::getSuperficie ( ) const
{
   return _superficie;
}

/**
 * @brief Modificador para el nombre de la dependencia
 * @param nNombre Nuevo nombre para la dependencia
 */
void Dependencia::setNombre ( string nNombre )
{
   this->_nombre = nNombre;
}

/**
 * @brief Observador para el nombre de la dependencia
 * @return El nombre de la dependencia
 */
string Dependencia::getNombre ( ) const
{
   return _nombre;
}

/**
 * @brief Operador de asignación
 * @param orig Objeto del que se copian los atributos
 * @return Una referencia al propio objeto, para que se puedan hacer
 *         asignaciones en cadena (a=b=c)
 */
Dependencia& Dependencia::operator = (const Dependencia& orig)
{
   _nombre = orig._nombre;
   _superficie = orig._superficie;
   _limpia = orig._limpia;

   return ( *this );
}

/**
 * @brief Método para obtener información extendida de la dependencia
 * @return Una cadena de texto con los datos de la dependencia
 */
string Dependencia::info () const
{
   std::stringstream ss;
   
   ss << _nombre << ", " << _superficie << " metros cuadrados, ";

   if ( _limpia == true )
   {
      ss << "limpia";
   }
   else
   {
      ss << "sucia";
   }

   return ( ss.str () );
}