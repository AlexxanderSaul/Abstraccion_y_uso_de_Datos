#include "pila_pun.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

pila_pun::pila_pun() {
    tope = NULL;
}

void pila_pun::push(int valor) {
    Nodo* aux = tope;
    while (aux != NULL) {
        if (aux->dato == valor) {
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

    nuevo->dato = valor;
    nuevo->siguiente = tope;
    tope = nuevo;

    cout << "Valor insertado correctamente.\n";
}

void pila_pun::pop() {
    if (tope == NULL) {
        cout << "Pila vacia\n";
    } else {
        Nodo* aux = tope;
        cout << "Eliminado: " << aux->dato << endl;
        tope = tope->siguiente;
        delete aux;
    }
}

void pila_pun::mos() {
    if (tope == NULL) {
        cout << "Pila vacia\n";
        return;
    }

    Nodo* aux = tope;
    while (aux != NULL) {
        cout << aux->dato << " ";
        aux = aux->siguiente;
    }
    cout << endl;
}

bool pila_pun::vacia() {
    return tope == NULL;
}

bool pila_pun::llena() {
    Nodo* prueba = new (nothrow) Nodo;
    if (!prueba) return true;
    delete prueba;
    return false;
}

int pila_pun::tam() {
    int c = 0;
    Nodo* aux = tope;
    while (aux != NULL) {
        c++;
        aux = aux->siguiente;
    }
    return c;
}

void pila_pun::guardarArchivo() {
    if (vacia()) {
        cout << "No hay datos para guardar\n";
        return;
    }

    string nombre;
    cout << "Nombre base del archivo sin extension: ";
    cin >> ws;
    getline(cin, nombre);

    ofstream txt(nombre + ".txt");
    ofstream csv(nombre + ".csv");
    ofstream xml(nombre + ".xml");
    ofstream json(nombre + ".json");

    if (!txt || !csv || !xml || !json) {
        cout << "Error al guardar archivos\n";
        return;
    }

    Nodo* aux = tope;
    while (aux) {
        txt << aux->dato << endl;
        aux = aux->siguiente;
    }

    csv << "valor\n";
    aux = tope;
    while (aux) {
        csv << aux->dato << endl;
        aux = aux->siguiente;
    }

    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    xml << "<datos>\n";
    aux = tope;
    while (aux) {
        xml << "  <valor>" << aux->dato << "</valor>\n";
        aux = aux->siguiente;
    }
    xml << "</datos>\n";

    json << "[\n";
    aux = tope;
    int total = tam();
    int i = 0;
    while (aux) {
        json << "  " << aux->dato;
        if (i < total - 1) json << ",";
        json << "\n";
        aux = aux->siguiente;
        i++;
    }
    json << "]\n";

    cout << "Archivos guardados\n";
}
