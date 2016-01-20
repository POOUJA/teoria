/** 
 * @brief Implementación de la clase Computadora
 * @file Computadora.cpp
 * @author algarcia
 * 
 * @date 11 de enero de 2016
 */

#include <time.h>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include "Computadora.h"

/**
 * @brief Constructor por defecto. Asigna a los atributos valores por defecto
 */
Computadora::Computadora ( ): _marca ("---"), _modelo ("---"), _nPiezas(0),
                              _compradoEn (1960)
{
   int i;
   
   for ( i = 0; i < _MAX_COMP_; i++ )
   {
      _piezas[i] = 0;
   }
}

/**
 * Inicializa una nueva computadora sin piezas
 * @brief Constructor parametrizado
 * @param nMarca Marca de la computadora
 * @param nModelo Modelo de la computadora
 * @param year Año de compra de la computadora. Debe ser mayor o igual a 1960 y
 *        menor o igual al año actual
 * @throws std::invalid_argument Si el año de compra de la computadora es un
 *         valor menor a 1960 o mayor al año actual
 */
Computadora::Computadora ( string nMarca,
                           string nModelo, int year): _marca (nMarca),
                                                      _modelo (nModelo),
                                                      _nPiezas (0),
                                                      _compradoEn (year)
{
   int i;
   time_t tiempoActual;
   struct tm *fechaYhora;
   
   for ( i = 0; i < _MAX_COMP_; i++ )
   {
      _piezas [i] = 0;
   }

   // Toma la fecha  y hora actuales
   tiempoActual = time (0);
   fechaYhora = localtime ( &tiempoActual );

   if ( ( year < 1960 ) || ( year > ( fechaYhora->tm_year + 1900 ) ) )
   {
      throw std::invalid_argument ( "Computadora::Computadora: el año no es"
                                    " correcto" );
   }
}

/**
 * No tiene sentido que existan dos computadoras con los mismos componentes. Por
 * este motivo, copia todos los atributos menos los componentes, y añade a marca
 * y modelo la cadena " - 2".
 * 
 * Otra opción es crear copias de los componentes, pero a estas alturas de
 * temario no hemos visto cómo hacerlo. Lo veremos en el Tema 4
 * @brief Constructor de copia
 * @param orig Objeto del que se copian los atributos
 */
Computadora::Computadora ( const Computadora& orig ): _compradoEn (orig._compradoEn),
                                                      _nPiezas (0)
{
   int i;

   _marca = orig._marca + " - 2";
   _modelo = orig._modelo + " - 2";

   for ( i = 0 ; i < _nPiezas; i++ )
   {
      _piezas[i] = 0;
   }
}

/**
 * Como la relación entre Computadora y Componente es agregación, no elimina los
 * objetos agregados. Produce un mensaje de error si no se han roto las
 * relaciones entre la computadora y sus piezas (véase Computadora::quitaPieza)
 * antes de llamar al destructor.
 * @brief Destructor
 */
Computadora::~Computadora ( )
{
   // Como lanzar excepciones en los destructores no es una buena práctica,
   // simplemente se muestra un mensaje por la consola de errores

   if ( _nPiezas > 0 )
   {
      std::cerr << "Computadora::~Computadora: se intenta eliminar una"
                << " computadora sin quitarle las piezas primero" << std::endl;
   }
}

/**
 * @brief Método para consultar el número de piezas de la computadora
 * @return El número de piezas de la computadora. Si no tiene piezas, devuelve 0
 */
int Computadora::getNPiezas ( ) const
{
   return _nPiezas;
}

/**
 * @brief Método para añadir una pieza más a la computadora
 * @param nuevaP Puntero a la nueva pieza. Sólo se copia el puntero; no se crea
 *        un objeto nuevo
 * @throws std::length_error Si la computadora no admite más piezas (ver
 *         Computadora::_MAX_COMP_)
 */
void Computadora::addPieza ( Componente* nuevaP )
{
   if ( _nPiezas < _MAX_COMP_ )
   {
      _piezas [_nPiezas] = nuevaP;
      _nPiezas++;
   }
   else
   {
      throw std::length_error ( "Computadora::addPieza: no se pueden añadir"
                                " más piezas" );
   }
}

/**
 * @brief Método para consultar una pieza de la computadora según su índice
 * @param cual Índice de la pieza a consultar. Su valor ha de estar en el rango
 *        [0, número de piezas - 1]
 * @return Una referencia a la pieza solicitada
 * @throws std::out_of_range Si el índice solicitado no corresponde con ninguna
 *         pieza de la computadora
 */
