/** Programa de prueba de uso de objetos Punto2D
 * @file   main.cpp
 * @author jrbalsas
 *
 * @date 4 de noviembre de 2015, 12:42
 */

#include <cstdlib>
#include <iostream>

#include "Punto2D.h"
#include "ordenacion.h"
#include "busqueda.h"

using namespace std;

/**Visualiza un punto del plano*/
template<typename T>
void Visualiza( const Punto2D<T> &punto) {
    std::cout <<"(" << punto.getX() << "," << punto.getY() << ")";
}
/**Visualiza un vector de puntos del plano*/
template<typename T>
void Visualiza( const Punto2D<T> puntos[], int numPuntos) {
    for (int i = 0; i < numPuntos; i++) {
        Visualiza(puntos[i]);
        std::cout << std::endl;
    }
}

/** Ejemplo de uso de puntos2D
  */
int main(int argc, char** argv) {

    Punto2D<int> Caceres(12,19);

    const int NUMCIUDADES=4;
    Punto2D<int> posicionCiudades[NUMCIUDADES]= {
        Punto2D<int>(4,90),
        Caceres,
        Punto2D<int>(13,1),
        Punto2D<int>(5,7)
    };

    std::cout << "Recorrido turístico" << std::endl;
    
    std::cout << "Localizaciones de ciudades a visitar" << std::endl;
    Visualiza(posicionCiudades,NUMCIUDADES);
        
    Ordena(posicionCiudades,NUMCIUDADES);

    std::cout << "Localizaciones ordenadas por distancia al origen" << std::endl;
    Visualiza(posicionCiudades,NUMCIUDADES);
    
    std::cout << "¿Está Cáceres entre las ciudades a visitar? ";
    int posCaceres=BuscaElemento(posicionCiudades, NUMCIUDADES, Caceres);
    if (posCaceres>=0){
        std::cout << " Sí,en las coordenadas ";
        Visualiza( posicionCiudades[posCaceres] );
        std::cout << " y es la número " << posCaceres+1 << " a visitar, a "
                  << posicionCiudades[posCaceres].distanciaAlOrigen() << " kms.";
        std::cout << std::endl;
    } else {
        std::cout << " No";
    }
    
    return 0;
}

