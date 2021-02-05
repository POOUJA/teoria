/**
 * @brief Ejemplo T_2_9 de teoría: Excepciones en métodos de una clase
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
int main(int argc, char** argv) {

    std::cout << "Ejemplo de teoría T_2_9: Excepciones en métodos de una clase" << std::endl;

    Usuario unUsuario("Luis");
    try {
        // Creamos una entrada con 0 comentarios como máximo
        std::cout << "1) Creando una entrada con 0 comentarios como máximo...\n";
        EntradaEnFacebook entrada(unUsuario, "Mi perra Lucera", 0);

    } catch (std::string e) {
        std::cerr << "  Error: " << e << std::endl;
    }

    try {
        // Creamos una entrada que admite 2 comentarios como máximo

        std::cout << "2) Añadiendo más comentarios de las permitidas a una entrada...\n";
        EntradaEnFacebook entrada(unUsuario, "Fin de semana en el pueblo", 2);

        // Añadimos comentarios
        entrada.AddComentario("Qué paisajes tan bonitos!");
        entrada.AddComentario("¿Te habrás traido un par de chorizos para los amigos, no?");

        // este comentario debería generar un error.
        entrada.AddComentario("Yo pensaba que siempre habías vivido en la capital");

    } catch (std::string e) {
        std::cerr << "  Error: " << e << std::endl;
    }

    try {
        // Creamos una entrada con un usuario sin nombre

        std::cout << "3) Creando una entrada con un usuario sin nombre...\n";
        unUsuario.setNombre("");
        EntradaEnFacebook entrada( unUsuario, "En la Feria de San Lucas", 10);

    } catch (std::string e) {
        std::cerr << "  Error: " << e << std::endl;
    }

    return 0;
}

