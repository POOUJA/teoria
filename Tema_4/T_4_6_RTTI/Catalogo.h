/** Implementación de un catálogo de ejemplares
 * @file   Catalogo.h
 * @author jrbalsas@ujaen.es
 *
 * @date 16 de octubre de 2015, 10:45
 */

#ifndef CATALOGO_H
#define	CATALOGO_H

#include <string>
#include "Ejemplar.h"
#include "Libro.h"
#include "Revista.h"

/** Catálogo de ejemplares*/
class Catalogo {
public:
    static const int MAXEJEMPLARES = 100; /*< número máximo de ejemplares en el Catálogo*/
private:
    Ejemplar** ejemplares; /*< Vector de punteros a ejemplares del catálogo*/
    unsigned int _numEjemplares; /*< Número de ejemplares en el catálogo*/
    unsigned int _posIteracion; /*< Elemento del catálogo sobre el que itera el usuario*/
public:
    Catalogo();
    Catalogo(const Catalogo& orig);
    virtual ~Catalogo();
    
    void nuevoLibro(const Libro &libro);
    void nuevaRevista(const Revista &revista);
    void nuevoEjemplar(const Ejemplar &ejemplar);
    
    void borraEjemplar(std::string idEjemplar);
    Ejemplar& buscaEjemplar(std::string idEjemplar);
    Ejemplar& ejemplarAlAzar();
    void guardaEnFichero(std::string nombreFichero) throw (std::runtime_error);
    void recuperaDeFichero(std::string nombreFichero ) throw (std::runtime_error,std::logic_error);
    int getNumEjemplares() const;
    void vaciar();
    
    //Métodos para iteración
    void iniciaIteracion();
    Ejemplar& siguienteEjemplar() throw (std::out_of_range);
    bool finalIteracion();
    
private:
};

#endif	/* CATALOGO_H */

