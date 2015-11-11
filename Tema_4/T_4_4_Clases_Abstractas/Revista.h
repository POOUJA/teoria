/** Definición de clase Revista
 * @file   Revista.h
 * @author jrbalsas@ujaen.es
 *
 * @date 9 de octubre de 2015, 13:40
 */

#ifndef REVISTA_H
#define	REVISTA_H
#include "Ejemplar.h"

class Revista: public Ejemplar {
private:
    unsigned int _numero;
    unsigned int _anio;
public:
  
    Revista( std::string ISSN="",  std::string titulo="Sin titulo",
             unsigned int anio=0, unsigned int numero=0,
             std::string editorial="Sin especificar", float precio=0);

    Revista(const Revista& orig);
    virtual ~Revista();
    void setAnio(unsigned int _anio);
    unsigned int getAnio() const;
    void setNumero(unsigned int _numero);
    unsigned int getNumero() const;
    void setISSN(std::string issn);
    std::string getISSN() const;

    //Interfaz ItemCSV
    virtual std::string toCSV() const;
    virtual void fromCSV(std::string linea);

    //Implementación de método vitual puro de clase abstracta Ejemplar
    virtual void setID(std::string identificador);
    
private:

};

#endif	/* REVISTA_H */

