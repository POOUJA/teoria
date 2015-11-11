/** Definición clase para representar cualquier ejemplar de un catálogo
 * @file   Ejemplar.h
 * @author jrbalsas@ujaen.es
 *
 * @date 9 de octubre de 2015, 12:55
 */

#ifndef EJEMPLAR_H
#define	EJEMPLAR_H

#include <string>
#include "ItemCSV.h"
#include "ExConversion.h"

/** Clase para cualquier ejemplar de un catálogo de una biblioteca*/
class Ejemplar: public ItemCSV {
private:
    std::string _titulo;
    std::string _editorial;
    float _precio;
protected:
    std::string _identificador;
public:
    Ejemplar(std::string identificador="000000000", std::string titulo="No especificado",
             std::string editorial="No especificada", float precio=0) throw (std::domain_error);
    Ejemplar(const Ejemplar& orig);
    virtual ~Ejemplar();

    virtual void setID(std::string identificador)=0; //Método virtual puro
    std::string getID() const;
    void setPrecio(float precio);
    float getPrecio() const;
    void setEditorial(std::string editorial);
    std::string getEditorial() const;
    void setTitulo(std::string titulo);
    std::string getTitulo() const;
   
    virtual std::string toCSV() const;
    virtual void fromCSV(std::string linea) throw (ExConversion,std::domain_error);

    virtual bool igualA(const Ejemplar& c) const;
    virtual bool operator==(const Ejemplar& c) const;

    virtual bool operator==(const std::string &identificador) const ;
    
private:
    

};

#endif	/* EJEMPLAR_H */

