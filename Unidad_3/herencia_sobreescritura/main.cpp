#include <iostream>
#include "herencia_sobreescritura.h"
using namespace std;

#include <fstream>
#include <string>
#include <vector>

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

static void guardarRegistros(const std::string& nombreBase, const std::vector<Registro>& registros) {
    if (registros.empty()) {
        std::cout << "No hay datos para guardar\n";
        return;
    }

    std::ofstream txt(nombreBase + ".txt");
    for (size_t i = 0; i < registros.size(); i++) {
        txt << "Registro " << i + 1 << "\n";
        for (const auto& dato : registros[i]) {
            txt << dato.first << ": " << dato.second << "\n";
        }
        txt << "\n";
    }
    txt.close();

    std::ofstream csv(nombreBase + ".csv");
    csv << "registro,campo,valor\n";
    for (size_t i = 0; i < registros.size(); i++) {
        for (const auto& dato : registros[i]) {
            csv << i + 1 << "," << escaparCsv(dato.first) << "," << escaparCsv(dato.second) << "\n";
        }
    }
    csv.close();

    std::ofstream xml(nombreBase + ".xml");
    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    xml << "<registros>\n";
    for (size_t i = 0; i < registros.size(); i++) {
        xml << "  <registro numero=\"" << i + 1 << "\">\n";
        for (const auto& dato : registros[i]) {
            xml << "    <campo nombre=\"" << escaparXml(dato.first) << "\">" << escaparXml(dato.second) << "</campo>\n";
        }
        xml << "  </registro>\n";
    }
    xml << "</registros>\n";
    xml.close();

    std::ofstream json(nombreBase + ".json");
    json << "[\n";
    for (size_t i = 0; i < registros.size(); i++) {
        json << "  {\n";
        for (size_t j = 0; j < registros[i].size(); j++) {
            json << "    \"" << escaparJson(registros[i][j].first) << "\": \"" << escaparJson(registros[i][j].second) << "\"";
            if (j + 1 < registros[i].size()) json << ",";
            json << "\n";
        }
        json << "  }";
        if (i + 1 < registros.size()) json << ",";
        json << "\n";
    }
    json << "]\n";
    json.close();

    std::cout << "Datos guardados" << nombreBase;
}

int main() {
    CalculadoraNueva o;
    vector<Registro> registros;
    int opcion, a, b;
    bool continuar = true;
    bool agregar;

    do {
        agregar = true;

        cout << "\nHerencia y sobreescritura\n";
        cout << "1. Sumar n numeros\n";
        cout << "2. Restar n numeros\n";
        cout << "3. Multiplicar n numeros\n";
        cout << "4. Dividir n numeros\n";
        cout << "5. Multiplicacion por sumas sucesivas\n";
        cout << "6. Division por restas sucesivas\n";
        cout << "7. Potencia por multiplicaciones sucesivas\n";
        cout << "8. Guardar datos\n";
        cout << "9. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: o.leer(); o.sum(); break;
            case 2: o.leer(); o.res(); break;
            case 3: o.leer(); o.mult(); break;
            case 4: o.leer(); agregar = o.div(); break;
            case 5:
                cout << "Ingresa numero 1: "; cin >> a;
                cout << "Ingresa numero 2: "; cin >> b;
                o.mult(a, b);
                break;
            case 6:
                cout << "Ingresa numero 1: "; cin >> a;
                cout << "Ingresa numero 2: "; cin >> b;
                agregar = o.div(a, b);
                break;
            case 7:
                cout << "Ingresa base: "; cin >> a;
                cout << "Ingresa exponente: "; cin >> b;
                o.potencia(a, b);
                break;
            case 8:
                guardarRegistros("herencia_sobreescritura", registros);
                agregar = false;
                break;
            case 9:
                continuar = false;
                agregar = false;
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida\n";
                agregar = false;
        }

        if (agregar) {
            registros.push_back(o.obtenerDatos());
            cout << "Datos agregados. Registros pendientes: " << registros.size() << endl;
        }
    } while (continuar);

    return 0;
}
