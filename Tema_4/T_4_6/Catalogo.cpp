/** 
 * @file   Catalogo.cpp
 * @author jrbalsas@ujaen.es
 *
 * @date 16 de octubre de 2015, 10:45
 */

#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <fstream>

#include "Catalogo.h"
#include "busqueda.h"
#include "ExNoEncontrado.h"

/**Constructor por defecto*/
Catalogo::Catalogo():_numEjemplares(0),_posIteracion(0) {
    ejemplares=new Ejemplar*[MAXEJEMPLARES];
}

/**Constructor de copia*/
Catalogo::Catalogo(const Catalogo& orig): _numEjemplares(orig._numEjemplares)
                                          ,_posIteracion(0) {
    
    ejemplares=new Ejemplar*[MAXEJEMPLARES];
    
    for (int i = 0; i < _numEjemplares; i++) {
        
        //Cada ejemplar del catálogo original devuelve una copia suya para
        //el nuevo catálogo
        ejemplares[i]=dynamic_cast<Ejemplar*>( orig.ejemplares[i]->copia() );
    }            
}
/**Destructor*/
Catalogo::~Catalogo() noexcept {
    std::cout << "Destruyendo catálogo" << std::endl;
    vaciar(); //Eliminamos ejemplares que queden
    delete[] ejemplares; //Liberamos el vector de punteros
    
}

/**Devuelve el número de ejemplares que hay en el catálogo*/
int Catalogo::getNumEjemplares() const {
    return _numEjemplares;
}

/**Borrar todos los ejemplares de un catálogo */
void Catalogo::vaciar() {
    //Liberamos ejemplares creados en el catálogo
    for (int i = 0; i < _numEjemplares; i++) {
        delete ejemplares[i];
    }
    _numEjemplares=0;
}

/**Añadir una copia de un libro al catálogo
 @throw std::out_of_range si no hay espacio suficiente en el catálogo*/
void Catalogo::nuevoLibro(const Libro& libro) {
    if (_numEjemplares==MAXEJEMPLARES) 
        throw std::out_of_range("[Catalogo]: Espacio insuficiente en catálogo para añadir un nuevo libro");
    ejemplares[_numEjemplares]=new Libro(libro);
    _numEjemplares++;
}

/**Añadir una copia de una revista al catálogo
 @throw std::out_of_range si no hay espacio suficiente en el catálogo*/
void Catalogo::nuevaRevista(const Revista& revista) {
    if (_numEjemplares==MAXEJEMPLARES) 
        throw std::out_of_range("[Catalogo]: Espacio insuficiente en catálogo para añadir una nueva revista");
    ejemplares[_numEjemplares]=new Revista(revista);
    _numEjemplares++;
}

/**Añadir una copia de un ejemplar al catálogo
 *  @throw std::out_of_range si no hay espacio suficiente en el catálogo*/
void Catalogo::nuevoEjemplar(const Ejemplar& ejemplar) {
    if (_numEjemplares==MAXEJEMPLARES) 
        throw std::out_of_range("[Catalogo::nuevoEjemplar]: Espacio insuficiente en catálogo para añadir un nuevo ejemplar");
    ejemplares[_numEjemplares]=dynamic_cast<Ejemplar*>(ejemplar.copia());
    _numEjemplares++;
}

/**Devuelve el ejemplar de un catálogo por su identificador
 @throw NoEncontrado si el ejemplar en cuestión no está en el catálogo*/
Ejemplar& Catalogo::buscaEjemplar(std::string idEjemplar) {

   int posEncontrado=buscaElemento(ejemplares,_numEjemplares,idEjemplar);
   if (posEncontrado<0) 
       throw ExNoEncontrado("[Catalogo::buscaEjemplar] el ejemplar no se encuentra en el Catálogo");
   return *ejemplares[posEncontrado];
}

/**Borra el primer ejemplar del catálogo a partir de su identificador
 @throw NoEncontrado si el ejemplar en cuestión no está en el catálogo
*/
void Catalogo::borraEjemplar(std::string idEjemplar) {
   int posEncontrado=buscaElemento(ejemplares,_numEjemplares,idEjemplar);
   if (posEncontrado<0) 
       throw ExNoEncontrado("[Catalogo::borraEjemplar] el ejemplar "+idEjemplar
                            +" no se encuentra en el Catálogo");
   
   delete ejemplares[posEncontrado];
   _numEjemplares--;
   if (_numEjemplares>0) {
       //Sustituimos el elemento borrado por último para no dejar huecos en el vector de ejemplares
        ejemplares[posEncontrado]=ejemplares[_numEjemplares];
   }
}

