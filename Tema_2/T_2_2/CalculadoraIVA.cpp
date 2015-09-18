/**
 * @brief  Definición de una clase. 
 *        Ejemplo T_2_2, de la Teoría de Prog. Orientada a Objetos
 *        del curso 2015-2016.
 * @file CalculadoraIVA.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 *
 * @date 18 de septiembre de 2015, 11:36
 */



// ATENCIÓN:
// Esta declaración de la clase se ha simplificado mucho por motivos pedagógicos.
// Para ver una declaración completa de una clase, mira el ejemplo T_3_3


#include "CalculadoraIVA.h"

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


