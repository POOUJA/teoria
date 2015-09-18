/** 
 * @brief Fichero principal del ejemplo de teoría 2.2
 * @file main.cpp
 * @author Victor M. Rivas (vrivas@ujaen.es)
 * @date 17 de septiembre de 2015, 18:17
 */

#include <cstdlib>
#include <iostream>
#include "CalculadoraIVA.h"
using namespace std;

/**
 * @brief Función principal
 * @param argc Número de argumentos
 * @param argv Caracteres que forman dichos argumentos
 * @post Crea un objeto de la clase Círculo e imprimir su diámetro
 */
int main(int argc, char** argv) {
    CalculadoraIVA calculadora( 21 );
    cout << "El IVA de un producto que cuesta 80 euros es "
            << calculadora.aplicar( 80 )<<endl;
    return 0;
}

