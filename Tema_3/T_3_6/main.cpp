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

void v1_objetos_automaticos();
void v2_objetos_dinamicos();

/** Pruebas con las clases Componente, Computadora, DiscoDuro, PlacaBase y Procesador*/
int main ( int argc, char** argv ) {

    v1_objetos_automaticos();
    v2_objetos_dinamicos();

    return 0;
}

/** Programa de prueba con objetos automáticos*/
void v1_objetos_automaticos ( )
{
   int i, nC;
   Componente *aux;
   
   std::cout << "VERSION 1 (OBJETOS AUTOMÁTICOS)" << "\n=========" << std::endl;
   
   // Crea computadoras y componentes
   Computadora c1 ( "IBM", "PC", 1981 );
   Computadora c2 ( "Apple", "Macintosh", 1984 );
   PlacaBase pb1 ( "Asus", "pb01", "1234", PlacaBase::ATX, 1,
                                    4, "CH123", "ABCD" );
   PlacaBase pb2 ;
   DiscoDuro dd1 ( "WD", "WD500", "123asdf", 500, "2.5",
                                   DiscoDuro::SATA );
   DiscoDuro dd2;
   Procesador p1( "Intel", "Celeron", "1234", 1,
                                     Procesador::intoArquitectura (1), "IA7" );
   Procesador p2 (p1);

   // Asigna valores usando distintos métodos
   pb1.setPrecio ( 60 );
   pb2 = pb1;
   pb2.setNumSerie ( "1235" );

   dd1.setPrecio ( 50 );
   dd2 = dd1;
   dd2.setModelo ( "WD750" );
   dd2.setCapacidad ( 750 );
   dd2.setNumSerie ( "124asdf" );
   dd2.setPrecio ( 55 );

   p1.setPrecio (80);
   p2.setPrecio (80);
   
   // Muestra la información de algunos componentes individuales, para que se
   // vea la diferencia entre unas funciones de información y otras
   cout << info (pb1) << endl;
   cout << info (dd2) << endl;
   cout << info (p1) << endl;

   // Asigna los componentes a las computadoras
   c1.addPieza (&pb1);
   c1.addPieza (&dd1);
   c1.addPieza (&p1);
   
   c2.addPieza (&pb2);
   c2.addPieza (&dd2);
   c2.addPieza (&p2);
   
   // Muestra la información de las computadoras
   cout << info (c1) << endl;
   cout << info (c2) << endl;
   
   // Libera los recursos. A las computadoras tiene que quitarle los componentes
   // antes de liberarlas
   nC = c1.getNPiezas ();
   for ( i = 0; i < nC; i++ )
   {
      aux = c1.quitaPieza (0);   // Como cada vez hay menos piezas, quita
                                 // la primera en lugar de incrementar el número
      //Las piezas son objetos automáticos (creados en main) y no es necesario liberarlas
   }
   
   nC = c2.getNPiezas ();
   for ( i = 0; i < nC; i++ )
   {
      aux = c2.quitaPieza (0);   // Como cada vez hay menos piezas, quita
                                 // la primera en lugar de incrementar el número
      //Las piezas son objetos automáticos (creados en main) y no es necesario liberarlas
   }

}

/**Programa de prueba con objetos dinámicos*/
void v2_objetos_dinamicos (  )
{
   int i, nC;
   Componente *aux;

   std::cout << "VERSION 2 (OBJETOS DINÁMICOS)" << "\n=========" << std::endl;

   
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
   pb1 = nullptr;
   c1->addPieza (dd1);
   dd1 = nullptr;
   c1->addPieza (p1);
   p1 = nullptr;
   
   c2->addPieza (pb2);
   pb2 = nullptr;
   c2->addPieza (dd2);
   dd2 = nullptr;
   c2->addPieza (p2);
   p2 = nullptr;
   
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

   aux = nullptr;
   delete c1;
   c1 = nullptr;
   
   nC = c2->getNPiezas ();
   for ( i = 0; i < nC; i++ )
   {
      aux = c2->quitaPieza (0);   // Como cada vez hay menos piezas, quita
      delete ( aux );             // la primera en lugar de incrementar el número
   }

   aux = nullptr;
   delete c2;
   c2 = nullptr;
   
}

