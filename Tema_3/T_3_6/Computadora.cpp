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
 * Hace copias de los componentes??????
 * @brief Constructor de copia
 * @param orig Objeto del que se copian los atributos
 */
Computadora::Computadora ( const Computadora& orig ): _marca (orig._marca),
                                                      _modelo (orig._modelo),
                                                      _compradoEn (orig._compradoEn),
                                                      _nPiezas (orig._nPiezas)
{
   int i;
   
   for ( i = 0 ; i < _)
}

Computadora::~Computadora ( )
{
}

int Computadora::getNPiezas ( ) const
{
   return _nPiezas;
}

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