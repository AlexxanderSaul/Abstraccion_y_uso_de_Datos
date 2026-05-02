#include "cola_arr.h"
#include <iostream>
using namespace std;

cola_arr::cola_arr() {
    frente = 0;
    final = -1;
}

bool cola_arr::enq(int valor) {
    if (lleno()) {
        cout << "Cola llena\n";
        return false;
    }

    for (int i = frente; i <= final; i++) {
        if (datos[i] == valor) {
            cout << "Ese valor ya esta en la cola\n";
            return false;
        }
    }

    datos[++final] = valor;
    return true;
}

void cola_arr::deq() {
    if (vacio()) {
        cout << "Cola vacia\n";
        return;
    }

    cout << "Eliminado: " << datos[frente++] << endl;
}

void cola_arr::mos() {
    if (vacio()) {
        cout << "Cola vacia\n";
        return;
    }

    for (int i = frente; i <= final; i++) {
        cout << datos[i] << " ";
    }
    cout << endl;
}

bool cola_arr::vacio() {
    return frente > final;
}

bool cola_arr::lleno() {
    return final == MAX - 1;
}

int cola_arr::tamanio() {
    return (final - frente + 1);
}
