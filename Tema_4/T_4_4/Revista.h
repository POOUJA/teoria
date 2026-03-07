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
    unsigned int _numero = 0;
    unsigned int _anio = 1800;
public:
    Revista() = default; 
    Revista(std::string issn);

    Revista( std::string ISSN,  std::string titulo,
             unsigned int anio, unsigned int numero,
             std::string editorial, float precio);
  
    //Copia y asignación por defecto
    Revista(const Revista& orig) = default;
    virtual Revista& operator=(const Revista& orig) = default;

    virtual ~Revista() noexcept override;
    void setAnio(unsigned int _anio);
    unsigned int getAnio() const;
    void setNumero(unsigned int _numero);
    unsigned int getNumero() const;
    void setISSN(std::string issn);
    std::string getISSN() const;

    //Interfaz ItemCSV
    virtual std::string toCSV() const override;
    virtual void fromCSV(std::string linea) override;

    //Implementación de método vitual puro de clase abstracta Ejemplar
    virtual void setID(std::string identificador) override;
    
private:

};

#endif	/* REVISTA_H */

