#include "cola_lib.h"
#include <iostream>
using namespace std;

bool cola_lib::enq(int v) {
    if (lleno()) {
        cout << "Cola llena\n";
        return false;
    }

    queue<int> temp = cola;

    while (!temp.empty()) {
        if (temp.front() == v) {
            cout << "Ese valor ya esta en la cola\n";
            return false;
        }
        temp.pop();
    }

    cola.push(v);
    return true;
}

void cola_lib::deq() {
    if (vacio()) {
        cout << "Cola vacia\n";
        return;
    }

    cout << "Eliminado: " << cola.front() << endl;
    cola.pop();
}

void cola_lib::mos() {
    if (vacio()) {
        cout << "Cola vacia\n";
        return;
    }

    queue<int> temp = cola;

    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;
}

bool cola_lib::vacio() {
    return cola.empty();
}

bool cola_lib::lleno() {
    return cola.size() == MAX;
}

int cola_lib::tamanio() {
    return cola.size();
}
