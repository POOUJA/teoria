/** 
 * @brief Declaración de la clase Procesador
 * @file Procesador.h
 * @author algarcia
 *
 * @date 11 de enero de 2016, 15:20
 */

#ifndef PROCESADOR_H
#define PROCESADOR_H

#include "Componente.h"

/**
 * Los objetos de esta clase representan microprocesadores utilizados para la
 * fabricación de computadoras
 * @brief Microprocesador para computadoras
 */
class Procesador: public Componente
{
   public:
      /// Tipos de arquitectura
      enum Arquitectura { x86_32,   ///< Intel IA-32 (32 bits)
                          x86_64,   ///< Intel IA-64, o AMD64 (64 bits)
                          ARM,      ///< ARM (32 bits)
                          ARM64,    ///< ARM (64 bits)
                          otra };
      static Arquitectura intoArquitectura ( int valor );
      static bool isArquitectura ( int valor );

   private:
      float _velocidad;    ///< Velocidad de reloj del procesador en GHz
      string _socket;      ///< Modelo de socket al que se ajusta el procesador
      Arquitectura _arq;   ///< Arquitectura del procesador

   public:
      Procesador ( );
      Procesador ( const Procesador& orig );
      virtual ~Procesador ( );
      void setArq ( Arquitectura _arq );
      Arquitectura getArq ( ) const;
      void setSocket ( string _socket );
      string getSocket ( ) const;
      void setVelocidad ( float _velocidad );
      float getVelocidad ( ) const;
};

#endif /* PROCESADOR_H */

