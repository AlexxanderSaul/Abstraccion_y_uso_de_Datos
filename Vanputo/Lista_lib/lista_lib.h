#ifndef LISTA_LIB_H
#define LISTA_LIB_H
#include <list>

#define MAX 5

class ListaLib {
private:
    std::list<int> lista;

public:
    bool ins(int v);
    void eli(int v);
    void mos();

    bool vacio();
    bool lleno();
    int tamanio();
};

#endif
