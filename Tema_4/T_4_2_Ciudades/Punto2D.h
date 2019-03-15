/** Definición de plantilla de clase para representar puntos en dos dimensiones
 * @file   Punto2D.h
 * @author jrbalsas
 *
 * @date 4 de noviembre de 2015, 12:43
 */

#include <cmath>

#ifndef PUNTO2D_H
#define	PUNTO2D_H

/**Plantilla de clase para crear puntos en dos dimensiones*/
template<typename T>
class Punto2D {						
private:
    T _x = 0,_y = 0;
public:
    Punto2D() = default;
    Punto2D(T x, T y);
    Punto2D(const Punto2D& orig);	
    virtual ~Punto2D();

    void setY(T _y);
    T getY() const;
    void setX(T _x);
    T getX() const;

    Punto2D& operator=(const Punto2D &orig);
    bool igualA(const Punto2D& p) const;
    bool operator==(const Punto2D& p) const;
    float distanciaA(const Punto2D& p) const;
    float distanciaAlOrigen() const;
    bool operator<(const Punto2D &p) const;
private:

};

/**Constructor defecto/parametrizado*/
template<typename T>
Punto2D<T>::Punto2D(T x, T y):_x(x),_y(y) {  //La plantilla de clase se denomina Punto2D<T>
}

/**Constructor de copia*/
template<typename T>
Punto2D<T>::Punto2D(const Punto2D& orig):_x(orig._x),_y(orig._y) {
}

/**Destructor*/
template<typename T>
Punto2D<T>::~Punto2D() {
}

template<typename T>
void Punto2D<T>::setY(T _y) {
    this->_y = _y;
}
template<typename T>
T Punto2D<T>::getY() const {
    return _y;
}
template<typename T>
void Punto2D<T>::setX(T _x) {
    this->_x = _x;
}
template<typename T>
T Punto2D<T>::getX() const {
    return _x;
}

/**Operador de asignación*/
template<typename T>
Punto2D<T>& Punto2D<T>::operator=(const Punto2D &orig) {
    if (&orig!=this) {
        _x=orig._x;
        _y=orig._y;
    };
    return *this;
}

/**Comprueba si un dos puntos son iguales*/
template<typename T>
bool Punto2D<T>::igualA(const Punto2D& p) const {
    return _x==p._x && _y==p._y;
}

/**Comprueba si un dos puntos son iguales*/
template<typename T>
bool Punto2D<T>::operator==(const Punto2D& p) const {
    return igualA(p);
}

/**Devuelve la distancia entre dos puntos*/
template<typename T>
float Punto2D<T>::distanciaA(const Punto2D& p) const {
    return sqrt( pow(_x-p._x,2) + pow(_y-p._y,2) );
}

/**Devuelve la distancia entre dos puntos*/
template<typename T>
float Punto2D<T>::distanciaAlOrigen() const {
    return distanciaA(Punto2D<T>(0,0));
}

/**Compara un punto con otro atendiendo a su distancia al origen
   @note Un punto es menor que otro si su distancia al origen es menor */
template<typename T>
bool Punto2D<T>::operator<(const Punto2D& p) const {
    return distanciaAlOrigen() < p.distanciaAlOrigen();
}

#endif	/* PUNTO2D_H */

