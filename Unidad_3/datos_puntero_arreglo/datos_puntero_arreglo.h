#ifndef DATOS_PUNTERO_ARREGLO_H
#define DATOS_PUNTERO_ARREGLO_H

#include <string>
#define MAX 5

struct Persona {
    std::string nombre;
    std::string ap;
    std::string am;
    char genero;
    int edad;
};

class DatosPunteroArreglo {
private:
    Persona* personas;
    int tam;

public:
    DatosPunteroArreglo();
    ~DatosPunteroArreglo();

    bool agregarPersona(Persona p);
    void mostrarPersonas();
    bool vacio();
    bool lleno();
    int tamanio();
    void guardarArchivos();
};

#endif
