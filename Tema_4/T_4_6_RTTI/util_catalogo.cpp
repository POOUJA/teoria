/** Implementación Utilidades para entrada/salida de elementos del catálogo por consola
 * @file   util_catalogo.cpp
 * @author jrbalsas@ujaen.es
 *
 * @date 18 de octubre de 2015
 */
#include "util_catalogo.h"
#include <iostream>

/**Visualiza todos los ejemplares de un catálogo*/
void utilCatalogo::visualiza(Catalogo &catalogo) {
    std::cout << std::endl  
              << "==============================" << std::endl
              << "ELEMENTOS DEL CATÁLOGO" << std::endl
              << "==============================" << std::endl;
    catalogo.iniciaIteracion();
    while (!catalogo.finalIteracion()) {
        utilCatalogo::visualiza(catalogo.siguienteEjemplar());
    }
}

/**Visualiza un ejemplar de forma adecuada según su tipo*/
void utilCatalogo::visualiza(Ejemplar& ejemplar) {
    //Usamos RTTI para determinar cómo se visualiza cada tipo de ejemplar
    //Se utiliza conversión a puntero para evitar capturar excepciones de conversión)
    if (dynamic_cast<Libro*>( &ejemplar )!=0) 
        visualiza(dynamic_cast<Libro&>( ejemplar ));
    else if (dynamic_cast<Revista*>( &ejemplar )!=0) 
        visualiza(dynamic_cast<Revista&>( ejemplar ));
    else {
        std::cout << "==============================" << std::endl;
        std::cout << "Ejemplar es de tipo desconocido:" << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "ID: "<< ejemplar.getID() << std::endl;
        std::cout << "Nombre: " << ejemplar.getTitulo() << std::endl;
        std::cout << "Precio: "<< ejemplar.getPrecio() << " euros" << std::endl;     
    }
}

/**Visualiza un ejemplar de forma adecuada según su tipo a partir de un puntero*/
void utilCatalogo::visualiza(Ejemplar* ejemplar) {
        visualiza(  *ejemplar  );
}

/**Visualiza un Libro en la salida estándar*/
void utilCatalogo::visualiza(Libro &libro) {
    std::cout << "==============================" << std::endl;
    std::cout << "LIBRO: " << libro.getTitulo() << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "Autor: " << libro.getAutor() << std::endl;
    std::cout << "Año de publicación:" << libro.getAnioPublicacion() << std::endl;
    std::cout << "Edición: " << libro.getEdicion() << std::endl;
    std::cout << "Editorial: " << libro.getEditorial() << std::endl;
    std::cout << "ISBN: " << libro.getIsbn() << std::endl;
    std::cout << "Precio: "<< libro.getPrecio() << " euros" << std::endl;     
}
/**Visualiza una Revista en la salida estándar*/
void utilCatalogo::visualiza(Revista &revista) {
    std::cout << "==============================" << std::endl;
    std::cout << "REVISTA: " << revista.getTitulo() << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "Editorial: " << revista.getEditorial() << std::endl;
    std::cout << "Año de publicación: " << revista.getAnio();
    std::cout << " Num: " << revista.getNumero() << std::endl;
    std::cout << "ISSN: " << revista.getISSN() << std::endl;
    std::cout << "Precio: "<< revista.getPrecio() << " euros" << std::endl;
}

