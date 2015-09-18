/**
 * @brief Definición de una clase. 
 *        Ejemplo T_2_1, de la Teoría de Prog. Orientada a Objetos
 *        del curso 2015-2016.
 * @file Circulo.h
 * @author vrivas
 *
 * @date 17 de septiembre de 2015, 18:29
 */

#ifndef CIRCULO_H
#define	CIRCULO_H

// ATENCIÓN:
// Esta declaración de la clase se ha simplificado mucho por motivos pedagógicos.
// Para ver una declaración completa de una clase, mira el ejemplo T_3_3

class Circulo {
public:
	Circulo();
        void SetRadio( double nuevoRadio );
        double GetRadio();
private:
        double radio;

};
#endif	/* CIRCULO_H */

