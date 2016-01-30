/** 
 * @brief Implementación de la clase Procesador
 * @file Procesador.cpp
 * @author algarcia
 * 
 * @date 11 de enero de 2016
 */

#include "Procesador.h"

/**
 * @brief Método de clase para asegurar un tipo de arquitectura correcto
 * @param valor Valor entero que se quiere convertir a un tipo de arquitectura
 * @return El valor convertido a uno de los valores del tipo
 *         Procesador::Arquitectura. Si el valor no se corresponde con ningún
 *         tipo de conexión, devuelve el valor Arquitectura::otra
 */
Procesador::Arquitectura Procesador::intoArquitectura (int valor)
{
   if ( ( valor >= x86_32 ) && ( valor <= otra ) )
   {
      return ( Procesador::Arquitectura ( valor ) );
   }
   else
   {
      return ( otra );
   }
}

/**
 * @brief Método para comprobar si un valor se corresponde con un tipo de
 *        arquitectura
 * @param valor Valor entero a comprobar
 * @retval true Si el valor se corresponde con uno de los del tipo
 *         Procesador::Arquitectura
 * @retval false Si el valor no se correponde con un valor del tipo antes
 *         indicado
 */
bool Procesador::isArquitectura ( int valor )
{
   if ( ( valor >= x86_32 ) && ( valor <= otra ) )
   {
      return ( true );
   }
   else
   {
      return ( false );
   }
}


Procesador::Procesador ( )
{
}

Procesador::Procesador ( const Procesador& orig )
{
}

Procesador::~Procesador ( )
{
}

void Procesador::setArq ( Procesador::Arquitectura _arq )
{
   this->_arq = _arq;
}

Procesador::Arquitectura Procesador::getArq ( ) const
{
   return _arq;
}

void Procesador::setSocket ( string _socket )
{
   this->_socket = _socket;
}

string Procesador::getSocket ( ) const
{
   return _socket;
}

void Procesador::setVelocidad ( float _velocidad )
{
   this->_velocidad = _velocidad;
}

float Procesador::getVelocidad ( ) const
{
   return _velocidad;
}

