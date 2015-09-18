/** 
 * @brief
 * @file CalculadoraIVA.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 18 de septiembre de 2015, 11:36
 */

#include "CalculadoraIVA.h"

double aplicaIVA(double precio);

/**
 * @brief Constructor de clase
 * @brief unPorcentaje Valor para inicializar el porcentaje
 */
CalculadoraIVA::CalculadoraIVA(double unPorcentaje) :
porcentaje(unPorcentaje) {
}

/**
 * 
 * @param precio Precio al que queremos aplicar el IVA
 * @post Devuelve el valor correspondiente a aplicar el Iva a ese precio
 */
double CalculadoraIVA::aplicar(double precio) {
    return precio*porcentaje/100;
}


