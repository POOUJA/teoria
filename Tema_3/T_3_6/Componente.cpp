/** 
 * @file Componente.cpp
 * @author algarcia
 * 
 * @date 11 de enero de 2016
 */

#include "Componente.h"

Componente::Componente ( )
{
}

Componente::Componente ( const Componente& orig )
{
}

Componente::~Componente ( )
{
}

void Componente::setPrecio ( float _precio )
{
   this->_precio = _precio;
}

float Componente::getPrecio ( ) const
{
   return _precio;
}

void Componente::setNumSerie ( string _numSerie )
{
   this->_numSerie = _numSerie;
}

string Componente::getNumSerie ( ) const
{
   return _numSerie;
}

void Componente::setModelo ( string _modelo )
{
   this->_modelo = _modelo;
}

string Componente::getModelo ( ) const
{
   return _modelo;
}

void Componente::setMarca ( string _marca )
{
   this->_marca = _marca;
}

string Componente::getMarca ( ) const
{
   return _marca;
}

