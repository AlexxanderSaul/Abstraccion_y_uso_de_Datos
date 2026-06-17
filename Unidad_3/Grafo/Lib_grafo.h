#ifndef LIB_GRAFO_H
#define LIB_GRAFO_H

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

struct Grafo {
    vector<Lugar>             nodos;
    vector<string>            aristas;
    Ruta                      rutas;
};

void agregarNodo      (Grafo& g, int id, string etiqueta);
void agregarConexion  (Grafo& g, int nodoIni, int nodoFin, string arista, float tiempo, float costo);
void mostrarGrafo     (const Grafo& g);
void dijkstra         (const Grafo& g, int origen);
void leerDesdeXML     (Grafo& g, const string& archivo);
void leerDesdeJSON    (Grafo& g, const string& archivo);
void guardarSalidas   (const Grafo& g);

#endif
