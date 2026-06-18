#ifndef CREACION_DE_DATO_H
#define CREACION_DE_DATO_H
#include <string>
#include <vector>
#include <utility>

typedef std::vector<std::pair<std::string, std::string> > Registro;


struct AutoPE {
    float precio;
    int anio;
};

struct PersonaPE {
    std::string nombre;
    std::string ap;
    std::string am;
    std::string genero;
    int edad;
};

class AutoPOO {
private:
    float precio;
    int anio;

public:
    void leer();
    void mostrar();
    Registro obtenerDatos();
};

class PersonaPOO {
private:
    std::string nombre;
    std::string ap;
    std::string am;
    std::string genero;
    int edad;

public:
    void leer();
    void mostrar();
    Registro obtenerDatos();
};

void guardarDatos(const std::string& nombreBase, const Registro& datos);
Registro datosAutoPE(AutoPE a);
Registro datosPersonaPE(PersonaPE p);

#endif
