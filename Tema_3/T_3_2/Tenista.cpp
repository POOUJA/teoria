/**
 * @file Tenista.cpp
 * Archivo con la implementación de la clase Tenista
 * @author algarcia
 * @date 2015-12-09
 */

#include "Tenista.h"
#include <sstream>     // Para usar stringstream
#include <stdexcept>   // Para usar std::out_of_range

/**
 * @brief Constructor por defecto de la clase
 * 
 * Inicializa el nombre a "---", y el ranking a 99999
 */
Tenista::Tenista ( ): _nombre ("---"), _ranking (99999)
{
}

/**
 * @brief Constructor de copia
 * 
 * Copia el valor de ranking, pero modifica el nombre, añadiendo "-2" al final,
 * para evitar que haya dos tenistas con el mismo nombre
 * @param orig Objeto del que se copian los atributos
 */
Tenista::Tenista ( const Tenista& orig ): _ranking ( orig._ranking )
{
   _nombre = orig._nombre + " - 2";
}

/**
 * @brief Constructor parametrizado
 * @param nNombre Nombre del nuevo tenista
 * @param nRanking Ranking del nuevo tenista. Ha de ser un número positivo
 * @throw std::out_of_range Si el valor de ranking no es positivo
 */
Tenista::Tenista ( const string nNombre, const int nRanking ): _nombre (nNombre)
{
   if ( nRanking > 0 )
   {
      _ranking = nRanking;
   }
   else
   {
      throw std::out_of_range ( "El valor de ranking no puede ser negativo o cero" );
   }
}

/**
 * @brief Destructor
 */
Tenista::~Tenista ( )
{
}

/**
 * @brief Modificador (setter) del atributo Tenista::_ranking
 * @param nRanking Nuevo valor de ranking. Debe ser un número positivo
 * @throws std::out_of_range Si el valor de nRanking no es positivo
 */
void Tenista::setRanking ( int nRanking )
{
   if ( nRanking > 0 )
   {
      this->_ranking = nRanking;
   }
   else
   {
      throw std::out_of_range ( "El valor de ranking no puede ser negativo o cero" );
   }
}

/**
 * @brief Observador (getter) del atributo Tenista::_ranking
 * @return El valor de ranking del tenista
 */
int Tenista::getRanking ( ) const
{
   return _ranking;
}

/**
 * @brief Modificador (setter) del atributo Tenista::_nombre
 * @param nNombre Nuevo valor para el nombre del tenista
 */
void Tenista::setNombre ( string nNombre )
{
   this->_nombre = nNombre;
}

/**
 * @brief Observador (getter) para el atributo Tenista::_nombre
 * @return El nombre del tenista
 */
string Tenista::getNombre ( ) const
{
   return _nombre;
}

/**
 * @brief Método para generar una cadena "user-friendly" de información
 * @return Una cadena de texto incluyendo los valores de los atributos del
 *         objeto 
 */
string Tenista::info () const
{
   std::stringstream aux;
   string resultado;
   
   aux << "Soy un tenista. Mi nombre es "
       << _nombre
       << " y estoy en el puesto "
       << _ranking
       << " del ranking";
   getline ( aux, resultado );
   return ( resultado );
}

/**
 * @brief Operador de asignación
 *
 * No se copia el atributo Tenista::_nombre, para evitar que haya dos tenistas
 * con el mismo nombre
 * @param orig Objeto del que se copian los atributos
 * @return Una referencia al propio objeto, para posibilitar las asignaciones en
 *         cascada (a=b=c)
 */
Tenista& Tenista::operator = (const Tenista& orig)
{
   this->_ranking = orig._ranking;
   
   return ( *this );
}