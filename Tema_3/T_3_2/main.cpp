/**
 * @file main.cpp
 * Archivo con la implementación de la función main
 * @author algarcia
 * @date 2015-12-09
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "F1team.h"

using namespace std;

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
   catch ( invalid_argument ex )
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
   mc = 0;
   delete ( alonso );
   delete ( button );
   delete ( vettel );
   alonso = button = vettel = 0;

   return 0;
}

