/** Definición de clase Revista
 * @file   Revista.h
 * @author jrbalsas@ujaen.es
 *
 * @date 9 de octubre de 2015, 13:40
 */

#ifndef REVISTA_H
#define	REVISTA_H
#include "Ejemplar.h"
#include "ExConversion.h"

/**Clase especialización de Ejemplar para representar una Revista del catálogo*/
class Revista: public Ejemplar {
private:
    unsigned int _numero; /*< Número de la revista*/
    unsigned int _anio; /*< Año de publicación de la revista*/
public:
  
    Revista( std::string ISSN="ISSN 0000-0000",  std::string titulo="Sin titulo",
             unsigned int anio=0, unsigned int numero=0,
             std::string editorial="Sin especificar", float precio=0)
                throw (std::domain_error);
    Revista(const Revista& orig);
    virtual ~Revista();
    void setAnio(unsigned int _anio);
    unsigned int getAnio() const;
    void setNumero(unsigned int _numero);
    unsigned int getNumero() const;
    virtual void setID(std::string issn) throw (std::domain_error);
    void setISSN(std::string issn) throw (std::domain_error);
    std::string getISSN() const;

    //Interfaz ItemCSV
    virtual std::string toCSV() const;
    virtual void fromCSV(std::string linea) throw (ExConversion,std::domain_error);

private:

};

#endif	/* REVISTA_H */

