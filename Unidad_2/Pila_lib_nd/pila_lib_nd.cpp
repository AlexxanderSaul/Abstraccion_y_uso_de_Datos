#include "pila_lib_nd.h"
#include <iostream>
using namespace std;

void pila_lib_nd::push(Dato d) {
    stack<Dato> copia = pila;

    while (!copia.empty()) {
        if (copia.top().valor == d.valor) {
            cout << "Ese valor ya existe en la pila.\n";
            return;
        }
        copia.pop();
    }

    pila.push(d);
    cout << "Valor insertado correctamente.\n";
}

void pila_lib_nd::pop() {
    if (pila.empty()) {
        cout << "Pila vacia\n";
    } else {
        cout << "Eliminado: " << pila.top().valor << endl;
        pila.pop();
    }
}

void pila_lib_nd::mos() {
    if (pila.empty()) {
        cout << "Pila vacia\n";
        return;
    }

    stack<Dato> copia = pila;

    while (!copia.empty()) {
        cout << copia.top().valor << " ";
        copia.pop();
    }
    cout << endl;
}

bool pila_lib_nd::vacia() {
    return pila.empty();
}

bool pila_lib_nd::llena() {
    return false;
}

int pila_lib_nd::tam() {
    return pila.size();
}
