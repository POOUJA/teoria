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
 * Inicializa los punteros a NULL, y el ranking a 99999
 * @brief Constructor por defecto
 */
Pareja::Pareja ( ): t1 (NULL), t2 (NULL), ranking (99999)
{
}

/**
 * @brief Constructor de copia
 * @param orig Objeto del que se copian los atributos
 */
Pareja::Pareja ( const Pareja& orig ): t1 (orig.t1), t2 (orig.t2),
                                       ranking (orig.ranking)
{
}

/**
 * @brief Constructor parametrizado
 * @param nT1 Puntero al primer tenista de la pareja
 * @param nT2 Puntero al segundo tenista de la pareja
 * @param nRanking Posición en el ranking de la pareja. Debe ser un número
 *                 positivo
 * @throw std::out_of_range Si el valor de ranking no es positivo
 */
Pareja::Pareja ( Tenista *nT1, Tenista *nT2, int nRanking ): t1 (nT1), t2 (nT2)
{
   if ( nRanking > 0 )
   {
      ranking = nRanking;
   }
   else
   {
      throw std::out_of_range ( "El ranking tiene que ser positivo" );
   }
}

/**
 * @brief Constructor parametrizado
 * @param nT1 Referencia al primer tenista de la pareja
 * @param nT2 Referencia al segundo tenista de la pareja
 * @param nRanking Posición en el ranking de la pareja. Debe ser un número
 *                 positivo
 * @throw std::out_of_range Si el valor de ranking no es positivo
 */
Pareja::Pareja ( Tenista &nT1, Tenista &nT2, int nRanking ): t1 (&nT1), t2 (&nT2)
{
   if ( nRanking > 0 )
   {
      ranking = nRanking;
   }
   else
   {
      throw std::out_of_range ( "El ranking tiene que ser positivo" );
   }
}

/**
 * Pone a NULL los punteros a los miembros de la pareja, pero no destruye los
 * objetos
 * @brief Destructor
 */
Pareja::~Pareja ( )
{
   t1 = NULL;
   t2 = NULL;
}

/**
 * @brief Modificador (setter) del atributo Pareja::ranking
 * @param nRanking Nuevo valor de ranking. Debe ser un número positivo
 * @throws std::out_of_range Si el valor de nRanking no es positivo
 */
void Pareja::setRanking ( int nRanking )
{
   if ( nRanking > 0 )
   {
      this->ranking = nRanking;
   }
   else
   {
      throw std::out_of_range ( "El valor de ranking tiene que ser positivo" );
   }
}

/**
 * @brief Observador (getter) del atributo Pareja::ranking
 * @return El valor de ranking de la pareja
 */
int Pareja::getRanking ( ) const
{
   return ranking;
}

/**
 * Si se pasa NULL como parámetro, la pareja pasa a tener ranking 99999, ya que
 * no está completa
 * @brief Método para cambiar el segundo tenista de la pareja
 * @param nT2 Puntero al nuevo tenista
 */
void Pareja::setT2 ( Tenista* nT2 )
{
   this->t2 = nT2;

   if ( t2 == NULL )
   {
      ranking = 99999;
   }
}

/**
 * @brief Observador (getter) para el atributo Pareja::t2
 * @return Un puntero al segundo tenista de la pareja, o NULL si éste no ha
 *         sido asignado
 */
Tenista* Pareja::getT2 ( ) const
{
   return t2;
}

/**
 * Si se pasa NULL como parámetro, la pareja pasa a tener ranking 99999, ya que
 * no está completa
 * @brief Método para cambiar el primer tenista de la pareja
 * @param nT1 Puntero al nuevo tenista
 */
void Pareja::setT1 ( Tenista* nT1 )
{
   this->t1 = nT1;
   
   if ( t1 == NULL )
   {
      ranking = 99999;
   }
}

/**
 * @brief Observador (getter) para el atributo Pareja::t1
 * @return Un puntero al primer tenista de la pareja, o NULL si éste no ha
 *         sido asignado
 */
Tenista* Pareja::getT1 ( ) const
{
   return t1;
}

/**
 * @brief Método para generar una cadena "user-friendly" de información
 * @return Una cadena de texto incluyendo los nombres de los tenistas que forman
 *         la pareja, y la posición en el ranking de la misma
 */
string Pareja::info () const
{
   std::stringstream aux;
   string resultado;

   if ( ( t1 != NULL ) && ( t2 != NULL ) )
   {
      aux << "Somos una pareja, formada por "
          << t1->getNombre ()
          << " y "
          << t2->getNombre ()
          << ". Nuestro ranking es "
          << ranking;
   }
   else
   {
      if ( t1 == NULL )
      {
         if ( t2 == NULL )
         {
            aux << "Esta pareja está vacía";
         }
         else
         {
            aux << "En esta pareja falta el primer integrante. El segundo es "
                << t2->getNombre ();
         }
      }
      else
      {
         // t2 es necesariamente distinto de NULL en este caso
         aux << "En esta pareja falta el segundo integrante. El primero es "
             << t1->getNombre ();
      }
   }

   getline ( aux, resultado );
   return ( resultado );
}

/**
 * Sólo copia el valor de ranking, puesto que no tiene sentido tener dos parejas
 * con los mismos jugadores
 * @brief Operador de asignación
 * @param orig Objeto del que se copian los valores de los atributos
 * @return Una referencia al propio objeto, para su uso en asignaciones en
 *         cascada (a=b=c)
 */
Pareja& Pareja::operator = (const Pareja& orig)
{
   this->ranking = orig.ranking;
   
   return ( *this );
}