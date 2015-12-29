/**
 * @file Vivienda.h
 * Archivo con la implementación de la clase Vivienda
 * @author algarcia
 * @date 2015-12-11
 */

#include <stdexcept>

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
         _dependencias[i] = new Dependencia ( *orig._dependencias[i] );
      }
   }
   catch ( std::bad_alloc ex )
   {
      throw ex;
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
 * @brief Método para añadir una habitación a la vivienda
 * @param nombre Nombre de la nueva habitación (p.ej.: "sala de juegos")
 * @param superficie Superficie en metros cuadrados de la habitación
 * @param estaLimpia Indica si la habitación está limpia (true) o sucia (false)
 * @return El número de habitaciones de la vivienda después de la ejecución del
 *         método
 * @throws std::bad_alloc Si hay problemas en la creación de la dependencia
 * @throws std::length_error Si se intenta añadir más dependencias de las
 *         permitidas (ver #_MAX_HAB_)
 * @throws std::invalid_argument Si la superficie de la habitación no es un
 *         número positivo
 */
int Vivienda::addDependencia (string nombre, float superficie, bool estaLimpia)
{
   if ( _numH < _MAX_HAB_ )
   {
      try
      {
         _dependencias [_numH] = new Dependencia ( nombre, superficie,
                                                   estaLimpia );
         _numH++;
      }
      catch ( std::invalid_argument ex1 )
      {
         throw std::invalid_argument ( "Vivienda::addDependencia: la superficie"
                                       " ha de ser un número positivo" );
      }
      catch ( std::bad_alloc ex2 )
      {
         throw ex2;
      }
   }
   else
   {
      throw std::length_error ( "Vivienda::addDependencia: la vivienda no admite"
                                " más habitaciones" );
   }

   return ( _numH );
}

/**
 * Si el nombre de la habitación que se pasa como parámetro no coincide
 * exactamente con el nombre de alguna de las dependencias de la vivienda, no
 * se hace nada
 * @brief Método para eliminar una habitación de la vivienda según su nombre
 * @param nombre Nombre de la dependencia que se quiere eliminar
 * @return El número de habitaciones tras el borrado
 */
int Vivienda::borraDependencia ( string nombre )
{
   
}

/**
 * @brief Método para eliminar una habitación de la vivienda según su posición
 * @param cual Índice que ocupa la habitación en el listado de dependencias de
 *        la vivienda. El valor ha de pertenecer al intervalo [1, número de
 *        habitaciones]
 * @return El número de habitaciones tras el borrado
 * @throws std::out_of_range Si se pasa un índice incorrecto
 */
int Vivienda::borraDependencia ( int cual )
{
   if ( ( cual > 0 ) && ( cual <= _numH ) )
   {
      
   }
   else
   {
      throw std::out_of_range ( "Vivienda::borraDependencia: el índice no se"
                                " corresponde con ninguna habitación" );
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