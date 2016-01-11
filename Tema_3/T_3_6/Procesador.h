/** 
 * @file Procesador.h
 * @author algarcia
 *
 * @date 11 de enero de 2016, 15:20
 */

#ifndef PROCESADOR_H
#define PROCESADOR_H

/**
 * Los objetos de esta clase representan microprocesadores utilizados para la
 * fabricación de computadoras
 * @brief Microprocesador para computadoras
 */
class Procesador
{
   public:
      enum Arquitectura { x86_32, x86_64, ARM, ARM64, otra };

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

