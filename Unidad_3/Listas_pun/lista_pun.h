#ifndef LISTA_PUN_H
#define LISTA_PUN_H

class ListaPun {
private:
    struct Nodo {
        int dato;
        Nodo* sig;
    };
    Nodo* cabeza;

public:
    ListaPun();
    void ins(int v);
    void eli(int v);
    void mos();

    bool vacia();
    bool llena();
    int tam();
    void guardarArchivo();
};

#endif
