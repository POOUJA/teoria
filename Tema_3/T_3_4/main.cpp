/* 
 * File:   main.cpp
 * Author: algarcia
 *
 * Created on 11 de diciembre de 2015, 18:11
 */

#include <cstdlib>
#include <iostream>

#include "Dependencia.h"

using namespace std;

/*
 * 
 */
int main ( int argc, char** argv )
{
   Dependencia *d = new Dependencia ();
   
   d->setTipo ( (dependencia_t) -150 );
   
   cout << d->getTipo ();

   delete ( d );

   return 0;
}

