#ifndef MATRICES_H
#define MATRICES_H

class Matrices {
private:
    int filasA, columnasA, filasB, columnasB;
    double A[10][10];
    double B[10][10];
    bool matrizALeida;
    bool matrizBLeida;

public:
    Matrices();
    void leerMatrizA();
    void leerMatrizB();
    void mostrarMatrizA();
    void mostrarMatrizB();
    void multiplicarPorConstante();
    void multiplicarMatrices();
    bool existeA();
    bool existeB();
    void guardarArchivos();
};

#endif
