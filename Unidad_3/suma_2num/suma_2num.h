#ifndef SUMA_2NUM_H
#define SUMA_2NUM_H
#include <string>
#include <vector>
#include <utility>

typedef std::vector<std::pair<std::string, std::string> > Registro;


class Sum2 {
private:
    int a, b, resultado;

public:
    Sum2();
    void leer();
    void sum();
    void guardar();
    Registro obtenerDatos();
};

#endif
