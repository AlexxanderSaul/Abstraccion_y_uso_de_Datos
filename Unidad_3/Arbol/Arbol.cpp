#include "Arbol.h"
#include <climits>

// Insertar nodo en BST (por id)
static NodoArbol* insertarBST(NodoArbol* nodo, Lugar l) {
    if (!nodo) return new NodoArbol(l);
    if (l.id < nodo->dato.id) nodo->izq = insertarBST(nodo->izq, l);
    else                       nodo->der = insertarBST(nodo->der, l);
    return nodo;
}

void agregarNodo(Arbol& a, int id, string etiqueta) {
    Lugar l; l.id = id; l.etiqueta = etiqueta;
    a.nodos.push_back(l);
    a.raiz = insertarBST(a.raiz, l);
}

void agregarConexion(Arbol& a, int nodoIni, int nodoFin,
                    string arista, float tiempo, float costo) {
    conexionNodo2Nodo c;
    c.nodoInicial = nodoIni; c.nodoFinal = nodoFin;
    c.aristaConexion = arista; c.tiempo = tiempo; c.costo = costo;
    a.rutas.conexiones.push_back(c);
    bool existe = false;
    for (auto& ar : a.aristas) if (ar == arista) { existe = true; break; }
    if (!existe) a.aristas.push_back(arista);
}

// Recorridos
void inorden(NodoArbol* nodo) {
    if (!nodo) return;
    inorden(nodo->izq);
    cout << "  [" << nodo->dato.id << "] " << nodo->dato.etiqueta << endl;
    inorden(nodo->der);
}
void preorden(NodoArbol* nodo) {
    if (!nodo) return;
    cout << "  [" << nodo->dato.id << "] " << nodo->dato.etiqueta << endl;
    preorden(nodo->izq);
    preorden(nodo->der);
}
void posorden(NodoArbol* nodo) {
    if (!nodo) return;
    posorden(nodo->izq);
    posorden(nodo->der);
    cout << "  [" << nodo->dato.id << "] " << nodo->dato.etiqueta << endl;
}

void mostrarArbol(const Arbol& a) {
    cout << "\n=== ARBOL BST ===" << endl;
    cout << "Nodos (" << a.nodos.size() << "):" << endl;
    for (auto& n : a.nodos) cout << "  [" << n.id << "] " << n.etiqueta << endl;
    cout << "\nAristas (" << a.aristas.size() << "):" << endl;
    for (auto& ar : a.aristas) cout << "  " << ar << endl;
    cout << "\nRutas / conexionNodo2Nodo (" << a.rutas.conexiones.size() << "):" << endl;
    for (auto& c : a.rutas.conexiones)
        cout << "  " << c.nodoInicial << " -[" << c.aristaConexion << "]-> "
            << c.nodoFinal << " | tiempo:" << c.tiempo << " | costo:$" << c.costo << endl;
    cout << "\nRecorrido Inorden:" << endl;   inorden(a.raiz);
    cout << "\nRecorrido Preorden:" << endl;  preorden(a.raiz);
    cout << "\nRecorrido Posorden:" << endl;  posorden(a.raiz);
}

//Dijkstra sobre las conexiones del árbol
void dijkstra(const Arbol& a, int origen) {
    int n = a.nodos.size();
    vector<float> dist(n, 1e9);
    vector<int>   prev(n, -1);
    vector<bool>  vis(n, false);

    // mapear id -> indice
    auto idx = [&](int id) -> int {
        for (int i = 0; i < n; i++) if (a.nodos[i].id == id) return i;
        return -1;
    };
    auto etq = [&](int id) -> string {
        for (auto& nd : a.nodos) if (nd.id == id) return nd.etiqueta;
        return to_string(id);
    };

    int oi = idx(origen);
    if (oi == -1) { cout << "Nodo origen no encontrado." << endl; return; }
    dist[oi] = 0;

    for (int iter = 0; iter < n-1; iter++) {
        int u = -1; float mn = 1e9;
        for (int i = 0; i < n; i++) if (!vis[i] && dist[i] < mn) { mn = dist[i]; u = i; }
        if (u == -1) break;
        vis[u] = true;
        for (auto& c : a.rutas.conexiones) {
            int ui = idx(c.nodoInicial), vi = idx(c.nodoFinal);
            // árbol no dirigido
            if (ui == u && !vis[vi] && dist[u]+c.costo < dist[vi]) { dist[vi]=dist[u]+c.costo; prev[vi]=u; }
            if (vi == u && !vis[ui] && dist[u]+c.costo < dist[ui]) { dist[ui]=dist[u]+c.costo; prev[ui]=u; }
        }
    }

    cout << "\n=== Dijkstra desde [" << etq(origen) << "] ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "  -> " << etq(a.nodos[i].id);
        if (dist[i] >= 1e9) { cout << ": INACCESIBLE" << endl; continue; }
        cout << ": $" << dist[i] << "  | camino: ";
        vector<int> path;
        for (int cur = i; cur != -1; cur = prev[cur]) path.push_back(cur);
        for (int k = path.size()-1; k >= 0; k--) {
            cout << etq(a.nodos[path[k]].id);
            if (k > 0) cout << " -> ";
        }
        cout << endl;
    }
}

