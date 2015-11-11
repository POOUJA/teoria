/** Definición de la especialización de Ejemplar: Libro
 * @file   Libro.h
 * @author jrbalsas@ujaen.es
 *
 * @date 9 de octubre de 2015, 13:16
 */

#ifndef LIBRO_H
#define	LIBRO_H

#include "Ejemplar.h"

class Libro: public Ejemplar {
private:
    std::string _autor;
    unsigned int _edicion;
    unsigned int _anioPublicacion;
    
public:
    Libro(std::string isbn="0000000000",std::string titulo="Sin titulo", unsigned int anio=0,
          unsigned int edicion=1, std::string autor="Desconocido", 
          std::string editorial="No especificada", float precio=0)
            throw (std::domain_error);
    Libro(const Libro& orig);
    virtual ~Libro();
    void setAnioPublicacion(unsigned int anioPublicacion);
    unsigned int getAnioPublicacion() const;
    void setEdicion(unsigned int edicion);
    unsigned int getEdicion() const;
    virtual void setID(std::string isbn) throw (std::domain_error);
    void setIsbn(std::string _isbn) throw (std::domain_error);
    std::string getIsbn() const;
    void setAutor(std::string _autor);
    std::string getAutor() const;

    virtual std::string toCSV() const;
    virtual void fromCSV(std::string linea) throw (ExConversion,std::domain_error);

    //Interfaz Duplicable
    virtual Duplicable* copia() const;
    
private:

};

#endif	/* LIBRO_H */

