/** 
 * @brief Ejemplo T_2_5 de teoría: Juego de Tronos
 * @file main.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 22 de septiembre de 2015, 11:00
 */

#include <iostream>
#include <cstdlib>
#include <vector>

#include "Familia.h"
#include "Personaje.h"
using namespace std;

/**
 * @brief Función principal
 * @argc Número de argumentos pasados por línea de órdenes
 * @argc Caractares pasados como argumentos por línea de órdenes
 * @return 0 si todo funciona bien; distinto de 0 en otro caso.
 */
int main(int argc, char** argv) {

    // Creamos un par de familias
    Familia lannister("Lannister"), stark("Stark");

    // Creamos un par de personajes
    Personaje tyrion("Tyrion", &lannister), robb("Robb", &stark);

    // Creamos copia de Robb
    Personaje copiaRobb( robb );

    // Imprimimos los datos antes de modificar la familia:
    // Tanto el nombre (Robb) como el apellido (Stark) serán
    // los mismos, en el original y en la copia
    cout << "DATOS ANTES DE MODIFICAR LA FAMILIA: " << endl;
    cout << "  ROBB ORIGINAL: Nombre: " << robb.GetNombre() << ", "
            << "Familia: " << robb.GetSuFamilia()->GetApellido() << " "
            << endl;
    cout << "  ROBB COPIADO: Nombre: " << copiaRobb.GetNombre() << ", "
            << "Familia: " << copiaRobb.GetSuFamilia()->GetApellido() << " "
            << endl;

    
    // Modificamos algún dato de la familia de la copia para ver si se modifica
    // también el original - dependerá del constructor de copia que hayamos usado
    copiaRobb.GetSuFamilia()->SetApellido("Starsky y Hutch");
    
    // Sobre Starky y Hutch ver: 
    // * http://www.imdb.com/title/tt0072567/
    // * https://en.wikipedia.org/wiki/Starsky_%26_Hutch

    
    // Si has compilado usando la primera versión del constructor de copia,
    // tanto el original como la copia tendrán por apellido "Starsky y Hutch"
    
    // Si has compilado usando la segunda versión del constructor de copia,
    // el original tendrá apellido Stark y la copia "Starsky y Hutch"
    cout << "DATOS *DESPUÉS* DE MODIFICAR LA FAMILIA: " << endl;
    cout << "  ROBB ORIGINAL: Nombre: " << robb.GetNombre() << ", "
            << "Familia: " << robb.GetSuFamilia()->GetApellido() << " "
            << endl;
    cout << "  ROBB COPIADO: Nombre: " << copiaRobb.GetNombre() << ", "
            << "Familia: " << copiaRobb.GetSuFamilia()->GetApellido() << " "
            << endl;

    return 0;
}

