/**
 * @brief Fichero principal del ejemplo de teor�a T_2_"
 * @file main.cpp
 * @author Victor M. Rivas (vrivas@ujaen.es)
 * @date 17 de septiembre de 2015, 18:17
 */

#include <iostream>
#include "CalculadoraIVA.h"


/**
 * @brief Funci�n principal
 * @param argc N�mero de argumentos
 * @param argv Caracteres que forman dichos argumentos
 * @post Crea un objeto de la clase CalculadoraIVA e imprime el IVA para un determinado precio
 */
int main(int argc, char** argv) {
    CalculadoraIVA calculadora( 21 );
    std::cout << "El IVA de un producto que cuesta 80 euros es "
              << calculadora.aplicar( 80 ) << std::endl;
    return 0;
}

