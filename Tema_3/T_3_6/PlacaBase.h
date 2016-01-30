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
      enum FactorDeForma { ATX,        ///< 305x244 mm
                           MicroATX,   ///< 244x244 mm
                           MiniITX,    ///< 170x170 mm
                           NanoITX,    ///< 120x120 mm
                           PicoITX,    ///< 100x72 mm
                           otro };
      static FactorDeForma intoFactorDeForma ( int valor );
      static bool isFactorDeForma ( int valor );

   private:
      FactorDeForma _fForma;   ///< Factor de forma de la placa base
      int _nPCIe;              ///< Número de puertos PCI Express
      int _nUSB;               ///< Número de puertos USB
      string _chipset;         ///< Modelo de chipset que lleva instalado
      string _socket;          ///< Modelo de socket que tiene la placa

   public:
      PlacaBase ( );
      PlacaBase ( string marca, string modelo, string nSerie, FactorDeForma fForma,
                  int nPCIe, int nUSB, string chipset, string socket );
      PlacaBase ( const PlacaBase& orig );
      virtual ~PlacaBase ( );
      void setSocket ( string socket );
      string getSocket ( ) const;
      void setChipset ( string chipset );
      string getChipset ( ) const;
      void setNUSB ( int nUSB );
      int getNUSB ( ) const;
      void setNPCIe ( int nPCIe );
      int getNPCIe ( ) const;
      void setFForma ( FactorDeForma fForma );
      FactorDeForma getFForma ( ) const;
      PlacaBase& operator= ( const PlacaBase& orig );
};

#endif /* PLACABASE_H */

