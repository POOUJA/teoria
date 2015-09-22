/** 
 * @brief
 * @file Familia.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 22 de septiembre de 2015, 11:01
 */

#include "Familia.h"

/**
 * @brief Constructor por defecto de la clase
 * @param apellido Apellido de la familia
 */
Familia::Familia(std::string apellido) :
apellido(apellido) {
}

/**
 * @brief Constructor de copia de la clase
 * @param orig Objeto cuyos datos se van a copiar
 */

Familia::Familia(const Familia& orig) :
apellido(orig.apellido) {
}

/**
 * @brief Destructor de clase
 */
Familia::~Familia() {
}

/**
 * @brief Modifica el apellido de la familia
 * @param apellido Nuevo apellido para la familia
 * @post Modifica el apellido de la familia
 */
void Familia::SetApellido(std::string apellido) {
    this->apellido = apellido;
}

/**
 * @brief Devuelve el apellido de la familia
 * @post Devuelve el apellido de la familia
 */
std::string Familia::GetApellido() const {
    return apellido;
}

