/** Definición de excepción lógica para fallos de conversión de datos
 * @file   ExConversion.h
 * @author jrbalsas@ujaen.es
 *
 * @date 16 de octubre de 2015
 */

#ifndef EXCONVERSION_H
#define	EXCONVERSION_H

#include <stdexcept>
#include <string>

/**Excepción para indicar un problema en la conversión de algún valor*/
class ExConversion: public std::logic_error {
public:
    ExConversion(std::string error="[ExConversion] Fallo en conversión de datos"):std::logic_error(error) {};
    ExConversion(const ExConversion& orig):logic_error(orig) {};
    virtual ~ExConversion() throw() {};
private:

};

#endif	/* NOENCONTRADO_H */

