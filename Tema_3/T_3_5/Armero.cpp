/**
 * @file Armero.cpp
 * Archivo con la definición de los métodos de la clase Armero
 * @author algarcia
 * @date 2015-12-31
 */

#include "Armero.h"
#include <stdlib.h>    // Para usar rand
#include <sstream>     // Para usar stringstream
#include <stdexcept>   // Para usar la excepción out_of_range

/**
 * @brief Constructor por defecto
 * 
 * Inicializa la energía vital a 1000, el nombre a "---" y el poder máximo de
 * las armas que cree a 100
 */
Armero::Armero ( ): _energia (1000), _nombre("---"), _maxPoderArma(100)
{
}

/**
 * @brief Constructor parametrizado
 * 
 * Inicializa la energía vital a 1000
 * @param nNombre Texto con el nombre que se asigna al armero. No se hacen
 *        comprobaciones sobre él
 * @param nMPArma Valor máximo de poder para las armas que cree el armero. Ha
 *        de ser un número positivo
 * @throws std::out_of_range Si el valor máximo de poder para las armas no es
 *            positivo
 */
Armero::Armero ( string nNombre, int nMPArma ): _energia (1000), _nombre(nNombre)
{
   if ( nMPArma > 0 )
   {
      _maxPoderArma = nMPArma;
   }
   else
   {
      throw std::out_of_range ( "Armero::Armero: valor fuera de rango" );
   }
}

/**
 * @brief Constructor de copia
 * 
 * Modifica el nombre del nuevo armero, añadiendo "-2" al final, para que no
 * haya dos armeros con el mismo nombre
 * @param orig Objeto del que copia los atributos
 */
Armero::Armero ( const Armero& orig ): _energia (orig._energia),
                                       _maxPoderArma (orig._maxPoderArma)
{
   _nombre = orig._nombre + " - 2";   // Para no tener dos armeros con el mismo nombre
}

/**
 * @brief Destructor de la clase
 */
Armero::~Armero ( )
{
}

/**
 * @brief Modificador para el atributo Armero::_energia
 * @param nEnergia Nuevo valor de energía a asignar. No se hacen comprobaciones
 *        sobre él
 */
void Armero::setEnergia ( int nEnergia )
{
   this->_energia = nEnergia;
}

/**
 * @brief Observador para el atributo Armero::_energia
 * @return La energía restante en el armero
 */
int Armero::getEnergia ( ) const
{
   return _energia;
}

/**
 * @brief Modificador para el atributo Armero::_nombre
 * @param nNombre Texto con el nuevo nombre. No se hacen comprobaciones sobre él
 */
void Armero::setNombre ( string nNombre )
{
   this->_nombre = nNombre;
}

/**
 * @brief Observador para el atributo Armero::_nombre
 * @return El texto con el nombre del armero
 */
string Armero::getNombre ( ) const
{
   return _nombre;
}

/**
 * @brief Modificador para el atributo Armero::_maxPoderArma
 * @param nMaxPoderArma Nuevo valor para el poder máximo de las armas producidas.
 *        Ha de ser un valor positivo
 * @throws std::out_of_range Si el valor del parámetro no es positivo
 */
void Armero::setMaxPoderArma ( int nMaxPoderArma )
{
   if ( nMaxPoderArma > 0 )
   {
      this->_maxPoderArma = nMaxPoderArma;
   }
   else
   {
      throw std::out_of_range ( "Armero::setMaxPoderArma: valor fuera de rango" );
   }
}

/**
 * @brief Observador para el atributo Armero::_maxPoderArma
 * @return El poder de destrucción máximo que tienen las armas fabricadas por el
 *         armero
 */
int Armero::getMaxPoderArma ( ) const
{
   return _maxPoderArma;
}

/**
 * @brief Método para crear armas
 * 
 * El poder de destrucción del arma creada variará aleatoriamente entre 1 y el
 * valor del atributo Armero::_maxPoderArma
 * @param nombreArma Texto con el nombre que se asignará a la nueva arma
 * @return Un puntero al objeto de clase Arma con la información de la nueva
 *         arma
 */
Arma* Armero::creaArma ( string nombreArma )
{
   // Crea un nuevo objeto de clase Arma, con el nombre que se le pasa
   Arma *a = new Arma ( nombreArma );

   // Calcula aleatoriamente el poder asociado al arma, y lo asigna
   int aux = (rand () % _maxPoderArma) + 1;   
   a->setPoder ( aux );

   return ( a );
}

/**
 * @brief Método para producir un ataque
 * 
 * @return El valor del daño provocado por el ataque de un armero
 */
int Armero::ataque ()
{
   return ( 0 );   // Un armero no puede atacar
}

/**
 * @brief Información del objeto
 * @return Devuelve una cadena de texto conteniendo los valores de los atributos
 *         del objeto
 */
string Armero::info () const
{
   std::stringstream aux;
   
   aux << "Soy armero. Mi nombre es "
       << _nombre
       << ", mi energía es "
       << _energia
       << " y puedo producir armas de hasta "
       << _maxPoderArma
       << " puntos de poder";

   return ( aux.str () );
}

/**
 * En este caso, no asigna el nombre del armero, para que no haya dos con el
 * mismo nombre
 * @brief Operador de asignación
 * @param orig Objeto del que se copian los atributos
 * @return Una referencia al propio objeto, para posibilitar las asignaciones
 *         en cascada (a=b=c)
 */
Armero& Armero::operator = (const Armero& orig)
{
   this->_energia = orig._energia;
   this->_maxPoderArma = orig._maxPoderArma;
   
   return ( *this );
}