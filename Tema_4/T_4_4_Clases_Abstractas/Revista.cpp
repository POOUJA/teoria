/** 
 * @file   Revista.cpp
 * @author jrbalsas
 *
 * @date 9 de octubre de 2015, 13:40
 */

#include <sstream>
#include <iostream>

#include "Revista.h"

/**Construye una revista a partir de su información básica*/
Revista::Revista(   std::string ISSN, std::string titulo, unsigned int anio, unsigned int numero,
                    std::string editorial, float precio)
    : Ejemplar(ISSN,titulo, editorial, precio), _anio(anio), _numero(numero) {
}

/**Constructor de copia*/
Revista::Revista(const Revista& orig)
    :Ejemplar(orig),_anio(orig._anio),_numero(orig._numero){

}

/**Destructor*/
Revista::~Revista() {
    std::cerr << "Destruyendo revista año " << _anio << " ";
}

void Revista::setAnio(unsigned int _anio) {
    this->_anio = _anio;
}

unsigned int Revista::getAnio() const {
    return _anio;
}

void Revista::setNumero(unsigned int _numero) {
    this->_numero = _numero;
}

unsigned int Revista::getNumero() const {
    return _numero;
}

/** Establece el ISSN como identificador del Ejemplar*/
 void Revista::setID(std::string issn) {
    setISSN(issn);
}

void Revista::setISSN(std::string issn) {
    //TODO: Comprobar formato ISSN
    _identificador=issn;
}

std::string Revista::getISSN() const {
    return getID();
}

/**Devuelve una cadena con la representación CSV de los datos de una revista*/
std::string Revista::toCSV() const {
    std::stringstream ss;
    std::string linea;
    
    ss  << _anio << ';'
        << _numero << ';';

    ss  << Ejemplar::toCSV();
    
    std::getline(ss,linea);
    
    return linea;
}

/**Inicializa una Revista a partir de sus datos obtenidos en formato CSV almacenados en línea
 @pre formato de línea: revista;año_publicacion;num_publicacion;issn;título;editorial;precio
 @pos Modifica los atributos de la revista si linea contiene la información requerida
*/
void Revista::fromCSV(std::string linea) {

    std::stringstream ss(linea);
    std::string tipoEjemplar,lineaEjemplar;
    
    std::getline(ss,tipoEjemplar,';'); //Nos aseguramos que la línea se corresponde con un libro
    if (tipoEjemplar=="revista") {

        ss>>_anio;
        ss.ignore(); //ignoramos siguiente ';'
        ss>>_numero;
        ss.ignore();

        //Procesamos resto de la línea con la parte de Ejemplar
        std::getline(ss,lineaEjemplar);
        Ejemplar::fromCSV(lineaEjemplar);
    }
}

