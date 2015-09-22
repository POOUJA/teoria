/* 
 * File:   Personaje.h
 * Author: Victor M. Rivas Santos <vrivas@ujaen.es>
 *
 * Created on 22 de septiembre de 2015, 11:01
 */

#ifndef PERSONAJE_H
#define	PERSONAJE_H

#include <string>
#include "Familia.h"

/**
 * @brief Clase para almacenar los datos de cada personaje de la serie
 * @param nombre Nombre del personaje
 * @param suFamilia Referencia a un objeto de tipo Familia, al cual el personaje pertenece
 */
class Personaje {
public:
    Personaje(std::string nombre = "", Familia* suFamilia = 0);
    Personaje(const Personaje& orig);
    virtual ~Personaje();
    void SetNombre(std::string nombre);
    std::string GetNombre() const;
    void SetSuFamilia(Familia* suFamilia);
    Familia* GetSuFamilia() const;
private:
    std::string nombre;
    Familia *suFamilia;
};

#endif	/* PERSONAJE_H */

