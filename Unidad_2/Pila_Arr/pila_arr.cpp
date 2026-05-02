#include "pila.h"
#include <iostream>
using namespace std;

pila_arr::pila_arr() {
    tope = -1;
}

void pila_arr::push(int valor) {
    for (int i = 0; i <= tope; i++) {
        if (datos[i] == valor) {
            cout << "Ese valor ya existe en la pila.\n";
            return;
        }
    }

    if (tope == MAX - 1) {
        cout << "Pila llena\n";
    } else {
        datos[++tope] = valor;
        cout << "Valor insertado correctamente.\n";
    }
}

void pila_arr::pop() {
    if (tope == -1) {
        cout << "Pila vacia\n";
    } else {
        cout << "Eliminado: " << datos[tope--] << endl;
    }
}

void pila_arr::mos() {
    if (tope == -1) {
        cout << "Pila vacia\n";
        return;
    }

    for (int i = tope; i >= 0; i--) {
        cout << datos[i] << " ";
    }
    cout << endl;
}
bool pila_arr::vacia() {
    return tope == -1;
}

bool pila_arr::llena() {
    return tope == MAX - 1;
}

int pila_arr::tam() {
    return tope + 1;
}
