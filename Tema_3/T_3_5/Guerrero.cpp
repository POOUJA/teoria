/**
 * @file Guerrero.cpp
 * Archivo con la definición de los métodos de la clase Guerrero
 * @author algarcia
 * @date 2015-12-31
 */

#include "Guerrero.h"

#include <stdlib.h>   // Para usar rand
#include <sstream>    // Para usar stringstream
#include <iostream>
#include <stdexcept>   // Para usar cerr

/**
 * @brief Constructor por defecto
 * 
 * Fija el nombre a "---", la energía a 1000, y está desarmado
 */
Guerrero::Guerrero ( ): _nombre ("---"), _numArmas (0), _energia (1000)
{
   int i;
   
   for ( i = 0; i < _MAX_AMMO_; i++ )
   {
      _armamento[i] = 0;
   }
}

/**
 * @brief Constructor parametrizado
 * 
 * Crea un guerrero desarmado, con el nombre y la energía que se le indican
 * @param nNombre Texto con el nombre a asignar al nuevo guerrero
 * @param nEnergia Valor de energía a asignar al guerrero
 */
Guerrero::Guerrero ( string nNombre, int nEnergia ): _nombre (nNombre),
                                                     _numArmas (0),
                                                     _energia (nEnergia)
{
   int i;
   
   for ( i = 0; i < _MAX_AMMO_; i++ )
   {
      _armamento[i] = 0;
   }
}

/**
 * @brief Constructor de copia
 * 
 * Solamente copia la energía y el nombre (añadiendo " - 2" al final, para que
 * no tenga exactamente el mismo nombre). El nuevo guerrero está desarmado, ya
 * que no tiene sentido que tenga las mismas armas que el original
 * @param orig Objeto del que se copian los atributos
 */
Guerrero::Guerrero ( const Guerrero& orig ): _numArmas (0),
                                             _energia (orig._energia)
{
   int i;

   _nombre = orig._nombre + " - 2";   // Para evitar nombres duplicados
   
   for ( i = 0; i < _MAX_AMMO_; i++ )
   {
      _armamento[i] = 0;
   }
}

/**
 * @brief Destructor
 * 
 * Como la relación con el arma es de asociación, no se destruyen los objetos de
 * clase Arma apuntados por Guerrero::_armamento. Es necesario llamar al método
 * Guerrero::desarmar antes de destruirlo
 */
Guerrero::~Guerrero ( )
{
   // Como lanzar excepciones en los destructores no es una buena práctica,
   // simplemente se muestra un mensaje por la consola de errores
   int i;
   
   for ( i = 0; i < _numArmas; i++ )
   {
      if ( _armamento[i] != 0 )
      {
         std::cerr << "Guerrero::~Guerrero: se destruye un guerrero sin "
                   << "desarmarlo previamente";
      }
   }
}

/**
 * @brief Método para añadir un arma al guerrero
 * @param nArma Puntero a un objeto de clase Arma, que representa a la nueva
 *        arma del guerrero
 * @throws std::length_error Si se intenta añadir más armas de las permitidas
 *         (ver #_MAX_AMMO_)
 */
void Guerrero::addArma ( Arma* nArma )
{
   if ( _numArmas < _MAX_AMMO_ )
   {
      _armamento[_numArmas] = nArma;
      _numArmas++;
   }
   else
   {
      throw std::length_error ( "Guerrero::addArma: el guerrero no puede llevar"
                                " más armas consigo" );
   }
}

/**
 * Este método sólo sirve para consultar. El arma sigue estando en poder del
 * guerrero. Si lo que se desea es quitarle el arma, hay que utilizar el método
 * Guerrero::desarmar
 * @brief Método para consultar un arma de un guerrero
 * @param cual Índice del arma que se quiere consultar. Su valor ha de estar en
 *        el rango [1, número de armas del guerrero]
 * @return Un puntero al arma del guerrero
 * @throws std::out_of_range Si se utiliza un índice que no se corresponde con
 *         ningún arma
 */
Arma* Guerrero::getArma ( int cual ) const
{
   if ( ( cual > 0 ) && (cual <= _numArmas ) )
   {
      return ( _armamento[cual-1] );
   }
   else
   {
      throw std::out_of_range ( "Guerrero::getArma: el guerrero no posee el arma"
                                " solicitada" );
   }
}

/**
 * @brief Método para consultar el número de armas que tiene el guerrero
 * @return El número de armas que tiene el guerrero
 */
int Guerrero::getNumArmas () const
{
   return ( _numArmas );
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
 * Es necesario romper la relación entre un guerrero y una de sus armas para
 * poder reutilizar el arma para asignarla a otro guerrero
 * @brief Método para quitarle al guerrero una de sus armas
 * @param cual Índice del arma que se quiere quitar al guerrero. Su valor ha de
 *        estar en el rango [1, número de armas del guerrero]
 * @return El puntero al arma que tenía asociada el guerrero
 * @throws std::out_of_range Si se utiliza un índice que no se corresponde con
 *         ningún arma
 */
Arma *Guerrero::desarmar ( int cual )
{
   int i, contador;
   Arma *aux[_MAX_AMMO_];
   Arma *aDevolver = 0;
   
   if ( ( cual > 0 ) && ( cual <= _numArmas ) )
   {
      aDevolver = _armamento[cual-1];
      _armamento[cual-1] = 0;
      
      /** queda compactar el array si es necesario **/
   }
   else
   {
      throw std::out_of_range ( "Guerrero::desarmar: el guerrero no tiene esa"
                                " arma" );
   }

   return ( aDevolver );
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
   int maxPoder = _FACTOR_ATAQUE_ * _energia * _armamento->getPoder ();
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
   std::stringstream aux;
   
   aux << "Soy guerrero. Mi nombre es "
       << _nombre
       << ", mi energía es "
       << _energia
       << " y puedo producir ataques de hasta "
       << (int) ( _FACTOR_ATAQUE_ * _energia * _armamento->getPoder () )
       << " puntos de poder";

   return ( aux.str () );
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
   this->_energia = orig._energia;
   
   return ( *this );
}