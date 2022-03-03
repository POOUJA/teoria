/**
 * @brief Implementación de la clase DiscoDuro 
 * @file DiscoDuro.cpp
 * @author algarcia
 * 
 * @date 11 de enero de 2016
 */

#include <stdexcept>
#include <sstream>

#include "DiscoDuro.h"

/**
 * Inicializa un objeto DiscoDuro con todos los parámetros, y a precio 0
 * @brief Constructor parametrizado
 * @param marca Marca del disco duro
 * @param modelo Modelo del disco duro
 * @param nSerie Número de serie del disco duro
 * @param capacidad Capacidad de almacenamiento. Ha de ser un número positivo
 * @param formato Formato del disco (2.5", 3.5"...)
 * @param conexion Identificador del tipo de conexión. Ver DiscoDuro::TipoConexion
 * @throws std::invalid_argument Si alguno de los parámetros no tiene valor
 *         correcto
 */
DiscoDuro::DiscoDuro ( string marca, string modelo, string nSerie
                       , float capacidad, string formato
                       , TipoConexion conexion ): Componente (marca, modelo, nSerie, 0)
                                                , _capacidad (capacidad)
                                                , _formato (formato)
                                                , _conexion (conexion)
{
    try {
        this->setCapacidad(capacidad); //Validar y asignar o lanza std::invalid_argument
    } catch (std::invalid_argument &e) {
        //Añadimos id del método al error y relanzamos la excepción
        throw std::invalid_argument("[DiscoDuro::DiscoDuro] " + std::string(e.what()));
    }
}

/**
 * @brief Constructor de copia
 * @param orig Objeto del que se copian los parámetros
 */
DiscoDuro::DiscoDuro ( const DiscoDuro& orig ): Componente (orig)
                                              , _capacidad (orig._capacidad)
                                              , _conexion (orig._conexion)
                                              , _formato (orig._formato)
{
}

/**
 * @brief Destructor
 */
DiscoDuro::~DiscoDuro ( )
{
}

/**
 * @brief Método para fijar el tipo de conexión del disco duro
 * @param conexion Identificador del nuevo tipo de conexión
 */
void DiscoDuro::setConexion ( TipoConexion conexion )
{
   this->_conexion = conexion;
}

/**
 * @brief Método para consultar el tipo de conexión del disco duro
 * @return El tipo de conexión del disco duro
 */
DiscoDuro::TipoConexion DiscoDuro::getConexion ( ) const
{
   return _conexion;
}

/**
 * @brief Método para cambiar el formato (dimensiones) del disco duro
 * @param formato Descripción del formato del disco (2.5"...)
 */
void DiscoDuro::setFormato ( string formato )
{
   this->_formato = formato;
}

/**
 * @brief Método para consultar el formato (dimensiones) del disco duro
 * @return La descripción del formato del disco duro
 */
string DiscoDuro::getFormato ( ) const
{
   return _formato;
}

/**
 * @brief Método para cambiar la capacidad del disco duro
 * @param capacidad Nuevo valor de capacidad del disco. Debe ser un valor
 *        positivo
 * @throws std::invalid_argument Si el valor de capacidad proporcionado no es
 *         positivo
 */
void DiscoDuro::setCapacidad ( float capacidad )
{
   if ( capacidad <= 0 )
   {
      throw std::invalid_argument ( "DiscoDuro::setCapacidad: el valor de"
                                    " capacidad ha de ser positivo" );
   }

   this->_capacidad = capacidad;
}

/**
 * @brief Método para consultar la capacidad del disco duro
 * @return El valor de capacidad del disco duro
 */
float DiscoDuro::getCapacidad ( ) const
{
   return _capacidad;
}

/**
 * @brief Método para consultar el número de serie del disco duro
 * @return Una cadena de texto que empieza por "DD-", con el número de serie del
 *         disco duro
 */
string DiscoDuro::getNumSerie ()
{
   /* Redefinición del método de la superclase. Se añade más información al
    * número de serie, para dejar claro que se trata de un disco duro */
   return ( "DD-" + _numSerie );
}

/**
 * @brief Operador de asignación
 * @param orig Objeto del que se copian los atributos
 * @return Una referencia al mismo objeto, para que se puedan hacer asignaciones
 *         en cascada (a=b=c)
 */
DiscoDuro& DiscoDuro::operator = (const DiscoDuro& orig)
{
   if ( this != &orig )
   {
      // Asigna los atributos heredados de Componente
      this->Componente::operator = (orig);

      _capacidad = orig._capacidad;
      _conexion = orig._conexion;
      _formato = orig._formato;
   }
   
   return ( *this );
}