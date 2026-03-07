/** Funciones de utilidad para la búsqueda de elementos
 * @file   busqueda.h
 * @author jrbalsas@ujaen.es
 *
 * @date 13 de octubre de 2015, 13:03
 */

#ifndef BUSQUEDA_H
#define	BUSQUEDA_H

/**Localiza un elemento en un vector
   @pre  Los elementos del vector deben poder compararse con el operador ==
   @post Devuelve la posicion del vector donde se encuentra la primera ocurrencia del elemento
   @post Devuelve -1 si el elemento no se encuentra en el vector
 */
template<typename T>
int buscaElemento(T elementos[], int numElementos, const T& elemento) {

    int posEncontrado=-1;
    
    for (int i=0; i<numElementos && posEncontrado==-1; i++) {
        if (elementos[i]==elemento) 
            posEncontrado=i;
    }
    return posEncontrado;
    
}

/**Localiza un elemento en un vector de punteros a elementos
   @pre  Los elementos del vector deben poder compararse con el operador ==
   @post Devuelve la posicion del vector donde se encuentra la primera ocurrencia del elemento
   @post Devuelve -1 si el elemento no se encuentra en el vector
 */
template<typename T>
int buscaElemento(T* elementos[], int numElementos, const T& elemento) {

    int posEncontrado=-1;
    
    for (int i=0; i<numElementos && posEncontrado==-1; i++) {
        if (*(elementos[i])==elemento) 
            posEncontrado=i;
    }
    return posEncontrado;
    
}

/**Localiza un elemento a partir de su identificador en un vector de punteros a elementos
   @pre  Los elementos del vector deben poder compararse con claves del tipo indicado (C) usando el operador ==
   @post Devuelve la posicion del vector donde se encuentra la primera ocurrencia del elemento
   @post Devuelve -1 si el elemento no se encuentra en el vector
 */
template<typename T,typename C>
int BuscaElemento(T* elementos[], int numElementos, const C& identificador) {

    int posEncontrado=-1;
    
    for (int i=0; i<numElementos && posEncontrado==-1; i++) {
        if ( (*elementos[i])==identificador) 
            posEncontrado=i;
    }
    return posEncontrado;
    
}

#endif	/* BUSQUEDA_H */

