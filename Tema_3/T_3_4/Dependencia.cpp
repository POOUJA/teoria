/**
 * @file Dependencia.cpp
 * Archivo con la implementación de la clase Dependencia
 * @author algarcia
 * @date 2015-12-11
 */

#include <stdexcept>

#include "Dependencia.h"

/**
 * Inicializa una dependencia del tipo "otra", con superficie 0 y nombre "---"
 * @brief Constructor por defecto
 */
Dependencia::Dependencia ( ): _nombre ("---"), _superficie(0), _tipo(otra)
{
}

/**
 * @brief Constructor de copia
 * @param orig
 */
Dependencia::Dependencia ( const Dependencia& orig ): _nombre (orig._nombre),
                                                      _superficie (orig._superficie),
                                                      _tipo (orig._tipo)
{
}

/**
 * Crea una nueva dependencia con los valores que se le pasan como parámetros
 * @brief Constructor parametrizado
 * @param nombre Nombre de la nueva dependencia
 * @param superficie Superficie. Debe ser un número positivo
 * @param tipo Tipo de la nueva dependencia
 * @throws std::invalid argument Si la superficie de la dependencia no es un
 *         número positivo, o si el tipo que se asigna a la dependencia no es
 *         válido (ver #dependencia_t)
 */
Dependencia::Dependencia ( string nombre, float superficie, dependencia_t tipo ):
                         _nombre (nombre), _superficie (superficie), _tipo (tipo)
{
   if ( superficie <= 0)
   {
      throw std::invalid_argument ( "Dependencia::Dependencia: la superficie debe"
                                    " ser un número positivo" );
   }
   
   switch ( tipo )
   {
      case dorm:
      case coc:
      case sal:
      case serv:
      case ent:
      case pas:
      case otra:
         break;
      default:
         throw std::invalid_argument ( "Dependencia::Dependencia: tipo de"
                                       " Dependencia no soportado" );
         break;
   }
}

/**
 * @brief Destructor por defecto
 */
Dependencia::~Dependencia ( )
{
}

/**
 * @brief Modificador del tipo de dependencia
 * @param nTipo Nuevo tipo de la dependencia
 * @throws std::invalid_argument Si el valor de tipo que se quiere asignar no es
 *         un valor correcto (ver #dependencia_t)
 */
void Dependencia::setTipo ( dependencia_t nTipo )
{
   switch ( nTipo )
   {
      case dorm:
      case coc:
      case sal:
      case serv:
      case ent:
      case pas:
      case otra:
         this->_tipo = nTipo;
         break;
      default:
         throw std::invalid_argument ( "Dependencia::setTipo: tipo de"
                                       " Dependencia no soportado" );
         break;
   }
}

/**
 * @brief Observador del tipo de dependencia
 * @return Un valor de #dependencia_t que identifica el tipo de dependencia
 */
dependencia_t Dependencia::getTipo ( ) const
{
   return _tipo;
}

/**
 * @brief Modificador de la superficie de la dependencia
 * @param nSuperficie Nuevo valor de superficie a asignar. Ha de ser positivo
 * @throws std::invalid_argument Si el valor de la superficie no es un número
 *         positivo
 */
void Dependencia::setSuperficie ( float nSuperficie )
{
   if ( nSuperficie > 0 )
   {
      this->_superficie = nSuperficie;
   }
   else
   {
      throw std::invalid_argument ( "Dependencia::setSuperficie: el valor de"
                                    " superficie ha de ser un número positivo" );
   }
}

/**
 * @brief Método para consultar la superficie de la dependencia
 * @return El valor de superficie de la dependencia
 */
float Dependencia::getSuperficie ( ) const
{
   return _superficie;
}

/**
 * @brief Modificador para el nombre de la dependencia
 * @param nNombre Nuevo nombre para la dependencia
 */
void Dependencia::setNombre ( string nNombre )
{
   this->_nombre = nNombre;
}

/**
 * @brief Observador para el nombre de la dependencia
 * @return El nombre de la dependencia
 */
string Dependencia::getNombre ( ) const
{
   return _nombre;
}

/**
 * @brief Operador de asignación
 * @param orig Objeto del que se copian los atributos
 * @return Una referencia al propio objeto, para que se puedan hacer
 *         asignaciones en cadena (a=b=c)
 */
Dependencia& Dependencia::operator = (const Dependencia& orig)
{
   _nombre = orig._nombre;
   _superficie = orig._superficie;
   _tipo = orig._tipo;

   return ( *this );
}