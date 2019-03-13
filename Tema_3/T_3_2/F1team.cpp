/**
 * @file F1team.h
 * Archivo con la implementación de la clase F1team
 * @author algarcia
 * @date 2015-12-09
 */

#include <stdexcept>   // Para utilizar excepciones estándar
#include "F1team.h"

using std::string;

/**
 * No copia los pilotos (no tiene sentido tener dos equipos con los mismos
 * pilotos), y añade al nombre " - 2", para que se sepa que es una copia
 * @brief Constructor de copia
 * @param orig Objeto del que se copian los atributos
 */
F1team::F1team ( const F1team& orig ): _p1 (nullptr), _p2 (nullptr)
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
{ }

/**
 * @brief Constructor parametrizado
 * @param nP1 Referencia al primer piloto del equipo
 * @param nP2 Referencia al segundo piloto del equipo
 * @param nNombre Texto con el nombre del equipo
 */
F1team::F1team ( Piloto &nP1, Piloto &nP2, string nNombre ): F1team ( &nP1, &nP2, nNombre )
{ }

/**
 * @brief Constructor parametrizado
 * @param nNombre Texto con el nombre del equipo
 */
F1team::F1team (std::string nNombre): F1team ( nullptr, nullptr, nNombre )
{ }

/**
 * @brief Destructor
 * @post Los pilotos, si los hubiera, no se destruyen
 * @note Es responsabilidad del programador obtener los punteros a los pilotos
 *       con F1team::getP1 y F1team::getP2 antes de que se destruya el objeto
 */
F1team::~F1team ( )
{
   _p1 = nullptr;
   _p2 = nullptr;
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
   if ( nP2 == 0 )
   {
      throw std::invalid_argument ( "F1team::setP2: valor incorrecto de parámetro" );
   }

   this->_p2 = nP2;
}

/**
 * @brief Método para comprobar si el equipo tiene segundo piloto
 * @retval true Si el equipo tiene segundo piloto
 * @retval false Si el equipo no tiene segundo piloto
 */
bool F1team::existeP2 ()
{
   return ( _p2 != 0 );
}

/**
 * @brief Observador (getter) para el atributo F1team::_p2
 * @return Una referencia al segundo piloto del equipo
 * @throws std::runtime_error Si el equipo no tiene aún segundo piloto
 */
Piloto& F1team::getP2 ( ) const
{
   if ( _p2 == 0 )
   {
      throw std::runtime_error ( "F1team::getP2: no hay segundo piloto" );
   }

   return (*_p2);
}

/**
 * @brief Método para cambiar el primer piloto del equipo
 * @param nP1 Puntero al nuevo piloto
 * @throws std::invalid_argument Si se pasa 0 como parámetro
 */
void F1team::setP1 ( Piloto* nP1 )
{
   if ( nP1 == 0 )
   {
      throw std::invalid_argument ( "F1team::setP1: valor incorrecto de parámetro" );
   }

   _p1 = nP1;
}

/**
 * @brief Método para comprobar si el equipo tiene primer piloto
 * @retval true Si el equipo tiene primer piloto
 * @retval false Si el equipo no tiene primer piloto
 */
bool F1team::existeP1 ()
{
   return ( _p1 != 0 );
}

/**
 * @brief Observador (getter) para el atributo F1team::_p1
 * @return Una referencia al primer piloto del equipo
 * @throws std::runtime_error Si el equipo no tiene aún primer piloto
 */
Piloto& F1team::getP1 ( ) const
{
   if ( _p1 == 0 )
   {
      throw std::runtime_error ( "F1team::getP1: no hay primer piloto" );
   }

   return (*_p1);
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
   if ( ( _p1 == 0 ) || ( _p2 == 0 ) )
   {
      throw std::logic_error ( "F1team::sumaPtosCarrera: el equipo no tiene los"
                               "dos pilotos asignados todavía" );
   }

   if ( ( ptosP1 < 0 ) || ( ptosP2 < 0 ) )
   {
      throw std::invalid_argument ( "F1team::sumaPtosCarrera: un piloto no"
                                    " puede tener puntuación negativa" );
   }

   _p1->addPuntos ( ptosP1 );
   _p2->addPuntos ( ptosP2 );
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
 * @brief Operador de asignación
 * @param orig Objeto del que se copian los valores de los atributos
 * @return Una referencia al propio objeto, para su uso en asignaciones en
 *         cascada (a=b=c)
 */
F1team& F1team::operator = (const F1team& orig)
{
   if ( this != &orig )
   {
      _nombre = orig._nombre;
      _p1 = orig._p1;
      _p2 = orig._p2;
   }
   
   return ( *this );
}