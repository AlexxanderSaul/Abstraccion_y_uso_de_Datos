#ifndef COLA_ARR_ND_H
#define COLA_ARR_ND_H

#define MAX 5

struct Dato {
    int valor;
};

class cola_arr_nd {
private:
    Dato datos[MAX];
    int frente, final;

public:
    cola_arr_nd();
    bool enq(Dato d);
    void deq();
    void mos();

    bool vacio();
    bool lleno();
    int tamanio();
};

#endif
