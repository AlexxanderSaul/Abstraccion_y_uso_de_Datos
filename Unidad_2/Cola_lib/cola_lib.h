#ifndef COLA_LIB_H
#define COLA_LIB_H
#include <queue>

#define MAX 5

class cola_lib {
private:
    std::queue<int> cola;

public:
    bool enq(int v);
    void deq();
    void mos();

    bool vacio();
    bool lleno();
    int tamanio();
};

#endif
