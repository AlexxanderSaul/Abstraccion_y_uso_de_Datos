#ifndef COLA_ARR_H
#define COLA_ARR_H

#define MAX 5

class cola_arr {
private:
    int datos[MAX];
    int frente, final;

public:
    cola_arr();
    bool enq(int valor);
    void deq();
    void mos();

    bool vacio();
    bool lleno();
    int tamanio();
};

#endif
