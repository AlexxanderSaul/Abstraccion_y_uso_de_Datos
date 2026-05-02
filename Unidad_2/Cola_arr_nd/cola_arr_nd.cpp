#include "cola_arr_nd.h"
#include <iostream>
using namespace std;

cola_arr_nd::cola_arr_nd() {
    frente = 0;
    final = -1;
}

bool cola_arr_nd::enq(Dato d) {
    if (lleno()) {
        cout << "Cola llena\n";
        return false;
    }

    for (int i = frente; i <= final; i++) {
        if (datos[i].valor == d.valor) {
            cout << "Ese valor ya esta en la cola\n";
            return false;
        }
    }

    datos[++final] = d;
    return true;
}

void cola_arr_nd::deq() {
    if (vacio()) {
        cout << "Cola vacia\n";
        return;
    }

    cout << "Eliminado: " << datos[frente++].valor << endl;
}

void cola_arr_nd::mos() {
    if (vacio()) {
        cout << "Cola vacia\n";
        return;
    }

    for (int i = frente; i <= final; i++) {
        cout << datos[i].valor << " ";
    }
    cout << endl;
}

bool cola_arr_nd::vacio() {
    return frente > final;
}

bool cola_arr_nd::lleno() {
    return final == MAX - 1;
}

int cola_arr_nd::tamanio() {
    return (final - frente + 1);
}
