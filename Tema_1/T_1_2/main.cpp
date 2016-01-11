/** 
 * @brief Fichero principal del ejemplo de teorÌa T_1_2
 * @file main.cpp
 * @author Victor M. Rivas (vrivas@ujaen.es)
 * @date 11 de Enero de 2016, 22:13
 */

#include <iostream>
#include <string>
#include "ParejaDePracticas.h"
using namespace std;

/**
 * @brief FunciÛn principal
 * @param argc N˙mero de argumentos
 * @param argv Caracteres que forman dichos argumentos
 * @post Crea varios structs con mis parejas de pr·cticas
 */
int main(int argc, char** argv) {
    ParejaDePracticas poo, fundamentos, algebra;

    // Datos de mi pareja de practicas para POO
    try {
        poo.setNombre("Jose Lopez Perez");
        poo.setTelefono("555123321");
        poo.setEmail("jlopez@jlopez.es");
    } catch (string s) {
        cerr << "Error: " << s << endl;
    }
    // Datos de mi pareja de pr·cticas para fundamentos
    try {
        fundamentos.setNombre("");
        fundamentos.setTelefono("???");
        fundamentos.setEmail("las vacas del pueblo ya se han escapao, riau, riau");
    } catch (string s) {
        cerr << "Error: " << s << endl;
    }

    // Datos de mi pareja de pr·cticas para algebra
    try {
        algebra.setNombre("luis@gmail.com");
        algebra.setTelefono("555654345566654434");
        algebra.setEmail("Luis Sanchez Sanchez");
    } catch (string s) {
        cerr << "Error: " << s << endl;
    }

    cout << "Pareja de prácticas de POO: " << poo.concatenar() << endl;
    cout << "Pareja de prácticas de Fundamentos: " << fundamentos.concatenar() << endl;
    cout << "Pareja de prácticas de Algebra: " << algebra.concatenar() << endl;

    return 0;
}

