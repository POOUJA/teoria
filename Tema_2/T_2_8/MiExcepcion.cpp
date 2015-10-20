/** 
 * @brief Implmentación de los métodos de la clase MiExcepcion
 * @file MiExcepcion.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 28 de septiembre de 2015, 11:01
 */

#include "MiExcepcion.h"

/**
 * @brief Constructor por defecto de la clase
 * @param texto Explicación de la excepción
 * @post Crea un objeto de la clase MiExcepcion
 */
MiExcepcion::MiExcepcion(std::string texto) :
texto(texto) {
}

/**
 * @brief Constructor de copia
 * @param orig Objeto cuyos datos se van a copiar
 */
MiExcepcion::MiExcepcion(const MiExcepcion& orig) :
texto(orig.texto) {
}

/**
 * @brief Destructor de clase
 * @post Destruye el objeto
 */
MiExcepcion::~MiExcepcion() {
}

/**
 * @brief Modifica el texto de la excepción
 * @param texto Nuevo texto para la excepción
 * @post Modifica el texto de la excepción
 */
void MiExcepcion::SetTexto(std::string texto) {
    this->texto = texto;
}

/**
 * @brief Devuelve el texto de la excepción
 * @post Devuelve el texto de la excepción
 */
std::string MiExcepcion::GetTexto() const {
    return texto;
}

