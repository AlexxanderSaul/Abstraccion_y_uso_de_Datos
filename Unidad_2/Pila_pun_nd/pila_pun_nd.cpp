#include "pila_pun_nd.h"
#include <iostream>
using namespace std;

pila_pun_nd::pila_pun_nd() {
    tope = NULL;
}

void pila_pun_nd::push(Dato d) {
    Nodo* aux = tope;

    while (aux != NULL) {
        if (aux->dato.valor == d.valor) {
            cout << "Ese valor ya existe en la pila.\n";
            return;
        }
        aux = aux->siguiente;
    }

    Nodo* nuevo = new Nodo();

    if (!nuevo) {
        cout << "Memoria insuficiente\n";
        return;
    }

    nuevo->dato = d;
    nuevo->siguiente = tope;
    tope = nuevo;

    cout << "Valor insertado correctamente.\n";
}

void pila_pun_nd::pop() {
    if (tope == NULL) {
        cout << "Pila vacia\n";
    } else {
        Nodo* aux = tope;
        cout << "Eliminado: " << aux->dato.valor << endl;
        tope = tope->siguiente;
        delete aux;
    }
}

void pila_pun_nd::mos() {
    if (tope == NULL) {
        cout << "Pila vacia\n";
        return;
    }

    Nodo* aux = tope;
    while (aux != NULL) {
        cout << aux->dato.valor << " ";
        aux = aux->siguiente;
    }
    cout << endl;
}

bool pila_pun_nd::vacia() {
    return tope == NULL;
}

bool pila_pun_nd::llena() {
    Nodo* prueba = new (nothrow) Nodo;
    if (!prueba) return true;
    delete prueba;
    return false;
}

int pila_pun_nd::tam() {
    int c = 0;
    Nodo* aux = tope;
    while (aux != NULL) {
        c++;
        aux = aux->siguiente;
    }
    return c;
}
