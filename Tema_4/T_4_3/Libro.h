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
    Libro(std::string isbn="",std::string titulo="Sin titulo", unsigned int anio=0, unsigned int edicion=1, std::string autor="Desconocido", std::string editorial="No especificada", float precio=0);
    Libro(const Libro& orig);
    virtual ~Libro();
    void setAnioPublicacion(unsigned int _anioPublicacion);
    unsigned int getAnioPublicacion() const;
    void setEdicion(unsigned int _edicion);
    unsigned int getEdicion() const;
    void setIsbn(std::string _isbn);
    std::string getIsbn() const;
    void setAutor(std::string _autor);
    std::string getAutor() const;

    virtual std::string toCSV() const;
    virtual void fromCSV(std::string linea);
    
private:
    int a;
};

#endif	/* LIBRO_H */

