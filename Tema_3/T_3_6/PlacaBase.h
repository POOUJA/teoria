/**
 * @brief Declaración de la clase PlacaBase 
 * @file PlacaBase.h
 * @author algarcia
 *
 * @date 11 de enero de 2016, 15:20
 */

#ifndef PLACABASE_H
#define PLACABASE_H

#include "Componente.h"

/**
 * Los objetos de esta clase representan placas base para la fabricación de
 * computadoras
 * @brief Placa base de computadora
 */
class PlacaBase: public Componente
{
   public:
      /// Factores de forma para placas base en el mercado
      enum FactorDeForma { ATX, MicroATX, MiniITX, NanoITX, PicoITX, otro };

   private:
      FactorDeForma _fForma;   ///< Factor de forma de la placa base
      int _nPCIe;              ///< Número de puertos PCI Express
      int _nUSB3;              ///< Número de puertos USB 3
      int _nUSB2;              ///< Número de puertos USB 2
      string _chipset;         ///< Modelo de chipset que lleva instalado
      string _socket;          ///< Modelo de socket que tiene la placa

   public:
      PlacaBase ( );
      PlacaBase ( const PlacaBase& orig );
      virtual ~PlacaBase ( );
      void setSocket ( string _socket );
      string getSocket ( ) const;
      void setChipset ( string _chipset );
      string getChipset ( ) const;
      void setNUSB2 ( int _nUSB2 );
      int getNUSB2 ( ) const;
      void setNUSB3 ( int _nUSB3 );
      int getNUSB3 ( ) const;
      void setNPCIe ( int _nPCIe );
      int getNPCIe ( ) const;
      void setFForma ( FactorDeForma _fForma );
      FactorDeForma getFForma ( ) const;
};

#endif /* PLACABASE_H */

