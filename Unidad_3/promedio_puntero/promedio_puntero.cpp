#include "promedio_puntero.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

PromedioPuntero::PromedioPuntero() {
    tam = 5;
    datos = new double[tam];
    datosIngresados = false;
}

PromedioPuntero::~PromedioPuntero() {
    delete[] datos;
}

void PromedioPuntero::leerDatos() {
    cout << "Ingrese 5 numeros:\n";
    for (int i = 0; i < tam; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> *(datos + i);
    }
    datosIngresados = true;
}

void PromedioPuntero::mostrarDatos() {
    if (estaVacio()) {
        cout << "Primero ingrese los datos\n";
        return;
    }
    for (int i = 0; i < tam; i++) cout << *(datos + i) << " ";
    cout << endl;
}

double PromedioPuntero::suma() {
    double s = 0;
    for (int i = 0; i < tam; i++) s += *(datos + i);
    return s;
}

double PromedioPuntero::promedio() { return suma() / tam; }
double PromedioPuntero::media() { return promedio(); }

double PromedioPuntero::maximo() {
    double mayor = *datos;
    for (int i = 1; i < tam; i++) if (*(datos + i) > mayor) mayor = *(datos + i);
    return mayor;
}

double PromedioPuntero::minimo() {
    double menor = *datos;
    for (int i = 1; i < tam; i++) if (*(datos + i) < menor) menor = *(datos + i);
    return menor;
}

bool PromedioPuntero::estaVacio() { return !datosIngresados; }

void PromedioPuntero::guardarArchivos() {
    if (estaVacio()) {
        cout << "Primero ingrese los datos\n";
        return;
    }

    string nombre;
    cout << "Nombre base del archivo: ";
    cin >> nombre;

    ofstream txt(nombre + ".txt");
    txt << "Datos:\n";
    for (int i = 0; i < tam; i++) txt << *(datos + i) << endl;
    txt << "Suma: " << suma() << endl;
    txt << "Promedio/media: " << promedio() << endl;
    txt << "Maximo: " << maximo() << endl;
    txt << "Minimo: " << minimo() << endl;

    ofstream csv(nombre + ".csv");
    csv << "posicion,valor\n";
    for (int i = 0; i < tam; i++) csv << i + 1 << "," << *(datos + i) << "\n";
    csv << "suma," << suma() << "\n";
    csv << "promedio," << promedio() << "\n";
    csv << "maximo," << maximo() << "\n";
    csv << "minimo," << minimo() << "\n";

    ofstream xml(nombre + ".xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    xml << "<promedio_puntero>\n  <datos>\n";
    for (int i = 0; i < tam; i++) xml << "    <numero posicion=\"" << i + 1 << "\">" << *(datos + i) << "</numero>\n";
    xml << "  </datos>\n  <suma>" << suma() << "</suma>\n  <promedio>" << promedio() << "</promedio>\n  <maximo>" << maximo() << "</maximo>\n  <minimo>" << minimo() << "</minimo>\n</promedio_puntero>\n";

    ofstream json(nombre + ".json");
    json << "{\n  \"datos\": [";
    for (int i = 0; i < tam; i++) {
        json << *(datos + i);
        if (i < tam - 1) json << ", ";
    }
    json << "],\n  \"suma\": " << suma() << ",\n  \"promedio\": " << promedio() << ",\n  \"maximo\": " << maximo() << ",\n  \"minimo\": " << minimo() << "\n}\n";

    cout << "Archivos guardados\n";
}
