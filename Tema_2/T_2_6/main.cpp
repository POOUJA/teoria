/** 
 * @brief Ejemplo T_2_6 de teoría: Entrada de Facebook
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
    // Creamos una entrada automática
    EntradaEnFacebook entrada(1, "Hoy mi gato se ha dormido encima de la lavadora", 30),
                      entradapordefecto;

    // Añadimos comentarios
    entrada.AddComentario("Qué lindo tu gato!");
    entrada.AddComentario("El mío prefiere dormir encima del sofá");
    entrada.AddComentario("Ja, ja... espero que no le dé por meterse dentro");

    // Mostramos los datos almacenados
    cout << "Entrada: " << endl
            << "    " << entrada.GetTexto() << endl;
    for (int i = 0; i < entrada.GetNumComentarios(); ++i) {
        cout << "         - " << entrada.GetComentario(i) << endl;
    }


    // Ahroa creamos una entrada dinámica
    EntradaEnFacebook *otraEntrada = nullptr;
    otraEntrada = new EntradaEnFacebook(2, "No pillo los ejemplos de POO", 30);

    // Añadimos comentarios
    otraEntrada->AddComentario("Ánimo!! El primer año no es fácil");
    otraEntrada->AddComentario("¿Te los has descargado de GitHub? Yo lo hice y me funcionó");

    // Mostramos los datos almacenados
    cout << "Entrada: " << endl
            << "    " << otraEntrada->GetTexto() << endl;
    for (int i = 0; i < otraEntrada->GetNumComentarios(); ++i) {
        cout << "         - " << otraEntrada->GetComentario(i) << endl;
    }

    // Llamamos explícitamente al destructor del objeto dinámico
    if( otraEntrada ) {
        delete otraEntrada;
        otraEntrada=0;
    }
    
    // No es necesario llamar al destructor del objeto automático.
    return 0;
}

