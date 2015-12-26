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
 * @throws std::out_of_range Si la superficie de la dependencia no es un número
 *         positivo
 * @throws std::invalid_argument Si el tipo que se asigna a la dependencia no es
 *         válido (ver #dependencia_t)
 */
Dependencia::Dependencia ( string nombre, float superficie, dependencia_t tipo ):
                         _nombre (nombre), _superficie (superficie), _tipo (tipo)
{
   if ( superficie <= 0)
   {
      throw std::out_of_range ( "Dependencia::Dependencia: la superficie debe"
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
 *         un valor correcto
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

dependencia_t Dependencia::getTipo ( ) const
{
   return _tipo;
}

void Dependencia::setSuperficie ( float nSuperficie )
{
   this->_superficie = nSuperficie;
}

float Dependencia::getSuperficie ( ) const
{
   return _superficie;
}

void Dependencia::setNombre ( string nNombre )
{
   this->_nombre = nNombre;
}

string Dependencia::getNombre ( ) const
{
   return _nombre;
}

