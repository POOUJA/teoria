/** Ejemplo de búsqueda y ordenación de elementos
 * @file   main.cpp
 * @author jrbalsas@ujaen.es
 *
 * @date 4 de noviembre de 2015, 14:17
 */

#include <cstdlib>
#include <iostream>
#include "busqueda.h"
#include "ordenacion.h"

using namespace std;

/**Visualiza un vector de enteros*/
void Visualiza(int elementos[], int numElementos) {
    std::cout << "[";
    for (int i = 0; i < numElementos; i++) {
        std::cout   << (i>0?", ":"")
                    << elementos[i];
    }
    std::cout << "]" << std::endl;
}


/**Ejemplo de búsqueda y ordenación de elementos en vectores 
 */
const int NUMELEMENTOS=10;
int main(int argc, char** argv) {

    int elementos[]={10, 5 ,8 , 2, 7, 25, 1, 12, 16, 5};
    
    std::cout << "Operaciones con enteros" << std::endl << std::endl;
    std::cout << "Vector inicial" << std::endl;
    Visualiza(elementos,NUMELEMENTOS);
    
    int valor=1;
    std::cout << "Buscar valor " << valor << std::endl;
    int posicion=buscaElemento(elementos,NUMELEMENTOS,valor);
    std::cout << "El elemento " << valor;
    if (posicion>=0) {
        std::cout << " está en la posición " << posicion;
    } else {
        std::cout << " no está en el vector";
    }
    std::cout << std::endl;
    
    std::cout << "Ordenamos el vector" << std::endl;
    ordena(elementos,NUMELEMENTOS);
    Visualiza(elementos,NUMELEMENTOS);
       
    return 0;
}

