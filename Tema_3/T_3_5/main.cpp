/**
 * @file main.cpp
 * Archivo con la función main
 * @author algarcia
 * @date 2015-12-31
 */

//#include <cstdlib>
#include <iostream>   // Para usar cout
#include <stdlib.h>   // Para usar srand
//#include <time.h>

#include "Armero.h"
#include "Guerrero.h"
#include "utils.h"

using namespace std;
using namespace t35_utils;

/**
 * Función principal. Crea objetos, utiliza métodos y libera recursos
 */
int main ( int argc, char** argv )
{
   Armero *a;
   Arma *b, *c, *d;
   Arma *armas[Guerrero::_MAX_AMMO_];
   Guerrero *g;
   int i, aux;

   // Inicializa el generador de números pseudoaleatorios
   srand ( time (0) );

   // Crea un nuevo armero
   a = new Armero ( "Merlín", 500 );
   cout << info (*a) << endl;

   // Pide al armero que fabrique un arma
   b = a->creaArma ( "Excalibur" );
   c = a->creaArma ( "Magnum 44" );
   d = a->creaArma ( "AK-47" );

   // Crea un guerrero, y le entrega el arma
   g = new Guerrero ( "Lancelot", 2500 );
   g->addArma (b);
   b = 0;
   g->addArma (c);
   c = 0;
   g->addArma (d);
   d = 0;
   cout << info (*g) << endl;

   // El guerrero hace varios ataques de prueba
   cout << "Ataques de demostración:" << endl;
   cout << g->ataque (1) << endl;
   cout << g->ataque (2) << endl;
   cout << g->ataque (3) << endl;

   // Pasa a liberar recursos. En primer lugar, hay que desarmar al guerrero
   // antes de destruirlo
   aux = g->desarmar ( armas );
   delete g;
   g = 0;

   // Destruye las armas
   for ( i = 0; i < aux; i++ )
   {
      delete armas[i];
      armas[i] = 0;
   }

   // Destruye el armero
   delete a;
   a = 0;

   return 0;
}

