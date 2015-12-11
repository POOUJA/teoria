/**
 * @file Pareja.h
 * Archivo con la declaración de la clase Pareja
 * @author algarcia
 * @date 2015-12-09
 */

#ifndef PAREJA_H
#define	PAREJA_H

#include "Tenista.h"

/**
 * Ejemplo de agregación: un doble de tenis está formado por dos tenistas, pero
 * la desaparición del doble no implica la desaparición de los tenistas
 * individuales. La relación se establece a través de punteros
 * @brief Representación de un doble de tenis
 */
class Pareja
{
   private:
      Tenista *_t1;   ///< Puntero al primer miembro del doble
      Tenista *_t2;   ///< Puntero al segundo miembro del doble
      int _ranking;   ///< Posición de la pareja en el ranking de dobles

   public:
      Pareja ( );
      Pareja ( const Pareja& orig );
      Pareja ( Tenista *nT1, Tenista *nT2, int nRanking );
      Pareja ( Tenista &nT1, Tenista &nT2, int nRanking );
      virtual ~Pareja ( );
      void setRanking ( int nRanking );
      int getRanking ( ) const;
      void setT2 ( Tenista* nT2 );
      Tenista* getT2 ( ) const;
      void setT1 ( Tenista* nT1 );
      Tenista* getT1 ( ) const;
      string info ( ) const;
      Pareja& operator= ( const Pareja& orig );
};

#endif	/* PAREJA_H */

