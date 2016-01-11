/** 
 * @file Computadora.cpp
 * @author algarcia
 * 
 * @date 11 de enero de 2016
 */

#include "Computadora.h"

Computadora::Computadora ( )
{
}

Computadora::Computadora ( const Computadora& orig )
{
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

Componente* Computadora::getPieza ( int cual ) const
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

void Computadora::setPrecio ( float nPrecio )
{
   this->_precio = nPrecio;
}

float Computadora::getPrecio ( ) const
{
   return _precio;
}

string Computadora::info ()
{
}