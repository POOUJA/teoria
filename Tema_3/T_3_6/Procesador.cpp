/** 
 * @file Procesador.cpp
 * @author algarcia
 * 
 * @date 11 de enero de 2016
 */

#include "Procesador.h"

Procesador::Procesador ( )
{
}

Procesador::Procesador ( const Procesador& orig )
{
}

Procesador::~Procesador ( )
{
}

void Procesador::setArq ( Procesador::Arquitectura _arq )
{
   this->_arq = _arq;
}

Procesador::Arquitectura Procesador::getArq ( ) const
{
   return _arq;
}

void Procesador::setSocket ( string _socket )
{
   this->_socket = _socket;
}

string Procesador::getSocket ( ) const
{
   return _socket;
}

void Procesador::setVelocidad ( float _velocidad )
{
   this->_velocidad = _velocidad;
}

float Procesador::getVelocidad ( ) const
{
   return _velocidad;
}

