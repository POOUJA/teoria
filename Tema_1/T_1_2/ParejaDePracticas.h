/* 
 * File:   ParejaDePracticas.h
 * Author: Victor M. Rivas Santos <vrivas@ujaen.es>
 *
 * Created on 11 de enero de 2016, 22:20
 */

#ifndef PAREJADEPRACTICAS_H
#define	PAREJADEPRACTICAS_H
#include <string>
/**
 * Clase que permite guardar los datos del compañero/a que es mi pareja de prácticas en una asignatura
 */
class ParejaDePracticas {
public:
    /**
     * Constructor por defecto de la clase
     */
    ParejaDePracticas();
    /**
     * Constructor de copia
     * @param orig Objeto original
     */
    ParejaDePracticas(const ParejaDePracticas& orig);
    /**
     * Destructor
     */
    virtual ~ParejaDePracticas();
    /**
     * Establece el valor para el email
     * @param email Nuevo valor para el email
     * @trhows String si el nuevo valor es vacío
     */
    void setEmail(std::string email);
    /**
     * Devuelve el valor del email
     * @return Valor del email
     */
    std::string getEmail() const;
    /**
     * Establece el valor para el telefono
     * @param telefono Nuevo valor para el telefono
     * @trhows String si el nuevo valor es vacío
     */
    void setTelefono(std::string telefono);
    
    /**
     * Devuelve el valor del telefono
     * @return El valor del telefono
     */
    std::string getTelefono() const;
    
    /**
     * Establece el valor para el nombre
     * @param nombre Nuevo valor para el nombre
     * @trhows String si el nuevo valor es vacío
     */
    void setNombre(std::string nombre);
    
    /**
     * Devuelve el valor del nombre
     * @return El valor del nombre
     */    
    std::string getNombre() const;
    
    /**
     * Devuelve los datos de la pareja de prácticas en una sola cadena
     * @return Datos de la pareja de prácticas
     */
    std::string concatenar() const;
private:
    /// Nombre de mi compaÒero/a
    std::string nombre;

    /// Teléfono
    std::string telefono;

    /// Email
    std::string email;
};

#endif	/* PAREJADEPRACTICAS_H */

