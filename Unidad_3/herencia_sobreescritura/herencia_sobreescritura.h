#ifndef HERENCIA_SOBREESCRITURA_H
#define HERENCIA_SOBREESCRITURA_H
#include <string>
#include <vector>
#include <utility>

typedef std::vector<std::pair<std::string, std::string> > Registro;


class Calculadora {
protected:
    int num[100];
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

class CalculadoraNueva : public Calculadora {
public:
    using Calculadora::mult;
    using Calculadora::div;
    void mult(int a, int b);
    bool div(int a, int b);
    void potencia(int a, int b);
};

#endif
