/** 
 * @brief Implementación de la clase Componente
 * @file Componente.cpp
 * @author algarcia
 * 
 * @date 11 de enero de 2016
 */

#include <stdexcept>
#include <sstream>

#include "Componente.h"

/**
 * Crea un nuevo componente con valores por defecto
 * @brief Constructor por defecto
 */
Componente::Componente ( ): _marca ("---"), _modelo ("---"), _numSerie ("---"),
                            _precio (0)
{
}

/**
 * Copia todos los atributos, pero añade al número de serie la cadena " - 2",
 * para que se vea que es una copia
 * @brief Constructor de copia
 * @param orig Objeto del que se copian los atributos
 */
Componente::Componente ( const Componente& orig ): _marca (orig._marca),
                                                   _modelo (orig._modelo),
                                                   _precio (orig._precio)
{
   _numSerie = orig._numSerie + " - 2";
}

/**
 * @brief Destructor
 */
Componente::~Componente ( )
{
}

/**
 * Permite fijar el precio de un componente en euros
 * @brief Modificador para el atributo Componente::_precio
 * @param nPrecio Nuevo precio para el componente
 * @throws std::invalid_argument Si el valor de nPrecio es negativo
 */
void Componente::setPrecio ( float nPrecio )
{
   if ( nPrecio >= 0 )
   {
      this->_precio = nPrecio;
   }
   else
   {
      throw std::invalid_argument ( "Componente::setPrecio: el precio ha de ser"
                                    " una cantidad positiva" );
   }
}

/**
 * @brief Método para consultar el precio de un componente
 * @return El precio del componente en euros
 */
float Componente::getPrecio ( ) const
{
   return _precio;
}

/**
 * @brief Método para cambiar el número de serie del componente
 * @param nNumSerie Nuevo número de serie para el componente
 */
void Componente::setNumSerie ( string nNumSerie )
{
   this->_numSerie = nNumSerie;
}

/**
 * @brief Método para consultar el número de serie del componente
 * @return El número de serie del componente
 */
string Componente::getNumSerie ( ) const
{
   return _numSerie;
}

/**
 * @brief Método para asignar el modelo del componente
 * @param nModelo Texto identificando el modelo del componente
 */
void Componente::setModelo ( string nModelo )
{
   this->_modelo = nModelo;
}

/**
 * @brief Método para consultar el modelo del componente
 * @return Una cadena de texto con el modelo del componente
 */
string Componente::getModelo ( ) const
{
   return _modelo;
}

/**
 * @brief Método para asignar a un componente la marca
 * @param nMarca Cadena de texto con la marca del componente
 */
void Componente::setMarca ( string nMarca )
{
   this->_marca = nMarca;
}

/**
 * @brief Método para consultar la marca de un componente
 * @return La marca del componente
 */
string Componente::getMarca ( ) const
{
   return _marca;
}

/**
 * @brief Genera una cadena de texto "user-friendly" con los datos del componente
 * @return Una cadena de texto con la información del componente 
 */
string Componente::info ()
{
   std::stringstream aux;
   
   aux << "Marca: " << _marca << "\t"
       << "Modelo:" << _modelo << "\t"
       << "S/N: " << _numSerie << "\t"
       << "Precio: " << _precio << " Euros";
   
   return ( aux.str () );
}