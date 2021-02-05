/**
 * @brief Ejemplo T_2_7 de teoría: Operadores con Entrada de Facebook
 * @file main.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 27 de septiembre de 2015, 11:00
 */

#include <iostream>
#include <cstdlib>
#include "EntradaEnFacebook.h"


/**
 * @brief Función principal
 * @argc Número de argumentos pasados por línea de órdenes
 * @argc Caractares pasados como argumentos por línea de órdenes
 * @return 0 si todo funciona bien; distinto de 0 en otro caso.
 */
int main ( int argc, char** argv )
{  std::cout << "Ejemplo de teoría T_2_7: Sobrecarga de operadores" << std::endl;

   // Creamos primera entrada
   EntradaEnFacebook entrada ( 1, "Hoy mi gato se ha dormido encima de la lavadora", 30);

   // Añadimos comentarios
   entrada.AddComentario ( "Qué lindo tu gato!" );
   entrada.AddComentario ( "El mío prefiere dormir encima del sofá" );
   entrada.AddComentario ( "Ja, ja... espero que no le dé por meterse dentro" );

   // Ahora creamos una segunda entrada
   // Prueba a cambiar el texto por otros distintos para que veas como
   // efectivamente salen ordenados alfabéticamente
   EntradaEnFacebook otraEntrada ( 2, "Mira lo que pasa: Hoy es mi cumpleaños", 30 );

   // Añadimos comentarios
   otraEntrada.AddComentario ( "Felicidades!!! Que cumplas muchos más" );
   otraEntrada.AddComentario ( "Desde luego, por ti no pasan los años" );
   otraEntrada.AddComentario ( "Jo... anda que invitas, ya te vale." );

   // Primera parte: comprobación del operador <=
   std::cout << "En primer lugar comprobamos el uso del operador <=" << std::endl
             << "Para ello, comparamos las entradas y las escribimos en orden alfabético" << std::endl;

   if ( entrada <= otraEntrada )
   {  // Mostramos los datos almacenados empezando por la primera
      std::cout << "+ Los datos de la variable entrada son: " << std::endl
                << "    " << entrada.GetTexto() << std::endl;

      for ( int i = 0; i < entrada.GetNumComentarios(); ++i )
      {  std::cout << "         - " << entrada.GetComentario(i) << std::endl;
      }

      std::cout << "+ Los datos de la variable otraEntrada son: " << std::endl
                << "    " << otraEntrada.GetTexto() << std::endl;
      for ( int i = 0; i < otraEntrada.GetNumComentarios(); ++i )
      {  std::cout << "         - " << otraEntrada.GetComentario(i) << std::endl;
      }
   }
   else
   {  // Mostramos los datos almacenados empezando por la segunda
      std::cout << "+ Los datos de la variable otraEntrada son: " << std::endl
                << "    " << otraEntrada.GetTexto() << std::endl;
      for ( int i = 0; i < otraEntrada.GetNumComentarios(); ++i )
      {  std::cout << "         - " << otraEntrada.GetComentario(i) << std::endl;
      }

      std::cout << "+ Los datos de la variable entrada son: " << std::endl
                << "    " << entrada.GetTexto() << std::endl;
      for ( int i = 0; i < entrada.GetNumComentarios(); ++i )
      {  std::cout << "         - " << entrada.GetComentario(i) << std::endl;
      }
   }

   // Segunda parte: comprobación del operador == (comparación)

   std::cout << std::endl << std::endl;
   std::cout << "A continuación, probamos el operador comparación." << std::endl;

   EntradaEnFacebook nuevaEntrada ( 3, "Este nuevo vídeo de Nyan Cat no lo habéis visto", 30);
   EntradaEnFacebook &entradaExistente = entrada; //Referencia a entrada existente

   if ( nuevaEntrada == entrada )
   {  // No se entra aquí
      std::cout << "Dos entradas diferentes tienen el mismo ID y eso no puede ser..."
                << std::endl;
   }
   else
   {  std::cout << "Las entradas " << entrada.GetId() << " y "
                << nuevaEntrada.GetId() << " son diferentes" << std::endl;
   }

   if ( entradaExistente == entrada)
   {  std::cout << "La entrada con id " << entrada.GetId()
                << " y su referencia son la misma" << std::endl;
   }
   else
   {  //No se entra aquí
      std::cout << "Umm, ,debe haber un error en Matrix!" << std::endl;
   }

   // Tercera parte: comprobación del operador = (asignación)
   std::cout << std::endl << std::endl;
   std::cout << "A continuación, probamos el operador asignación." << std::endl
             << "Deben salir los datos de las dos variables exactamente iguales" << std::endl;
   otraEntrada = entrada;
   // Mostramos los datos de ambas y deben ser iguales
   std::cout << "+ Los datos de la variable otraEntrada son " << std::endl
             << "    " << otraEntrada.GetTexto() << std::endl;
   for ( int i = 0; i < otraEntrada.GetNumComentarios(); ++i )
   {  std::cout << "         - " << otraEntrada.GetComentario(i) << std::endl;
   }

   std::cout << "+ Los datos de la variable entrada son: " << std::endl
             << "    " << entrada.GetTexto() << std::endl;
   for ( int i = 0; i < entrada.GetNumComentarios(); ++i )
   {  std::cout << "         - " << entrada.GetComentario(i) << std::endl;
   }

   return 0;
}