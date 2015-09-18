/**
 * @brief  Definición de una clase. 
 *        Ejemplo T_2_2, de la Teoría de Prog. Orientada a Objetos
 *        del curso 2015-2016.
 * @file CalculadoraIVA.h
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 *
 * @date 18 de septiembre de 2015, 11:36
 */


// ATENCIÓN:
// Esta declaración de la clase se ha simplificado mucho por motivos pedagógicos.
// Para ver una declaración completa de una clase, mira el ejemplo T_3_3

#ifndef CALCULADORAIVA_H
#define	CALCULADORAIVA_H

/**
 * @brief Clase CalculadoraIVA. Ejemplo T_2_2 de teoría
 * @param porcentaje  Porcentaje de IVA a aplicar
 */
class CalculadoraIVA {
public:
    CalculadoraIVA(double unPorcentaje);
    double aplicar(double precio);
private:
    double porcentaje;

};

#endif	/* CALCULADORAIVA_H */

