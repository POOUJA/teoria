/** Utilidades para la búsqueda de elementos
 * @file   busqueda.h
 * @author jrbalsas
 *
 * @date 4 de noviembre de 2015, 13:43
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

#endif	/* ORDENACION_H */

