/** 
 * @brief Usuario que puede publicar una entrada en Facebook
 * @file Usuario.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 27 de octubre de 2015, 18:17
 */

#include "Usuario.h"

/**
 * @brief Constructor por defecto de la clase
 */
Usuario::Usuario(std::string nombre) :
nombre(nombre) {
    if (nombre.length() <= 0) throw std::string("Usuario.cpp, constructor: El nombre del usuario no puede estar vacio.");
}

/**
 * @brief Constructor de copia de la clase
 */

Usuario::Usuario(const Usuario& orig) :
nombre(orig.nombre) {
    if (nombre.length() <= 0) throw std::string("Usuario.cpp, constructor: El nombre del usuario no puede estar vacio.");

}

/**
 * @brief Destructor de clase
 */
Usuario::~Usuario() {
}

void Usuario::setNombre(std::string nombre) {
    this->nombre = nombre;
}

std::string Usuario::getNombre() const {
    return nombre;
}

