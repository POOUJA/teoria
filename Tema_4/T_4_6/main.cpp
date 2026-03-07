/** Programa de ejemplo de uso de RTTI
 * @file   main.cpp
 * @author jrbalsas@ujaen.es
 *
 * @date 4 de noviembre de 2015
 */

//TODO COMENTARIOS SOBRE USO DE RTTI Y DOWNCASTING
//TODO ¿Pruebas de ordenación o iteración?

#include <cstdlib>
#include <iostream>
#include <fstream>

#include "Catalogo.h"
#include "Libro.h"
#include "Revista.h"
#include "busqueda.h"
#include "ExNoEncontrado.h"
#include "ExConversion.h"
#include "util_catalogo.h"

const std::string FICHEROCATALOGO="catalogo.csv"; /*< Fichero donde se almacenan/recuperan los ejemplares del catálogo*/

/**Inicializamos un catálogo con algunos ejemplares de prueba*/
void inicializa(Catalogo &catalogo) {

    try {
        catalogo.nuevoEjemplar( Libro("9786071512123","Programación en C/C++, Java y UML",
                                2014,2,"Luís Joyanes Aguilar", "MacGraw-Hill", 42) );
        catalogo.nuevoEjemplar( Libro("8497320409","C++ Estandar",
                                2001,1,"Enrique Hernández Orallo","Paraninfo",12) );
        catalogo.nuevoEjemplar( Revista("ISSN 1234-56789","Bike",2015,10,"Motorpress",3.50) );
        catalogo.nuevoEjemplar( Revista("ISSN 1130-40810","Muy Interesante",2015,11,"G+J",3) );
        catalogo.nuevoEjemplar( Libro("8499893740","La mano de Fatima",
                                        2012,1,"Falcon, I.","De bolsillo",9.46) ) ;
        std::cout << "Catálogo inicializado" << std::endl << std::endl;
    } catch (std::exception &e) {
        //TODO capturar excepciones 
        std::cerr << "Ha ocurrido un error al preparar el catálogo: "
                  << e.what() << std::endl;
        throw e;  //Consideramos que La excepción no es recuperable
    }
        
}

/**
 * Ejemplo de prueba clases Catálogo
 */
int main(int argc, char** argv) {
    
    Catalogo catalogo;
    
    inicializa(catalogo);
    
    utilCatalogo::visualiza(catalogo);
    

    //Pruebas de búsqueda correcta y visualización
    try {
        utilCatalogo::visualiza( catalogo.ejemplarAlAzar() );    
        utilCatalogo::visualiza( catalogo.buscaEjemplar("8497320409") );        
    } catch (std::exception &e) {
        std::cerr << "Error en programa principal: "
                  << e.what();
    }

    //Prueba de búsqueda sin éxito
    std::string idBusqueda="2222222222"; //ejemplar no existente
    
    try {
        utilCatalogo::visualiza( catalogo.buscaEjemplar(idBusqueda) );        
    } catch (std::exception &e) {
        std::cerr << "El ejemplar  "+idBusqueda
                  << " no se encuentra disponible" << std::endl;
    };
    
    //Prueba de volcado y recuperación a fichero CSV    
    try {
        std::cout << std::endl << "Volcando catálogo en fichero " << FICHEROCATALOGO << std::endl;
        catalogo.guardaEnFichero(FICHEROCATALOGO);

        std::cout << std::endl << "Vaciámos catálogo original " << std::endl;
        catalogo.vaciar();

        std::cout << std::endl << "Cargamos catálogo desde fichero " << FICHEROCATALOGO << std::endl;

        catalogo.recuperaDeFichero(FICHEROCATALOGO);
        std::cout << "Recuperados " << catalogo.getNumEjemplares() 
                  << " Ejemplares del fichero " << FICHEROCATALOGO << std::endl;

        try {
            idBusqueda="8497320409"; //Debería estar en el catálogo original almacenado
            utilCatalogo::visualiza( catalogo.buscaEjemplar(idBusqueda) );        
        } catch (ExNoEncontrado &e) {
            std::cerr << "El ejemplar  "+idBusqueda
                      << " no se encuentra disponible" << std::endl;
        }
    } catch (std::exception &e){
        std::cerr << "[main] Error al recuperar catálogo de disco. " << e.what();
        throw e; //Error irrecuperable. Terminamos la aplicación
    }

    //Prueba de copia del catálogo
    std::cout << "Duplicamos el catálogo original" << std::endl;
    Catalogo catalogoCopia(catalogo);
    
    //Prueba de borrado de elementos del catálogo copia
    try {
        idBusqueda="ISSN 1234-56789"; //Revista bike
        catalogoCopia.borraEjemplar(idBusqueda); 
        std::cout << std::endl << "Probamos a borrar un ejemplar no existente " << std::endl;
        catalogoCopia.borraEjemplar(idBusqueda); //No existente!
    } catch (ExNoEncontrado &e) {
        std::cerr << "El ejemplar  "+idBusqueda
                  << " no se encuentra disponible en la copia del catálogo" << std::endl;
    } 

    try {
        idBusqueda="ISSN 1234-56789"; //Revista bike
        //La revista sí debe estar en el catálogo original
        utilCatalogo::visualiza( catalogo.buscaEjemplar(idBusqueda) );        
    } catch (ExNoEncontrado &e) {
        std::cerr << "El ejemplar  "+idBusqueda
                  << " no se encuentra disponible" << std::endl;
    } 
    
    std::cout   << std::endl << "Saliendo de programa principal"
                << std::endl << std::endl;
    
    return 0;
}
