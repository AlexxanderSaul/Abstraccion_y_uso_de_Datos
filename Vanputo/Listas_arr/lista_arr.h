#ifndef LISTA_ARR_H
#define LISTA_ARR_H
#define MAX 5

class ListaArr {
private:
    int datos[MAX];
    int tam;

public:
    ListaArr();
    void ins(int v);
    void eli(int v);
    void mos();

    bool vacio();
    bool lleno();
    int tamanio();
};

#endif
