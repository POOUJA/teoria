/** Interfaz para operación de obtener duplicado de un objeto de una clase
 * @file   Duplicable.h
 * @author jrbalsas@ujaen.es
 *
 * @date 16 de octubre de 2015, 11:00
 */

#ifndef DUPLICABLE_H
#define	DUPLICABLE_H

/** Interfaz para clases que permiten a sus objetos obtener copias de ellos mismos.
 La implementación de copia debe devolver una copia en memoria dinámica del objeto llamado.
 El llamador es responsable de liberar la memoria del objeto duplicado cuando ya no
 sea de utilidad.*/
class Duplicable {
public:
    /**Devuelve una copia en memoria dinámica del objeto
      @post La copia generada debe ser liberada por quién la solicita
    */
    virtual Duplicable* copia(void) const = 0;
    virtual ~Duplicable() {};
private:

};

#endif	/* DUPICABLE_H */

