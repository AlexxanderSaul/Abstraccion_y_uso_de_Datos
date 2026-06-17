#ifndef LIB_DIGRAFO_H
#define LIB_DIGRAFO_H

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

// Dígrafo: las aristas son DIRIGIDAS
struct Digrafo {
    vector<Lugar>  nodos;
    vector<string> aristas;
    Ruta           rutas;
};

void agregarNodo     (Digrafo& g, int id, string etiqueta);
void agregarConexion (Digrafo& g, int nodoIni, int nodoFin, string arista, float tiempo, float costo);
void mostrarDigrafo  (const Digrafo& g);
void dijkstra        (const Digrafo& g, int origen);
void leerDesdeXML    (Digrafo& g, const string& archivo);
void leerDesdeJSON   (Digrafo& g, const string& archivo);
void guardarSalidas  (const Digrafo& g);

#endif
