#ifndef PILA_PUN_H
#define PILA_PUN_H

class pila_pun{
private:
    struct Nodo {
        int dato;
        Nodo* siguiente;
    };

    Nodo* tope;

public:
    pila_pun();
    void push(int valor);
    void pop();
    void mos();

    bool vacia();
    bool llena();
    int tam();
};

#endif
