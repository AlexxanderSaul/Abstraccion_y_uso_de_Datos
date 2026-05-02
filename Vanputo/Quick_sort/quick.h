#ifndef QUICK_H
#define QUICK_H

#include <string>

class Quick {
private:
    int* arreglo;
    int tam;
    bool archivoLeido;
    bool archivoOrdenado;
    bool archivoGrabado;

    int particion(int inicio, int fin);
    void quickSort(int inicio, int fin);

public:
    Quick();
    ~Quick();

    void leerArchivo();
    void mostrarArreglo();
    void ordenarQuickSort();
    void guardarArchivo();
    bool salir();

    bool estaLeido();
    bool estaOrdenado();
    bool estaGuardado();
};

#endif
