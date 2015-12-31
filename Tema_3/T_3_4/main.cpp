/**
 * @file main.cpp
 * Archivo con la implementación de la función principal
 * @author algarcia
 * @date 2015-12-11
 */

#include <cstdlib>
#include <iostream>

#include "Vivienda.h"

using namespace std;

int main ( int argc, char** argv )
{
   Vivienda *v;
   
   v = new Vivienda ( "C/ Ben Saprut 32, 5ºA" );
   v->addDependencia ( "Cocina", 10, 0 );
   v->addDependencia ( "Comedor", 20, 0 );
   v->addDependencia ( "Aseo", 3, 0 );
   v->addDependencia ( "Dormitorio", 15, 0 );
   v->limpiezaGeneral ();
   v->borraDependencia ( "Comedor" );
   v->addDependencia ( "Salón-comedor", 20, 0 );
   cout << v->info ();

   delete v;
   v = 0;

   return 0;
}

