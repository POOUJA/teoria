/**
 * @brief  Definición de una clase. 
 *        Ejemplo T_2_3, de la Teoría de Prog. Orientada a Objetos
 *        del curso 2015-2016.
 * @file Gol.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 *
 * @date 18 de septiembre de 2015, 11:36
 */


#include "Gol.h"

/**
 * @brief Constructor parametrizado
 * @param elJugador Nombre del jugador que mete el gol
 * @param elMinuto Minuto en que se mete gol
 * @post Crea un nuevo objeto con los valores indicados
 */
Gol::Gol(const std::string elJugador, const int elMinuto) :
jugador(elJugador)
, minuto(elMinuto) {
}

/**
 * @brief Constructor de copia
 * @param orig Objeto del cual se van a copiar los datos
 * @post Crea un nuevo objeto copiando los valores desde el objeto orig
 */
Gol::Gol(const Gol& orig) :
jugador(orig.jugador)
, minuto(orig.minuto) {
}

/**
 * @brief Destructor
 * @post Destruye el objeto
 */
Gol::~Gol() {
}

/**
 * @brief modifica el valor del atributo minuto
 * @param minuto Nuevo valor para el atributo
 * @post El valor del atributo queda modificado
 */
void Gol::SetMinuto(int minuto) {
    if (minutoEsCorrecto(minuto)) {
        this->minuto = minuto;
    }
}

/**
 * @brief Devuelve el valor del atributo minuto
 * @post Devuelve el valor del atributo minuto
 */
int Gol::GetMinuto() const {
    return this->minuto;
}

/**
 * @brief modifica el valor del atributo jugador
 * @param jugador Nuevo valor para el atributo
 * @post El valor del jugador queda modificado
 */
void Gol::SetJugador(std::string jugador) {
    this->jugador = jugador;
}

/**
 * @brief Devuelve el valor del atributo jugador
 * @post Devuelve el valor del atributo jugador
 */
std::string Gol::GetJugador() const {
    return this->jugador;
}

/**
 * @brief Comprueba si el valor que se pasa del minuto en que se marca un gol es correcto o no.
 * @param minuto Valor del minuto que se quiere comprobar
 * @post Devuelve true si el minuto está entre 0 y 120, false en otro caso 
 */
bool Gol::minutoEsCorrecto(int minuto) const {
    if (minuto >= 0 && minuto <= 120) { // 90'+30' de prórroga
        return true;
    } else {
        return false;
    }
    // Más breve: return ( minuto>=0 && minuto<=120 );
}