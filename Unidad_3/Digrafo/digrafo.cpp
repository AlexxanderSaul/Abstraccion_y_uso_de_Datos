#include "digrafo.h"
#include <climits>

void agregarNodo(Digrafo& g, int id, string etiqueta) {
    Lugar l; l.id = id; l.etiqueta = etiqueta;
    g.nodos.push_back(l);
}

void agregarConexion(Digrafo& g, int nodoIni, int nodoFin,
                    string arista, float tiempo, float costo) {
    conexionNodo2Nodo c;
    c.nodoInicial = nodoIni; c.nodoFinal = nodoFin;
    c.aristaConexion = arista; c.tiempo = tiempo; c.costo = costo;
    g.rutas.conexiones.push_back(c);
    bool existe = false;
    for (auto& a : g.aristas) if (a == arista) { existe = true; break; }
    if (!existe) g.aristas.push_back(arista);
}

void mostrarDigrafo(const Digrafo& g) {
    cout << "\nDIGRAFO (dirigido)" << endl;
    cout << "Nodos (" << g.nodos.size() << "):" << endl;
    for (auto& n : g.nodos) cout << "  [" << n.id << "] " << n.etiqueta << endl;
    cout << "\nAristas (" << g.aristas.size() << "):" << endl;
    for (auto& a : g.aristas) cout << "  " << a << endl;
    cout << "\nRutas / conexionNodo2Nodo (" << g.rutas.conexiones.size() << "):" << endl;
    for (auto& c : g.rutas.conexiones)
        cout << "  " << c.nodoInicial << " --[" << c.aristaConexion
            << "]--> " << c.nodoFinal
            << "  | tiempo: " << c.tiempo
            << " min  | costo: $" << c.costo << endl;
}

void dijkstra(const Digrafo& g, int origen) {
    int n = g.nodos.size();
    vector<float> dist(n, 1e9);
    vector<int>   prev(n, -1);
    vector<bool>  vis(n, false);
    if (origen < 0 || origen >= n) {
        cout << "Nodo origen invalido." << endl;
        return;
    }
    dist[origen] = 0;

    for (int iter = 0; iter < n-1; iter++) {
        int u = -1; float mn = 1e9;
        for (int i = 0; i < n; i++)
            if (!vis[i] && dist[i] < mn) { mn = dist[i]; u = i; }
        if (u == -1) break;
        vis[u] = true;
        // DIGRAFO: solo relaja en la dirección nodoInicial -> nodoFinal
        for (auto& c : g.rutas.conexiones) {
        int v = -1;
        float w = c.costo;

        if (c.nodoInicial == g.nodos[u].id) {
            for (int j = 0; j < n; j++) {
                if (g.nodos[j].id == c.nodoFinal) {
                    v = j;
                    break;
                }
            }
        }

    else if (c.nodoFinal == g.nodos[u].id) {
        for (int j = 0; j < n; j++) {
            if (g.nodos[j].id == c.nodoInicial) {
                v = j;
                break;
            }
        }
    }

    if (v != -1 && !vis[v] && dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        prev[v] = u;
    }
}
    }

    auto etq = [&](int id) -> string {
        for (auto& nd : g.nodos) if (nd.id == id) return nd.etiqueta;
        return to_string(id);
    };

    cout << "\nDijkstra desde [" << etq(origen) << "]" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  -> " << etq(g.nodos[i].id);
        if (dist[i] >= 1e9) { cout << ": INACCESIBLE" << endl; continue; }
        cout << ": $" << dist[i] << "  | camino: ";
        vector<int> path;
        for (int cur = i; cur != -1; cur = prev[cur]) path.push_back(cur);
        for (int k = path.size()-1; k >= 0; k--) {
            cout << etq(g.nodos[path[k]].id);
            if (k > 0) cout << " -> ";
        }
        cout << endl;
    }
}

