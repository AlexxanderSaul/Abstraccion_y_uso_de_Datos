#include "promedio.h"
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

    std::cout << "Datos guardados" << nombreBase;
}

Prom::Prom() {
    suma = 0;
    maxi = 0;
    mini = 0;
    resultado = 0;
    operacion = "";
}

void Prom::leer() {
    cout << "Ingresa los 5 numeros:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> num[i];
    }
}

void Prom::sum() {
    resultado = 0;
    for (int i = 0; i < 5; i++) resultado += num[i];
    operacion = "suma";
    cout << "Resultado: " << resultado << endl;
}

void Prom::prom() {
    suma = 0;
    for (int i = 0; i < 5; i++) suma += num[i];
    resultado = suma / 5.0;
    operacion = "promedio";
    cout << "Promedio: " << resultado << endl;
}

void Prom::maymen() {
    maxi = num[0];
    mini = num[0];
    for (int i = 1; i < 5; i++) {
        if (num[i] > maxi) maxi = num[i];
        if (num[i] < mini) mini = num[i];
    }
    resultado = maxi;
    operacion = "maximo_minimo";
    cout << "Maximo: " << maxi << endl;
    cout << "Minimo: " << mini << endl;
}

string Prom::numerosComoTexto() {
    string texto;
    for (int i = 0; i < 5; i++) {
        texto += to_string(num[i]);
        if (i + 1 < 5) texto += " ";
    }
    return texto;
}

Registro Prom::obtenerDatos() {
    Registro datos = {{"programa", "promedio"}, {"numeros", numerosComoTexto()}, {"operacion", operacion}, {"resultado", to_string(resultado)}};
    if (operacion == "maximo_minimo") {
        datos.push_back({"maximo", to_string(maxi)});
        datos.push_back({"minimo", to_string(mini)});
    }
    return datos;
}

void Prom::guardar() {
    guardarArchivos("promedio", obtenerDatos());
}
