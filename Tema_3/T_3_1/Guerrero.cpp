/**
 * @file Guerrero.cpp
 * Archivo con la definición de los métodos de la clase Guerrero
 * @author algarcia
 * @date 2015-10-20
 */

#include <stdlib.h>    // Para usar rand
#include <iostream>    // Para usar cerr
#include <stdexcept>   // Para usar std::invalid_argument
#include <cassert>
#include "Guerrero.h"

/**
 * @brief Constructor parametrizado
 * 
 * Crea un guerrero desarmado, con el nombre que se le indica y energia 1000
 * @param nNombre Texto con el nombre a asignar al nuevo guerrero
 */
Guerrero::Guerrero ( string nNombre): Guerrero(nNombre,1000)
{ }

/**
 * @brief Constructor parametrizado
 * 
 * Crea un guerrero desarmado, con el nombre y la energía que se le indican
 * @param nNombre Texto con el nombre a asignar al nuevo guerrero
 * @param nEnergia Valor de energía a asignar al guerrero. Ha de ser positivo
 * @throws std::invalid_argument Si el valor de energía no es un número positivo
 */
Guerrero::Guerrero ( string nNombre, int nEnergia ): _nombre (nNombre),
                                                     _armamento (nullptr),
                                                     _energia (nEnergia)
{
   if ( nEnergia <= 0 )
   {
      throw std::invalid_argument ( "Guerrero::Guerrero: la energía vital ha de"
                                    " ser un valor positivo" );
   }
}

/**
 * @brief Constructor de copia
 * @param orig Objeto del que se copian los atributos
 * @post El nuevo objeto añade a su nombre " - copia" al final
 */
Guerrero::Guerrero ( const Guerrero& orig ): _armamento (orig._armamento)
                                           , _energia (orig._energia)
{
   _nombre = orig._nombre + " - copia";   // Para evitar nombres duplicados
}

/**
 * @brief Destructor
 * 
 * Como la relación con el arma es de asociación, no se destruye el objeto de
 * clase Arma apuntado por Guerrero::_armamento. Es necesario llamar al método
 * Guerrero::desarmar antes de destruirlo
 * @pre Antes de destruir un guerrero debe garantizarse que no tiene arma
 *      asociada o retirarla usando el método desarmar
 */
Guerrero::~Guerrero ( )
{
    // Como lanzar excepciones en los destructores no es una buena práctica,
    // simplemente se comprueba que se ha desarmado el guerrero con la función assert y,
    // en caso de que no, el programa finaliza mostrando un mensaje con la condición
    // no satisfecha.
   assert ( _armamento == nullptr ); //finalizamos el programa si se destruye un guerrero
                                    //sin desarmarlo previamente


}

/**
 * @brief Modificador para el atributo Guerrero::_armamento
 * @param nArmamento Puntero a un objeto de clase Arma, que representa a la
 *        nueva arma del guerrero
 */
void Guerrero::setArmamento ( Arma* nArmamento )
{
   this->_armamento = nArmamento;
}

/**
 * @brief Observador para el atributo Guerrero::_armamento
 * @return Una referencia al arma del guerrero
 * @throws std::runtime_error Si el guerrero no tiene arma asociada
 */
const Arma& Guerrero::getArmamento ( )
{
   if ( _armamento == nullptr )
   {
      throw std::runtime_error ( "Guerrero::getArmamento: no hay arma asociada" );
   }

   return  *_armamento ;
}

/**
 * @brief Modificador para el atributo Guerrero::_energia
 * @param nEnergia Nuevo valor de energía a asignar. No se hacen comprobaciones
 *        sobre él
 */
void Guerrero::setEnergia ( int nEnergia )
{
   this->_energia = nEnergia;
}

/**
 * @brief Observador para el atributo Guerrero::_energia
 * @return La energía restante del guerrero
 */
int Guerrero::getEnergia ( ) const
{
   return _energia;
}

/**
 * @brief Método para conocer el máximo poder destructor de los ataques del
 *        guerrero
 * @return El valor numérico máximo que pueden tener los ataques del guerrero
 */
int Guerrero::getMaxPoder ()
{
   if ( _armamento != nullptr )
   {
      return ( calculaMaxPoder ( _armamento->getPoder () ) );
   }

   return  0 ;   // Está desarmado
}

/**
 * @brief Modificador para el atributo Guerrero::_nombre
 * @param nNombre Texto con el nuevo nombre a asignar al guerrero. No se hacen
 *        comprobaciones sobre él
 */
void Guerrero::setNombre ( string nNombre )
{
   this->_nombre = _nombre;
}

/**
 * @brief Observador para el atributo Guerrero::_nombre
 * @return Una cadena de texto con el nombre asignado al guerrero
 */
string Guerrero::getNombre ( ) const
{
   return _nombre;
}

/**
 * @brief Método para romper la asociación entre un guerrero y su arma
 * 
 * Este método ha de ser llamado antes de la destrucción de un objeto de clase
 * Guerrero, para romper la asociación entre un guerrero y su arma. De otro
 * modo, no se podrá reutilizar el arma para asignarla a otro guerrero
 * @return El puntero al arma que tenía asociada el guerrero
 */
Arma* Guerrero::desarmar ()
{
   Arma *aux = _armamento;
   _armamento = nullptr;
   return aux ;
}

/**
 * @brief Método para producir un ataque
 * 
 * La potencia de un ataque depende de la energía del guerrero, así como del
 * poder de destrucción de su arma. Se incluye también un factor de
 * aleatoriedad, para que cada ataque tenga un daño diferente
 * @return El valor del daño provocado por el ataque de un guerrero
 */
int Guerrero::ataque ()
{
   int maxPoder = getMaxPoder ();
   int resultado = rand () % maxPoder + 1;

   return resultado;
}

/**
 * En este caso, no copia el nombre del guerrero (para evitar dos guerreros con
 * el mismo nombre) ni el arma (un arma no puede estar en poder de dos guerreros
 * a la vez)
 * @brief Operador de asignación
 * @param orig Objeto del que se copian los atributos
 * @return Una referencia al propio objeto, para facilitar la asignación en
 *         cascada (a=b=c)
 */
Guerrero& Guerrero::operator = (const Guerrero& orig)
{
   if ( this != &orig )
   {
      this->_energia = orig._energia;
   }
   
   return  *this ;
}

/**
 * El valor máximo de daño que puede producir un guerrero, dado el poder
 * de un arma, depende de la energía vital que tenga el guerrero
 * @brief Método para calcular el valor máximo de daño que puede producir
 *        el guerrero, dado el poder de un arma
 * @param valorBase Máximo daño que puede producir un arma
 * @return El valor máximo de daño que puede producir el guerrero con esa
 *         arma
 */
int Guerrero::calculaMaxPoder ( int valorBase )
{
   return  int ( _FACTOR_ATAQUE_ * _energia * valorBase ) ;
}