void leerDesdeXML(Digrafo& g, const string& archivo) {
    ifstream f(archivo);
    if (!f.is_open()) { cout << "[ERROR] No se pudo abrir " << archivo << endl; return; }
    string linea; conexionNodo2Nodo c; bool enConexion = false;
    while (getline(f, linea)) {
        if (linea.find("<conexionNodo2Nodo>") != string::npos) { enConexion = true; c = {}; }
        else if (linea.find("</conexionNodo2Nodo>") != string::npos) {
            if (enConexion) agregarConexion(g, c.nodoInicial, c.nodoFinal, c.aristaConexion, c.tiempo, c.costo);
            enConexion = false;
        } else if (enConexion) {
            auto ext = [&](string tag) -> string {
                string op="<"+tag+">", cl="</"+tag+">";
                size_t s=linea.find(op), e=linea.find(cl);
                if(s!=string::npos&&e!=string::npos) return linea.substr(s+op.size(),e-s-op.size());
                return "";
            };
            string v;
            if(!(v=ext("nodoInicial")).empty())    c.nodoInicial=stoi(v);
            if(!(v=ext("nodoFinal")).empty())      c.nodoFinal=stoi(v);
            if(!(v=ext("aristaConexion")).empty()) c.aristaConexion=v;
            if(!(v=ext("tiempo")).empty())         c.tiempo=stof(v);
            if(!(v=ext("costo")).empty())          c.costo=stof(v);
        }
        if (linea.find("<nodo>") != string::npos) {
            auto ext = [&](string tag) -> string {
                string op="<"+tag+">", cl="</"+tag+">";
                size_t s=linea.find(op), e=linea.find(cl);
                if(s!=string::npos&&e!=string::npos) return linea.substr(s+op.size(),e-s-op.size());
                return "";
            };
            string sid=ext("id"), set=ext("etiqueta");
            if(!sid.empty()) agregarNodo(g, stoi(sid), set);
        }
    }
    f.close();
    cout << "XML cargado: " << g.rutas.conexiones.size() << " conexiones." << endl;
}

