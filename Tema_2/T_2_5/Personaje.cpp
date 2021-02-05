/**
 * @brief
 * @file Personaje.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 22 de septiembre de 2015, 11:01
 */

#include "Personaje.h"

/**
 * @brief Constructor por defecto de la clase
 * @param nombre Nombre del personaje
 */
Personaje::Personaje(std::string nombre, std::string* apellidoFamilia):
    nombre(nombre),
    apellidoFamilia(apellidoFamilia) {
}
/**
 * @brief Constructor por defecto
 */
Personaje::Personaje():
    Personaje("",nullptr) {  //Llamada a constructor parametrizado
}
/**
 * @brief Constructor parametrizado (solo nombre)
 */
Personaje::Personaje(std::string nombre):
    Personaje(nombre,nullptr) {
}

/**
 * @brief Constructor de copia, PRRIMERA VERSION: Se copian las direcciones de los punteros
 * @param orig Objeto cuyos datos se van a copiar
 */
Personaje::Personaje(const Personaje& orig) : // Si quieres usar este costructor de copia debes poner entre comentarios el de abajo
nombre(orig.nombre)
, apellidoFamilia(orig.apellidoFamilia) {
}

/**
 * @brief Constructor de copia, SEGUNDA VERSION: Se duplica el objeto apuntado
 * @param orig Objeto cuyos datos se van a copiar
 */

/*
Personaje::Personaje(const Personaje& orig) : // Si quieres usar este constructor de copia, debes poner entre comentarios el de arriba
nombre(orig.nombre)
, apellidoFamilia(0) {
    apellidoFamilia = new std::string;
 *apellidoFamilia = *orig.apellidoFamilia;
}
 */

/**
 *  @brief Destructor de clase, asociado a la SEGUNDA VERSION del constructor de copia
 * @post Destruye el objeto
 */
Personaje::~Personaje() {
}

/**
 * @brief Modifica el nombre del personaje
 * @param nombre Nuevo nombre para la familia
 * @post Modifica el nombre del personaje
 */
void Personaje::SetNombre(std::string nombre) {
    this->nombre = nombre;
}

/**
 * @brief Devuelve el nombre del personaje
 * @post Devuelve el nombre del personaje
 */
std::string Personaje::GetNombre() const {
    return nombre;
}

/**
 * @brief Modifica el valor del atributo apellidoFamilia
 * @param apellidoFamilia Nueva familia para el personaje
 * @post  Modifica el valor del atributo apellidoFamilia
 */
void Personaje::SetApellidoFamilia(std::string* apellidoFamilia) {
    this->apellidoFamilia = apellidoFamilia;
}

/**
 * @brief Devuelve una referencia a la familia a la que pertenece el personaje
 * @post Devuelve una referencia a la familia a la que pertenece el personaje
 */
std::string* Personaje::GetApellidoFamilia() const {
    return apellidoFamilia;
}

