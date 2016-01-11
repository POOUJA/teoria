/** 
 * @brief Fichero principal del ejemplo de teorÌa T_1_1
 * @file main.cpp
 * @author Victor M. Rivas (vrivas@ujaen.es)
 * @date 11 de Enero de 2016, 13:13
 */

#include <iostream>
#include <string>
using namespace std;

/**
 * Struct que contiene los datos impresincidibles que necesito saber de mis parejas para las pr·cticas
 */
struct ParejaDePracticas {
    /// Nombre de mi compaÒero/a
    string nombre;

    /// TelÈfono
    string telefono;

    /// Email
    string email;
};

/**
 * FunciÛn que me devuelve los datos de mi compaÒero en una sola lÌnea
 * @param pareja La pareja para una determinada asignatura
 * @param error CÛdigo de error que devuelvo si ocurre algo errÛneo
 * @return Los datos d emi pareja concatenados
 */
string parejaDePracticas_concatenar_datos(struct ParejaDePracticas& pareja, int& error) {
    if (pareja.nombre == "" || pareja.telefono == "" || pareja.email == "") {
        error = 1;
        return "";
    }
    error = 0;
    return pareja.nombre + ", " + pareja.telefono + ", " + pareja.email;
}

/**
 * @brief FunciÛn principal
 * @param argc N˙mero de argumentos
 * @param argv Caracteres que forman dichos argumentos
 * @post Crea varios structs con mis parejas de pr·cticas
 */
int main(int argc, char** argv) {
    ParejaDePracticas poo, fundamentos, algebra;
    int error = 0;
    string cadena = "";

    // Datos de mi pareja de pr·cticas para POO
    poo.nombre = "Jose Lopez Perez";
    poo.telefono = "555123321";
    poo.email = "jlopez@jlopez.es";

    // Datos de mi pareja de pr·cticas para fundamentos
    fundamentos.nombre = "";
    fundamentos.telefono = "???";
    fundamentos.email = "las vacas del pueblo ya se han escapao, riau, riau";

    // Datos de mi pareja de pr·cticas para algebra
    algebra.nombre = "luis@gmail.com";
    algebra.telefono = "555654345566654434";
    algebra.email = "Luis Sanchez Sanchez";

    cadena = parejaDePracticas_concatenar_datos(poo, error);
    if (error != 0) {
        cerr << "T_1_1: main: Hubo alg˙n problema al mostrar la pareja de pr·cticas de POO" << endl;
    } else {
        cout << "Pareja de pr·cticas de POO: " << cadena << endl;
    }
    cadena = parejaDePracticas_concatenar_datos(fundamentos, error);
    if (error != 0) {
        cerr << "T_1_1: main: Hubo alg˙n problema al mostrar la pareja de pr·cticas de Fundamentos" << endl;
    } else {
        cout << "Pareja de pr·cticas de Fundamentos: " << cadena << endl;
    }
    cadena = parejaDePracticas_concatenar_datos(algebra, error);
    if (error != 0) {
        cerr << "T_1_1: main: Hubo alg˙n problema al mostrar la pareja de pr·cticas de Algebra" << endl;
    } else {
        cout << "Pareja de pr·cticas de Algebra: " << cadena << endl;
    }

    return 0;
}

