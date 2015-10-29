/* 
 * File:   Guerrero.cpp
 * Author: algarcia
 * 
 * Created on 20 de octubre de 2015, 13:58
 */

#include "Guerrero.h"
#include "Arma.h"

#include <stdlib.h>   // Para usar rand
#include <sstream>    // Para usar stringstream

Guerrero::Guerrero ( ): nombre ("---"), armamento (NULL), energia (1000)
{
}

Guerrero::Guerrero ( string nNombre, int nEnergia ): nombre (nNombre),
                                                     armamento (NULL),
                                                     energia (nEnergia)
{
}

Guerrero::Guerrero ( const Guerrero& orig ): armamento (NULL),
                                             energia (orig.energia)
{
   nombre = orig.nombre + " - 2";   // Para evitar nombres duplicados
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

Arma *Guerrero::desarmar ()
{
   Arma *aux = armamento;
   armamento = NULL;
   return ( aux );
}

int Guerrero::ataque ()
{
   int maxPoder = _FACTOR_ATAQUE_ * energia * armamento->getPoder ();
   int resultado = rand () % maxPoder + 1;

   return ( resultado );
}

string Guerrero::info () const
{
   string resultado;
   stringstream aux;
   
   aux << "Soy guerrero. Mi nombre es "
       << nombre
       << ", mi energía es "
       << energia
       << " y puedo producir ataques de hasta "
       << (int) ( _FACTOR_ATAQUE_ * energia * armamento->getPoder () )
       << " puntos de poder";

   getline ( aux, resultado );
   return ( resultado );
}