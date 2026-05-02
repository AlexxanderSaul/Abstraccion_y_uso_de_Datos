#ifndef PILA_LIB_ND_H
#define PILA_LIB_ND_H

#include <stack>

struct Dato {
    int valor;
};

class pila_lib_nd {
private:
    std::stack<Dato> pila;

public:
    void push(Dato d);
    void pop();
    void mos();

    bool vacia();
    bool llena();
    int tam();
};

#endif
