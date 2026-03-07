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
    std::string _titulo = "No especificado";
    std::string _editorial = "No especificada";
    float _precio = 0;
protected:
    std::string _identificador = "000000000";
public:
    Ejemplar() = default;

    Ejemplar(std::string identificador);;

    Ejemplar(std::string identificador, std::string titulo,
             std::string editorial, float precio);
    
    //Copia y asignación por defecto
    Ejemplar(const Ejemplar& orig) = default;
    virtual Ejemplar& operator=(const Ejemplar& orig) = default;
    
    virtual ~Ejemplar() noexcept;

    virtual void setID(std::string identificador)=0; //Método virtual puro
    std::string getID() const;
    void setPrecio(float precio);
    float getPrecio() const;
    void setEditorial(std::string editorial);
    std::string getEditorial() const;
    void setTitulo(std::string titulo);
    std::string getTitulo() const;
   
    virtual std::string toCSV() const override;
    virtual void fromCSV(std::string linea) override;

    virtual bool igualA(const Ejemplar& c) const;
    virtual bool operator==(const Ejemplar& c) const;

    virtual bool operator==(const std::string &identificador) const ;
    
private:
    

};

#endif	/* EJEMPLAR_H */

