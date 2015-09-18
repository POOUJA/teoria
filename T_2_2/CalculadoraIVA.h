/**
 * @file CalculadoraIVA.h
 * @author Victor M. Rivas Santos <vrivas@ujaen.es>
 *
 * @date 18 de septiembre de 2015, 11:36
 */

#ifndef CALCULADORAIVA_H
#define	CALCULADORAIVA_H

class CalculadoraIVA {
public:
    CalculadoraIVA(double unPorcentaje);
    double aplicar(double precio);
private:
    double porcentaje;

};

#endif	/* CALCULADORAIVA_H */

