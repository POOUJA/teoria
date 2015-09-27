/** 
 * @brief Ejemplo T_2_7 de teoría: Operadores con Entrada de Facebook
 * @file main.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 27 de septiembre de 2015, 11:00
 */

#include <iostream>
#include <cstdlib>
#include "EntradaEnFacebook.h"
using namespace std;

/**
 * @brief Función principal
 * @argc Número de argumentos pasados por línea de órdenes
 * @argc Caractares pasados como argumentos por línea de órdenes
 * @return 0 si todo funciona bien; distinto de 0 en otro caso.
 */
int main(int argc, char** argv) {

    cout << "Ejemplo de teoría T_2_7: Sobrecarga de operadores" << endl;


    // Creamos primera entrada
    EntradaEnFacebook entrada("Hoy mi gato se ha dormido encima de la lavadora", 30);

    // Añadimos comentarios
    entrada.AddComentario("Qué lindo tu gato!");
    entrada.AddComentario("El mío prefiere dormir encima del sofá");
    entrada.AddComentario("Ja, ja... espero que no le dé por meterse dentro");

    // Ahora creamos una segunda entrada
    // Prueba a cambiar el texto por otros distintos para que veas como 
    // efectivamente salen ordenados alfabéticamente
    EntradaEnFacebook otraEntrada("Mira lo que pasa: Hoy es mi cumpleaños", 30);

    // Añadimos comentarios
    otraEntrada.AddComentario("Felicidades!!! Que cumplas muchos más");
    otraEntrada.AddComentario("Desde luego, por ti no pasan los años");
    otraEntrada.AddComentario("Jo... anda que invitas, ya te vale.");

    // Primera parte: comprobación del operador <=
    cout << "En primer lugar comprobamos el uso del operador <=" << endl
            << "Para ello, comparamos las entradas y las escribimos en orden alfabético" << endl;

    if (entrada <= otraEntrada) {
        // Mostramos los datos almacenados empezando por la primera
        cout << "+ Los datos de la variable entrada son: " << endl
                << "    " << entrada.GetTexto() << endl;
        for (int i = 0; i < entrada.GetNumComentarios(); ++i) {
            cout << "         - " << entrada.GetComentario(i) << endl;
        }

        cout << "+ Los datos de la variable otraEntrada son: " << endl
                << "    " << otraEntrada.GetTexto() << endl;
        for (int i = 0; i < otraEntrada.GetNumComentarios(); ++i) {
            cout << "         - " << otraEntrada.GetComentario(i) << endl;
        }
    } else {
        // Mostramos los datos almacenados empezando por la segunda
        cout << "+ Los datos de la variable otraEntrada son: " << endl
                << "    " << otraEntrada.GetTexto() << endl;
        for (int i = 0; i < otraEntrada.GetNumComentarios(); ++i) {
            cout << "         - " << otraEntrada.GetComentario(i) << endl;
        }

        cout << "+ Los datos de la variable entrada son: " << endl
                << "    " << entrada.GetTexto() << endl;
        for (int i = 0; i < entrada.GetNumComentarios(); ++i) {
            cout << "         - " << entrada.GetComentario(i) << endl;
        }
    }

    // Segunda parte: comprobación del operador = (asignación)
    cout << endl << endl;
    cout << "A continuación, probamos el operador asignación." << endl
            << "Deben salir los datos de las dos variables exactamente iguales" << endl;
    otraEntrada = entrada;
    // Mostramos los datos de ambas y deben ser iguales
    cout << "+ Los datos de la variable otraEntrada son " << endl
            << "    " << otraEntrada.GetTexto() << endl;
    for (int i = 0; i < otraEntrada.GetNumComentarios(); ++i) {
        cout << "         - " << otraEntrada.GetComentario(i) << endl;
    }

    cout << "+ Los datos de la variable entrada son: " << endl
            << "    " << entrada.GetTexto() << endl;
    for (int i = 0; i < entrada.GetNumComentarios(); ++i) {
        cout << "         - " << entrada.GetComentario(i) << endl;
    }

    return 0;
}

