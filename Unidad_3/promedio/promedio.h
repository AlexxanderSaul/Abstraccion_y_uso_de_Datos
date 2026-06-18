#ifndef PROMEDIO_H
#define PROMEDIO_H
#include <string>
#include <vector>
#include <utility>

typedef std::vector<std::pair<std::string, std::string> > Registro;


class Prom {
private:
    int num[5];
    int suma;
    int maxi;
    int mini;
    double resultado;
    std::string operacion;

public:
    Prom();
    void leer();
    void sum();
    void prom();
    void maymen();
    std::string numerosComoTexto();
    Registro obtenerDatos();
    void guardar();
};

#endif
