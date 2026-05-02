#ifndef LISTA_LIB_ND_H
#define LISTA_LIB_ND_H
#include <list>

#define MAX 5

struct Dato {
    int valor;
};

class ListaLibNd {
private:
    std::list<Dato> lista;

public:
    bool ins(Dato d);
    void eli(int v);
    void mos();

    bool vacio();
    bool lleno();
    int tamanio();
};

#endif
