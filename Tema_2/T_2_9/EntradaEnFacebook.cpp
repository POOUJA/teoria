/** 
 * @brief Implmentación de los métodos de la clase EntradaEnFacebook con excepciones
 * @file EntradaEnFacebook.cpp
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 * @date 27 de septiembre de 2015, 11:01
 */

#include <iostream>
#include "EntradaEnFacebook.h"

/**
 * @brief Constructor por defecto de la clase
 * @param texto Texto del comentario en Facebook
 * @param maxComentarios Máximo número de comentarios que se permiten para esta entrada
 */
EntradaEnFacebook::EntradaEnFacebook(std::string texto, int maxComentarios)
try :
    texto(texto)
    , maxComentarios(maxComentarios)
    , numComentarios(0)
    , comentarios(0) {
        // Estos throw NO serían capturados por el catch que acompaña al try anterior
    if (maxComentarios <= 0) throw std::string("EntradaEnFacebook.cpp, constructor: el valor de maxComentarios debe ser mayor que 0");
    if (maxComentarios > 100) throw std::string("EntradaEnFacebook.cpp, constructor: el valor de maxComentarios debe ser menor que 100");
    comentarios = new std::string[maxComentarios];
} catch (std::string e) {
    // Este catch solo podría capturar excepciones lanzadas en los constructores de sus atributos
    std::cerr << "Error en constructor por defecto de EntradaEnFacebook: " << e << std::endl;
    throw e;
}

/**
 * @brief Constructor de copia: se duplican los comentarios.
 * @param orig Objeto cuyos datos se van a copiar
 */
EntradaEnFacebook::EntradaEnFacebook(const EntradaEnFacebook& orig)
try :
    texto(orig.texto)
    , maxComentarios(orig.maxComentarios)
    , numComentarios(0)
    , comentarios(0) {
    comentarios = new std::string[maxComentarios];
    for (int i = 0; i < orig.numComentarios; ++i) {
        comentarios[i] = orig.comentarios[i];
    }
    numComentarios = orig.numComentarios;
} catch (std::string e) {
    std::cerr << "Error en constructor por copia de EntradaEnFacebook: " << e << std::endl;
    throw e;
}

/**
 * @brief Destructor de clase
 * @post Destruye el objeto
 */
EntradaEnFacebook::~EntradaEnFacebook() {
    // Liberamos la memoria que se reservó en el constructor
    if (comentarios) {
        delete [] comentarios;
        comentarios = 0;
    }
}

/**
 * @brief Modifica el texto de la entrada
 * @param texto Modifica el texto de la entrada
 * @post Modifica el texto de la entrada
 */
void EntradaEnFacebook::SetTexto(std::string texto) {
    this->texto = texto;
}

/**
 * @brief Devuelve el texto de la entrada
 * @post Devuelve el texto de la entrada
 */
std::string EntradaEnFacebook::GetTexto() const {
    return texto;
}

/**
 * @brief Devuelve el máximo número de comentarios máximo que puede tener la entrada
 * @post Devuelve el máximo número de comentarios máximo que puede tener la entrada 
 */
int EntradaEnFacebook::GetMaxComentarios() const {
    return maxComentarios;
}

/**
 * @brief Devuelve el número de comentarios que tiene la entrada
 * @post Devuelve el número de comentarios que tiene la entrada
 */
int EntradaEnFacebook::GetNumComentarios() const {
    return numComentarios;
}

/**
 * @brief Devuelve el comentario ubicado en la posición pos
 * @param pos Posición del comentario que queremos devolver.
 * @post Devuelve el comentario ubicado en la posición pos
 * @post Si la posición no existe, lanza una excepción
 */
std::string EntradaEnFacebook::GetComentario(int pos) const {
    if (pos < 0 || pos > numComentarios) throw (std::string) "EntradaEnFacebook.cpp, método GetComentario: La posición solicitada no existe";
    return comentarios[pos];
}

/**
 * @@brief Añade un nuevo comentario a la entrada
 * @param nuevoComentario Texto del nuevo comentario
 * @post Si existe espacio en el vector de comentarios, añade el nuevo comentario, e incrementa el contador de comentarios
 * @post Si no existe espacio suficiente, lanza una excepción.
 */
void EntradaEnFacebook::AddComentario(std::string nuevoComentario) {
    if (numComentarios < maxComentarios) {
        comentarios[numComentarios++] = nuevoComentario;
    } else {
        throw (std::string) "EntradaEnFacebook.cpp, método AddComentario: No se pueden añadir más comentarios a esta entrada";
    }
}

/**
 * @brief Compara alfabéticamente dos entras en función del texto que contienen
 * @param otro Entrada cuyos datos se quieren comparar
 * @post Devuelve true si esta entrada es menor o igual que la que se pasa por parámetro, desde un punto de vista alfabético
 */
bool EntradaEnFacebook::operator<=(const EntradaEnFacebook& otro) {
    return texto <= otro.texto;
}

/**
 * @brief Operador asignación
 * @param otro Entrada cuyos datos se quieren copiar
 * @post Asigna los datos de otro en el objeto que recibe la llamada al método.
 * @post Devuelve el mismo objeto que ha recibido la llamada por referencia para "encadenar" asignaciones: a=b=c=d
 */
EntradaEnFacebook& EntradaEnFacebook::operator=(const EntradaEnFacebook& orig) {
    if (this != &orig) {
        texto = orig.texto;
        maxComentarios = orig.maxComentarios;
        if (comentarios) {
            delete [] comentarios;
            comentarios = 0;
        }
        if (maxComentarios > 0) {
            comentarios = new std::string[maxComentarios];
            if (comentarios) {
                numComentarios = orig.numComentarios;
                for (int i = 0; i < orig.numComentarios; ++i) {
                    comentarios[i] = orig.comentarios[i];
                }
            }
        }
    }
    // Devolvermos referencia al propio objeto para las asignaciones encadenadas: a=b=c=d
    return *this;
}