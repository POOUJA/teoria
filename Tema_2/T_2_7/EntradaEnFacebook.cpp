/**
 * @brief Implmentación de los métodos de la clase EntradaEnFacebook
 * @file EntradaEnFacebook.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 27 de septiembre de 2015, 11:01
 */

#include "EntradaEnFacebook.h"

/**
 * @brief Constructor por defecto de la clase
 * @post Aloja espacio para el bloque de comentarios por defecto
 */
EntradaEnFacebook::EntradaEnFacebook ( )
{  // Como todos los atributos tienen valores por defecto, no hace falta
   // asignarlos en la secuencia de inicialización
   _comentarios = new std::string [ _maxComentarios ];
}


/**
 * @brief Constructor parametrizado de la clase
 * @param id Identificador de la nueva entrada
 * @param texto Texto de la nueva entrada
 * @param maxComentarios Número máximo de comentarios que se permitirán en la
 *                       entrada
 * @post Aloja espacio para tantos comentarios como se indica en maxComentarios
 */
EntradaEnFacebook::EntradaEnFacebook ( int id, std::string texto,
                                       int maxComentarios ):
                                     _id ( id ), _texto ( texto )
                                     , _maxComentarios ( maxComentarios )
                                     , _numComentarios ( 0 )
                                     , _comentarios ( nullptr )
{  if ( maxComentarios > 0 )
   {  _comentarios = new std::string [ maxComentarios ];
   }
}

/**
 * @brief Constructor de copia
 * @param orig Entrada cuyos datos se van a copiar
 * @post También se copian los comentarios de la entrada original
 */
EntradaEnFacebook::EntradaEnFacebook ( const EntradaEnFacebook& orig ):
                                     _id ( orig._id )
                                     , _texto ( orig._texto )
                                     , _maxComentarios ( orig._maxComentarios )
                                     , _numComentarios ( orig._numComentarios )
                                     , _comentarios ( nullptr )
{  _comentarios = new std::string [ _maxComentarios ];
   for ( int i = 0; i < orig._numComentarios; ++i )
   {  _comentarios[i] = orig._comentarios[i];
   }
}

/**
 * @brief Destructor de clase
 * @post Destruye el objeto, liberando la memoria alojada para los comentarios,
 *       si fuera necesario
 */
EntradaEnFacebook::~EntradaEnFacebook()
{  // Liberamos la memoria que se reservó en el constructor
   if ( _comentarios )
   {  delete [] _comentarios;
      _comentarios = nullptr;
   }
}

/**
 * @brief Asigna un nuevo identificador a la entrada
 * @param id Nuevo identificador a asignar
 * @post No se hace comprobación alguna sobre el identificador (por ejemplo: no
 *       se comprueba si hay otra entrada con el mismo identificador)
 */
void EntradaEnFacebook::SetId ( int id )
{  this->_id = id;
}

/**
 * @brief Consulta el identificador de la entrada
 * @return El identificador de la entrada
 */
int EntradaEnFacebook::GetId() const
{  return _id;
}

/**
 * @brief Modifica el texto de la entrada
 * @param texto Modifica el texto de la entrada
 * @post Modifica el texto de la entrada
 */
void EntradaEnFacebook::SetTexto ( const std::string& texto )
{  this->_texto = texto;
}

/**
 * @brief Devuelve el texto de la entrada
 * @post Devuelve el texto de la entrada
 */
std::string EntradaEnFacebook::GetTexto() const
{  return _texto;
}

/**
 * @brief Devuelve el máximo número de comentarios que puede tener la entrada
 * @post Devuelve el máximo número de comentarios que puede tener la entrada
 */
int EntradaEnFacebook::GetMaxComentarios() const
{  return _maxComentarios;
}

/**
 * @brief Devuelve el número de comentarios que tiene la entrada
 * @post Devuelve el número de comentarios que tiene la entrada
 */
int EntradaEnFacebook::GetNumComentarios() const
{  return _numComentarios;
}

/**
 * @brief Devuelve el comentario ubicado en la posición pos
 * @param pos Posición del comentario que queremos devolver.
 * @post Devuelve el comentario ubicado en la posición pos
 * @post Si la posición no existe, devuelve la cadena vacía
 */
std::string EntradaEnFacebook::GetComentario(int pos) const
{  return ( ( pos < 0 ) || ( pos > _numComentarios ) ) ? "" : _comentarios[pos];
}

/**
 * @brief Añade un nuevo comentario a la entrada
 * @param nuevoComentario Texto del nuevo comentario
 * @post Si existe espacio en el vector de comentarios, añade el nuevo
 *       comentario, e incrementa el contador de comentarios
 */
void EntradaEnFacebook::AddComentario ( const std::string& nuevoComentario )
{  if ( _numComentarios < _maxComentarios )
   {  _comentarios[_numComentarios++] = nuevoComentario;
   }
}

/**
 * @brief Compara dos entras a partir de su id
 * @param otro Entrada cuyos datos se quieren comparar
 * @post Devuelve true si ambas entradas tienen el mismo id
 */
bool EntradaEnFacebook::operator== ( const EntradaEnFacebook& otro )
{  return _id==otro._id;
}

/**
 * @brief Compara alfabéticamente dos entradas en función del texto que contienen
 * @param otro Entrada cuyos datos se quieren comparar
 * @retval true Si esta entrada es menor o igual que la que se pasa por
 *              parámetro, desde un punto de vista alfabético
 * @retval false En otro caso
 */
bool EntradaEnFacebook::operator<= ( const EntradaEnFacebook& otro )
{  return _texto <= otro._texto;
}

/**
 * @brief Operador de asignación
 * @param otro Entrada cuyos datos se quieren copiar
 * @post Asigna los datos de otro en el objeto que recibe la llamada al método.
 * @post Devuelve el mismo objeto que ha recibido la llamada por referencia para
 *       "encadenar" asignaciones: a=b=c=d
 */
EntradaEnFacebook& EntradaEnFacebook::operator= ( const EntradaEnFacebook& orig )
{  if ( this != &orig )   // Comprueba que no se está intentando hacer a=a
   {  _texto = orig._texto;
      if ( _maxComentarios != orig._maxComentarios )
      {  // Si el bloque de comentarios tiene distinto tamaño, hay que
         // desecharlo y crear uno nuevo
         delete [] _comentarios;
         _comentarios = nullptr;
         _comentarios = new std::string [ orig._maxComentarios ];
         _maxComentarios = orig._maxComentarios;
      }

      _numComentarios = orig._numComentarios;

      for ( int i = 0; i < _numComentarios; i++ )
      {  _comentarios[i] = orig._comentarios[i];
      }

      for ( int i = _numComentarios; i < _maxComentarios; i++ )
      {  _comentarios[i] = "";
      }
   }

   // Devolvermos referencia al propio objeto para las asignaciones
   // encadenadas: a=b=c=d
   return *this;
}