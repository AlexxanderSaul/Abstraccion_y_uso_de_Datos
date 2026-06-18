#ifndef CALCULADORA_H
#define CALCULADORA_H
#include <string>
#include <vector>
#include <utility>

typedef std::vector<std::pair<std::string, std::string> > Registro;


class Calculadora {
protected:
    double num[100];
    int n;
    double resultado;
    std::string operacion;

public:
    Calculadora();
    void leer();
    void sum();
    void res();
    void mult();
    bool div();
    std::string numerosComoTexto();
    Registro obtenerDatos();
    void guardar();
};

class CalculadoraHija : public Calculadora {
public:
    void prom();
    void may();
};

#endif
