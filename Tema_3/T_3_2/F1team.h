/**
 * @file F1team.h
 * Archivo con la declaración de la clase F1team
 * @author algarcia
 * @date 2015-12-09
 */

#ifndef F1TEAM_H
#define	F1TEAM_H

#include "Piloto.h"

/**
 * Ejemplo de agregación: un equipo de Fórmula 1 agrega dos pilotos, pero
 * la desaparición del equipo no implica la desaparición de los pilotos
 * individuales. Igualmente, un piloto puede pasar a otro equipo.
 * La relación se establece a través de punteros
 * @brief Representación de un equipo de Fórmula 1
 */
class F1team
{
   private:
      Piloto *_p1;      ///< Puntero al primer piloto
      Piloto *_p2;      ///< Puntero al segundo piloto
      string _nombre;   ///< Nombre del equipo

   public:
      F1team ( );
      F1team ( const F1team& orig );
      F1team ( Piloto *nP1, Piloto *nP2, string nNombre );
      F1team ( Piloto &nP1, Piloto &nP2, string nNombre );
      virtual ~F1team ( );
      void setNombre ( string nNombre );
      string getNombre ( ) const;
      void setP2 ( Piloto* nP2 );
      bool existeP2 ();
      Piloto& getP2 ( ) const;
      void setP1 ( Piloto* nP1 );
      bool existeP1 ();
      Piloto& getP1 ( ) const;
      void sumaPtosCarrera ( int ptosP1, int ptosP2 );
      int getPtosConstructores () const;
      F1team& operator= ( const F1team& orig );
};

#endif	/* F1TEAM_H */

