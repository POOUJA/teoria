/** Programa de ejemplo de uso de Clases abstractas e Interfaces
 * @file   main.cpp
 * @author jrbalsas@ujaen.es
 *
 * @date 4 de noviembre de 2015
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Libro.h"
#include "Revista.h"
#include "busqueda.h"

const int NUMEJEMPLARES=4; /*< Tamaño del vector de ejemplares*/
const std::string FICHEROEJEMPLARES="ejemplares.csv"; /*< Fichero donde se almacenan/recuperan los ejemplares*/

/**Visualiza elementos que implementan la Interfaz CSV*/
void Visualiza(const ItemCSV &item ) {
    //Polimorfismo de objetos mediante referencias en paso de parámetro
    //El método sólo conoce el tipo de objetos por el comportamiento que ofrecen de la interfaz
    //Polimorfismo de método en llamada a método según el tipo de ejemplar (enlace dinámico)
    std::cout << item.toCSV();
}

/**Visualiza los ejemplares de un vector*/
void Visualiza(Ejemplar* elementos[], int numElementos ) {
    std::cout << "Ejemplares del catálogo" << std::endl
              << "======================="
              << std::endl;
    for (int i = 0; i < numElementos; i++) {
        std::cout << i+1 << ".- ";
        //Poliformismo de objetos mediante referencia
        Visualiza(*elementos[i]);
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**Guarda en un fichero elementos que implementan la Interfaz CSV
   @param[in] elementos vector de punteros a objetos de la clase T
   @param[in] nombreFichero ruta del fichero donde se almacenarán los elementos
   @pre la clase T implementa la interfaz ItemCSV
   @return devuelve un valór lógico indicando si la operación ha tenido éxito*/
template<class T>
bool GuardaCSV(T* elementos[], int numElementos, std::string nombreFichero ) {
    std::ofstream f;
    std::string linea;
    bool guardado=false;

    f.open(nombreFichero.c_str());
    
    if (f.good()) {
        for ( int i=0; i<numElementos; i++ ) {
            //Polimorfismo de métodos usando la interfaz ItemCSV
            linea=linea+elementos[i]->toCSV();
            f << linea << std::endl;
        };
        f.close();
        guardado=true;
    }
    return guardado;
}

/**
 * Ejemplo de prueba clases Ejemplar y Libro
 */
int main(int argc, char** argv) {

    Revista revistaMUY("ISSN 1130-40810","Muy Interesante",2015,11,"G+J",3);

    //No es posible crear objetos de tipo Ejemplar por ser Abstracta
    //Ejemplar dvdRAM("B00C061I3K","Random Access Memories - Daft Punk",
    //                "Sony Intl & Dance",12);

    Libro libroQuijote("9788467016901","El ingenioso hidalgo, Don Quijote de la Mancha",
                       2004, 1, "Miguel de Cervantes", "Espasa libros", 15.95);
    Libro libroPOO( "9786071512123","Programación en C/C++, Java y UML",
                    2014,2,"Luís Joyanes Aguilar", "MacGraw-Hill", 42);

    //Polimorfismo de objetos mediante punteros
    Ejemplar *previstaMUY=new Revista(revistaMUY);
    Ejemplar *plibroQuijote=new Libro(libroQuijote);
    
    //Utilizamos polimorfismo de objetos mediante punteros a clase base
    Ejemplar* ejemplares[NUMEJEMPLARES]= {
        previstaMUY,
        plibroQuijote,
        new Libro("8497320409","C++ Estandar",2001,1,"Enrique Hernández Orallo","Paraninfo",12),
        new Libro(libroPOO),
    };
    
    //Visualizamos todos los ejemplares
    Visualiza(ejemplares,NUMEJEMPLARES);
    
    //Almacenamos los ejemplares en un fichero
    if (GuardaCSV(ejemplares,NUMEJEMPLARES,FICHEROEJEMPLARES)) {
        std::cout << "Ejemplares almacenados en fichero "
                  << FICHEROEJEMPLARES << std::endl << std::endl;
    } else {
        std::cerr << "Ha ocurrido un error al guardar los ejemplares en fichero "
                  << FICHEROEJEMPLARES << std::endl;
    }

    //Búsqueda de un ejemplar en el vector de ejemplar
    Libro ejemAux("9788467016901"); //Vamos a buscar el Quijote
    int posQuijote=BuscaElemento(ejemplares,NUMEJEMPLARES,ejemAux);
    if (posQuijote>=0) { 
        std::cout   << "Hay un ejemplar de "
                    << ejemplares[posQuijote]->getTitulo() //enlace estático
                    << " en el catálogo" << std::endl;
    }
    
    //Búsqueda de un ejemplar a partir de su identificador
    int posMuy=BuscaElemento(ejemplares,NUMEJEMPLARES,"ISSN 1130-40810");
    if (posMuy>=0) {
        std::cout   << "Hay un ejemplar de "
                    << ejemplares[posMuy]->getTitulo()
                    << " en el catálogo" << std::endl;
    }   
    
    std::cout << std::endl << "Liberando objetos en memoria dinámica" 
              << std::endl << std::endl;

    //Liberamos objetos en memoria dinámica
    for (int i = 0; i < NUMEJEMPLARES; i++) {
        //Se utiliza enlace dinámico para llamar a los destructores específicos
        //de cada clase. Los destructores deben ser virtuales!
        delete ejemplares[i];
    } 
    std::cout   << std::endl << "Saliendo de programa principal"
                << std::endl << std::endl;
    
    return 0;
}
