/* 
 * File:   Familia.h
 * Author: Victor M. Rivas Santos <vrivas@ujaen.es>
 *
 * Created on 22 de septiembre de 2015, 11:01
 */

#ifndef FAMILIA_H
#define	FAMILIA_H

#include <string>

class Familia {
public:
    Familia( std::string apellido="" );
    Familia(const Familia& orig);
    virtual ~Familia();
    void SetApellido(std::string apellido);
    std::string GetApellido() const;
private:
    std::string apellido;
};

#endif	/* FAMILIA_H */

