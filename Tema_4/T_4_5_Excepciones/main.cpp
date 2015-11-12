/** Programa de ejemplo de uso de Excepciones
 * @file   main.cpp
 * @author jrbalsas@ujaen.es
 *
 * @date 4 de noviembre de 2015
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

#include "Libro.h"
#include "Revista.h"
#include "busqueda.h"
#include "ExNoEncontrado.h"
#include "ExConversion.h"

const int MAXEJEMPLARES=4; /*< Tamaño del vector de ejemplares*/
const std::string FICHEROEJEMPLARES="ejemplares.csv"; /*< Fichero donde se almacenan/recuperan los ejemplares*/

/**Borra un ejemplar del vector a partir de su identificador
 * @param[in,out] numEjemplares número de ejemplares almacenados en el vector
 * @pre El elemento a borrar debe estar ubicado en memoria dinámica
 * @pos Se libera la memoria dinámica ocupada por el elemento
 * @pos Se reduce en una unidad el parámetro numEjemplares
 * @pos Los elementos restantes se reagrupan al comienzo del vector. Puede variar el orden y posición de los elementos restantes
 * @throws ExNoEncontrado si no existe un elemento con el identificador indicado */
void BorraEjemplar(Ejemplar* ejemplares[], unsigned int &numEjemplares, std::string identificador)
                    throw (ExNoEncontrado) {
    int posEjemplar=BuscaElemento(ejemplares, numEjemplares,identificador);
    if (posEjemplar<0) 
        throw ExNoEncontrado("[BorraEjemplar] el ejemplar "+identificador+" no existe");
    delete ejemplares[posEjemplar];
    numEjemplares--;
    if (numEjemplares>0)
        ejemplares[posEjemplar]=ejemplares[numEjemplares];
}

/**Añade un ejemplar al vector de ejemplares
 * @param[in,out] numEjemplares número de ejemplares almacenados en el vector
 * @pre El ejemplar está almacenado en memoria dinámica
 * @pos Coloca el puntero al ejemplar proporcionado en la última posición válida del vector
 * @pos Se aumenta en una unidad el parámetro numEjemplares
 * @pos devuelve en numEjemplares el nuevo número de ejemplares almacenados en el vector
 * @throw std::out_of_range si no hay espacio en el vector
  */
void NuevoEjemplar(Ejemplar* ejemplares[], unsigned int &numEjemplares, Ejemplar *ejemplar) 
                    throw (std::out_of_range) {
    if (numEjemplares>=MAXEJEMPLARES)
        throw std::out_of_range("[NuevoEjemplar] se ha intentado sobrepasar el tamaño del vector");
    ejemplares[numEjemplares]=ejemplar;
    numEjemplares++;
}

/**Guarda en un fichero elementos que implementan la Interfaz CSV
   @param[in] elementos vector de punteros a objetos de la clase T
   @param[in] nombreFichero ruta del fichero donde se almacenarán los elementos
   @pre la clase T implementa la interfaz ItemCSV
   @return devuelve un valór lógico indicando si la operación ha tenido éxito*/
template<class T>
void GuardaCSV(T* elementos[], int numElementos, std::string nombreFichero ) {
    std::ofstream f;
    std::string linea;

    f.open(nombreFichero.c_str());
    
    if (f.good()) {
        for ( int i=0; i<numElementos; i++ ) {
            //Polimorfismo de métodos usando la interfaz ItemCSV
            linea=linea+elementos[i]->toCSV();
            f << linea << std::endl;
        };
        f.close();
    } else {
        throw std::runtime_error("[Guarda] No se han podido guardar los ejemplares en "+nombreFichero);
    }
}

/**Visualiza elementos que implementan la Interfaz CSV*/
void Visualiza(const ItemCSV &item ) {
    //Polimorfismo de objetos mediante referencias en paso de parámetro
    //Polimorfismo de método en llamada a método según el tipo de ejemplar (enlace dinámico)
    std::cout << item.toCSV();
}