void leerDesdeJSON(Digrafo& g, const string& archivo) {
    ifstream f(archivo);
    if (!f.is_open()) { cout << "[ERROR] No se pudo abrir " << archivo << endl; return; }
    string content((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
    f.close();
    auto extVal = [&](const string& bloque, const string& key) -> string {
        size_t k=bloque.find("\""+key+"\""); if(k==string::npos)return "";
        size_t col=bloque.find(":",k); if(col==string::npos)return "";
        size_t vs=col+1;
        while(vs<bloque.size()&&(bloque[vs]==' '||bloque[vs]=='\t'||bloque[vs]=='\n'))vs++;
        if(bloque[vs]=='"'){size_t ve=bloque.find("\"",vs+1);return bloque.substr(vs+1,ve-vs-1);}
        size_t ve=vs; while(ve<bloque.size()&&bloque[ve]!=','&&bloque[ve]!='}')ve++;
        return bloque.substr(vs,ve-vs);
    };
    size_t posN=content.find("\"nodos\"");
    if(posN!=string::npos){
        size_t arr=content.find("[",posN), arrE=content.find("]",arr);
        string nArr=content.substr(arr,arrE-arr+1); size_t p=0;
        while((p=nArr.find("{",p))!=string::npos){
            size_t e=nArr.find("}",p); string blk=nArr.substr(p,e-p+1);
            string sid=extVal(blk,"id"),set=extVal(blk,"etiqueta");
            if(!sid.empty()) agregarNodo(g,stoi(sid),set); p=e+1;
        }
    }
    size_t posC=content.find("\"conexiones\"");
    if(posC!=string::npos){
        size_t arr=content.find("[",posC), arrE=content.find("]",arr);
        string cArr=content.substr(arr,arrE-arr+1); size_t p=0;
        while((p=cArr.find("{",p))!=string::npos){
            size_t e=cArr.find("}",p); string blk=cArr.substr(p,e-p+1);
            string sni=extVal(blk,"nodoInicial"),snf=extVal(blk,"nodoFinal");
            string sac=extVal(blk,"aristaConexion"),st=extVal(blk,"tiempo"),sc=extVal(blk,"costo");
            if(!sni.empty()) agregarConexion(g,stoi(sni),stoi(snf),sac,stof(st),stof(sc));
            p=e+1;
        }
    }
    cout << "JSON cargado: " << g.rutas.conexiones.size() << " conexiones." << endl;
}

void guardarSalidas(const Digrafo& g) {
    ofstream txt("salida.txt");
    txt << "=== DIGRAFO ===" << endl;
    txt << "NODOS:" << endl;
    for(auto& n:g.nodos) txt<<"  ["<<n.id<<"] "<<n.etiqueta<<endl;
    txt << "ARISTAS:" << endl;
    for(auto& a:g.aristas) txt<<"  "<<a<<endl;
    txt << "RUTAS (conexionNodo2Nodo):" << endl;
    for(auto& c:g.rutas.conexiones)
        txt<<"  "<<c.nodoInicial<<" -["<<c.aristaConexion<<"]--> "<<c.nodoFinal
        <<" | tiempo:"<<c.tiempo<<" | costo:"<<c.costo<<endl;
    txt.close();

    ofstream csv("salida.csv");
    csv<<"tipo,id,etiqueta,nodoInicial,nodoFinal,aristaConexion,tiempo,costo"<<endl;
    for(auto& n:g.nodos) csv<<"nodo,"<<n.id<<","<<n.etiqueta<<",,,,,\n";
    for(auto& c:g.rutas.conexiones)
        csv<<"conexion,,,"<<c.nodoInicial<<","<<c.nodoFinal<<","<<c.aristaConexion<<","<<c.tiempo<<","<<c.costo<<"\n";
    csv.close();

    ofstream json("salida.json");
    json<<"{\n  \"digrafo\": {\n    \"nodos\": [\n";
    for(size_t i=0;i<g.nodos.size();i++){
        json<<"      {\"id\":"<<g.nodos[i].id<<",\"etiqueta\":\""<<g.nodos[i].etiqueta<<"\"}";
        if(i<g.nodos.size()-1)json<<","; json<<"\n";
    }
    json<<"    ],\n    \"aristas\": [";
    for(size_t i=0;i<g.aristas.size();i++){json<<"\""<<g.aristas[i]<<"\"";if(i<g.aristas.size()-1)json<<",";}
    json<<"],\n    \"rutas\": {\n      \"conexiones\": [\n";
    for(size_t i=0;i<g.rutas.conexiones.size();i++){
        auto& c=g.rutas.conexiones[i];
        json<<"        {\n          \"conexionNodo2Nodo\": {\n";
        json<<"            \"nodoInicial\": "<<c.nodoInicial<<",\n";
        json<<"            \"nodoFinal\": "<<c.nodoFinal<<",\n";
        json<<"            \"aristaConexion\": \""<<c.aristaConexion<<"\",\n";
        json<<"            \"tiempo\": "<<c.tiempo<<",\n";
        json<<"            \"costo\": "<<c.costo<<"\n";
        json<<"          }\n        }";
        if(i<g.rutas.conexiones.size()-1)json<<","; json<<"\n";
    }
    json<<"      ]\n    }\n  }\n}"<<endl;
    json.close();

    ofstream xml("salida.xml");
    xml<<"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<digrafo>\n  <nodos>\n";
    for(auto& n:g.nodos) xml<<"    <nodo><id>"<<n.id<<"</id><etiqueta>"<<n.etiqueta<<"</etiqueta></nodo>\n";
    xml<<"  </nodos>\n  <aristas>\n";
    for(auto& a:g.aristas) xml<<"    <arista>"<<a<<"</arista>\n";
    xml<<"  </aristas>\n  <rutas>\n    <conexiones>\n";
    for(auto& c:g.rutas.conexiones){
        xml<<"      <conexionNodo2Nodo>\n";
        xml<<"        <nodoInicial>"<<c.nodoInicial<<"</nodoInicial>\n";
        xml<<"        <nodoFinal>"<<c.nodoFinal<<"</nodoFinal>\n";
        xml<<"        <aristaConexion>"<<c.aristaConexion<<"</aristaConexion>\n";
        xml<<"        <tiempo>"<<c.tiempo<<"</tiempo>\n";
        xml<<"        <costo>"<<c.costo<<"</costo>\n";
        xml<<"      </conexionNodo2Nodo>\n";
    }
    xml<<"    </conexiones>\n  </rutas>\n</digrafo>"<<endl;
    xml.close();
    cout<<"[Salidas generadas: salida.txt, salida.csv, salida.json, salida.xml]"<<endl;
}
