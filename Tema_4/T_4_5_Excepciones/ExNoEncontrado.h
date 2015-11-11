/** Definición de excepción lógica
 * @file   ExNoEncontrado.h
 * @author jrbalsas
 *
 * @date 16 de octubre de 2015, 9:33
 */

#ifndef NOENCONTRADO_H
#define	NOENCONTRADO_H

#include <stdexcept>
#include <string>

/**Excepción para indicar ausencia de elementos en búsquedas*/
class ExNoEncontrado: public std::logic_error {
public:
    ExNoEncontrado(std::string error="[NoEncontrado] Elemento no disponible"):std::logic_error(error) {};
    ExNoEncontrado(const ExNoEncontrado& orig):logic_error(orig) {};
    virtual ~ExNoEncontrado() throw() {};
private:

};

#endif	/* NOENCONTRADO_H */

