/**
 * @file Guerrero.cpp
 * Archivo con la definición de los métodos de la clase Guerrero
 * @author algarcia
 * @date 2015-10-20
 */

#include "Guerrero.h"

#include <stdlib.h>   // Para usar rand
#include <sstream>    // Para usar stringstream
#include <iostream>   // Para usar cerr

/// Factor a aplicar para calcular el valor de los ataques
#define _FACTOR_ATAQUE_ 0.001


/**
 * @brief Constructor por defecto
 * 
 * Fija el nombre a "---", la energía a 1000, y está desarmado
 */
Guerrero::Guerrero ( ): nombre ("---"), armamento (NULL), energia (1000)
{
}

/**
 * @brief Constructor parametrizado
 * 
 * Crea un guerrero desarmado, con el nombre y la energía que se le indican
 * @param nNombre Texto con el nombre a asignar al nuevo guerrero
 * @param nEnergia Valor de energía a asignar al guerrero
 */
Guerrero::Guerrero ( string nNombre, int nEnergia ): nombre (nNombre),
                                                     armamento (NULL),
                                                     energia (nEnergia)
{
}

/**
 * @brief Constructor de copia
 * 
 * Solamente copia la energía y el nombre (añadiendo " - 2" al final, para que
 * no tenga exactamente el mismo nombre). El nuevo guerrero está desarmado, ya
 * que no tiene sentido que tenga la misma arma que el original
 * @param orig Objeto del que se copian los atributos
 */
Guerrero::Guerrero ( const Guerrero& orig ): armamento (NULL),
                                             energia (orig.energia)
{
   nombre = orig.nombre + " - 2";   // Para evitar nombres duplicados
}

/**
 * @brief Destructor
 * 
 * Como la relación con el arma es de asociación, no se destruye el objeto de
 * clase Arma apuntado por Guerrero::armamento. Es necesario llamar al método
 * Guerrero::desarmar antes de destruirlo
 */
Guerrero::~Guerrero ( )
{
   // Como lanzar excepciones en los destructores no es una buena práctica,
   // simplemente se muestra un mensaje por la consola de errores
   if ( armamento != NULL )
   {
      std::cerr << "Guerrero::~Guerrero: se destruye un guerrero sin "
                << "desarmarlo previamente";
   }
}

/**
 * @brief Modificador para el atributo Guerrero::armamento
 * @param nArmamento Puntero a un objeto de clase Arma, que representa a la
 *        nueva arma del guerrero
 */
void Guerrero::setArmamento ( Arma* nArmamento )
{
   this->armamento = nArmamento;
}

/**
 * @brief Observador para el atributo Guerrero::armamento
 * @return Un puntero al arma del guerrero
 */
Arma* Guerrero::getArmamento ( ) const
{
   return armamento;
}

/**
 * @brief Modificador para el atributo Guerrero::energia
 * @param nEnergia Nuevo valor de energía a asignar. No se hacen comprobaciones
 *        sobre él
 */
void Guerrero::setEnergia ( int nEnergia )
{
   this->energia = nEnergia;
}

/**
 * @brief Observador para el atributo Guerrero::energia
 * @return La energía restante del guerrero
 */
int Guerrero::getEnergia ( ) const
{
   return energia;
}

/**
 * @brief Modificador para el atributo Guerrero::nombre
 * @param nNombre Texto con el nuevo nombre a asignar al guerrero. No se hacen
 *        comprobaciones sobre él
 */
void Guerrero::setNombre ( string nNombre )
{
   this->nombre = nombre;
}

/**
 * @brief Observador para el atributo Guerrero::nombre
 * @return Una cadena de texto con el nombre asignado al guerrero
 */
string Guerrero::getNombre ( ) const
{
   return nombre;
}

/**
 * @brief Método para romper la asociación entre un guerrero y su arma
 * 
 * Este método ha de ser llamado antes de la destrucción de un objeto de clase
 * Guerrero, para romper la asociación entre un guerrero y su arma. De otro
 * modo, no se podrá reutilizar el arma para asignarla a otro guerrero
 * @return El puntero al arma que tenía asociada el guerrero
 */
Arma *Guerrero::desarmar ()
{
   Arma *aux = armamento;
   armamento = NULL;
   return ( aux );
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
   int maxPoder = _FACTOR_ATAQUE_ * energia * armamento->getPoder ();
   int resultado = rand () % maxPoder + 1;

   return ( resultado );
}

/**
 * @brief Información del objeto
 * @return Devuelve una cadena de texto conteniendo los valores de los atributos
 *         del objeto
 */
string Guerrero::info () const
{
   string resultado;
   std::stringstream aux;
   
   aux << "Soy guerrero. Mi nombre es "
       << nombre
       << ", mi energía es "
       << energia
       << " y puedo producir ataques de hasta "
       << (int) ( _FACTOR_ATAQUE_ * energia * armamento->getPoder () )
       << " puntos de poder";

   getline ( aux, resultado );
   return ( resultado );
}