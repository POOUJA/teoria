/**
 * @file Piloto.cpp
 * Archivo con la implementación de la clase Piloto
 * @author algarcia
 * @date 2015-12-09
 */

#include "Piloto.h"
#include <sstream>     // Para usar stringstream
#include <stdexcept>   // Para usar std::out_of_range

/**
 * @brief Constructor por defecto de la clase
 * 
 * Inicializa el nombre a "---", y los puntos a 0
 */
Piloto::Piloto ( ): _nombre ("---"), _puntos (0)
{
}

/**
 * @brief Constructor de copia
 * @param orig Objeto del que se copian los atributos
 */
Piloto::Piloto ( const Piloto& orig ): _nombre (orig._nombre),
                                       _puntos (orig._puntos)
{
}

/**
 * @brief Constructor parametrizado
 * @param nNombre Nombre del nuevo piloto
 * @param nPuntos Puntos del piloto. Ha de ser un número mayor o igual a 0
 * @throws std::out_of_range Si el valor de puntos no es mayor o igual a 0
 */
Piloto::Piloto ( const string nNombre, const int nPuntos ): _nombre (nNombre)
{
   if ( nPuntos >= 0 )
   {
      _puntos = nPuntos;
   }
   else
   {
      throw std::out_of_range ( "Piloto::Piloto: El valor de puntos no"
                                " puede ser negativo" );
   }
}

/**
 * @brief Destructor
 */
Piloto::~Piloto ( )
{
}

/**
 * @brief Método para poner el contador de puntos acumulados a 0
 */
void Piloto::resetPuntos ()
{
   _puntos = 0;
}

/**
 * @brief Método para sumar los puntos obtenidos en una carrera
 * @param puntosCarrera Puntos obtenidos en la última carrera. Debe ser un
 *        número mayor o igual a 0
 * @throws std::out_of_range Si el valor de puntosCarrera es negativo
 */
void Piloto::addPuntos ( int puntosCarrera )
{
   if ( puntosCarrera >= 0 )
   {
      this->_puntos = puntosCarrera;
   }
   else
   {
      throw std::out_of_range ( "Piloto::addPuntos: El valor de puntos no"
                                " puede ser negativo" );
   }
}

/**
 * @brief Observador (getter) del atributo Piloto::_puntos
 * @return Los puntos acumulados por el piloto en el campeonato actual
 */
int Piloto::getPuntos ( ) const
{
   return _puntos;
}

/**
 * @brief Modificador (setter) del atributo Piloto::_nombre
 * @param nNombre Nuevo valor para el nombre del piloto
 */
void Piloto::setNombre ( string nNombre )
{
   this->_nombre = nNombre;
}

/**
 * @brief Observador (getter) para el atributo Piloto::_nombre
 * @return El nombre del piloto
 */
string Piloto::getNombre ( ) const
{
   return _nombre;
}

/**
 * @brief Método para generar una cadena "user-friendly" de información
 * @return Una cadena de texto incluyendo los valores de los atributos del
 *         objeto 
 */
string Piloto::info () const
{
   std::stringstream aux;
   
   aux << "Soy un piloto de Fórmula 1. Mi nombre es "
       << _nombre
       << " y llevo acumulados "
       << _puntos
       << " en el campeonato actual";

   return ( aux.str () );
}

/**
 * @brief Operador de asignación
 * @param orig Objeto del que se copian los atributos
 * @return Una referencia al propio objeto, para posibilitar las asignaciones en
 *         cascada (a=b=c)
 */
Piloto& Piloto::operator = (const Piloto& orig)
{
   this->_puntos = orig._puntos;
   this->_nombre = orig._nombre;

   return ( *this );
}