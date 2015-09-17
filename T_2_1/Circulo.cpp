/* 
 * File:   Circulo.cpp
 * Author: vrivas
 * 
 * Created on 17 de septiembre de 2015, 18:29
 */

#include "Circulo.h"

Circulo::Circulo():
 radio(0) {
}

void Circulo::SetRadio( double nuevoRadio ) {
    radio=nuevoRadio;
}

double Circulo::GetRadio() {
    return radio;
}

