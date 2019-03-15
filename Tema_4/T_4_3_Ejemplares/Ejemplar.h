/** Definición clase para representar cualquier ejemplar de un catálogo
 * @file   Ejemplar.h
 * @author jrbalsas@ujaen.es
 *
 * @date 9 de octubre de 2015, 12:55
 */

#ifndef EJEMPLAR_H
#define	EJEMPLAR_H

#include <string>

/** Clase para cualquier ejemplar de un catálogo de una biblioteca*/
class Ejemplar {
private:
    std::string _titulo = "No especificado";
    std::string _editorial = "No especificada";
    std::string _identificador = "000000000";
    float _precio = 0;

public:
    Ejemplar() = default;
    Ejemplar(std::string identificador);;
    Ejemplar(std::string identificador, std::string titulo,
             std::string editorial, float precio);

    //Copia y asignación por defecto
    Ejemplar(const Ejemplar& orig) = default;
    virtual Ejemplar& operator=(const Ejemplar& orig) = default;
    
    virtual ~Ejemplar() noexcept;

    void setID(std::string identificador);
    std::string getID() const;
    void setPrecio(float precio);
    float getPrecio() const;
    void setEditorial(std::string editorial);
    std::string getEditorial() const;
    void setTitulo(std::string titulo);
    std::string getTitulo() const;
   
    virtual std::string toCSV() const;
    virtual void fromCSV(std::string linea);

    virtual bool operator==(const Ejemplar& c) const;
    virtual bool operator==(const std::string &identificador) const ;
    
    
private:
    

};

#endif	/* EJEMPLAR_H */

