/** 
 * @file Computadora.cpp
 * @author algarcia
 * 
 * @date 11 de enero de 2016
 */

#include "Computadora.h"

/**
 * @brief Constructor por defecto. Asigna a los atributos valores por defecto
 */
Computadora::Computadora ( ): _marca ("---"), _modelo ("---"), _nPiezas(0),
                              _compradoEn (1900)
{
   int i;
   
   for ( i = 0; i < _MAX_COMP_; i++ )
   {
      _piezas[i] = 0;
   }
}

/**
 * \b OJO: sólo copia los punteros a los componentes; no crea objetos nuevos
 * @brief Constructor de copia
 * @param orig Objeto del que se copian los atributos
 */
Computadora::Computadora ( const Computadora& orig ): _marca (orig._marca),
                                                      _modelo (orig._modelo),
                                                      _compradoEn (orig._compradoEn),
                                                      _nPiezas (orig._nPiezas)
{
   int i;
   
   for ( i = 0 ; i < _nPiezas; i++ )
   {
      _piezas[i] = orig._piezas[i];
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
 * @param nuevaP Puntero a la nueva pieza
 * @throws std::out_of_range Si la computadora no admite más piezas (ver
 *         Computadora::_MAX_COMP_)
 */
void Computadora::addPieza ( Componente* nuevaP )
{
   
}

Componente* Computadora::getPieza ( int cual )
{
   
}

void Computadora::setCompradoEn ( int year )
{
   this->_compradoEn = year;
}

int Computadora::getCompradoEn ( ) const
{
   return _compradoEn;
}

void Computadora::setModelo ( string nModelo )
{
   this->_modelo = nModelo;
}

string Computadora::getModelo ( ) const
{
   return _modelo;
}

void Computadora::setMarca ( string nMarca )
{
   this->_marca = nMarca;
}

string Computadora::getMarca ( ) const
{
   return _marca;
}

float Computadora::getPrecio ( ) const
{
   
}

string Computadora::info ()
{
}