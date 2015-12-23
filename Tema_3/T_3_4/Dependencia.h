/**
 * @file Dependencia.h
 * Archivo con la declaración de la clase Dependencia
 * @author algarcia
 * @date 2015-12-11
 */

#ifndef DEPENDENCIA_H
#define DEPENDENCIA_H

#include <string>

using std::string;

/// Tipos de dependencia
enum dependencia_t
{
   dorm,   ///< Identifica el tipo "dormitorio"
   coc,    ///< Identifica el tipo "cocina"
   sal,    ///< Identifica el tipo "salón"
   serv,   ///< Identifica el tipo "servicio"
   ent,    ///< Identifica el tipo "entrada"
   pas,    ///< Identifica el tipo "pasillo"
   otra    ///< Identifica un tipo de dependencia no especificado
};

class Dependencia
{
   private:
      string _nombre;        ///< Nombre de la dependencia
      float _superficie;     ///< Superficie en metros cuadrados
      dependencia_t _tipo;   ///< Tipo de la dependencia. Véase #dependencia_t
   public:
      Dependencia ( );
      Dependencia ( const Dependencia& orig );
      Dependencia ( string nombre, float superficie, dependencia_t tipo );
      virtual ~Dependencia ( );
      void setTipo ( dependencia_t nTipo );
      int getTipo ( ) const;
      void setSuperficie ( float nSuperficie );
      float getSuperficie ( ) const;
      void setNombre ( string nNombre );
      string getNombre ( ) const;
};

#endif	/* DEPENDENCIA_H */