/**Devuelve un ejemplar al azar del Catálogo
 @throw NoEncontrado si el catálogo está vacío
*/
Ejemplar& Catalogo::ejemplarAlAzar() {
    if (_numEjemplares==0)
       throw ExNoEncontrado("[Catalogo::ejemplarAlAzar] El catálogo está vacío");
    return *ejemplares[rand()%_numEjemplares];
}

/** Guarda los ejemplares del catálogo en un fichero 
 @throw std::runtime_error si no se pueden volcar los datos al fichero*/
void Catalogo::guardaEnFichero(std::string nombreFichero) {
    std::ofstream f;
    std::string linea;
    
    f.open(nombreFichero.c_str());
    
    if (f.good()) {
        for ( int i=0; i<_numEjemplares; i++ ) {
            //Añadimos el tipo de cada ejemplar en la primera columna de cada línea del fichero CSV
            if (dynamic_cast<Libro*>(ejemplares[i])!=0) {
                linea="libro;";
            } else if (dynamic_cast<Revista*>(ejemplares[i])!=0) {
                linea="revista;";
            } else {
                //Ejemplar de tipo desconocido
                linea="desconocido;";
            }
            linea=linea+ejemplares[i]->toCSV();
            f <<  linea << std::endl;
        };
        f.close();        
    } else {
        throw std::runtime_error("[Catalogo::guardaEnFichero] No puede abrirse el fichero "+nombreFichero);
    }
}

/** Recupera de un fichero CSV los ejemplares de un catálogo
    @throw std::logic_error si encuentra algún ejemplar que no es válido
    @throw std::runtime_error si no se puede acceder al fichero
 */
void Catalogo::recuperaDeFichero(std::string nombreFichero) {
    std::ifstream f;
    std::string tipo,linea;
    
    if (_numEjemplares>0) {
        //Si el catálogo ya tiene ejemplares, borrarlos previamente
        vaciar();
    }
    f.open( nombreFichero.c_str() );

    if ( f.good() ) {
        while( !f.eof() ) {
            std::getline( f, tipo, ';' );
            if (tipo=="") {
                continue; //ignoramos líneas vacías
            }else if (tipo=="libro") {
                ejemplares[_numEjemplares]=new Libro();
            }else if (tipo=="revista") {
                ejemplares[_numEjemplares]=new Revista();
            }else {
                throw std::logic_error("[Catalogo::recuperaDeFichero] El fichero contiene ejemplares de tipo desconocido");                
            };
            
            std::getline(f,linea);
            ejemplares[_numEjemplares]->fromCSV(linea);
            _numEjemplares++;            
            }
            f.close();
    } else {
        throw std::runtime_error("[Catalogo::recuperaDeFichero] No puede abrirse el fichero "+nombreFichero);
    }

}

//Métodos para iterar sobre ejemplares del catálogo

/**Inicia el catálogo para iterar sobre sus elementos
   @see siguiente(), finalIteracion()*/
void Catalogo::iniciaIteracion()  {
    _posIteracion=0;
}

/**Devuelve el siguiente ejemplar del catálogo
   @pre Se ha inicializado la iteración con iniciaIteracion
   @pre No se ha modificado el catálogo tras iniciar la iteración
   @throw   std::out_of_range si no hay elementos o si se ha intentado obtener un 
 *          ejemplar habiendo finalizado la iteración*/
Ejemplar& Catalogo::siguienteEjemplar() {
    if (_numEjemplares==0 || _posIteracion>=_numEjemplares) {
        throw std::out_of_range("[Catalogo::siguiente] No más ejemplares en el catálogo");
    }
    return *(ejemplares[_posIteracion++]);
}

/**Indica si se ha llegado al final de la iteración y no quedan ejemplares que obtener
   @pre Se ha inicializado la iteración con iniciaIteracion*/
bool Catalogo::finalIteracion()  {
    return _posIteracion==_numEjemplares;
}



