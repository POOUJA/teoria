/**
 * @file Vivienda.h
 * Archivo con la implementación de la clase Vivienda
 * @author algarcia
 * @date 2015-12-11
 */

#include <stdexcept>   // Para utilizar las excepciones estándar

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
      _habitaciones[i] = 0;
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
         _habitaciones[i] = new Dependencia ( *orig._habitaciones[i] );
      }
   }
   catch ( std::bad_alloc ba )
   {
      throw ba;
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
      _habitaciones[i] = 0;
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
      delete ( _habitaciones[i] );
      _habitaciones[i] = 0;
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
   if ( _numH >= _MAX_HAB_ )
   {
      throw std::length_error ( "Vivienda::addDependencia: la vivienda no admite"
                                " más habitaciones" );
   }

   try
   {
      _habitaciones [_numH] = new Dependencia ( nombre, superficie, estaLimpia );
      _numH++;
   }
   catch ( std::invalid_argument ia )
   {
      throw std::invalid_argument ( "Vivienda::addDependencia: la superficie"
                                    " ha de ser un número positivo" );
   }
   catch ( std::bad_alloc ba )
   {
      throw ba;
   }

   return ( _numH );
}

/**
 * Si el nombre de la habitación que se pasa como parámetro no coincide
 * exactamente con el nombre de alguna de las dependencias de la vivienda, no
 * se hace nada
 * @brief Método para eliminar la primera habitación de la vivienda cuyo nombre
 *        coincide con el que se pasa como parámetro
 * @param nombre Nombre de la dependencia que se quiere eliminar
 * @return El número de habitaciones tras el borrado
 */
int Vivienda::borraDependencia ( string nombre )
{
   int i = 0;
   bool hecho = false;
   
   while ( ( i < _numH ) && !hecho )
   {
      if ( _habitaciones[i]->getNombre () == nombre )
      {
         delete _habitaciones[i];
         _habitaciones[i] = 0;
         hecho = true;
      }

      i++;
   }
   
   if ( hecho )
   {
      return ( repasaDependencias () );
   }

   return ( _numH );
}

/**
 * @brief Método para eliminar una habitación de la vivienda según su posición
 * @param cual Índice que ocupa la habitación en el listado de dependencias de
 *        la vivienda. El valor ha de pertenecer al intervalo [1, número de
 *        habitaciones]
 * @return El número de habitaciones tras el borrado
 * @throws std::out_of_range Si se pasa como parámetro un índice incorrecto
 */
int Vivienda::borraDependencia ( int cual )
{
   if ( ( cual <= 0 ) || ( cual > _numH ) )
   {
      throw std::out_of_range ( "Vivienda::borraDependencia: el índice no se"
                                " corresponde con ninguna habitación" );
   }

   delete _habitaciones[cual-1];
   _habitaciones[cual-1] = 0;
   return ( repasaDependencias () );
}

/**
 * Si el nombre de la habitación que se pasa como parámetro no coincide
 * exactamente con el nombre de alguna de las dependencias de la vivienda, no
 * se hace nada
 * @brief Método para eliminar todas las habitaciones de la vivienda cuyos nombres
 *        coinciden con el que se pasa como parámetro
 * @param nombre Nombre de las dependencias que se quiere eliminar
 * @return El número de habitaciones tras el borrado
 */
int Vivienda::borraDependencias ( string nombre )
{
   int i = 0;
   bool hecho = false;
   
   for ( i = 0; i < _numH; i++ )
   {
      if ( _habitaciones[i]->getNombre () == nombre )
      {
         delete _habitaciones[i];
         _habitaciones[i] = 0;
         hecho = true;
      }
   }
   
   if ( hecho )
   {
      return ( repasaDependencias () );
   }

   return ( _numH );
}

/**
 * @brief Método para consultar una de las habitaciones de la vivienda
 * @param cual Índice de la dependencia a consultar. Su valor ha de estar en el
 *        intervalo [1, número de habitaciones]
 * @return Un puntero a la habitación consultada
 * @throws std::out_of_range Si el índice no se corresponde con ninguna
 *         habitación de la vivienda
 */
const Dependencia& Vivienda::getDependencia ( int cual )
{
   if ( ( cual <= 0 ) || ( cual > _numH ) )
   {
      throw std::out_of_range ( "Vivienda::getDependencia: el índice no se"
                                " corresponde con ninguna habitación" );
   }

   return ( *(_habitaciones[cual-1]) );
}

/**
 * @brief Método para cambiar el estado de una dependencia de "sucia" a "limpia"
 * @param cual Índice de la dependencia a limpiar. Debe estar en el rango [1,
 *        número de habitaciones]
 * @throws std::out_of_range Si se pasa como parámetro un índice incorrecto
 * @throws std::runtime_error Si la dependencia ya estaba limpia
 */
