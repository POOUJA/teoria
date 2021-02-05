/**
 * @brief Ejemplo T_2_5 de teoría: Juego de Tronos
 * @file main.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 22 de septiembre de 2015, 11:00
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include "Personaje.h"


/**
 * @brief Función principal
 * @argc Número de argumentos pasados por línea de órdenes
 * @argc Caractares pasados como argumentos por línea de órdenes
 * @return 0 si todo funciona bien; distinto de 0 en otro caso.
 */
int main(int argc, char** argv) {

    // Creamos un par de familias
    //Familia lannister("Lannister"), stark("Stark");
    std::string lannister = "Lannister", stark = "Stark";

    // Creamos algunos personajes
    Personaje tyrion("Tyrion", &lannister), robb("Robb", &stark), khaleesi("Khaleesi");

    // Creamos copia de Robb
    Personaje copiaRobb(robb);

    // Imprimimos los datos antes de modificar el apellido de la familia:
    // Tanto el nombre (Robb) como el apellido (Stark) serán
    // los mismos, en el original y en la copia
    std::cout << "DATOS ANTES DE MODIFICAR LA FAMILIA: " << std::endl
              << "  ROBB ORIGINAL: Nombre: " << robb.GetNombre() << ", "
              << "Familia: " << *(robb.GetApellidoFamilia()) << " " << std::endl
              << "  ROBB COPIADO: Nombre: " << copiaRobb.GetNombre() << ", "
              << "Familia: " << *(copiaRobb.GetApellidoFamilia()) << " "
              << std::endl;


    // Modificamos algún dato de la familia de la copia para ver si se modifica
    // también el original - dependerá del constructor de copia que hayamos usado
    *(copiaRobb.GetApellidoFamilia()) = "Starsky y Hutch";

    // Sobre Starky y Hutch ver:
    // * http://www.imdb.com/title/tt0072567/
    // * https://en.wikipedia.org/wiki/Starsky_%26_Hutch


    // Si has compilado usando la primera versión del constructor de copia,
    // tanto el original como la copia tendrán por apellido "Starsky y Hutch"
    // porque al cambiárselo a la copia TAMBIÉN se lo has cambiado al original
    // dado que los apellidos de ambos apuntan al mismo sitio

    // Si has compilado usando la segunda versión del constructor de copia,
    // el original tendrá apellido Stark y la copia "Starsky y Hutch"
    // Porque SOLO has modificado el apellido de la copia, el cual había
    // duplicado el apellido original en otra zona de memoria.

    std::cout << "DATOS *DESPUÉS* DE MODIFICAR LA FAMILIA: " << std::endl
              << "  ROBB ORIGINAL: Nombre: " << robb.GetNombre() << ", "
              << "Familia: " << *(robb.GetApellidoFamilia()) << " " << std::endl
              << "  ROBB COPIADO: Nombre: " << copiaRobb.GetNombre() << ", "
              << "Familia: " << *(copiaRobb.GetApellidoFamilia()) << " "
              << std::endl;


    /*
     Salida esperada si compilas con la primera versión del constructor de copia:

    DATOS ANTES DE MODIFICAR LA FAMILIA:
        ROBB ORIGINAL: Nombre: Robb, Familia: Stark
        ROBB COPIADO: Nombre: Robb, Familia: Stark
    DATOS *DESPUÉS* DE MODIFICAR LA FAMILIA:
        ROBB ORIGINAL: Nombre: Robb, Familia: Starsky y Hutch
        ROBB COPIADO: Nombre: Robb, Familia: Starsky y Hutch

     *   Salida esperada si compilas con la segunda versión del constructor de copia:

    DATOS ANTES DE MODIFICAR LA FAMILIA:
        ROBB ORIGINAL: Nombre: Robb, Familia: Stark
        ROBB COPIADO: Nombre: Robb, Familia: Stark
    DATOS *DESPUÉS* DE MODIFICAR LA FAMILIA:
        ROBB ORIGINAL: Nombre: Robb, Familia: Stark
        ROBB COPIADO: Nombre: Robb, Familia: Starsky y Hutch



     */
    return 0;
}

