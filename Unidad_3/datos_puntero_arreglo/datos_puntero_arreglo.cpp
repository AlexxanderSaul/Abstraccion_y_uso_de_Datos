#include "datos_puntero_arreglo.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static string escJson(string s) {
    string r;
    for (char c : s) {
        if (c == '\\') r += "\\\\";
        else if (c == '"') r += "\\\"";
        else if (c == '\n') r += "\\n";
        else r += c;
    }
    return r;
}

static string escXml(string s) {
    string r;
    for (char c : s) {
        if (c == '&') r += "&amp;";
        else if (c == '<') r += "&lt;";
        else if (c == '>') r += "&gt;";
        else if (c == '"') r += "&quot;";
        else r += c;
    }
    return r;
}

DatosPunteroArreglo::DatosPunteroArreglo() {
    personas = new Persona[MAX];
    tam = 0;
}

DatosPunteroArreglo::~DatosPunteroArreglo() {
    delete[] personas;
}

bool DatosPunteroArreglo::agregarPersona(Persona p) {
    if (lleno()) {
        cout << "Lista llena\n";
        return false;
    }

    *(personas + tam) = p;
    tam++;
    return true;
}

void DatosPunteroArreglo::mostrarPersonas() {
    if (vacio()) {
        cout << "Lista vacia\n";
        return;
    }

    for (int i = 0; i < tam; i++) {
        Persona p = *(personas + i);
        cout << i + 1 << ". "
             << p.nombre << " "
             << p.ap << " "
             << p.am
             << ", genero: " << p.genero
             << ", edad: " << p.edad << endl;
    }
}

bool DatosPunteroArreglo::vacio() {
    return tam == 0;
}

bool DatosPunteroArreglo::lleno() {
    return tam == MAX;
}

int DatosPunteroArreglo::tamanio() {
    return tam;
}

void DatosPunteroArreglo::guardarArchivos() {
    if (vacio()) {
        cout << "Primero agrega personas\n";
        return;
    }

    string nombre;
    cout << "Nombre base del archivo: ";
    cin >> ws;
    getline(cin, nombre);

    if (nombre == "") {
        cout << "Nombre invalido\n";
        return;
    }

    ofstream txt(nombre + ".txt");
    if (!txt) {
        cout << "No se pudo crear el archivo TXT\n";
        return;
    }

    for (int i = 0; i < tam; i++) {
        Persona p = *(personas + i);
        txt << p.nombre << " "
            << p.ap << " "
            << p.am << " "
            << p.genero << " "
            << p.edad << "\n";
    }
    txt.close();

    ofstream csv(nombre + ".csv");
    if (!csv) {
        cout << "No se pudo crear el archivo CSV\n";
        return;
    }

    csv << "nombre,ap,am,genero,edad\n";
    for (int i = 0; i < tam; i++) {
        Persona p = *(personas + i);
        csv << p.nombre << ","
            << p.ap << ","
            << p.am << ","
            << p.genero << ","
            << p.edad << "\n";
    }
    csv.close();

    ofstream xml(nombre + ".xml");
    if (!xml) {
        cout << "No se pudo crear el archivo XML\n";
        return;
    }
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    xml << "<personas>\n";
    for (int i = 0; i < tam; i++) {
        Persona p = *(personas + i);
        xml << "  <persona>\n";
        xml << "    <nombre>" << escXml(p.nombre) << "</nombre>\n";
        xml << "    <ap>" << escXml(p.ap) << "</ap>\n";
        xml << "    <am>" << escXml(p.am) << "</am>\n";
        xml << "    <genero>" << p.genero << "</genero>\n";
        xml << "    <edad>" << p.edad << "</edad>\n";
        xml << "  </persona>\n";
    }
    xml << "</personas>\n";
    xml.close();

    ofstream json(nombre + ".json");
    if (!json) {
        cout << "No se pudo crear el archivo JSON\n";
        return;
    }

    json << "{\n";
    json << "  \"personas\": [\n";
    for (int i = 0; i < tam; i++) {
        Persona p = *(personas + i);
        json << "    {\n";
        json << "      \"nombre\": \"" << escJson(p.nombre) << "\",\n";
        json << "      \"ap\": \"" << escJson(p.ap) << "\",\n";
        json << "      \"am\": \"" << escJson(p.am) << "\",\n";
        json << "      \"genero\": \"" << p.genero << "\",\n";
        json << "      \"edad\": " << p.edad << "\n";
        json << "    }";

        if (i < tam - 1) {
            json << ",";
        }

        json << "\n";
    }
    json << "  ]\n";
    json << "}\n";
    json.close();

    cout << "Archivos guardados\n";
}
