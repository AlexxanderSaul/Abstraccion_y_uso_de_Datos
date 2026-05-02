#ifndef LISTA_PUN_ND_H
#define LISTA_PUN_ND_H

#define MAX 5

struct Dato {
    int valor;
};

class ListaPunNd {
private:
    struct Nodo {
        Dato dato;
        Nodo* sig;
    };

    Nodo* cabeza;
    int tam;

public:
    ListaPunNd();
    bool ins(Dato d);
    void eli(int v);
    void mos();

    bool vacio();
    bool lleno();
    int tamanio();
};

#endif
