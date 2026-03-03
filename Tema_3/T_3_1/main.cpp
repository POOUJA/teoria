/**
 * @file main.cpp
 * Archivo con la función main
 * @author algarcia
 * @date 2015-09-25
 */

#include <iostream>   // Para usar cout
#include <stdlib.h>   // Para usar srand

#include "Arma.h"
#include "Armero.h"
#include "Guerrero.h"
#include "utils.h"

using namespace std;
using namespace t31_utils;

/**
 * Función principal. Crea objetos, utiliza métodos y libera recursos
 */
int main ( int argc, char** argv )
{
   // Crea un armero
   Armero merlin ( "Merlín", 500 );
   Guerrero* lanci = nullptr;
   // Crea un guerrero
   Guerrero blacki ( "Caballero negro", 3000 );

   // Inicializa el generador de números pseudoaleatorios
   srand ( time (0) );

   // Muestra los datos del armero para comprobarlo
   cout << info (merlin) << endl;

   // Pide al armero que fabrique un arma
   Arma espada = merlin.creaArma ( "Excalibur" );
   cout << info (espada) << endl;

   // Crea un guerrero en memoria dinámica, y le entrega el arma
   lanci = new Guerrero ( "Lancelot", 2500 );
   lanci->setArmamento (&espada);
   cout << info (*lanci) << endl;

   // El guerrero hace varios ataques de prueba
   cout << "Ataques de demostración:" << endl;
   cout << lanci->ataque () << endl;
   cout << lanci->ataque () << endl;
   cout << lanci->ataque () << endl;

   // En primer lugar, hay que desarmar al guerrero antes de destruirlo
   Arma *pArmaAbandonada = lanci->desarmar ();
   delete lanci;  //Lanci dies...Aaargh!!! Liberamos su memoria dinámica
   lanci = nullptr;

   // Reutiliza el arma, dándosela a otro guerrero
   blacki.setArmamento (pArmaAbandonada);
   cout << info (blacki) << endl;
   cout << "Ataque de demostración:" << endl;
   cout << blacki.ataque () << endl;

   // Desarma al segundo guerrero
   pArmaAbandonada = blacki.desarmar ();

   //La espada, Excalibur, se libera automáticamente
   //El guerrero, Blacki,  se libera automáticamente

   return 0;
}

