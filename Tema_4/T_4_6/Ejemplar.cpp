/** Implementación de la clase Ejemplar
 * @file   Ejemplar.cpp
 * @author jrbalsas@ujaen.es
 *
 * @date 9 de octubre de 2015, 12:55
 */

#include <sstream>
#include <iostream>

#include "Ejemplar.h"

Ejemplar::Ejemplar(std::string identificador): _identificador(identificador) {
    if (identificador.length()<5) {
        throw std::domain_error("[Ejemplar::Ejemplar] el identificador de un ejemplar debe tener al menos 5 caracteres");
    }
}

/**Inicializa un ejemplar a partir de sus atributos
   @throw std::domain_error si algún atributo no es válido para un ejemplar*/
Ejemplar::Ejemplar(std::string identificador, std::string titulo, std::string editorial, float precio)         
        :_identificador(identificador)
{
    if (identificador.length()<5) {
        throw std::domain_error("[Ejemplar::Ejemplar] el identificador de un ejemplar debe tener al menos 5 caracteres");
    }
    //inicializamos resto de atributos con métodos set 
    //para comprobaciones de valores válidos de dominio
    setTitulo(titulo);
    setEditorial(editorial);
    setPrecio(precio);
}

Ejemplar::~Ejemplar() noexcept {
        std::cerr << "Destruyendo ejemplar " << _titulo << std::endl;
}

std::string Ejemplar::getID() const {
    return _identificador;
}

void Ejemplar::setPrecio(float precio) {
    if (precio<0)
        throw std::domain_error("[Ejemplar::setPrecio] El precio de un ejemplar no puede ser negativo");
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

/** Establece el título del ejemplar
 * @throw std::domain_error si el título es una cadena vacía*/
void Ejemplar::setTitulo(std::string titulo) {
    if (titulo.length()==0)
        throw std::domain_error("[Ejemplar::setTitulo] El ejemplar debe tener algún título");
    this->_titulo = titulo;
}

std::string Ejemplar::getTitulo() const {
    return _titulo;
}

/**Devuelve la representación CSV de un ejemplar
  @post el formato CSV será identificador;titulo;editorial;precio
*/
std::string Ejemplar::toCSV() const{
    std::stringstream ss;
    std::string linea;
    
    ss  << _identificador << ";"
        << _titulo << ';'
        << _editorial << ';'
        << _precio;
    
    std::getline(ss,linea);
    return linea;
}

/**Modifica los atributos de un ejemplar a partir de su representación CSV
   @pre línea tiene el formato identificador;titulo;editorial;precio
   @throw ExConversion si hay algún error en el proceso de conversión
   @throw std::domain_error si algún dato para el ejemplar no es válido*/
void Ejemplar::fromCSV(std::string linea)  {
    std::stringstream ss(linea);
    std::string campo;
    float valor;

    std::getline(ss,campo,';');
    setID(campo);   //Los métodos set verifican la validez de los datos leidos
                    //Polimorfismo de método: se llama al setID de la clase derivada
                    //para que verifique la validez de su ID
    std::getline(ss,campo,';');
    setTitulo(campo);
    std::getline(ss,campo,';');
    setEditorial(campo);
    ss >> valor;
    if (ss.fail())
        throw ExConversion("[Ejemplar::fromCSV] el precio del libro no es un número: "+linea);
    setPrecio(valor);
}

/**Compara dos ejemplares por su identificador*/
bool Ejemplar::operator==(const Ejemplar& orig) const {
    return igualA(orig);
}

/**Compara dos ejemplares por su identificador*/
bool Ejemplar::igualA(const Ejemplar& orig) const {
    return _identificador==orig._identificador;
}

/**Compara un ejemplar con su identificador*/
bool Ejemplar::operator==(const std::string &identificador) const {
    return _identificador==identificador;
}