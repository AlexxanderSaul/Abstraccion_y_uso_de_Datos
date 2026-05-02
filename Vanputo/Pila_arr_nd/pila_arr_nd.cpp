#include "pila_arr_nd.h"
#include <iostream>
using namespace std;

pila_arr_nd::pila_arr_nd() {
    tope = -1;
}

void pila_arr_nd::push(Dato d) {
    for (int i = 0; i <= tope; i++) {
        if (datos[i].valor == d.valor) {
            cout << "Ese valor ya existe en la pila.\n";
            return;
        }
    }

    if (tope == MAX - 1) {
        cout << "Pila llena\n";
    } else {
        datos[++tope] = d;
        cout << "Valor insertado correctamente.\n";
    }
}

void pila_arr_nd::pop() {
    if (tope == -1) {
        cout << "Pila vacia\n";
    } else {
        cout << "Eliminado: " << datos[tope--].valor << endl;
    }
}

void pila_arr_nd::mos() {
    if (tope == -1) {
        cout << "Pila vacia\n";
        return;
    }

    for (int i = tope; i >= 0; i--) {
        cout << datos[i].valor << " ";
    }
    cout << endl;
}

bool pila_arr_nd::vacia() {
    return tope == -1;
}

bool pila_arr_nd::llena() {
    return tope == MAX - 1;
}

int pila_arr_nd::tam() {
    return tope + 1;
}
