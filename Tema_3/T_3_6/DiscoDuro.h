/** 
 * @brief Declaración de la clase DiscoDuro
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
 * Los objetos de esta clase representan discos duros. Ejemplo de relación de
 * \b herencia: un disco duro es también un componente de computadora
 * @brief Disco duro de computadora
 */
class DiscoDuro: public Componente
{
   public:
      /// Tipos de conexiones
      enum TipoConexion { SATA,   ///< Serial ATA
                          IDE,    ///< Integrated Drive Electronics
                          EIDE,   ///< Enhanced IDE
                          SCSI,   ///< Small Computer Interface
                          OTRA };
      static TipoConexion intoTipoConexion ( int valor );
      static bool isTipoConexion ( int valor );

   private:
      float _capacidad=0;         ///< Capacidad en Megabytes
      string _formato="---";          ///< Formato (dimensiones) del disco (2.5", 3.5"...)
      TipoConexion _conexion=OTRA;   ///< Tipo de conexión

   public:
      DiscoDuro ( ) = default;
      DiscoDuro ( string marca, string modelo, string nSerie, float capacidad,
                  string formato, TipoConexion conexion );
      DiscoDuro ( const DiscoDuro& orig );
      
      virtual ~DiscoDuro ( ) override;
      void setConexion ( TipoConexion conexion );
      TipoConexion getConexion ( ) const;
      void setFormato ( string formato );
      string getFormato ( ) const;
      void setCapacidad ( float capacidad );
      float getCapacidad ( ) const;
      string getNumSerie ();
      DiscoDuro& operator= ( const DiscoDuro& orig );
};

#endif /* DISCODURO_H */

