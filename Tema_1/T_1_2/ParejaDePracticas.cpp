/** 
 * @brief
 * @file ParejaDePracticas.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 11 de enero de 2016, 22:20
 */

#include "ParejaDePracticas.h"

/**
 * @brief Constructor parametrizado de la clase
 */
ParejaDePracticas::ParejaDePracticas() :
nombre("Nombre no válido")
, telefono("Teléfono no válido")
, email("Email no válido") {
}

/**
 * @brief Constructor de copia de la clase
 */

ParejaDePracticas::ParejaDePracticas(const ParejaDePracticas& orig) :
nombre(orig.nombre)
, telefono(orig.telefono)
, email(orig.email) {
}

/**
 * @brief Destructor de clase
 */
ParejaDePracticas::~ParejaDePracticas() {
}

void ParejaDePracticas::setEmail(std::string email) {
    if (email == "") throw std::string( "ParejaDePracticas:setEmail: El valor para email está vacío");
    this->email = email;
}

std::string ParejaDePracticas::getEmail() const {
    return email;
}

void ParejaDePracticas::setTelefono(std::string telefono) {
    if (telefono == "") throw std::string ("ParejaDePracticas:setTelefono: El valor para teléfono está vacío");
    this->telefono = telefono;
}

std::string ParejaDePracticas::getTelefono() const {
    return telefono;
}

void ParejaDePracticas::setNombre(std::string nombre) {
    if (nombre == "") throw std::string ("ParejaDePracticas:setNombre: El valor para nombre está vacío");
    this->nombre = nombre;
}

std::string ParejaDePracticas::getNombre() const {
    return nombre;
}

std::string ParejaDePracticas::concatenar() const {
    return nombre+", "+telefono+", "+email;
}

