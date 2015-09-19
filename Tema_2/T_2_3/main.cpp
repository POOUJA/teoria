/** 
 * @brief Fichero principal del ejemplo de teoría T_2_3
 * @file main.cpp
 * @author Victor M. Rivas (vrivas@ujaen.es)
 * @date 17 de septiembre de 2015, 18:17
 */

#include <iostream>
#include "Gol.h"
using namespace std;

/**
 * @brief Función principal
 * @param argc Número de argumentos
 * @param argv Caracteres que forman dichos argumentos
 * @post Crea un objeto de la clase Gol e imprime su estado
 */
int main(int argc, char** argv) {
    Gol primerGol( "Alex Cruz", 23 );
    cout << "Ejemplo Teoria T_2_3" << endl;
    cout << "El gol fue marcado por " << primerGol.GetJugador()
            << " en el minuto " << primerGol.GetMinuto() << endl;
    
    // Incorrecto: cout << "El gol fue marcado por " << primerGol.jugador
    return 0;
}

