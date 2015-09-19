/**
 * @brief  Definición de una clase. 
 *        Ejemplo T_2_3, de la Teoría de Prog. Orientada a Objetos
 *        del curso 2015-2016.
 * @file Gol.h
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 *
 * @date 18 de septiembre de 2015, 11:36
 */


#include <string>

#ifndef GOL_H
#define	GOL_H

/**
 * @brief Clase Gol. Ejemplo T_2_3 de Teoría
 * @param autor Nombre del jugador que ha marcado el gol
 * @param minuto Minuto del partido en que se ha marcado el gol
 */

class Gol {
public:                                                     // Métodos públicos
    Gol(const std::string elJugador, const int elMinuto);   // Método: constructor
    Gol(const Gol& orig);                                   // Método: constructor
    ~Gol();                                                 // Método: constructor
    void SetMinuto(int minuto);                             // Método: mutador
    int GetMinuto() const;                                  // Método: observador
    void SetJugador(std::string jugador);                   // Método: mutador
    std::string GetJugador() const;                         // Método: observador
private:
    bool minutoEsCorrecto(int minuto) const;                // Método privado  
private:
    std::string jugador;                                    // Atributo
    int minuto;                                             // Atributo
};

#endif	/* GOL_H */

