/** 
 * @brief Fichero principal del ejemplo de teoría T_2_1
 * @file main.cpp
 * @author Victor M. Rivas (vrivas@ujaen.es)
 * @date 17 de septiembre de 2015, 18:17
 */

#include <cstdlib>
#include <iostream>
#include "Circulo.h"
using namespace std;

/**
 * @brief Función principal
 * @param argc Número de argumentos
 * @param argv Caracteres que forman dichos argumentos
 * @post Crea un objeto de la clase Círculo e imprime su radio
 */
int main(int argc, char** argv) {
    Circulo rueda;
    rueda.SetRadio(12);
    cout << "Ejemplo T_2_1" << endl;
    cout << "El radio de la rueda es " << rueda.GetRadio() << endl;
    return 0;
}

