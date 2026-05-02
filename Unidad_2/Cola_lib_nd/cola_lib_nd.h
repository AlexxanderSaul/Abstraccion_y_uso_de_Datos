#ifndef COLA_LIB_ND_H
#define COLA_LIB_ND_H
#include <queue>

#define MAX 5

struct Dato {
    int valor;
};

class cola_lib_nd {
private:
    std::queue<Dato> cola;

public:
    bool enq(Dato d);
    void deq();
    void mos();

    bool vacio();
    bool lleno();
    int tamanio();
};

#endif
