/** 
 * @brief Ejemplo T_2_8 de teoría: Excepciones con clases
 * @file main.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 28 de septiembre de 2015, 11:00
 */

#include <iostream>
#include <cstdlib>
#include "MiExcepcion.h"
using namespace std;

/**
 * @brief Divide a entre b comprobando que b no sea 0
 * @param a Dividendo
 * @param b Divisor
 * @post Devuelve el resultado de a/b, si b es distinto de 0
 * @throws MiExcepcion Si be es 0
 * @return El resultado de dividir a entre b
 */
float dividir( float a, float b) {
    if( b==0 ) throw MiExcepcion( "Función dividir: No se puede dividir por 0");
    return a/b;
}
/**
 * @brief Función principal
 * @argc Número de argumentos pasados por línea de órdenes
 * @argc Caractares pasados como argumentos por línea de órdenes
 * @return 0 si todo funciona bien; distinto de 0 en otro caso.
 */
int main(int argc, char** argv) {

    cout << "Ejemplo de teoría T_2_8: Excepciones con clases" << endl;

    // Primero creamos una excepción, para luego lanzarla
    cout << "+ En primer lugar creamos un objeto excepción que luego lanzaremos" << endl;
    MiExcepcion fueraDeRango("Función main: La posición indicada está fuera del rango válido");

    std::string profesores[] = {"José Ramón Balsas", "Angel Luis García", "Victor Rivas"};
    try {
        for (int i = 0; i < 5; ++i) {
            if (i < 3) {
                cout << "    - Profesor " << i << ": " << profesores[i] << endl;
            } else {
                throw fueraDeRango;
            }
        }
    } catch (MiExcepcion &e) {
        cerr << "Error: " << e.GetTexto() << endl;
    }
    cout << endl;

    cout << "+ En segundo lugar, usamos una excepción creada en el propio throw (dentro de la función dividir)" 
            << endl 
            << endl;

    try {
        double notaDePracticas = 7.3;
        double notaDeTeoria = 5.5;
        int numEjerciciosSinHacer = 0;
        // La siguiente instrucción no llega a ejecutarse, salvo que cambiemos el valor de numEjerciciosSinHacer
        // Nótese que el throw se hace en el función dividir yq ue la excepción se captura aquí.
        cout << "    - Nota final: " << dividir (notaDePracticas + notaDeTeoria, numEjerciciosSinHacer )<< endl;
    } catch (MiExcepcion &e) {
        cerr << "Error: " << e.GetTexto() << endl;
    }

    cout << endl;

    cout << "+ Finalmente, usamos un puntero a la clase excepción" << endl << endl;

    try {
        int *variableNoInicializada = nullptr;
        if (!variableNoInicializada) {
            throw new MiExcepcion("Función main: No puede accederse al contenido de un puntero a NULL");
        }
        
        // Las siguientes instrucciones no se ejecutan, salvo que hagamos un new para la variableNoInicializada
        *variableNoInicializada = 6;
        cout << "    - El contenido de variableNoInicialidada es  "
                << *variableNoInicializada << endl;
    } catch (MiExcepcion *e) {
        cerr << "Error: " << e->GetTexto() << endl;
        delete e;
        e = nullptr;
    }
    cout << endl;

    cout << "+ El programa finaliza correctamente." << endl;
    return 0;
}