/**Visualiza los ejemplares de un vector*/
void Visualiza(Ejemplar* elementos[], int numElementos ) {
    std::cout << "Ejemplares del catálogo" << std::endl
              << "======================="
              << std::endl;
    for (int i = 0; i < numElementos; i++) {
        std::cout << i+1 << ".- ";
        //Poliformismo de objetos mediante referencia
        Visualiza(*elementos[i]);
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

/**
 * Ejemplo de prueba clases Ejemplar y Libro
 */
int main(int argc, char** argv) {
    
    Ejemplar** ejemplares; /*<Vector para almacenar los ejemplares en memoria dinámica disponibles*/
    unsigned int numEjemplares=0; /*<Número de ejemplares disponibles*/

    try {
        //Reservamos memoria e inicializamos el vector de punteros a ejemplares
        ejemplares=new Ejemplar*[MAXEJEMPLARES];
        for (int i = 0; i < MAXEJEMPLARES; i++) {
            ejemplares[i]=0;
        }
    } catch (std::bad_alloc &e) {
        std::cerr << e.what() << ". No ha memoria para crear el vector de ejemplares";
        throw e; //Finalizamos el programa por no poder recuperar la situación actual
    }
    
    try {
        //Esta revista no se creará porque su ISSN es inválido
        Revista revistaBike("XXXXXX","Bike",2014,1,"Motorpress Ibérica", 2.5);
    } catch (std::domain_error &e) {
        std::cout << "No se ha podido inicializar un objeto. " << e.what() << std::endl ;
        //Consideramos que es un error recuperable
    };

    //Utilizamos polimorfirmo de objetos mediante punteros a clase base
    //Añadimos algunos ejemplares en memoria dinámica al vector
    try  {
        Revista revistaMUY("ISSN 1130-40810","Muy Interesante",2015,11,"G+J",3);
        Libro libroQuijote("9788467016901","El ingenioso hidalgo, Don Quijote de la Mancha",
                           2004, 1, "Miguel de Cervantes", "Espasa libros", 15.95);
        Libro libroPOO( "9786071512123","Programación en C/C++, Java y UML",
                        2014,2,"Luís Joyanes Aguilar", "MacGraw-Hill", 42);

        //Polimorfismo de objetos mediante punteros
        Ejemplar *previstaMUY=new Revista(revistaMUY);
        Ejemplar *plibroQuijote=new Libro(libroQuijote);

        NuevoEjemplar(ejemplares,numEjemplares,previstaMUY);
        NuevoEjemplar(ejemplares,numEjemplares,plibroQuijote);
        NuevoEjemplar(ejemplares,numEjemplares,
                      new Libro("8497320409","C++ Estandar",2001,1,"Enrique Hernández Orallo","Paraninfo",12));
        NuevoEjemplar(ejemplares,numEjemplares,new Libro(libroPOO));
        //El siguiente ejemplar no se podrá añadir por falta de espacio en el vector
        NuevoEjemplar(ejemplares,numEjemplares,new Libro(libroPOO));

    } catch (std::bad_alloc &e) {
        std::cerr <<  "[main] No hay memoria para crear más ejemplares "<< std::endl;
        throw e;  //No se puede continuar la aplicación

    } catch (std::domain_error &e) {
        std::cout << "No se ha podido inicializar un objeto. " << e.what() << std::endl;
        //Consideramos que es un error recuperable

    } catch (std::exception &e) {
        //Polimorfismo de objetos mediante referencias (excepción de tipo std::out_of_range)
        std::cout << "[main] El vector de ejemplares se ha quedado sin espacio. " 
                  << e.what() << std::endl << std::endl;
        //Continuamos el programa aunque no se han añadido todos los elementos
    }
    //Visualizamos todos los ejemplares
    Visualiza(ejemplares,numEjemplares);
   
    std::string cadena="11111111"; 
    try {
        BorraEjemplar(ejemplares,numEjemplares,cadena);
        //No se ejecuta puesto que el ejemplar no existe
        std::cout << "Ejemplar " << cadena << " borrado con éxito" << std::endl;
    } catch (ExNoEncontrado &e) {
        std::cout << "Aviso: el ejemplar " << cadena
                  << " no está disponible y no puede borrarse"
                  << std::endl;
    }
    
    //Volcamos los ejemplares a disco
    try {
        GuardaCSV(ejemplares,numEjemplares,FICHEROEJEMPLARES);
        std::cout << "Ejemplares almacenados en " << FICHEROEJEMPLARES << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << std::endl << "Liberando objetos en memoria dinámica" 
              << std::endl << std::endl;

    //Liberamos objetos en memoria dinámica
    for (int i = 0; i < numEjemplares; i++) {
        //Se utiliza enlace dinámico para llamar a los destructores específicos
        //de cada clase. Los destructores deben ser virtuales!
        delete ejemplares[i];
    } 
    delete[] ejemplares; //Liberamos vector de punteros a ejemplares
    
    std::cout   << std::endl << "Saliendo de programa principal"
                << std::endl << std::endl;
    
    return 0;
}
