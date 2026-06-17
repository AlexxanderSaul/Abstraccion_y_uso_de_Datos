#ifndef HOLA_MUNDO_H
#define HOLA_MUNDO_H
#include <string>
#include <vector>
#include <utility>

typedef std::vector<std::pair<std::string, std::string> > Registro;


class Holamundo {
private:
    std::string mensaje;

public:
    void leer();
    void mos();
    void guardar();
    Registro obtenerDatos();
};

#endif
