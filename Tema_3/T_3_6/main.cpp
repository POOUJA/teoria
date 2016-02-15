/**
 * @brief Implementación de la función principal del programa
 * @file main.cpp
 * @author algarcia
 *
 * @date 11 de enero de 2016
 */

#include <cstdlib>
#include <iostream>
#include "Computadora.h"
#include "utils.h"

using namespace std;
using namespace t36_utils;

int main ( int argc, char** argv )
{
   int i, nC;
   Componente *aux;
   
   throw string ( "hola");

   // Crea computadoras y componentes
   Computadora *c1 = new Computadora ( "IBM", "PC", 1981 );
   Computadora *c2 = new Computadora ( "Apple", "Macintosh", 1984 );
   PlacaBase *pb1 = new PlacaBase ( "Asus", "pb01", "1234", PlacaBase::ATX, 1,
                                    4, "CH123", "ABCD" );
   PlacaBase *pb2 = new PlacaBase ();
   DiscoDuro *dd1 = new DiscoDuro ( "WD", "WD500", "123asdf", 500, "2.5",
                                    DiscoDuro::SATA );
   DiscoDuro *dd2 = new DiscoDuro ();
   Procesador *p1 = new Procesador ( "Intel", "Celeron", "1234", 1,
                                     Procesador::intoArquitectura (1), "IA7" );
   Procesador *p2 = new Procesador (*p1);

   // Asigna valores usando distintos métodos
   pb1->setPrecio ( 60 );
   *pb2 = *pb1;
   pb2->setNumSerie ( "1235" );

   dd1->setPrecio ( 50 );
   *dd2 = *dd1;
   dd2->setModelo ( "WD750" );
   dd2->setCapacidad ( 750 );
   dd2->setNumSerie ( "124asdf" );
   dd2->setPrecio ( 55 );

   p1->setPrecio (80);
   p2->setPrecio (80);
   
   // Muestra la información de algunos componentes individuales, para que se
   // vea la diferencia entre unas funciones de información y otras
   cout << info (*pb1) << endl;
   cout << info (*dd2) << endl;
   cout << info (*p1) << endl;

   // Asigna los componentes a las computadoras
   c1->addPieza (pb1);
   pb1 = 0;
   c1->addPieza (dd1);
   dd1 = 0;
   c1->addPieza (p1);
   p1 = 0;
   
   c2->addPieza (pb2);
   pb2 = 0;
   c2->addPieza (dd2);
   dd2 = 0;
   c2->addPieza (p2);
   p2 = 0;
   
   // Muestra la información de las computadoras
   cout << info (*c1) << endl;
   cout << info (*c2) << endl;
   
   // Libera los recursos. A las computadoras tiene que quitarle los componentes
   // antes de liberarlas
   nC = c1->getNPiezas ();
   for ( i = 0; i < nC; i++ )
   {
      aux = c1->quitaPieza (0);   // Como cada vez hay menos piezas, quita
      delete ( aux );             // la primera en lugar de incrementar el número
   }

   aux = 0;
   delete c1;
   c1 = 0;
   
   nC = c2->getNPiezas ();
   for ( i = 0; i < nC; i++ )
   {
      aux = c2->quitaPieza (0);   // Como cada vez hay menos piezas, quita
      delete ( aux );             // la primera en lugar de incrementar el número
   }

   aux = 0;
   delete c2;
   c2 = 0;
   
   return 0;
}

