#ifndef CALCBAS_H
#define CALCBAS_H
#include <string>
#include <vector>
#include <utility>

typedef std::vector<std::pair<std::string, std::string> > Registro;


class Calculadora {
private:
    double a, b, resultado;
    std::string operacion;

public:
    Calculadora();
    void leer();
    bool operar(int opcion);
    void mostrar();
    void guardar();
    Registro obtenerDatos();
};

#endif
