#ifndef PILA_H
#define PILA_H

#define MAX 5

class pila_arr {
private:
    int datos[MAX];
    int tope;

public:
    pila_arr();
    void push(int valor);
    void pop();
    void mos();

    bool vacia();
    bool llena();
    int tam();
};

#endif
