/**
 * @file main.cpp
 * Archivo con la función main
 * @author algarcia
 * @date 2015-09-25
 */

#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Armero.h"
#include "Guerrero.h"

using namespace std;

/**
 * Función principal. Crea objetos, utiliza métodos y libera recursos
 */
int main ( int argc, char** argv )
{
   Armero *a;
   Arma *b;
   Guerrero *g;

   // Inicializa el generador de números pseudoaleatorios
   srand ( time (0) );

   // Crea un nuevo armero
   a = new Armero ( "Merlín", 500 );
   cout << a->info () << endl;

   // Pide al armero que fabrique un arma
   b = a->creaArma ( "Excalibur" );
   cout << b->info () << endl;

   // Crea un guerrero, y le entrega el arma
   g = new Guerrero ( "Lancelot", 2500 );
   g->setArmamento (b);
   b = 0;
   cout << g->info () << endl;

   // El guerrero hace varios ataques de prueba
   cout << "Ataques de demostración:" << endl;
   cout << g->ataque () << endl;
   cout << g->ataque () << endl;
   cout << g->ataque () << endl;

   // Pasa a liberar recursos. En primer lugar, hay que desarmar al guerrero
   // antes de destruirlo
   b = g->desarmar ();
   delete g;
   g = 0;

   // Destruye el arma
   delete b;
   b = 0;

   // Destruye el armero
   delete a;
   a = 0;

   return 0;
}

