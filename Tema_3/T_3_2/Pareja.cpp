/**
 * @file Pareja.h
 * Archivo con la implementación de la clase Pareja
 * @author algarcia
 * @date 2015-12-09
 */

#include <sstream>
#include <stdexcept>
#include "Pareja.h"

/**
 * Inicializa los punteros a 0, y el ranking a 99999
 * @brief Constructor por defecto
 */
Pareja::Pareja ( ): _t1 (0), _t2 (0), _ranking (99999)
{
}

/**
 * @brief Constructor de copia
 * @param orig Objeto del que se copian los atributos
 */
Pareja::Pareja ( const Pareja& orig ): _t1 (orig._t1), _t2 (orig._t2),
                                       _ranking (orig._ranking)
{
}

/**
 * @brief Constructor parametrizado
 * @param nT1 Puntero al primer tenista de la pareja
 * @param nT2 Puntero al segundo tenista de la pareja
 * @param nRanking Posición en el ranking de la pareja. Debe ser un número
 *                 positivo
 * @throws std::out_of_range Si el valor de ranking no es positivo
 */
Pareja::Pareja ( Tenista *nT1, Tenista *nT2, int nRanking ): _t1 (nT1), _t2 (nT2)
{
   if ( nRanking > 0 )
   {
      _ranking = nRanking;
   }
   else
   {
      throw std::out_of_range ( "Pareja::Pareja: El ranking tiene que ser"
                                " positivo" );
   }
}

/**
 * @brief Constructor parametrizado
 * @param nT1 Referencia al primer tenista de la pareja
 * @param nT2 Referencia al segundo tenista de la pareja
 * @param nRanking Posición en el ranking de la pareja. Debe ser un número
 *                 positivo
 * @throws std::out_of_range Si el valor de ranking no es positivo
 */
Pareja::Pareja ( Tenista &nT1, Tenista &nT2, int nRanking ): _t1 (&nT1), _t2 (&nT2)
{
   if ( nRanking > 0 )
   {
      _ranking = nRanking;
   }
   else
   {
      throw std::out_of_range ( "Pareja::Pareja: El ranking tiene que ser"
                                " positivo" );
   }
}

/**
 * @brief Destructor
 * 
 * Pone a 0 los punteros a los miembros de la pareja, pero no destruye los
 * objetos
 */
Pareja::~Pareja ( )
{
   _t1 = 0;
   _t2 = 0;
}

/**
 * @brief Modificador (setter) del atributo Pareja::_ranking
 * @param nRanking Nuevo valor de ranking. Debe ser un número positivo
 * @throws std::out_of_range Si el valor de nRanking no es positivo
 */
void Pareja::setRanking ( int nRanking )
{
   if ( nRanking > 0 )
   {
      this->_ranking = nRanking;
   }
   else
   {
      throw std::out_of_range ( "Pareja::setRanking: El valor de ranking tiene"
                                " que ser positivo" );
   }
}

/**
 * @brief Observador (getter) del atributo Pareja::_ranking
 * @return El valor de ranking de la pareja
 */
int Pareja::getRanking ( ) const
{
   return _ranking;
}

/**
 * @brief Método para cambiar el segundo tenista de la pareja
 * 
 * Si se pasa 0 como parámetro, la pareja pasa a tener ranking 99999, ya que
 * no está completa
 * @param nT2 Puntero al nuevo tenista
 */
void Pareja::setT2 ( Tenista* nT2 )
{
   this->_t2 = nT2;

   if ( _t2 == 0 )
   {
      _ranking = 99999;
   }
}

/**
 * @brief Observador (getter) para el atributo Pareja::_t2
 * @return Un puntero al segundo tenista de la pareja, o 0 si éste no ha
 *         sido asignado
 */
Tenista* Pareja::getT2 ( ) const
{
   return _t2;
}

/**
 * @brief Método para cambiar el primer tenista de la pareja
 * 
 * Si se pasa 0 como parámetro, la pareja pasa a tener ranking 99999, ya que
 * no está completa
 * @param nT1 Puntero al nuevo tenista
 */
void Pareja::setT1 ( Tenista* nT1 )
{
   this->_t1 = nT1;
   
   if ( _t1 == 0 )
   {
      _ranking = 99999;
   }
}

/**
 * @brief Observador (getter) para el atributo Pareja::_t1
 * @return Un puntero al primer tenista de la pareja, o 0 si éste no ha
 *         sido asignado
 */
Tenista* Pareja::getT1 ( ) const
{
   return _t1;
}

/**
 * @brief Método para generar una cadena "user-friendly" de información
 * @return Una cadena de texto incluyendo los nombres de los tenistas que forman
 *         la pareja, y la posición en el ranking de la misma
 */
string Pareja::info () const
{
   std::stringstream aux;

   if ( ( _t1 != 0 ) && ( _t2 != 0 ) )
   {
      aux << "Somos una pareja, formada por "
          << _t1->getNombre ()
          << " y "
          << _t2->getNombre ()
          << ". Nuestro ranking es "
          << _ranking;
   }
   else
   {
      if ( _t1 == 0 )
      {
         if ( _t2 == 0 )
         {
            aux << "Esta pareja está vacía";
         }
         else
         {
            aux << "En esta pareja falta el primer integrante. El segundo es "
                << _t2->getNombre ();
         }
      }
      else
      {
         // t2 es necesariamente distinto de 0 en este caso
         aux << "En esta pareja falta el segundo integrante. El primero es "
             << _t1->getNombre ();
      }
   }

   return ( aux.str () );
}

/**
 * @brief Operador de asignación
 * 
 * Sólo copia el valor de ranking, puesto que no tiene sentido tener dos parejas
 * con los mismos jugadores
 * @param orig Objeto del que se copian los valores de los atributos
 * @return Una referencia al propio objeto, para su uso en asignaciones en
 *         cascada (a=b=c)
 */
Pareja& Pareja::operator = (const Pareja& orig)
{
   this->_ranking = orig._ranking;
   
   return ( *this );
}