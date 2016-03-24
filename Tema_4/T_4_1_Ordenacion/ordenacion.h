/** Utilidades para la ordenación de elementos
 * @file   Ordenacion.h
 * @author jrbalsas
 *
 * @date 4 de noviembre de 2015, 13:43
 */

#ifndef ORDENACION_H
#define	ORDENACION_H

/**Intercambia dos variables de cualquier tipo
  @pre el tipo T tiene sobrecargado el operador de asignación*/
template<typename T>
void intercambia(T &a, T &b) {
    T c=a;
    a=b;
    b=c;
}

/**Ordena un vector de elementos de menor a mayor utilizando el algoritmo de selección
  @pre Los elementos tienen sobrecargado el operador < */
template<typename T>
void Ordena( T valores[], int numValores) {
    int posMenor;
    
    for (int i = 0; i < numValores-1; i++) {
        posMenor=i;
        for (int j = i+1; j < numValores; j++) {
            if (valores[j] < valores[posMenor])
                posMenor=j;
        }
        intercambia(valores[i],valores[posMenor]);
    }
}

#endif	/* ORDENACION_H */

