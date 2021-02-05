/**
 * @brief Fichero principal del ejemplo de teor�a T_2_3
 * @file main.cpp
 * @author Victor M. Rivas (vrivas@ujaen.es)
 * @date 17 de septiembre de 2015, 18:17
 */

#include <iostream>
#include "Gol.h"


/**
 * @brief Funci�n principal
 * @param argc N�mero de argumentos
 * @param argv Caracteres que forman dichos argumentos
 * @post Crea un objeto de la clase Gol e imprime su estado
 */
int main(int argc, char** argv) {
    Gol primerGol( "Alex Cruz", 23 );
    std::cout << "Ejemplo Teoria T_2_3" << std::endl
              << "El gol fue marcado por " << primerGol.GetJugador()
              << " en el minuto " << primerGol.GetMinuto() << std::endl;

    // Incorrecto: cout << "El gol fue marcado por " << primerGol.jugador
    return 0;
}

