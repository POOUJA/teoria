/* 
 * File:   MiExcepcion.h
 * Author: Victor M. Rivas Santos <vrivas@ujaen.es>
 *
 * Created on 28 de septiembre de 2015, 11:01
 */

#ifndef MIEXCEPCION_H
#define	MIEXCEPCION_H

#include <string>

/**
 * @brief Clase para almacenar una excepción, con un mensaje asociado
 * @param texto Texto de la excepción
 */
class MiExcepcion {
public:
    MiExcepcion() = default;
    MiExcepcion(std::string texto );
    MiExcepcion(const MiExcepcion& orig);
    virtual ~MiExcepcion();
    void SetTexto(std::string texto);
    std::string GetTexto() const;

private:
    /// Texto explicatorio de la excepción
    std::string texto="";
};

#endif	/* MIEXCEPCION_H */

