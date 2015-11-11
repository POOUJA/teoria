/**
 * @file   Ejemplar.cpp
 * @author jrbalsas@ujaen.es
 *
 * @date 9 de octubre de 2015, 12:55
 */

#include <sstream>
#include <iostream>

#include "Ejemplar.h"

Ejemplar::Ejemplar(std::string identificador, std::string titulo, std::string editorial, float precio)
    :_identificador(identificador),_titulo(titulo),_editorial(editorial),_precio(precio) {
}

Ejemplar::Ejemplar(const Ejemplar& orig)
    :_identificador(orig._identificador),_titulo(orig._titulo),
     _editorial(orig._editorial),_precio(orig._precio){
}

Ejemplar::~Ejemplar() {
        std::cerr << "Destruyendo ejemplar " << _titulo << std::endl;
}


void Ejemplar::setID(std::string identificador) {
    this->_identificador = identificador;
}

std::string Ejemplar::getID() const {
    return _identificador;
}

void Ejemplar::setPrecio(float precio) {
    this->_precio = precio;
}

float Ejemplar::getPrecio() const {
    return _precio;
}

void Ejemplar::setEditorial(std::string editorial) {
    this->_editorial = editorial;
}

std::string Ejemplar::getEditorial() const {
    return _editorial;
}

void Ejemplar::setTitulo(std::string titulo) {
    this->_titulo = titulo;
}

std::string Ejemplar::getTitulo() const {
    return _titulo;
}

std::string Ejemplar::toCSV() const{
    std::stringstream ss;
    std::string linea;
    
    ss  << _titulo << ';'
        << _editorial << ';'
        << _precio;
    
    std::getline(ss,linea);
    return linea;
}

void Ejemplar::fromCSV(std::string linea) {
    std::stringstream ss(linea);

    std::getline(ss,_titulo,';');
    std::getline(ss,_editorial,';');
    ss >> _precio;
    
}

/**Compara dos ejemplares por su identificador*/
bool Ejemplar::operator==(const Ejemplar& orig) const {
    return _identificador==orig._identificador;
}

/**Compara un ejemplar con su identificador*/
bool Ejemplar::operator==(const std::string &identificador) const {
    return _identificador==identificador;
}