/**
 * @file Vivienda.h
 * Archivo con la implementación de la clase Vivienda
 * @author algarcia
 * @date 2015-12-11
 */

#include "Vivienda.h"

/**
 * La dirección inicial de la vivienda es "---", sin habitaciones
 * @brief Constructor por defecto
 */
Vivienda::Vivienda ( ): _direccion ("---"), _numH (0)
{
   int i;
   
   for ( i = 0; i < _MAX_HAB_; i++ )
   {
      _dependencias[i] = 0;
   }
}

/**
 * Crea una nueva vivienda, copiando los atributos y creando copias de las
 * habitaciones
 * @brief Constructor de copia
 * @param orig Vivienda de la que se copian los atributos
 * @throws std::bad_alloc Si hay problemas creando las nuevas habitaciones
 */
Vivienda::Vivienda ( const Vivienda& orig ): _direccion (orig._direccion),
                                             _numH (orig._numH)
{
   int i;

   try
   {   
      for ( i = 0; i < _numH; i++ )
      {
         _dependencias[i] = new Dependencia ( orig._dependencias[i] );
      }
   }
   catch ( std::bad_alloc ex )
   {
      throw std::bad_alloc ( "Vivienda::Vivienda: error de memoria al crear"
                             " las habitaciones" );
   }
}

/**
 * La nueva vivienda se crea sin habitaciones
 * @brief Constructor parametrizado
 * @param direccion Cadena de texto con la dirección de la nueva vivienda
 */
Vivienda::Vivienda ( string direccion ): _direccion(direccion), _numH(0)
{
   int i;
   
   for ( i = 0; i < _MAX_HAB_; i++ )
   {
      _dependencias[i] = 0;
   }
}

/**
 * Elimina las dependencias que forman parte de la vivienda
 * @brief Destructor
 */
Vivienda::~Vivienda ( )
{
   int i;
   
   for ( i = 0; i < _numH; i++ )
   {
      delete ( _dependencias[i] );
      _dependencias[i] = 0;
   }
}

/**
 * @brief Método para cambiar la dirección de la vivienda
 * @param nDireccion Nueva dirección de la vivienda. No se hace ninguna
 *        comprobación sobre su valor
 */
void Vivienda::setDireccion ( string nDireccion )
{
   this->_direccion = nDireccion;
}

/**
 * @brief Método para consultar la dirección de la vivienda
 * @return Una cadena de texto con la dirección de la vivienda
 */
string Vivienda::getDireccion ( ) const
{
   return _direccion;
}

/**
 * @brief Método para añadir una nueva dependencia
 * @param nombre Nombre de la nueva dependencia
 * @param superficie Superficie (en metros cuadrados) de la nueva dependencia
 * @param tipo Identifica el tipo de la dependencia (ver #dependencia_t)
 * @return El número de dependencias en la vivienda
 * @throws std::bad_alloc Si hay problemas en la creación de la dependencia
 * @throws std::length_error Si se intenta añadir más dependencias de las
 *         permitidas (ver #_MAX_HAB_)
 */
int Vivienda::addDependencia ( string nombre, float superficie,
                               dependencia_t tipo )
{
}




/*      int repasaDependencias ();

   public:
      int addDependencia ( string nombre, float superficie, dependencia_t tipo );
      int borraDependencia ( string nombre );
      int borraDependencia ( dependencia_t tipo );
      float getSuperficie ();
      void setDireccion ( string nDireccion );
      string getDireccion ( ) const;
      int getNumDependencias ();
      Vivienda& operator= ( const Vivienda& orig );
*/