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
#include "Guerrero.h"

using namespace std;

/*
 * 
 */
int main ( int argc, char** argv )
{
   Armero *a;
   Arma *b;
   Guerrero *g;

   // Inicializa el generador de números pseudoaleatorios
   srand ( time (NULL) );

   a = new Armero ( "Merlín", 500 );
   cout << a->info () << endl;
   b = a->creaArma ( "Excalibur" );
   cout << b->info () << endl;
   g = new Guerrero ( "Lancelot", 2500 );
   g->setArmamento (b);
   b = NULL;
   cout << g->info () << endl;

   cout << "Ataques de demostración:" << endl;
   cout << g->ataque () << endl;
   cout << g->ataque () << endl;
   cout << g->ataque () << endl;
   
   delete g;
   g = NULL;
   delete a;
   a = NULL;

   return 0;
}

