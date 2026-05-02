#ifndef MERGE_H
#define MERGE_H

#include <string>

class Merge {
private:
    int* arreglo;
    int tam;
    bool archivoLeido;
    bool archivoGrabado;
    bool archivoOrdenado;

    void merge(int inicio, int medio, int fin);
    void mergeSort(int inicio, int fin);

public:
    Merge();
    ~Merge();

    void leerArchivo();
    void mostrarArreglo();
    void ordenarMerge();
    void guardarArchivo();
    bool salir();

    bool estaLeido();
    bool estaOrdenado();
    bool estaGuardado();
};

#endif
