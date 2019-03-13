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
    std::string _autor            = "Desconocido";
    unsigned int _edicion         = 1;
    unsigned int _anioPublicacion = 0;
    
public:
    Libro() = default;
    Libro(std::string isbn, std::string titulo, unsigned int anio,
          unsigned int edicion, std::string autor, 
          std::string editorial, float precio);
        
    //Copia y asignación por defecto
    Libro(const Libro& orig) = default;
    virtual Libro& operator=(const Libro& orig) = default;
    
    virtual ~Libro() noexcept;
    void setAnioPublicacion(unsigned int anioPublicacion);
    unsigned int getAnioPublicacion() const;
    void setEdicion(unsigned int edicion);
    unsigned int getEdicion() const;
    virtual void setID(std::string isbn) override;
    void setIsbn(std::string _isbn);
    std::string getIsbn() const;
    void setAutor(std::string _autor);
    std::string getAutor() const;

    virtual std::string toCSV() const override;
    virtual void fromCSV(std::string linea) override;

    //Interfaz Duplicable
    virtual Duplicable* copia() const override;
    
private:

};

#endif	/* LIBRO_H */

