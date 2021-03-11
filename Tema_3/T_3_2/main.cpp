/**
 * @file main.cpp
 * Archivo con la implementación de la función main
 * @author algarcia
 * @date 2015-12-09
 */

#include <iostream>    // Para usar cout
#include <stdexcept>   // Para usar las excepciones estándar
#include "F1team.h"
#include "utils.h"

using namespace std;
using namespace t32_utils;

/*
 *
 */
int main ( int argc, char** argv )
{
   Piloto *alonso = new Piloto ( "Fernando", 0 );
   Piloto *button = new Piloto ( "Jenson", 0 );
   Piloto *vettel = new Piloto ( "Sebastian", 0 );
   F1team *mc = new F1team ( alonso, button, "McLaren F1 Team" );

   cout << info (*alonso) << endl;
   cout << info (*mc) << endl;

   try
   {
      mc->setP2 ( 0 );
   }
   catch ( std::invalid_argument &ex )
   {
      cout << "-----Excepción capturada----- Mensaje: "
           << ex.what ()
           << endl;
   }

   mc->sumaPtosCarrera ( 10, 8 );
   cout << info (*mc) << endl;

   mc->setP2 ( vettel );
   cout << info (*mc) << endl;

   delete ( mc );
   mc = nullptr;
   delete ( alonso );
   delete ( button );
   delete ( vettel );
   alonso = button = vettel = nullptr;

   return 0;
}

