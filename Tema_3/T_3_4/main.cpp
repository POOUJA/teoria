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
   
   // Crea una vivienda y le añade habitaciones
   v = new Vivienda ( "C/ Ben Saprut 32, 5ºA" );
   v->addDependencia ( "Cocina", 10, 0 );
   v->addDependencia ( "Comedor", 20, 0 );
   v->addDependencia ( "Aseo", 3, 0 );
   v->addDependencia ( "Dormitorio", 15, 0 );

   // Cambia el estado de limpieza de las habitaciones
   v->limpiezaGeneral ();
   
   // Borra una dependencia por su nombre
   v->borraDependencia ( "Comedor" );
   
   // Añade una nueva dependencia
   v->addDependencia ( "Salón-comedor", 20, 0 );
   
   // Muestra un resumen de la vivienda
   cout << v->info ();

   // Libera los recursos antes de terminar
   delete v;
   v = 0;

   return 0;
}

