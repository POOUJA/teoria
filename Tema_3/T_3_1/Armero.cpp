/* 
 * File:   Armero.cpp
 * Author: algarcia
 * 
 * Created on 21 de octubre de 2015, 16:12
 */

#include "Armero.h"
#include <stdlib.h>   // Para usar rand
#include <sstream>    // Para usar stringstream

Armero::Armero ( ): energia (1000), nombre("---"), maxPoderArma(100)
{
}

Armero::Armero (string nNombre): energia (1000), nombre(nNombre),
                                 maxPoderArma(100)
{
}

Armero::Armero ( const Armero& orig ): energia (orig.energia),
                                       maxPoderArma (orig.maxPoderArma)
{
   nombre = orig.nombre + " - 2";   // Para no tener dos armeros con el mismo nombre
}

Armero::~Armero ( )
{
}

void Armero::setEnergia ( int nEnergia )
{
   this->energia = nEnergia;
}

int Armero::getEnergia ( ) const
{
   return energia;
}

void Armero::setNombre ( string nNombre )
{
   this->nombre = nNombre;
}

string Armero::getNombre ( ) const
{
   return nombre;
}

void Armero::setMaxPoderArma ( int nMaxPoderArma )
{
   this->maxPoderArma = nMaxPoderArma;
}

int Armero::getMaxPoderArma ( ) const
{
   return maxPoderArma;
}

Arma *Armero::creaArma ( string nombreArma )
{
   // Crea un nuevo objeto de clase Arma, con el nombre que se le pasa
   Arma *a = new Arma ( nombreArma );

   // Calcula aleatoriamente el poder asociado al arma, y lo asigna
   int aux = (rand () % maxPoderArma) + 1;   
   a->setPoder ( aux );

   return ( a );
}

string Armero::info () const
{
   string resultado;
   stringstream aux;
   
   aux << "Soy armero. Mi nombre es "
       << nombre
       << ", mi energía es "
       << energia
       << " y puedo producir armas de hasta "
       << maxPoderArma
       << " puntos de poder";

   getline ( aux, resultado );
   return ( resultado );
}