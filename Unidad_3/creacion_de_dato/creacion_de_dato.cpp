#include "creacion_de_dato.h"
#include <iostream>
#include <fstream>
using namespace std;

static std::string escaparJson(const std::string& texto) {
    std::string r;
    for (char c : texto) {
        if (c == '"') r += "\\\"";
        else if (c == '\\') r += "\\\\";
        else if (c == '\n') r += "\\n";
        else r += c;
    }
    return r;
}

static std::string escaparXml(const std::string& texto) {
    std::string r;
    for (char c : texto) {
        if (c == '&') r += "&amp;";
        else if (c == '<') r += "&lt;";
        else if (c == '>') r += "&gt;";
        else if (c == '"') r += "&quot;";
        else r += c;
    }
    return r;
}

static std::string escaparCsv(const std::string& texto) {
    std::string r = "\"";
    for (char c : texto) {
        if (c == '"') r += "\"\"";
        else r += c;
    }
    r += "\"";
    return r;
}

void guardarArchivos(const std::string& nombreBase, const Registro& datos) {
    std::ofstream txt(nombreBase + ".txt");
    for (const auto& dato : datos) {
        txt << dato.first << ": " << dato.second << "\n";
    }
    txt.close();

    std::ofstream csv(nombreBase + ".csv");
    csv << "campo,valor\n";
    for (const auto& dato : datos) {
        csv << escaparCsv(dato.first) << "," << escaparCsv(dato.second) << "\n";
    }
    csv.close();

    std::ofstream xml(nombreBase + ".xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    xml << "<registro>\n";
    for (const auto& dato : datos) {
        xml << "  <campo nombre=\"" << escaparXml(dato.first) << "\">" << escaparXml(dato.second) << "</campo>\n";
    }
    xml << "</registro>\n";
    xml.close();

    std::ofstream json(nombreBase + ".json");
    json << "{\n";
    for (size_t i = 0; i < datos.size(); i++) {
        json << "  \"" << escaparJson(datos[i].first) << "\": \"" << escaparJson(datos[i].second) << "\"";
        if (i + 1 < datos.size()) json << ",";
        json << "\n";
    }
    json << "}\n";
    json.close();

    std::cout << "Datos guardados en " << nombreBase << ".txt, .csv, .xml y .json\n";
}

void guardarDatos(const string& nombreBase, const Registro& datos) {
    guardarArchivos(nombreBase, datos);
}

void AutoPOO::leer() {
    cout << "Precio del auto: ";
    cin >> precio;
    cout << "Anio del auto: ";
    cin >> anio;
}

void AutoPOO::mostrar() {
    cout << "Precio: " << precio << endl;
    cout << "Anio: " << anio << endl;
}

Registro AutoPOO::obtenerDatos() {
    return {{"programa", "creacion_de_dato"}, {"tipo", "Auto POO"}, {"precio", to_string(precio)}, {"anio", to_string(anio)}};
}

void PersonaPOO::leer() {
    cout << "Nombre: "; cin >> nombre;
    cout << "Apellido paterno: "; cin >> ap;
    cout << "Apellido materno: "; cin >> am;
    cout << "Genero: "; cin >> genero;
    cout << "Edad: "; cin >> edad;
}

void PersonaPOO::mostrar() {
    cout << "Nombre completo: " << nombre << " " << ap << " " << am << endl;
    cout << "Genero: " << genero << endl;
    cout << "Edad: " << edad << endl;
}

Registro PersonaPOO::obtenerDatos() {
    return {{"programa", "creacion_de_dato"}, {"tipo", "Persona POO"}, {"nombre", nombre}, {"apellido_paterno", ap}, {"apellido_materno", am}, {"genero", genero}, {"edad", to_string(edad)}};
}

Registro datosAutoPE(AutoPE a) {
    return {{"programa", "creacion_de_dato"}, {"tipo", "Auto PE"}, {"precio", to_string(a.precio)}, {"anio", to_string(a.anio)}};
}

Registro datosPersonaPE(PersonaPE p) {
    return {{"programa", "creacion_de_dato"}, {"tipo", "Persona PE"}, {"nombre", p.nombre}, {"apellido_paterno", p.ap}, {"apellido_materno", p.am}, {"genero", p.genero}, {"edad", to_string(p.edad)}};
}