Componente& Computadora::getPieza ( int cual ) const
{
   if ( ( cual >= 0 ) && ( cual < _nPiezas ) )
   {
      return ( *(_piezas [cual]) );
   }
   else
   {
      throw std::out_of_range ( "Computadora::getPieza: valor de índice"
                                " incorrecto" );
   }
}

/**
 * @brief Método para quitar una pieza a una computadora
 * @param cual Índice de la pieza a quitar. Su valor ha de estar en el intervalo
 *        [0, número de piezas - 1]
 * @return Un puntero a la pieza eliminada de la computadora
 * @throws std::out_of_range Si el índice que se pasa como parámetro no
 *         corresponde con ninguna pieza de la computadora
 */
Componente* Computadora::quitaPieza (int cual)
{
   Componente *aux;
   int i;

   if ( ( cual >= 0 ) && ( cual < _nPiezas ) )
   {
      aux = _piezas [cual];
      _piezas[cual] = 0;

      // Si es necesario, compacta el array de piezas
      if ( cual < ( _nPiezas - 1 ) )
      {
         i = cual;
         while ( i < ( _nPiezas - 1 ) )
         {
            _piezas[i] = _piezas[i+1];
            i++;
         }
      }

      return ( aux );
   }
   else
   {
      throw std::out_of_range ( "Computadora::quitaPieza: valor de índice"
                                " incorrecto" );
   }
}

/**
 * @brief Método para establecer el año de compra de la computadora
 * @param year Año en que se ha comprado la computadora
 * @throws std::invalid_argument Si el valor del año es menor de 1960 o mayor
 *         que el año actual
 */
void Computadora::setCompradoEn ( int year )
{
   time_t tiempoActual;
   struct tm *fechaYhora;

   // Toma la fecha  y hora actuales
   tiempoActual = time (0);
   fechaYhora = localtime ( &tiempoActual );

   if ( ( year >= 1960 ) && ( year <= ( fechaYhora->tm_year + 1900 ) ) )
   {
      _compradoEn = year;
   }
   else
   {
      throw std::invalid_argument ( "Computadora::setCompradoEn: el año no es"
                                    " correcto" );
   }
}

/**
 * @brief Método para consultar el año en que se compró la computadora
 * @return El año en que se compró la computadora
 */
int Computadora::getCompradoEn ( ) const
{
   return _compradoEn;
}

/**
 * @brief Método para establecer el modelo de la computadora
 * @param nModelo Texto indicando el modelo de la computadora
 */
void Computadora::setModelo ( string nModelo )
{
   this->_modelo = nModelo;
}

/**
 * @brief Método para consultar el modelo de la computadora
 * @return Un texto indicando el modelo de la computadora
 */
string Computadora::getModelo ( ) const
{
   return _modelo;
}

/**
 * @brief Método para establecer la marca de la computadora
 * @param nMarca Cadena de texto con la nueva marca de la computadora
 */
void Computadora::setMarca ( string nMarca )
{
   this->_marca = nMarca;
}

/**
 * @brief Método para consultar la marca de la computadora
 * @return Una cadena de texto con la marca de la computadora
 */
string Computadora::getMarca ( ) const
{
   return _marca;
}

/**
 * Calcula el precio de la computadora como la suma de los precios de sus
 * componentes
 * @brief Método para consultar el precio de la computadora
 * @return El precio de la computadora. Si no tiene componentes, devuelve 0
 */
float Computadora::getPrecio ( ) const
{
   float suma = 0;
   int i;
   
   if ( _nPiezas > 0 )
   {
      for ( i = 0; i < _nPiezas; i++ )
      {
         suma += _piezas[i]->getPrecio ();
      }
   }

   return ( suma );
}

/**
 * No tiene sentido que haya dos computadoras con los mismos componentes, así
 * que copia los atributos de tipos simples solamente
 * @brief Operador de asignación
 * @param orig Objeto del que se copian los atributos
 * @return Una referencia al mismo objeto, para posibilitar las asignaciones en
 *         cascada (a=b=c)
 */
Computadora& Computadora::operator = (const Computadora& orig)
{
   _compradoEn = orig._compradoEn;
   _marca = orig._marca;
   _modelo = orig._modelo;
   
   return ( *this );
}