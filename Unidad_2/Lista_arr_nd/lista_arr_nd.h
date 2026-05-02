#ifndef LISTA_ARR_NT_H
#define LISTA_ARR_NT_H
#define MAX 5

struct Dato {
    int valor;
};

class ListaArrNd {
private:
    Dato datos[MAX];
    int tam;

public:
    ListaArrNd();
    bool ins(Dato d);
    void eli(int v);
    void mos();

    bool vacio();
    bool lleno();
    int tamanio();
};

#endif