void Vivienda::limpiaDependencia ( int cual )
{
   if ( ( cual <= 0 ) || ( cual > _numH ) )
   {
      throw std::out_of_range ( "Vivienda::limpiaDependencia: el índice no se"
                                " corresponde con ninguna habitación" );
   }
      
   try
   {
      _habitaciones[cual-1]->limpiar ();
   }
   catch ( std::runtime_error rt )
   {
      throw std::runtime_error ( "Vivienda::limpiaDependencia: la habitación ya"
                                 " está limpia" );
   }
}

/**
 * @brief Método para cambiar el estado de una dependencia de "limpia" a "sucia"
 * @param cual Índice de la dependencia a ensuciar. Su valor ha de estar en el
 *        rango [1, número de habitaciones]
 * @throws std::out_of_range Si se pasa como parámetro un índice incorrecto
 * @throws std::runtime_error Si la dependencia ya estaba sucia
 */
void Vivienda::ensuciaDependencia ( int cual )
{
   if ( ( cual <= 0 ) || ( cual > _numH ) )
   {
      throw std::out_of_range ( "Vivienda::ensuciaDependencia: el índice no se"
                                " corresponde con ninguna habitación" );
   }
      
   try
   {
      _habitaciones[cual]->ensuciar ();
   }
   catch ( std::runtime_error rt )
   {
      throw std::runtime_error ( "Vivienda::ensuciaDependencia: la habitación"
                                 " ya está sucia" );
   }
}

/**
 * @brief Método para cambiar el estado de todas las habitaciones a "limpia"
 */
void Vivienda::limpiezaGeneral ()
{
   int i;
   
   for ( i = 0; i < _numH; i++ )
   {
      if ( _habitaciones[i]->estaLimpia () == false )
      {
         _habitaciones[i]->limpiar ();
      }
   }
}

/**
 * @brief Método para consultar la superficie total de la vivienda
 * @return La suma de las superficies de las habitaciones que forman la vivienda.
 *         Si la vivienda no tiene todavía habitaciones, devuelve 0
 */
float Vivienda::getSuperficie ()
{
   float suma = 0;
   int i;
   
   for ( i = 0; i < _numH; i++ )
   {
      suma += _habitaciones[i]->getSuperficie ();
   }
   
   return ( suma );
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
 * @brief Método para consultar el número de habitaciones de la vivienda
 * @return El número de habitaciones de la vivienda. 0 Si aún no tiene ninguna
 */
int Vivienda::getNumDependencias () const
{
   return ( _numH );
}

/**
 * Se crean habitaciones nuevas, copiando las habitaciones de la vivienda
 * original
 * @brief Operador de asignación
 * @param orig Vivienda de la que se copian los atributos
 * @return Una referencia al objeto, para que se puedan hacer asignaciones en
 *         cascada (a=b=c)
 * @throws std::bad_alloc Si hay algún problema creando las habitaciones
 */
Vivienda &Vivienda::operator = (const Vivienda& orig)
{
   int i;
   
   if ( this != &orig )
   {
      _direccion = orig._direccion;
      _numH = orig._numH;

      // Si la vivienda ya tenía dependencias, las borra
      if ( _numH > 0 )
      {
         for ( i = 0; i < _numH; i++ )
         {
            delete _habitaciones[i];
            _habitaciones[i] = 0;
         }
      }

      try
      {   
         for ( i = 0; i < _numH; i++ )
         {
            _habitaciones[i] = new Dependencia ( *orig._habitaciones[i] );
         }
      }
      catch ( std::bad_alloc ex )
      {
         throw ex;
      }
   }
   
   return ( *this );
}

/**
 * Este método repasa la estructura que guarda las habitaciones y la compacta en
 * caso de que se encuentre algún hueco. Se debe llamar cada vez que haya un
 * borrado de habitaciones
 * @brief Método para reorganizar las habitaciones
 * @return El número de habitaciones que tiene la vivienda
 */
int Vivienda::repasaDependencias ()
{
   int i, contador;
   Dependencia *aux[_MAX_HAB_];
   
   // Utiliza un array auxiliar, que inicializa a 0
   for ( i = 0; i < _MAX_HAB_; i++ )
   {
      aux[i] = 0;
   }

   // Copia los punteros que son distintos de 0 en el array auxiliar, y los va
   // contando
   contador = 0;

   for ( i = 0; i < _MAX_HAB_; i++ )
   {
      if ( _habitaciones[i] != 0 )
      {
         aux[contador] = _habitaciones[i];
         contador++;
      }
   }
   
   // Copia de vuelta los punteros al array de dependencias
   for ( i = 0; i < contador; i++ )
   {
      _habitaciones[i] = aux[i];
      aux[i] = 0;
   }
   
   // Pone el resto de punteros del array de dependencias a 0
   for ( ; i< _MAX_HAB_; i++ )
   {
      _habitaciones[i] = 0;
   }
   
   _numH = contador;
   return ( _numH );
}