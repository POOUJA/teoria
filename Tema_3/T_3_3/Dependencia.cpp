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

void Dependencia::setSuperficie ( float nSuperficie )
{
   this->_superficie = nSuperficie;
}

float Dependencia::getSuperficie ( ) const
{
   return _superficie;
}

void Dependencia::setNombre ( string nNombre )
{
   this->_nombre = nNombre;
}

string Dependencia::getNombre ( ) const
{
   return _nombre;
}

