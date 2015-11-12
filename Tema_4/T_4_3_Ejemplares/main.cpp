/** Programa de ejemplo de uso de Poliformismo de Objetos y Métodos
 * @file   main.cpp
 * @author jrbalsas@ujaen.es
 *
 * @date 4 de noviembre de 2015
 */

#include <cstdlib>
#include <iostream>
#include "Ejemplar.h"
#include "Libro.h"
#include "busqueda.h"

/**Visualiza un ejemplar en formato CSV*/
void Visualiza(const Ejemplar &ejemplar ) {
    //Polimorfismo de objetos mediante referencias en paso de parámetro
    //Polimorfismo de método en llamada a método según el tipo de ejemplar (enlace dinámico)
    std::cout << ejemplar.toCSV();
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

const int NUMEJEMPLARES=6; /*< Tamaño del vector de ejemplares*/

/**
 * Ejemplo de prueba clases Ejemplar y Libro
 */
int main(int argc, char** argv) {

    Ejemplar revistaMUY("1130-40810","Muy Interesante","G+J",3);
    Ejemplar dvdRAM("B00C061I3K","Random Access Memories - Daft Punk",
                    "Sony Intl & Dance",12);
    Libro libroQuijote("9788467016901","El ingenioso hidalgo, Don Quijote de la Mancha",
                       2004, 1, "Miguel de Cervantes", "Espasa libros", 15.95);
    Libro libroPOO( "9786071512123","Programación en C/C++, Java y UML",
                    2014,2,"Luís Joyanes Aguilar", "MacGraw-Hill", 42);
    Libro libroFatima("8499893740","La mano de Fatima",
                       2012,1,"Falcon, I.","De bolsillo",9.46);

    Ejemplar *pRevistaMuy=new Ejemplar(revistaMUY);
    //Polimorfismo de objetos mediante referencia
    Ejemplar &refFatima= libroFatima;
    //Polimorfismo de objetos mediante punteros
    Ejemplar *plibroQuijote=new Libro(libroQuijote);
    
    //Utilizamos polimorfirmos de objetos mediante punteros a clase base
    //Sólo apuntamos a objetos en memoria dinámica para saber que todos pueden liberarse
    Ejemplar* ejemplares[NUMEJEMPLARES]= {
        pRevistaMuy,
        plibroQuijote,
        //new Libro(refFatima), //No es una conversión válida
        new Libro (libroFatima),
        new Libro("8497320409","C++ Estandar",2001,1,"Enrique Hernández Orallo","Paraninfo",12),
        new Ejemplar(dvdRAM),
        new Ejemplar(dvdRAM)
    };
    
    //Visualizamos todos los ejemplares
    Visualiza(ejemplares,NUMEJEMPLARES);

    //Búsqueda de un ejemplar en el vector de ejemplar
    Ejemplar ejemAux("9788467016901"); //Vamos a buscar el Quijote
    int posQuijote=BuscaElemento(ejemplares,NUMEJEMPLARES,ejemAux);
    if (posQuijote>=0) {
        std::cout   << "Hay un ejemplar de "
                    << ejemplares[posQuijote]->getTitulo() //enlace estático
                    << " en el catálogo" << std::endl;
    }
    
    //Búsqueda de un ejemplar a partir de su identificador
    int posMuy=BuscaElemento(ejemplares,NUMEJEMPLARES,"1130-40810");
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
