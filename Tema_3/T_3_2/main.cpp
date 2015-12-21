/* 
 * File:   main.cpp
 * Author: algarcia
 *
 * Created on 21 de octubre de 2015, 15:03
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "Pareja.h"

using namespace std;

/*
 * 
 */
int main ( int argc, char** argv )
{
   Tenista *nadal = new Tenista ( "Rafa", 1 );
   Tenista *federer = new Tenista ( "Roger", 2 );
   Tenista *novak = new Tenista ( "Djokovic", 3 );
   Pareja *p1 = new Pareja ( nadal, novak, 1 );
   
   cout << nadal->info () << endl;
   cout << p1->info () << endl;
   
   try
   {
      p1->setRanking ( 0 );
   }
   catch ( out_of_range ex )
   {
      cout << "-----Excepción capturada----- Mensaje: "
           << ex.what ()
           << endl;
   }

   p1->setT2 ( 0 );
   cout << p1->info () << endl;

   delete ( p1 );
   p1 = 0;
   delete ( nadal );
   delete ( federer );
   delete ( novak );
   nadal = federer = novak = 0;

   return 0;
}

