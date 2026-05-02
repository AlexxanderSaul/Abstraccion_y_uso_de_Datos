#include "cola_lib_nd.h"
#include <iostream>
using namespace std;

bool cola_lib_nd::enq(Dato d) {
    if (lleno()) {
        cout << "Cola llena\n";
        return false;
    }

    queue<Dato> temp = cola;

    while (!temp.empty()) {
        if (temp.front().valor == d.valor) {
            cout << "Ese valor ya esta en la cola\n";
            return false;
        }
        temp.pop();
    }

    cola.push(d);
    return true;
}

void cola_lib_nd::deq() {
    if (vacio()) {
        cout << "Cola vacia\n";
        return;
    }

    cout << "Eliminado: " << cola.front().valor << endl;
    cola.pop();
}

void cola_lib_nd::mos() {
    if (vacio()) {
        cout << "Cola vacia\n";
        return;
    }

    queue<Dato> temp = cola;

    while (!temp.empty()) {
        cout << temp.front().valor << " ";
        temp.pop();
    }
    cout << endl;
}

bool cola_lib_nd::vacio() {
    return cola.empty();
}

bool cola_lib_nd::lleno() {
    return cola.size() == MAX;
}

int cola_lib_nd::tamanio() {
    return cola.size();
}
