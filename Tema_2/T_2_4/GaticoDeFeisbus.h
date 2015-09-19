/**
 * @brief  Definición de una clase. 
 *        Ejemplo T_2_4, de la Teoría de Prog. Orientada a Objetos
 *        del curso 2015-2016.
 * @file GaticoDeFeisbus.h
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 *
 * @date 19 de septiembre de 2015, 11:36
 */

#ifndef GATICODEFEISBUS_H
#define	GATICODEFEISBUS_H

/**
 * @brief Clase GaticoDeFeisbus. Ejemplo T_2_4 de Teoría
 */

class GaticoDeFeisbus {
public:
    GaticoDeFeisbus();
    GaticoDeFeisbus(const GaticoDeFeisbus& orig);
    ~GaticoDeFeisbus();
    void megusta() {           // Método inline
        ++this->numMeGusta;
    };
    int GetNumMeGusta() const;
private:
    
    /// Número de "Me gusta" que ha recibido.
    int numMeGusta;
};

#endif	/* GATICODEFEISBUS_H */

