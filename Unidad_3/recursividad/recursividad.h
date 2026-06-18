#ifndef RECURSIVIDAD_H
#define RECURSIVIDAD_H
#include <string>
#include <vector>
#include <utility>

typedef std::vector<std::pair<std::string, std::string> > Registro;


class Recursividad {
private:
    int n;
    std::string operacion;
    std::string resultadoTexto;

public:
    Recursividad();
    void leer();
    long long factorial(int x);
    long long fibonacci(int x);
    void mostrarFactorial();
    void mostrarFibonacci();
    Registro obtenerDatos();
    void guardar();
};

#endif
