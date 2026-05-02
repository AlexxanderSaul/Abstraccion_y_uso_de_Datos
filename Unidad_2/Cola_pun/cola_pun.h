#ifndef COLA_PUN_H
#define COLA_PUN_H

class cola_pun {
private:
    struct Nodo {
        int dato;
        Nodo* sig;
    };

    Nodo* frente;
    Nodo* final;
    int tam;

public:
    cola_pun();
    bool enq(int valor);
    void deq();
    void mos();

    bool vacio();
    int tamanio();
};

#endif
