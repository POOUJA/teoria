/** 
 * @file DiscoDuro.cpp
 * @author algarcia
 * 
 * @date 11 de enero de 2016
 */

#include "DiscoDuro.h"

DiscoDuro::DiscoDuro ( )
{
}

DiscoDuro::DiscoDuro ( const DiscoDuro& orig )
{
}

DiscoDuro::~DiscoDuro ( )
{
}

void DiscoDuro::setConexion ( string _conexion )
{
   this->_conexion = _conexion;
}

string DiscoDuro::getConexion ( ) const
{
   return _conexion;
}

void DiscoDuro::setFormato ( string _formato )
{
   this->_formato = _formato;
}

string DiscoDuro::getFormato ( ) const
{
   return _formato;
}

void DiscoDuro::setCapacidad ( float _capacidad )
{
   this->_capacidad = _capacidad;
}

float DiscoDuro::getCapacidad ( ) const
{
   return _capacidad;
}

