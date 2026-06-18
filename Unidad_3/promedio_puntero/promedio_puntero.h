#ifndef PROMEDIO_PUNTERO_H
#define PROMEDIO_PUNTERO_H

class PromedioPuntero {
private:
    double* datos;
    int tam;
    bool datosIngresados;

public:
    PromedioPuntero();
    ~PromedioPuntero();

    void leerDatos();
    void mostrarDatos();
    double suma();
    double promedio();
    double media();
    double maximo();
    double minimo();
    bool estaVacio();
    void guardarArchivos();
};

#endif
