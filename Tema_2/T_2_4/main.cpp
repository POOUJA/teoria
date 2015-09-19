/** 
 * @brief Fichero principal del ejemplo de teoría T_2_3
 * @file main.cpp
 * @author Victor M. Rivas (vrivas@ujaen.es)
 * @date 17 de septiembre de 2015, 18:17
 */

#include <iostream>
#include "GaticoDeFeisbus.h"
using namespace std;

/**
 * @brief Función principal
 * @param argc Número de argumentos
 * @param argv Caracteres que forman dichos argumentos
 * @post Crea un objeto de la clase Gol e imprime su estado
 */
int main(int argc, char** argv) {
    GaticoDeFeisbus minino;
    minino.megusta();
    minino.megusta();
    minino.megusta();
    cout << "Ejemplo Teoria T_2_4" << endl;
    cout << "El dichoso gato le gusta a " << minino.GetNumMeGusta() << endl;
    return 0;
}

