#include "pila_lib.h"
#include <iostream>
using namespace std;

void pila_lib::push(int valor) {
    stack<int> copia = pila;

    while (!copia.empty()) {
        if (copia.top() == valor) {
            cout << "Ese valor ya existe en la pila.\n";
            return;
        }
        copia.pop();
    }

    pila.push(valor);
    cout << "Valor insertado correctamente.\n";
}

void pila_lib::pop() {
    if (pila.empty()) {
        cout << "Pila vacia\n";
    } else {
        cout << "Eliminado: " << pila.top() << endl;
        pila.pop();
    }
}

void pila_lib::mos() {
    if (pila.empty()) {
        cout << "Pila vacia\n";
        return;
    }

    stack<int> copia = pila;

    while (!copia.empty()) {
        cout << copia.top() << " ";
        copia.pop();
    }
    cout << endl;
}

bool pila_lib::vacia() {
    return pila.empty();
}

bool pila_lib::llena() {
    return false;
}

int pila_lib::tam() {
    return pila.size();
}
