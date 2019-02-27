/**
 * @brief Declaración de la clase Componente
 * @file Componente.h
 * @author algarcia
 *
 * @date 11 de enero de 2016, 15:06
 */

#ifndef COMPONENTE_H
#define COMPONENTE_H

#include <string>

using std::string;

/**
 * Los objetos de esta clase representan componentes que se utilizan para la
 * fabricación de computadoras
 * @brief Pieza de computadora
 */
class Componente
{
   protected:
      string _marca="---";      ///< Marca del componente
      string _modelo="---";     ///< Modelo del componente
      string _numSerie="000000000000";   ///< Número de serie del componente
      float _precio=0;      ///< Precio del componente

   public:
      Componente () = default;
      Componente ( string marca, string modelo, string nSerie, float precio);
      Componente ( const Componente& orig );
      virtual ~Componente ( );
      void setPrecio ( float nPrecio );
      float getPrecio ( ) const;
      void setNumSerie ( string nNumSerie );
      string getNumSerie ( ) const;
      void setModelo ( string nModelo );
      string getModelo ( ) const;
      void setMarca ( string nMarca );
      string getMarca ( ) const;
      Componente& operator= ( const Componente& orig );
};

#endif /* COMPONENTE_H */