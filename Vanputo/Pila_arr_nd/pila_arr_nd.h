#ifndef PILA_ARR_ND_H
#define PILA_ARR_ND_H

#define MAX 5

struct Dato {
    int valor;
};

class pila_arr_nd {
private:
    Dato datos[MAX];
    int tope;

public:
    pila_arr_nd();
    void push(Dato d);
    void pop();
    void mos();

    bool vacia();
    bool llena();
    int tam();
};

#endif
