/** 
 * @brief Implementación de la clase Procesador
 * @file Procesador.cpp
 * @author algarcia
 * 
 * @date 11 de enero de 2016
 */

#include <stdexcept>

#include "Procesador.h"

/**
 * Convierte una arquitectura en una cadena de texto
 * @param arq Arquitectura a convertir
 * @return Una cadena de texto describiendo la arquitectura
 */
std::string Procesador::arq2string ( Arquitectura arq )
{
   std::string aDevolver = "";

   switch ( arq )
   {
      case Arquitectura::x86_32:
         aDevolver = "Intel IA-32 (32 bits)";
         break;
      case Arquitectura::x86_64:
         aDevolver = "Intel IA-64 o AMD64 (64 bits)";
         break;
      case Arquitectura::ARM:
         aDevolver = "ARM (32 bits)";
         break;
      case Arquitectura::ARM64:
         aDevolver = "ARM (64 bits)";
         break;
      case Arquitectura::OTRA:
         aDevolver = "OTRA";
         break;
      default:
         aDevolver = "Desconocida";
         break;
   }

   return aDevolver;
}

/**
 * @brief Constructor parametrizado. Inicializa el procesador con precio 0
 * @param marca Marca del procesador. Cadena de texto sin restricciones
 * @param modelo Modelo del procesador. Cadena de texto sin restricciones
 * @param nSerie Número de serie del procesador. Cadena de texto sin
 *        restricciones
 * @param nVelocidad Velocidad del procesador en gigahercios. Ha de ser un valor
 *        mayor o igual a cero
 * @param nArquitectura Identificador de la arquitectura del procesador. Ha de
 *        ser un valor válido del tipo Procesador::Arquitectura
 * @param nSocket Socket del procesador. Cadena de texto sin restricciones
 * @throws std::invalid_argument Si la velocidad es un número negativo, o si el
 *         valor de arquitectura no es válido
 */
Procesador::Procesador ( string marca, string modelo, string nSerie,
                         float velocidad, Arquitectura arquitectura,
                         string socket ): Componente ( marca, modelo, nSerie, 0 )
                                        , _arq (arquitectura), _socket (socket)
                                        , _velocidad (velocidad)
{

    try {
        this->setVelocidad(velocidad); //Validar y asignar o lanza std::invalid_argument
    }catch(std::invalid_argument &e) {
        //Añadimos id del método al error y relanzamos la excepción
        throw std::invalid_argument( "[Procesador::Procesador] "+std::string(e.what()) );
    }
}

/**
 * @brief Constructor de copia
 * @param orig Objeto del que se copian los atributos
 */
Procesador::Procesador ( const Procesador& orig ): Componente (orig)
                                                 , _arq (orig._arq)
                                                 , _socket (orig._socket)
                                                 , _velocidad (orig._velocidad)
{
}

/**
 * @brief Destructor
 */
Procesador::~Procesador ( )
{
}

/**
 * @brief Método para cambiar la arquitectura del procesador
 * @param nArq Un valor del tipo Procesador::Arquitectura, que identifica la
 *        nueva arquitectura del procesador
 */
void Procesador::setArq ( Procesador::Arquitectura arq )
{
   this->_arq = arq;
}

/**
 * @brief Método para consultar el tipo de arquitectura del procesador
 * @return El identificador de la arquitectura del procesador
 */
Procesador::Arquitectura Procesador::getArq ( ) const
{
   return _arq;
}

/**
 * @brief Método para cambiar el socket del procesador
 * @param nSocket Texto con la descripción del nuevo socket
 */
void Procesador::setSocket ( string socket )
{
   this->_socket = socket;
}

/**
 * @brief Método para consultar el socket del procesador
 * @return Un texto con la descripción del socket del procesador
 */
string Procesador::getSocket ( ) const
{
   return _socket;
}

/**
 * @brief Método para cambiar la velocidad nominal del procesador
 * @param nVelocidad Velocidad del procesador en gigahercios. Ha de ser un
 *        número mayor o igual a cero
 * @throws std::invalid_argument Si se intenta asignar al procesador una
 *         velocidad negativa
 */
void Procesador::setVelocidad ( float velocidad )
{
   if ( velocidad < 0 )
   {
      throw std::invalid_argument ( "Procesador::setVelocidad: valor de"
                                    " velocidad incorrecto" );
   }

   this->_velocidad = velocidad;
}

/**
 * @brief Método para consultar la velocidad del procesador
 * @return La velocidad del procesador en gigahercios
 */
float Procesador::getVelocidad ( ) const
{
   return _velocidad;
}

/**
 * @brief Método para consultar el número de serie del procesador
 * @return Una cadena de texto que empieza por "P-", con el número de serie del
 *         procesador
 */
string Procesador::getNumSerie ()
{
   /* Redefinición del método de la superclase. Se añade más información al
    * número de serie, para dejar claro que se trata de un procesador */
   return ( "P-" + _numSerie );
}

/**
 * @brief Operador de asignación
 * @param orig Objeto del que se copian los datos
 * @return Una referencia al propio objeto, para posibilitar las asignaciones en
 *         cascada (a=b=c)
 */
Procesador& Procesador::operator = (const Procesador& orig)
{
   if ( this != &orig )
   {
      // Asigna los atributos heredados
      this->Componente::operator = (orig);

      // Asigna el resto de atributos
      _arq = orig._arq;
      _socket = orig._socket;
      _velocidad = orig._velocidad;
   }

   return ( *this );
}