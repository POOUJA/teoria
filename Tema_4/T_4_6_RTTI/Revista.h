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

class Revista: public Ejemplar {
private:
    unsigned int _numero;
    unsigned int _anio;
public:
  
    Revista( std::string ISSN="ISSN 0000-0000",  std::string titulo="Sin titulo",
             unsigned int anio=1800, unsigned int numero=0,
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
    
    //Interfaz Duplicable
    virtual Duplicable* copia() const;

private:

};

#endif	/* REVISTA_H */

