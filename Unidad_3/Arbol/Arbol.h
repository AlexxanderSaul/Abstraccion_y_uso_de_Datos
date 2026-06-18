#ifndef ARBOL_H
#define ARBOL_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Lugar {
    int    id;
    string etiqueta;
};

struct conexionNodo2Nodo {
    int    nodoInicial;
    int    nodoFinal;
    string aristaConexion;
    float  tiempo;
    float  costo;
};

struct Ruta {
    vector<conexionNodo2Nodo> conexiones;
};

// Nodo del árbol BST
struct NodoArbol {
    Lugar     dato;
    NodoArbol* izq;
    NodoArbol* der;
    NodoArbol(Lugar l) : dato(l), izq(nullptr), der(nullptr) {}
};

struct Arbol {
    vector<Lugar>  nodos;    // conjunto de nodos
    vector<string> aristas;  // conjunto de aristas
    Ruta           rutas;    // conjunto de conexiones
    NodoArbol*     raiz;
    Arbol() : raiz(nullptr) {}
};

void agregarNodo    (Arbol& a, int id, string etiqueta);
void agregarConexion(Arbol& a, int nodoIni, int nodoFin, string arista, float tiempo, float costo);
void inorden        (NodoArbol* nodo);
void preorden       (NodoArbol* nodo);
void posorden       (NodoArbol* nodo);
void mostrarArbol   (const Arbol& a);
void busquedaBinaria(NodoArbol* raiz, int idBuscado);
void leerDesdeXML   (Arbol& a, const string& archivo);
void leerDesdeJSON  (Arbol& a, const string& archivo);
void guardarSalidas (const Arbol& a);

#endif
