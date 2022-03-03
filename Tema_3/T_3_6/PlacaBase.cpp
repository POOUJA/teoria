/** 
 * @brief Implementación de la clase PlacaBase
 * @file PlacaBase.cpp
 * @author algarcia
 * 
 * @date 11 de enero de 2016
 */

#include <stdexcept>

#include "PlacaBase.h"

/**
 * Convierte un factor de forma a texto
 * @param ff Factor de forma a convertir
 * @return Una cadena de texto describiendo el factor de forma
 */
std::string PlacaBase::ff2string ( FactorDeForma ff )
{
   std::string aDevolver = "";

   switch (ff)
   {
      case FactorDeForma::ATX:
         aDevolver = "ATX";
         break;
      case FactorDeForma::MicroATX:
         aDevolver = "MicroATX";
         break;
      case FactorDeForma::MiniITX:
         aDevolver = "MiniITX";
         break;
      case FactorDeForma::NanoITX:
         aDevolver = "NanoITX";
         break;
      case FactorDeForma::PicoITX:
         aDevolver = "PicoITX";
         break;
      case FactorDeForma::OTRO:
         aDevolver = "OTRO";
         break;
      default:
         aDevolver = "Desconocido";
         break;
   }

   return aDevolver;
}

/**
 * @brief Constructor parametrizado
 * @param marca Texto con la marca de la placa base
 * @param modelo Texto con el modelo de la placa base
 * @param nSerie Número de serie de la placa base
 * @param nPCIe Número de puertos PCI Express de la placa base. No puede ser
 *        negativo
 * @param nUSB Número de puertos USB de la placa base. No puede ser negativo
 * @param chipset Texto con la información del chipset de la placa base
 * @param socket Texto con la información del socket de la placa base
 * @throws std::invalid_argument Si el factor de forma no es correcto, o si
 *         alguno de los números de puertos es negativo
 */
PlacaBase::PlacaBase ( string marca, string modelo, string nSerie
                     , FactorDeForma fForma, int nPCIe, int nUSB, string chipset
                     , string socket ):
                                    Componente (marca, modelo, nSerie, 0)
                                  , _fForma (fForma), _nPCIe (nPCIe)
                                  , _nUSB (nUSB), _chipset (chipset)
                                  , _socket (socket)
{
    try {
        this->setNUSB(nUSB); //Validar y asignar o excepción std::invalid_argument
        this->setNPCIe(nPCIe);
    }catch(std::invalid_argument &e) {
        //Añadimos id del método al error y relanzamos la excepción
        throw std::invalid_argument ( "[PlacaBase::PlacaBase] "
                                      + std::string(e.what()) );
    }
}

/**
 * @brief Constructor de copia
 * @param orig Objeto del que se copian los atributos
 */
PlacaBase::PlacaBase ( const PlacaBase& orig ): Componente (orig)
                                              , _fForma (orig._fForma)
                                              , _nPCIe (orig._nPCIe)
                                              , _nUSB (orig._nUSB)
                                              , _chipset (orig._chipset)
                                              , _socket (orig._socket)
{
}

/**
 * @brief Destructor
 */
PlacaBase::~PlacaBase ( )
{
}

/**
 * @brief Método para cambiar el socket de la placa base
 * @param socket Información sobre el socket de la placa
 */
void PlacaBase::setSocket ( string socket )
{
   this->_socket = socket;
}

/**
 * @brief Método para consultar el socket de la placa
 * @return Una cadena de texto con información del socket que lleva la placa
 */
string PlacaBase::getSocket ( ) const
{
   return _socket;
}

/**
 * @brief Método para cambiar la información del chipset de la placa base
 * @param chipset Texto con la nueva información del chipset
 */
void PlacaBase::setChipset ( string chipset )
{
   this->_chipset = chipset;
}

/**
 * @brief Método para consultar el chipset de la placa base
 * @return Una cadena de texto con la información del chipset
 */
string PlacaBase::getChipset ( ) const
{
   return _chipset;
}

/**
 * @brief Método para cambiar el número de puertos USB
 * @param nUSB Nuevo valor de número de puertos USB. No puede ser negativo
 * @throws std::invalid_argument Si el número de puertos USB es negativo
 */
void PlacaBase::setNUSB ( int nUSB )
{
   if ( nUSB < 0 )
   {
      throw std::invalid_argument ( "PlacaBase::setNUSB: el número de puertos"
                                    " no puede ser negativo" );
   }

   this->_nUSB = nUSB;
}

/**
 * @brief Método para consultar el número de puertos USB de la placa
 * @return El número de puertos USB de la placa
 */
int PlacaBase::getNUSB ( ) const
{
   return _nUSB;
}

/**
 * Método para cambiar el número de puertos PCI Express
 * @param nUSB Nuevo valor de número de puertos PCIe. No puede ser negativo
 * @throws std::invalid_argument Si el número de puertos PCIe es negativo
 */
void PlacaBase::setNPCIe ( int nPCIe )
{
   if ( nPCIe < 0 )
   {
      throw std::invalid_argument ( "PlacaBase::setNPCIe: el número de puertos"
                                    " no puede ser negativo" );
   }

   this->_nPCIe = nPCIe;
}

/**
 * @brief Método para consultar el número de puertos PCI Express de la placa
 * @return El número de puertos PCIe de la placa
 */
int PlacaBase::getNPCIe ( ) const
{
   return _nPCIe;
}

/**
 * @brief Método para cambiar el factor de forma de la placa
 * @param fForma Identificador del factor de forma. Valor del tipo
 *        PlacaBase::FactorDeForma
 */
void PlacaBase::setFForma ( FactorDeForma fForma )
{
   this->_fForma = fForma;
}

/**
 * @brief Método para consultar el factor de forma de la placa
 * @return Un valor del tipo PlacaBase::FactorDeForma, identificando el factor
 *         de forma de la placa
 */
PlacaBase::FactorDeForma PlacaBase::getFForma ( ) const
{
   return _fForma;
}

/**
 * @brief Método para consultar el número de serie de la placa base
 * @return Una cadena de texto que empieza por "PB-", con el número de serie de
 *         la placa base
 */
string PlacaBase::getNumSerie ()
{
   /* Redefinición del método de la superclase. Se añade más información al
    * número de serie, para dejar claro que se trata de una placa base */
   return ( "PB-" + _numSerie );
}

/**
 * @brief Operador de asignación
 * @param orig Objeto del que se copian los atributos
 * @return Una referencia al propio objeto, para poder hacer asignaciones en
 *         cascada (a=b=c)
 */
PlacaBase& PlacaBase::operator= ( const PlacaBase& orig )
{
   if ( this != &orig )
   {
      // Asigna los atributos heredados
      this->Componente::operator = (orig);

      // Asigna el resto de atributos
      _chipset = orig._chipset;
      _fForma = orig._fForma;
      _nPCIe = orig._nPCIe;
      _nUSB = orig._nUSB;
      _socket = orig._socket;
   }

   return ( *this );
}