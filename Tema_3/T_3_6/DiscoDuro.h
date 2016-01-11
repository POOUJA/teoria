/** 
 * @file DiscoDuro.h
 * @author algarcia
 *
 * @date 11 de enero de 2016, 15:19
 */

#ifndef DISCODURO_H
#define DISCODURO_H

#include <string>
#include "Componente.h"

using std::string;

/**
 * @brief
 */
class DiscoDuro: public Componente
{
   private:
      float _capacidad;   ///< Capacidad en Megabytes
      string _formato;    ///< Formato (dimensiones) del disco (2.5", 3.5"...)
      string _conexion;   ///< Tipo de conexión (SATA, IDE...)

   public:
      DiscoDuro ( );
      DiscoDuro ( const DiscoDuro& orig );
      virtual ~DiscoDuro ( );
      void setConexion ( string _conexion );
      string getConexion ( ) const;
      void setFormato ( string _formato );
      string getFormato ( ) const;
      void setCapacidad ( float _capacidad );
      float getCapacidad ( ) const;
};

#endif /* DISCODURO_H */

