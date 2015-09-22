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
Personaje::Personaje(std::string nombre, Familia* suFamilia) :
nombre(nombre)
, suFamilia(suFamilia) {
}

/**
 * @brief Constructor de copia, PRRIMERA VERSION: Se copian las direcciones de los punteros
 * @param orig Objeto cuyos datos se van a copiar
 */
Personaje::Personaje(const Personaje& orig) : // Si quieres usar este costructor de copia debes poner entre comentarios el de abajo, y también el destructor que lleva asociado
nombre(orig.nombre) 
, suFamilia(orig.suFamilia) {
}

/**
 * @brief Destructor de clase, asociado a la PRIMERA VERSION del constructor de copia
 */
Personaje::~Personaje() {
}


/**
 * @brief Constructor de copia, SEGUNDA VERSION: Se duplica el objeto apuntado
 *        ¡IMPORTANTE! Si la usas, debes usar también el destructor denominado SEGUNDA VERSION
 * @param orig Objeto cuyos datos se van a copiar
 */

/*
Personaje::Personaje(const Personaje& orig) :  // Si quieres usar este constructor de copia, debes poner entre comentarios el de arriba y también el destructor que lleva asociado
nombre(orig.nombre)
, suFamilia(0)
{
    suFamilia=new Familia( *orig.suFamilia );
}
 */

/**
 * @brief Destructor de clase, asociado a la SEGUNDA VERSION del constructor de copia
 */
/*
Personaje::~Personaje() {
    if( suFamilia ) delete suFamilia;
}
 */

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
 * @brief Modifica el valor del atributo suFamilia
 * @param suFamilia Nueva familia para el personaje
 * @post  Modifica el valor del atributo suFamilia
 */
void Personaje::SetSuFamilia(Familia* suFamilia) {
    this->suFamilia = suFamilia;
}

/**
 * @brief Devuelve una referencia a la familia a la que pertenece el personaje
 * @post Devuelve una referencia a la familia a la que pertenece el personaje
 */
Familia* Personaje::GetSuFamilia() const {
    return suFamilia;
}

