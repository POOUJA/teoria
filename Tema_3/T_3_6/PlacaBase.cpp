/** 
 * @file PlacaBase.cpp
 * @author algarcia
 * 
 * @date 11 de enero de 2016
 */

#include "PlacaBase.h"

PlacaBase::PlacaBase ( )
{
}

PlacaBase::PlacaBase ( const PlacaBase& orig )
{
}

PlacaBase::~PlacaBase ( )
{
}

void PlacaBase::setSocket ( string _socket )
{
   this->_socket = _socket;
}

string PlacaBase::getSocket ( ) const
{
   return _socket;
}

void PlacaBase::setChipset ( string _chipset )
{
   this->_chipset = _chipset;
}

string PlacaBase::getChipset ( ) const
{
   return _chipset;
}

void PlacaBase::setNUSB2 ( int _nUSB2 )
{
   this->_nUSB2 = _nUSB2;
}

int PlacaBase::getNUSB2 ( ) const
{
   return _nUSB2;
}

void PlacaBase::setNUSB3 ( int _nUSB3 )
{
   this->_nUSB3 = _nUSB3;
}

int PlacaBase::getNUSB3 ( ) const
{
   return _nUSB3;
}

void PlacaBase::setNPCIe ( int _nPCIe )
{
   this->_nPCIe = _nPCIe;
}

int PlacaBase::getNPCIe ( ) const
{
   return _nPCIe;
}

void PlacaBase::setFForma ( PlacaBase::FactorDeForma _fForma )
{
   this->_fForma = _fForma;
}

PlacaBase::FactorDeForma PlacaBase::getFForma ( ) const
{
   return _fForma;
}

