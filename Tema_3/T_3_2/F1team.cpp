/**
 * @file F1team.h
 * Archivo con la implementación de la clase F1team
 * @author algarcia
 * @date 2015-12-09
 */

#include <sstream>
#include <stdexcept>
#include "F1team.h"

/**
 * Inicializa los punteros a 0, y el nombre a "---"
 * @brief Constructor por defecto
 */
F1team::F1team ( ): _p1 (0), _p2 (0), _nombre ("---")
{
}

/**
 * No copia los pilotos (no tiene sentido tener dos equipos con los mismos
 * pilotos), y añade al nombre " - 2", para que se sepa que es una copia
 * @brief Constructor de copia
 * @param orig Objeto del que se copian los atributos
 */
F1team::F1team ( const F1team& orig ): _p1 (0), _p2 (0)
{
   _nombre = orig._nombre + " - 2";
}

/**
 * @brief Constructor parametrizado
 * @param nP1 Puntero al primer piloto del equipo
 * @param nP2 Puntero al segundo piloto del equipo
 * @param nNombre Texto con el nombre del equipo
 */
F1team::F1team ( Piloto *nP1, Piloto *nP2, string nNombre ): _p1 (nP1), _p2 (nP2),
                                                             _nombre (nNombre)
{
}

/**
 * @brief Constructor parametrizado
 * @param nP1 Referencia al primer piloto del equipo
 * @param nP2 Referencia al segundo piloto del equipo
 * @param nNombre Texto con el nombre del equipo
 */
F1team::F1team ( Piloto &nP1, Piloto &nP2, string nNombre ): _p1 (&nP1), _p2 (&nP2),
                                                             _nombre (nNombre)
{
}

/**
 * Pone a 0 los punteros a los pilotos del equipo, pero no destruye los objetos.
 * Es responsabilidad del programador obtener los punteros a los pilotos con
 * F1team::getP1 y F1team::getP2 antes de destruir el objeto
 * @brief Destructor
 */
F1team::~F1team ( )
{
   _p1 = 0;
   _p2 = 0;
}

/**
 * @brief Modificador (setter) del atributo F1team::_nombre
 * @param nNombre Nuevo nombre para el equipo
 */
void F1team::setNombre ( string nNombre )
{
   _nombre = nNombre;
}

/**
 * @brief Observador (getter) del atributo F1team::_nombre
 * @return El nombre del equipo
 */
string F1team::getNombre ( ) const
{
   return _nombre;
}

/**
 * @brief Método para cambiar el segundo piloto del equipo
 * @param nP2 Puntero al nuevo piloto
 * @throws std::invalid_argument Si se pasa 0 como parámetro
 */
void F1team::setP2 ( Piloto* nP2 )
{
   if ( nP2 != 0 )
   {
      this->_p2 = nP2;
   }
   else
   {
      throw std::invalid_argument ( "F1team::setP2: valor incorrecto de parámetro" );
   }
}

/**
 * @brief Observador (getter) para el atributo F1team::_p2
 * @return Un puntero al segundo piloto del equipo
 */
Piloto* F1team::getP2 ( ) const
{
   return _p2;
}

/**
 * @brief Método para cambiar el primer piloto del equipo
 * @param nP1 Puntero al nuevo piloto
 * @throws std::invalid_argument Si se pasa 0 como parámetro
 */
void F1team::setP1 ( Piloto* nP1 )
{
   if ( nP1 != 0 )
   {
      _p1 = nP1;
   }
   else
   {
      throw std::invalid_argument ( "F1team::setP1: valor incorrecto de parámetro" );
   }
}

/**
 * @brief Observador (getter) para el atributo F1team::_p1
 * @return Un puntero al primer piloto del equipo
 */
Piloto* F1team::getP1 ( ) const
{
   return _p1;
}

/**
 * Método para sumar a cada piloto los puntos obtenidos al final de una carrera
 * @brief Suma los puntos obtenidos por los pilotos en una carrera
 * @param ptosP1 Puntos obtenidos por el primer piloto. No puede ser negativo
 * @param ptosP2 Puntos obtenidos por el segundo piloto. No puede ser negativo
 * @throws std::invalid_argument Si alguno de los dos valores de puntos son
 *         negativos
 * @throws std::logic_error Si aún no se han asignado pilotos al equipo
 */
void F1team::sumaPtosCarrera ( int ptosP1, int ptosP2 )
{
   if ( ( _p1 != 0 ) && ( _p2 != 0 ) )
   {
      if ( ( ptosP1 >= 0 ) && ( ptosP2 >= 0 ) )
      {
         _p1->addPuntos ( ptosP1 );
         _p2->addPuntos ( ptosP2 );
      }
      else
      {
         throw std::invalid_argument ( "F1team::sumaPtosCarrera: un piloto no"
                                       " puede tener puntuación negativa" );
      }
   }
   else
   {
      throw std::logic_error ( "F1team::sumaPtosCarrera: el equipo no tiene"
                               " pilotos aún" );
   }
}

/**
 * @brief Consulta los puntos del equipo en el campeonato de constructores
 * @return La suma de los puntos de los pilotos del equipo en el campeonato
 *         actual. 0 si todavía no se han asignado los pilotos
 */
int F1team::getPtosConstructores () const
{
   int aux = 0;

   if ( ( _p1 != 0 ) && ( _p2 != 0 ) )
   {
      aux = _p1->getPuntos () + _p2->getPuntos ();
   }
   
   return ( aux );
}

/**
 * @brief Método para generar una cadena "user-friendly" de información
 * @return Una cadena de texto incluyendo la información del equipo y los
 *         pilotos que lo forman
 */
string F1team::info () const
{
   std::stringstream aux;

   if ( ( _p1 != 0 ) && ( _p2 != 0 ) )
   {
      aux << "Equipo "
          << _nombre
          << std::endl
          << "Pilotos: "
          << _p1->getNombre ()
          << " y "
          << _p2->getNombre ()
          << std::endl
          << "Puntos en el campeonato de constructores: "
          << getPtosConstructores ();
   }
   else
   {
      aux << "Equipo de nueva creación. Sin datos todavía";
   }

   return ( aux.str () );
}

/**
 * @brief Operador de asignación
 * @param orig Objeto del que se copian los valores de los atributos
 * @return Una referencia al propio objeto, para su uso en asignaciones en
 *         cascada (a=b=c)
 */
F1team& F1team::operator = (const F1team& orig)
{
   _nombre = orig._nombre;
   _p1 = orig._p1;
   _p2 = orig._p2;
   
   return ( *this );
}