/* 
 * File:   main.cpp
 * Author: algarcia
 *
 * Created on 25 de septiembre de 2015, 19:02
 */

#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Armero.h"

using namespace std;

/*
 * 
 */
int main ( int argc, char** argv )
{
   Armero *a;
   Arma *b;

   // Inicializa el generador de números pseudoaleatorios
   srand ( time (NULL) );

   a = new Armero ( "pepe" );
   cout << a->info () << endl;
   b = a->creaArma ( "kk" );
   cout << b->info () << endl;
   return 0;
}

