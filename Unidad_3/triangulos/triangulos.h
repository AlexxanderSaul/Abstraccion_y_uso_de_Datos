#ifndef TRIANGULOS_H
#define TRIANGULOS_H
#include <vector>
#include <string>
#include <vector>
#include <utility>

typedef std::vector<std::pair<std::string, std::string> > Registro;


class Sierpinski {
private:
    std::vector<std::vector<char> > mat;
    int size;
    int nivel;
    std::string dibujo;

public:
    Sierpinski();
    void iniciar();
    void dibujar(int fila, int col, int n, int nivelActual);
    Registro obtenerDatos();
};

class Cantor {
private:
    int nivel;
    std::string dibujo;

public:
    Cantor();
    void iniciar();
    void dibujar(std::vector<char> linea, int nivelActual);
    Registro obtenerDatos();
};

void guardarDatos(const std::string& nombreBase, const Registro& datos);

#endif
