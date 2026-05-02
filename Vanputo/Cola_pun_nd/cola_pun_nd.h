#ifndef COLA_PUN_ND_H
#define COLA_PUN_ND_H

struct Dato {
    int valor;
};

class cola_pun_nd {
private:
    struct Nodo {
        Dato dato;
        Nodo* sig;
    };

    Nodo* frente;
    Nodo* final;
    int tam;

public:
    cola_pun_nd();
    bool enq(Dato d);
    void deq();
    void mos();

    bool vacio();
    int tamanio();
};

#endif
