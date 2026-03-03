/**
 * @file main.cpp
 * Archivo con la función main
 * @author algarcia
 * @date 2015-12-31
 */

//#include <cstdlib>
#include <iostream>   // Para usar cout
#include <cstdlib>   // Para usar srand
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
   
   Arma* inventario[Guerrero::_MAX_ARMAS_];
   Guerrero *pGuerrero{};  //el puntero se inicializa a nullptr   

   // Inicializa el generador de números pseudoaleatorios
   srand ( time (0) );

   // Crea un nuevo armero
   Armero armero { "Merlín", 500 };
   cout << info (armero) << endl;

   // Pide al armero que fabrique un arma
   Arma arma1 = armero.creaArma ( "Excalibur" );
   Arma arma2 = armero.creaArma ( "Magnum 44" );
   Arma arma3 = armero.creaArma ( "AK-47" );

   // Crea un guerrero, y le entrega las armas
   pGuerrero = new Guerrero ( "Lancelot", 2500 );

   pGuerrero->addArma (&arma1);
   pGuerrero->addArma (&arma2);
   pGuerrero->addArma (&arma3);

   cout << info (*pGuerrero) << endl;

   // El guerrero hace varios ataques de prueba
   cout << "Ataques de demostración:" << endl;
   cout << pGuerrero->ataque (1) << endl;
   cout << pGuerrero->ataque (2) << endl;
   cout << pGuerrero->ataque (3) << endl;

   // Pasa a liberar recursos. En primer lugar, hay que desarmar al guerrero
   // antes de destruirlo
   int armasRecuperadas = pGuerrero->desarmar ( inventario );
   delete pGuerrero;  //Liberar memoria dinámica del objeto Guerrero
   pGuerrero = nullptr;

   for (int i = 0; i < armasRecuperadas; i++)
   {
      std::cout << "Se ha recuperado el arma " << inventario[i]->getNombre() << std::endl;
   }
   
   //Se liberan automáticamente las armas y el armero

   return 0;
}

