#include "cola_pun_nd.h"
#include <iostream>
using namespace std;

cola_pun_nd::cola_pun_nd() {
    frente = final = NULL;
    tam = 0;
}

bool cola_pun_nd::enq(Dato d) {

    Nodo* aux = frente;
    while (aux) {
        if (aux->dato.valor == d.valor) {
            cout << "Ese valor ya esta en la cola\n";
            return false;
        }
        aux = aux->sig;
    }

    Nodo* nuevo = new Nodo{d, NULL};

    if (!final) {
        frente = final = nuevo;
    } else {
        final->sig = nuevo;
        final = nuevo;
    }

    tam++;
    return true;
}

void cola_pun_nd::deq() {
    if (vacio()) {
        cout << "Cola vacia\n";
        return;
    }

    Nodo* aux = frente;
    cout << "Eliminado: " << aux->dato.valor << endl;

    frente = frente->sig;
    delete aux;

    tam--;

    if (!frente) {
        final = NULL;
    }
}

void cola_pun_nd::mos() {
    if (vacio()) {
        cout << "Cola vacia\n";
        return;
    }

    Nodo* aux = frente;
    while (aux) {
        cout << aux->dato.valor << " ";
        aux = aux->sig;
    }
    cout << endl;
}

bool cola_pun_nd::vacio() {
    return frente == NULL;
}

int cola_pun_nd::tamanio() {
    return tam;
}
