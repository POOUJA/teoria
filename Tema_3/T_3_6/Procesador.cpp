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

/**
 * Inicializa los atributos a sus valores por defecto: socket "---",
 * arquitectura \em otra y velocidad 0
 * @brief Constructor por defecto
 */
Procesador::Procesador ( ): Componente (), _arq (otra), _socket ("---"),
                            _velocidad(0)
{
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
                         string socket ): Componente ( marca, modelo, nSerie, 0 ),
                                          _arq (arquitectura), _socket (socket),
                                          _velocidad (velocidad)
{
   if ( velocidad < 0 )
   {
      throw std::invalid_argument ( "Procesador::Procesador: valor de velocidad"
                                    " no válido" );
   }
   
   if ( isArquitectura ( arquitectura ) == false )
   {
      throw std::invalid_argument ( "Procesador::Procesador: identificador de"
                                    " arquitectura incorrecto no válido" );
   }
}

/**
 * @brief Constructor de copia
 * @param orig Objeto del que se copian los atributos
 */
Procesador::Procesador ( const Procesador& orig ): Componente (orig),
                                                   _arq (orig._arq),
                                                   _socket (orig._socket),
                                                   _velocidad (orig._velocidad)
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
 * @throws std::invalid_argument Si el parámetro no es un valor válido del tipo
 */
void Procesador::setArq ( Procesador::Arquitectura arq )
{
   if ( isArquitectura (arq) == true )
   {
      this->_arq = arq;
   }
   else
   {
      throw std::invalid_argument ( "Procesador::setArq: valor de arquitectura"
                                    " no válido" );
   }
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
   if ( velocidad >= 0 )
   {
      this->_velocidad = velocidad;
   }
   else
   {
      throw std::invalid_argument ( "Procesador::setVelocidad: valor de"
                                    " velocidad incorrecto" );
   }
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
 * Redefinición del método de la superclase. Se añade más información al número
 * de serie, para dejar claro que se trata de un procesador
 * @brief Método para consultar el número de serie del procesador
 * @return Una cadena de texto que empieza por "P-", con el número de serie del
 *         procesador
 */
string Procesador::getNumSerie ()
{
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