// ─── Leer XML ─────────────────────────────────────────────
void leerDesdeXML(Arbol& a, const string& archivo) {
    ifstream f(archivo);
    if (!f.is_open()) { cout << "[ERROR] No se pudo abrir " << archivo << endl; return; }
    string linea; conexionNodo2Nodo c; bool enC = false;
    while (getline(f, linea)) {
        if (linea.find("<conexionNodo2Nodo>") != string::npos) { enC = true; c = {}; }
        else if (linea.find("</conexionNodo2Nodo>") != string::npos) {
            if (enC) agregarConexion(a,c.nodoInicial,c.nodoFinal,c.aristaConexion,c.tiempo,c.costo);
            enC = false;
        } else if (enC) {
            auto ext=[&](string tag)->string{
                string op="<"+tag+">",cl="</"+tag+">";
                size_t s=linea.find(op),e=linea.find(cl);
                if(s!=string::npos&&e!=string::npos)return linea.substr(s+op.size(),e-s-op.size());
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
            auto ext=[&](string tag)->string{
                string op="<"+tag+">",cl="</"+tag+">";
                size_t s=linea.find(op),e=linea.find(cl);
                if(s!=string::npos&&e!=string::npos)return linea.substr(s+op.size(),e-s-op.size());
                return "";
            };
            string sid=ext("id"),set=ext("etiqueta");
            if(!sid.empty()) agregarNodo(a,stoi(sid),set);
        }
    }
    f.close();
    cout<<"XML cargado: "<<a.rutas.conexiones.size()<<" conexiones, "<<a.nodos.size()<<" nodos."<<endl;
}

// Leer JSON
void leerDesdeJSON(Arbol& a, const string& archivo) {
    ifstream f(archivo);
    if (!f.is_open()) { cout<<"[ERROR] No se pudo abrir "<<archivo<<endl; return; }
    string content((istreambuf_iterator<char>(f)),istreambuf_iterator<char>());
    f.close();
    auto extVal=[&](const string& bloque,const string& key)->string{
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
        size_t arr=content.find("[",posN),arrE=content.find("]",arr);
        string nArr=content.substr(arr,arrE-arr+1); size_t p=0;
        while((p=nArr.find("{",p))!=string::npos){
            size_t e=nArr.find("}",p); string blk=nArr.substr(p,e-p+1);
            string sid=extVal(blk,"id"),set=extVal(blk,"etiqueta");
            if(!sid.empty()) agregarNodo(a,stoi(sid),set); p=e+1;
        }
    }
    size_t posC=content.find("\"conexiones\"");
    if(posC!=string::npos){
        size_t arr=content.find("[",posC),arrE=content.find("]",arr);
        string cArr=content.substr(arr,arrE-arr+1); size_t p=0;
        while((p=cArr.find("{",p))!=string::npos){
            size_t e=cArr.find("}",p); string blk=cArr.substr(p,e-p+1);
            string sni=extVal(blk,"nodoInicial"),snf=extVal(blk,"nodoFinal");
            string sac=extVal(blk,"aristaConexion"),st=extVal(blk,"tiempo"),sc=extVal(blk,"costo");
            if(!sni.empty()) agregarConexion(a,stoi(sni),stoi(snf),sac,stof(st),stof(sc));
            p=e+1;
        }
    }
    cout<<"JSON cargado: "<<a.rutas.conexiones.size()<<" conexiones."<<endl;
}

// Aquí se guardan las 4 salidas
void guardarSalidas(const Arbol& a) {
    ofstream txt("salida.txt");
    txt<<"=== ARBOL BST ==="<<endl<<"NODOS:"<<endl;
    for(auto& n:a.nodos) txt<<"  ["<<n.id<<"] "<<n.etiqueta<<endl;
    txt<<"ARISTAS:"<<endl;
    for(auto& ar:a.aristas) txt<<"  "<<ar<<endl;
    txt<<"RUTAS (conexionNodo2Nodo):"<<endl;
    for(auto& c:a.rutas.conexiones)
        txt<<"  "<<c.nodoInicial<<" -["<<c.aristaConexion<<"]->"<<c.nodoFinal
        <<" | tiempo:"<<c.tiempo<<" | costo:"<<c.costo<<endl;
    txt.close();

    ofstream csv("salida.csv");
    csv<<"tipo,id,etiqueta,nodoInicial,nodoFinal,aristaConexion,tiempo,costo"<<endl;
    for(auto& n:a.nodos) csv<<"nodo,"<<n.id<<","<<n.etiqueta<<",,,,,\n";
    for(auto& c:a.rutas.conexiones)
        csv<<"conexion,,,"<<c.nodoInicial<<","<<c.nodoFinal<<","<<c.aristaConexion<<","<<c.tiempo<<","<<c.costo<<"\n";
    csv.close();

    ofstream json("salida.json");
    json<<"{\n  \"arbol\": {\n    \"nodos\": [\n";
    for(size_t i=0;i<a.nodos.size();i++){
        json<<"      {\"id\":"<<a.nodos[i].id<<",\"etiqueta\":\""<<a.nodos[i].etiqueta<<"\"}";
        if(i<a.nodos.size()-1)json<<","; json<<"\n";
    }
    json<<"    ],\n    \"aristas\": [";
    for(size_t i=0;i<a.aristas.size();i++){json<<"\""<<a.aristas[i]<<"\"";if(i<a.aristas.size()-1)json<<",";}
    json<<"],\n    \"rutas\": {\n      \"conexiones\": [\n";
    for(size_t i=0;i<a.rutas.conexiones.size();i++){
        auto& c=a.rutas.conexiones[i];
        json<<"        {\n          \"conexionNodo2Nodo\": {\n";
        json<<"            \"nodoInicial\": "<<c.nodoInicial<<",\n";
        json<<"            \"nodoFinal\": "<<c.nodoFinal<<",\n";
        json<<"            \"aristaConexion\": \""<<c.aristaConexion<<"\",\n";
        json<<"            \"tiempo\": "<<c.tiempo<<",\n";
        json<<"            \"costo\": "<<c.costo<<"\n";
        json<<"          }\n        }";
        if(i<a.rutas.conexiones.size()-1)json<<","; json<<"\n";
    }
    json<<"      ]\n    }\n  }\n}"<<endl;
    json.close();

    ofstream xml("salida.xml");
    xml<<"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<arbol>\n  <nodos>\n";
    for(auto& n:a.nodos) xml<<"    <nodo><id>"<<n.id<<"</id><etiqueta>"<<n.etiqueta<<"</etiqueta></nodo>\n";
    xml<<"  </nodos>\n  <aristas>\n";
    for(auto& ar:a.aristas) xml<<"    <arista>"<<ar<<"</arista>\n";
    xml<<"  </aristas>\n  <rutas>\n    <conexiones>\n";
    for(auto& c:a.rutas.conexiones){
        xml<<"      <conexionNodo2Nodo>\n";
        xml<<"        <nodoInicial>"<<c.nodoInicial<<"</nodoInicial>\n";
        xml<<"        <nodoFinal>"<<c.nodoFinal<<"</nodoFinal>\n";
        xml<<"        <aristaConexion>"<<c.aristaConexion<<"</aristaConexion>\n";
        xml<<"        <tiempo>"<<c.tiempo<<"</tiempo>\n";
        xml<<"        <costo>"<<c.costo<<"</costo>\n";
        xml<<"      </conexionNodo2Nodo>\n";
    }
    xml<<"    </conexiones>\n  </rutas>\n</arbol>"<<endl;
    xml.close();
    cout<<"[Salidas generadas: salida.txt, salida.csv, salida.json, salida.xml]"<<endl;
}
