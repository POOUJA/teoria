/** Implementación de la clase Libro
 * @file   Libro.cpp
 * @author jrbalsas@ujaen.es
 *
 * @date 9 de octubre de 2015, 13:16
 */

#include <sstream>
#include "Libro.h"

#include <iostream>

/**Constructor de un libro a partir de su información básica
   @throw std::domain_error si algún atributo no es válido para un libro*/
Libro::Libro( std::string isbn, std::string titulo, unsigned int anio, unsigned int edicion,
              std::string autor, std::string editorial, float precio)              
    try 
            :Ejemplar(isbn,titulo,editorial,precio) {
        //inicializamos atributos con métodos set para comprobaciones de valores válidos de dominio
        setIsbn(isbn); //Aunque ISBN está inicializado como ejemplar, verificamos que es válido
        setAutor(autor);
        setAnioPublicacion(anio);
        setEdicion(edicion);
    } catch (std::domain_error &e ) {
        //relanzamos excepciones de Ejemplar o de inicialización de atributos propios
        throw std::domain_error(std::string("[Libro::Libro] Error en inicialización: ")+
                                std::string( e.what() ) );
    }

/**Destructor*/
Libro::~Libro() noexcept{
    std::cerr << "Destruyendo libro de " << _autor << " ";
}

void Libro::setAutor(std::string _autor) {
    this->_autor = _autor;
}

std::string Libro::getAutor() const {
    return _autor;
}

/**Establece el año de publicación de un libro
 * @throw std::domain_error si el año tiene más de 4 dígitos
 */
void Libro::setAnioPublicacion(unsigned int anioPublicacion) {
    if (anioPublicacion>9999)
        throw std::domain_error("[Libro::setAnioPublicacion] sólo se admiten años de cuatro dígitos");
    this->_anioPublicacion = anioPublicacion;
}

unsigned int Libro::getAnioPublicacion() const {
    return _anioPublicacion;
}

/**Establece la edición de un libro
 * @throw std::domain_error si la edición es superior a 100
 */
void Libro::setEdicion(unsigned int edicion) {
    if (edicion>100)
        throw std::domain_error("[Libro::setEdicion] sólo se admiten hasta 100 ediciones");
    this->_edicion = edicion;
}

unsigned int Libro::getEdicion() const {
    return _edicion;
}

/**Establece como ID de un libro su isbn
   @throw std::domain_error si el ISBN no tiene un formato válido*/
void Libro::setID(std::string isbn) {
    setIsbn(isbn); //El identificador de un libro es su ISBN
}

/**Asigna un ISBN según el formato adecuado
  @throw std::domain_error si el ISBN no tiene un formato válido*/
void Libro::setIsbn(std::string isbn){
    //FIXME: Verificar con más detalle formato del ISBN
    if (isbn.length()<10)
        throw std::domain_error("[Libro::setISBN] el ISBN debe tener al menos 10 dígitos");
    _identificador=isbn;
}

std::string Libro::getIsbn() const {
    return this->getID();
}

/**Devuelve una cadena con la representación CSV de los datos de un libro
  @post el formato de cadena será autor;año_publicación;edicion;isbn;titulo;editorial;precio*/
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
 @pre formato de línea: año_publicacion;num_edicion;isbn;título;editorial;precio
 @pos Modifica los atributos del libro si linea contiene la información requerida
 @throw ExConversion si la línea CSV no tiene el formato adecuado
 @throw std::domain_error si algún dato para el libro no es válido*/
void Libro::fromCSV(std::string linea) {

    std::stringstream ss(linea);
    std::string lineaEjemplar,campo;
    int valor;
    
    //Primero leemos los datos específicos de un Libro
        std::getline(ss,campo,';');
        this->setAutor(campo); //el método SET es el responsable de comprobar la validez del dato

        ss >> valor;
        if (ss.fail())
            throw ExConversion("[Libro::fromCSV] el año del libro no es un número: "+linea);
        this->setAnioPublicacion(valor);
        ss.ignore(); //ignoramos siguiente ';'

        ss >> valor;
        if (ss.fail())
            throw ExConversion("[Libro::fromCSV] la edición del libro no es un número: "+linea);
        this->setEdicion(valor);
        ss.ignore();

        //Procesamos resto de la línea con los datos como Ejemplar
        std::getline(ss,lineaEjemplar);
        Ejemplar::fromCSV(lineaEjemplar);
}

/**Devuelve una copia en memoria dinámica del objeto
 @post la copia devuelta debe ser liberada por el llamador*/
Duplicable* Libro::copia() const{
    return new Libro(*this);
}
