/* 
 * File:   Habitacion.cpp
 * Author: algarcia
 * 
 * Created on 11 de diciembre de 2015, 18:20
 */

#include "Dependencia.h"

Dependencia::Dependencia ( )
{
}

Dependencia::Dependencia ( const Dependencia& orig )
{
}

Dependencia::~Dependencia ( )
{
}

void Dependencia::setTipo ( dependencia_t _tipo )
{
   this->_tipo = _tipo;
}

int Dependencia::getTipo ( ) const
{
   return _tipo;
}

void Dependencia::setSuperficie ( int _superficie )
{
   this->_superficie = _superficie;
}

int Dependencia::getSuperficie ( ) const
{
   return _superficie;
}

void Dependencia::setNombre ( string _nombre )
{
   this->_nombre = _nombre;
}

string Dependencia::getNombre ( ) const
{
   return _nombre;
}

