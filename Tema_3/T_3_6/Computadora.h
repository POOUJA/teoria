/** 
 * @brief Declaración de la clase Computadora
 * @file Computadora.h
 * @author algarcia
 *
 * @date 11 de enero de 2016, 15:19
 */

#ifndef COMPUTADORA_H
#define COMPUTADORA_H

#include <string>
#include "Componente.h"

using std::string;

/**
 * Los objetos de esta clase representan computadoras como \b agregación de
 * componentes de diversa naturaleza (procesadores, discos duros,...)
 * @brief Representación simple de computadoras
 */
class Computadora
{
   public:
      /// Número máximo de piezas en una computadora
      static const int _MAX_COMP_ = 10;

   private:
      string _marca;                     ///< Marca de la computadora
      string _modelo;                    ///< Modelo de la computadora
      int _compradoEn;                   ///< Año en que fue comprada
      Componente* _piezas[_MAX_COMP_];   ///< Piezas de la computadora
      int _nPiezas;                      ///< Número de piezas de la computadora

   public:
      Computadora ( );
      Computadora ( string nMarca, string nModelo, int year );
      Computadora ( const Computadora& orig );
      virtual ~Computadora ( );
      int getNPiezas ( ) const;
      void addPieza ( Componente* nuevaP );
      Componente& getPieza ( int cual ) const;
      Componente* quitaPieza ( int cual );
      void setCompradoEn ( int year );
      int getCompradoEn ( ) const;
      void setModelo ( string nModelo );
      string getModelo ( ) const;
      void setMarca ( string nMarca );
      string getMarca ( ) const;
      float getPrecio ( ) const;
      Computadora& operator= ( const Computadora& orig );
};

#endif /* COMPUTADORA_H */

