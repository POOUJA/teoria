/* 
 * File:   Guerrero.cpp
 * Author: algarcia
 * 
 * Created on 20 de octubre de 2015, 13:58
 */

#include "Guerrero.h"

Guerrero::Guerrero ( )
{
}

Guerrero::Guerrero ( const Guerrero& orig )
{
}

Guerrero::~Guerrero ( )
{
}

void Guerrero::setArmamento ( Arma* nArmamento )
{
   this->armamento = nArmamento;
}

Arma* Guerrero::getArmamento ( ) const
{
   return armamento;
}

void Guerrero::setEnergia ( int nEnergia )
{
   this->energia = nEnergia;
}

int Guerrero::getEnergia ( ) const
{
   return energia;
}

void Guerrero::setNombre ( string nNombre )
{
   this->nombre = nombre;
}

string Guerrero::getNombre ( ) const
{
   return nombre;
}

