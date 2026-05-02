#ifndef PILA_PUN_ND_H
#define PILA_PUN_ND_H

struct Dato {
    int valor;
};

class pila_pun_nd {
private:
    struct Nodo {
        Dato dato;
        Nodo* siguiente;
    };

    Nodo* tope;

public:
    pila_pun_nd();
    void push(Dato d);
    void pop();
    void mos();

    bool vacia();
    bool llena();
    int tam();
};

#endif
