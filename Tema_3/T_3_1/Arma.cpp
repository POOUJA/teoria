/* 
 * File:   Arma.cpp
 * Author: algarcia
 * 
 * Created on 21 de octubre de 2015, 16:12
 */

#include "Arma.h"
#include <sstream>   // Para usar stringstream

Arma::Arma ( ): nombre("---"), poder(0)
{
}

Arma::Arma ( const Arma& orig ): poder(orig.poder)
{
   nombre = orig.nombre + " - 2";   // Para evitar dos armas con el mismo nombre
}

Arma::Arma (const string nNombre, const int nPoder): nombre(nNombre),
                                                     poder(nPoder)
{
}

Arma::~Arma ( )
{
}

void Arma::setNombre ( string nombre )
{
   this->nombre = nombre;
}

string Arma::getNombre ( ) const
{
   return nombre;
}

void Arma::setPoder ( int poder )
{
   this->poder = poder;
}

int Arma::getPoder ( ) const
{
   return poder;
}

string Arma::info () const
{
   stringstream aux;
   string resultado;
   
   aux << "Soy un arma. Mi nombre es "
       << nombre
       << " y mi poder es de "
       << poder
       << " puntos";

   getline ( aux, resultado );
   return ( resultado );
}