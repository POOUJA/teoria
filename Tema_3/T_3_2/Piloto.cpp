/**
 * @file Piloto.cpp
 * Archivo con la implementación de la clase Piloto
 * @author algarcia
 * @date 2015-12-09
 */

#include <stdexcept>   // Para usar std::out_of_range
#include "Piloto.h"

/**
 * @brief Constructor por defecto de la clase
 * 
 * Inicializa el nombre a "---", y los puntos a 0
 */
Piloto::Piloto ( ): _nombre ("---"), _puntos (0)
{
}

/**
 * Copia los puntos en el campeonato, pero en el nombre añade la cadena "-2",
 * para que se sepa que es una copia
 * @brief Constructor de copia
 * @param orig Objeto del que se copian los atributos
 */
Piloto::Piloto ( const Piloto& orig ): _puntos (orig._puntos)
{
   _nombre = orig._nombre + " - 2";
}

/**
 * @brief Constructor parametrizado
 * @param nNombre Nombre del nuevo piloto
 * @param nPuntos Puntos del piloto. Ha de ser un número mayor o igual a 0
 * @throws std::invalid_argument Si el valor de puntos no es mayor o igual a 0
 */
Piloto::Piloto ( const string nNombre, const int nPuntos ): _nombre (nNombre),
                                                            _puntos (nPuntos)
{
   if ( nPuntos < 0 )
   {
      throw std::invalid_argument ( "Piloto::Piloto: El valor de puntos no"
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
 * @throws std::invalid_argument Si el valor de puntosCarrera es negativo
 */
void Piloto::addPuntos ( int puntosCarrera )
{
   if ( puntosCarrera >= 0 )
   {
      this->_puntos = puntosCarrera;
   }
   else
   {
      throw std::invalid_argument ( "Piloto::addPuntos: El valor de puntos no"
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
 * @brief Operador de asignación
 * @param orig Objeto del que se copian los atributos
 * @return Una referencia al propio objeto, para posibilitar las asignaciones en
 *         cascada (a=b=c)
 */
Piloto& Piloto::operator = (const Piloto& orig)
{
   if ( this != &orig )
   {
      this->_puntos = orig._puntos;
      this->_nombre = orig._nombre;
   }

   return ( *this );
}