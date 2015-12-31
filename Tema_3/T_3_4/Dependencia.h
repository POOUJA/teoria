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

/**
 * @brief Clase que representa una habitación en una vivienda
 */
class Dependencia
{
   private:
      string _nombre;      ///< Nombre de la dependencia
      float _superficie;   ///< Superficie en metros cuadrados
      bool _limpia;        ///< Indica si la dependencia está limpia

   public:
      Dependencia ( );
      Dependencia ( const Dependencia& orig );
      Dependencia ( string nombre, float superficie, bool estaLimpia );
      virtual ~Dependencia ( );
      void limpiar ();
      void ensuciar ();
      bool estaLimpia ( ) const;
      void setSuperficie ( float nSuperficie );
      float getSuperficie ( ) const;
      void setNombre ( string nNombre );
      string getNombre ( ) const;
      Dependencia& operator= ( const Dependencia& orig);
      string info () const;
};

#endif	/* DEPENDENCIA_H */

