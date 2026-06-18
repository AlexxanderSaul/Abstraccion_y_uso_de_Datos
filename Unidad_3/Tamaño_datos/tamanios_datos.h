#ifndef TAMANIOS_DATOS_H
#define TAMANIOS_DATOS_H
#include <string>

class TamaniosDatos {
private:
    std::string contenido;

public:
    TamaniosDatos();
    void mostrarBasicos();
    bool vacio();
    void guardarArchivos();
};

#endif
