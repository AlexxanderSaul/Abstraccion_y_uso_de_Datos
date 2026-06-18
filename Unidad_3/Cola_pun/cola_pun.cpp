#include "cola_pun.h"
#include <iostream>
#include <fstream>
#include <string>
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

void cola_pun::guardarArchivo() {
    if (vacio()) {
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

    Nodo* aux = frente;
    while (aux) {
        txt << aux->dato << endl;
        aux = aux->sig;
    }

    csv << "valor\n";
    aux = frente;
    while (aux) {
        csv << aux->dato << endl;
        aux = aux->sig;
    }

    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    xml << "<datos>\n";
    aux = frente;
    while (aux) {
        xml << "  <valor>" << aux->dato << "</valor>\n";
        aux = aux->sig;
    }
    xml << "</datos>\n";

    json << "[\n";
    aux = frente;
    int i = 0;
    while (aux) {
        json << "  " << aux->dato;
        if (i < tam - 1) json << ",";
        json << "\n";
        aux = aux->sig;
        i++;
    }
    json << "]\n";

    cout << "Archivos guardados\n";
}
