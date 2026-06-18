#ifndef BURBUJA_H
#define BURBUJA_H

#include <string>

class Burbuja {
private:
    int* arreglo;
    int tam;
    bool archivoLeido;
    bool archivoGrabado;
    bool archivoOrdenado;

public:
    Burbuja();
    ~Burbuja();

    void leerArchivo();
    void mostrarArreglo();
    void ordenarBurbuja();
    void guardarArchivo();
    bool salir();

    bool estaLeido();
    bool estaOrdenado();
    bool estaGuardado();
};

#endif
