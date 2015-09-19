/**
 * @brief  Definición de una clase con métodos inline
 *        Ejemplo T_2_4, de la Teoría de Prog. Orientada a Objetos
 *        del curso 2015-2016.
 * @file GaticoDeFeisbus.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 *
 * @date 19 de septiembre de 2015, 11:36
 */


#include "GaticoDeFeisbus.h"

/**
 * @brief Constructor parametrizado
 * @post Crea un nuevo objeto inicializando su estadoa 0
 */
GaticoDeFeisbus::GaticoDeFeisbus() :
numMeGusta(0) {
}

/**
 * @brief Constructor de copia
 * @param orig Objeto del cual se van a copiar los datos
 * @post Crea un nuevo objeto copiando los valores desde el objeto orig
 */
GaticoDeFeisbus::GaticoDeFeisbus(const GaticoDeFeisbus& orig) :
numMeGusta(orig.numMeGusta) {
}

/**
 * @brief Destructor
 * @post Destruye el objeto
 */
GaticoDeFeisbus::~GaticoDeFeisbus() {
}

/**
 * @brief Devuelve el valor del atributo numMeGusta
 * @post Devuelve el valor del atributo numMeGusta
 */
int GaticoDeFeisbus::GetNumMeGusta() const {
    return this->numMeGusta;
}

