/** 
 * @file   Libro.cpp
 * @author jrbalsas
 *
 * @date 9 de octubre de 2015, 13:16
 */

#include <sstream>
#include "Libro.h"

#include <iostream>



/**Constructor de un libro a partir de su información básica*/
Libro::Libro( std::string isbn, std::string titulo, unsigned int anio, unsigned int edicion,
              std::string autor, std::string editorial, float precio)
            :Ejemplar(isbn,titulo,editorial,precio),
            _autor(autor),
            _anioPublicacion(anio),
            _edicion(edicion){
}

/**Constructor de copia*/
Libro::Libro(const Libro& orig): Ejemplar(orig),
                                _autor(orig._autor),
                                _anioPublicacion(orig._anioPublicacion),
                                _edicion(orig._edicion) {
}

/**Destructor*/
Libro::~Libro() {
    std::cerr << "Destruyendo libro de " << _autor << " ";
}

void Libro::setAutor(std::string _autor) {
    this->_autor = _autor;
}

std::string Libro::getAutor() const {
    return _autor;
}

void Libro::setAnioPublicacion(unsigned int _anioPublicacion) {
    this->_anioPublicacion = _anioPublicacion;
}

unsigned int Libro::getAnioPublicacion() const {
    return _anioPublicacion;
}

void Libro::setEdicion(unsigned int _edicion) {
    this->_edicion = _edicion;
}

unsigned int Libro::getEdicion() const {
    return _edicion;
}

void Libro::setIsbn(std::string _isbn) {
    this->setID(_isbn);
}

std::string Libro::getIsbn() const {
    return this->getID();
}

/**Devuelve una cadena con la representación CSV de los datos de un libro*/
std::string Libro::toCSV() const {

    std::stringstream ss;
    std::string linea;
    
    
    //Primero guardamos la información específica como Libro
    ss  << _autor << ';'
        << _anioPublicacion << ';'
        << _edicion << ';';

    //Después guardamos la información específica como Ejemplar
    ss  << Ejemplar::toCSV();

    std::getline(ss,linea);

    return linea;
}

/**Inicializa un Libro a partir de sus datos obtenidos en formato CSV almacenados en línea
 @pre formato de línea: autor;año_publicacion;num_edicion;ISSN;título;editorial;precio*/
void Libro::fromCSV(std::string linea) {

    std::stringstream ss(linea);
    std::string lineaEjemplar;
    
    //Primero leemos los datos específicos de un Libro
   
    std::getline(ss,_autor,';');
    ss >> _anioPublicacion;
    ss.ignore(); //ignoramos siguiente ';'
    ss >> _edicion;
    ss.ignore();
    
    //Procesamos resto de la línea con los datos como Ejemplar
    std::getline(ss,lineaEjemplar);
    Ejemplar::fromCSV(lineaEjemplar);
    
}

