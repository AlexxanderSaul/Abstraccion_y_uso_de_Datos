#ifndef PILA_LIB_H
#define PILA_LIB_H

#include <stack>

class pila_lib {
private:
    std::stack<int> pila;

public:
    void push(int valor);
    void pop();
    void mos();

    bool vacia();
    bool llena();
    int tam();
};

#endif
