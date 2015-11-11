/** Implementación de la clase Revista
 * @file   Revista.cpp
 * @author jrbalsas
 *
 * @date 9 de octubre de 2015, 13:40
 */

#include <sstream>
#include <iostream>

#include "Revista.h"

/**Construye una revista a partir de su información básica
   @throw std::domain_error si algún atributo no es válido para un libro*/
Revista::Revista(   std::string ISSN, std::string titulo, unsigned int anio, unsigned int numero,
                    std::string editorial, float precio) 
                throw (std::domain_error)
    try
        : Ejemplar(ISSN,titulo, editorial, precio) {
        //inicializamos atributos con métodos set para comprobaciones de valores válidos de dominio
        setISSN(ISSN); //Aunque ISSN está inicializado como ID ejemplar, verificamos que es válido
        setAnio(anio);
        setNumero(numero);
    } catch (std::domain_error &e ) {
        //relanzamos excepciones de Ejemplar o de inicialización de atributos propios
        throw e;
    }

/**Constructor de copia*/
Revista::Revista(const Revista& orig)
    :Ejemplar(orig),_anio(orig._anio),_numero(orig._numero){

}

/**Destructor*/
Revista::~Revista() {
    std::cerr << "Destruyendo revista año " << _anio << " ";
}

/** Establece el año de publicación de una revista
 * @throw std::domain_error si el año es inferior a 1800 o tiene más de 4 dígitos
 */
void Revista::setAnio(unsigned int anio) {
    if (anio<1800 || anio>9999)
        throw std::domain_error("[Revista::setAnio] sólo se admiten años de 4 dígitos a partir de 1800");
    this->_anio = anio;
}

unsigned int Revista::getAnio() const {
    return _anio;
}

/**Establece el número de una revista
 * @throw std::domain_error si el número es superior a 999
 */
void Revista::setNumero(unsigned int numero) {
    if (numero>100)
        throw std::domain_error("[Revista::setNumero] no se admite más 999 números de una revista");
    this->_numero = numero;
}

unsigned int Revista::getNumero() const {
    return _numero;
}

/**Establece como ID de una revista su issn
   @throw std::domain_error si el ISSN no tiene un formato válido*/
void Revista::setID(std::string issn) throw (std::domain_error) {
    setISSN(issn); //El identificador de una revista es su ISBN
}

/**Asigna un ISBN según el formato adecuado
  @throw std::domain_error si el ISSN no tiene un formato válido*/
void Revista::setISSN(std::string issn) throw (std::domain_error) {
    //FIXME: Verificar con más detalle formato del ISSN
    if (issn.substr(0,4)!="ISSN")
        throw std::domain_error("[Revista::setISSN] el ISSN debe comenzar por ISSN");
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
 @pre formato de línea: año_publicacion;num_publicacion;issn;título;editorial;precio
 @pos Modifica los atributos de la revista si linea contiene la información requerida
 @throw ExConversion si la línea CSV no tiene el formato adecuado
 @throw std::domain_error si algún dato para la revista no es válido*/
void Revista::fromCSV(std::string linea) throw (ExConversion,std::domain_error){

    std::stringstream ss(linea);
    std::string lineaEjemplar;
    int valor;

    ss >> valor;
    if (ss.fail())
        throw ExConversion("[Revista::fromCSV] el año de la revista no es un número: "+linea);
    setAnio(valor);
    ss.ignore(); //ignoramos siguiente ';'

    ss >> valor;
    if (ss.fail())
        throw ExConversion("[Revista::fromCSV] la edición no es un número: "+linea);
    setNumero(valor);
    ss.ignore(); //ignoramos siguiente ';'
    

    //Procesamos resto de la línea con la parte de Ejemplar
    std::getline(ss,lineaEjemplar);
    Ejemplar::fromCSV(lineaEjemplar);
}

