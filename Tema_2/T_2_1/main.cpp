/**
 * @brief Fichero principal del ejemplo de teor�a T_2_1
 * @file main.cpp
 * @author Victor M. Rivas (vrivas@ujaen.es)
 * @date 17 de septiembre de 2015, 18:17
 */

#include <cstdlib>
#include <iostream>
#include "Circulo.h"


/**
 * @brief Funci�n principal
 * @param argc N�mero de argumentos
 * @param argv Caracteres que forman dichos argumentos
 * @post Crea un objeto de la clase C�rculo e imprime su radio
 */
int main(int argc, char** argv) {
    Circulo rueda;
    rueda.SetRadio(1.2);
    std::cout << "Ejemplo T_2_1" << std::endl
              << "El radio de la rueda es " << rueda.GetRadio() << std::endl;
    return 0;
}

