#include "cola_pun.h"
#include <iostream>
using namespace std;

cola_pun::cola_pun() {
    frente = final = NULL;
    tam = 0;
}

bool cola_pun::enq(int valor) {

    Nodo* aux = frente;
    while (aux) {
        if (aux->dato == valor) {
            cout << "Ese valor ya esta en la cola\n";
            return false;
        }
        aux = aux->sig;
    }

    Nodo* nuevo = new Nodo{valor, NULL};

    if (!final) {
        frente = final = nuevo;
    } else {
        final->sig = nuevo;
        final = nuevo;
    }

    tam++;
    return true;
}

void cola_pun::deq() {
    if (vacio()) {
        cout << "Cola vacia\n";
        return;
    }

    Nodo* aux = frente;
    cout << "Eliminado: " << aux->dato << endl;

    frente = frente->sig;
    delete aux;

    tam--;

    if (!frente) {
        final = NULL;
    }
}

void cola_pun::mos() {
    if (vacio()) {
        cout << "Cola vacia\n";
        return;
    }

    Nodo* aux = frente;
    while (aux) {
        cout << aux->dato << " ";
        aux = aux->sig;
    }
    cout << endl;
}

bool cola_pun::vacio() {
    return frente == NULL;
}

int cola_pun::tamanio() {
    return tam;
}
