#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED
typedef struct nolista{
    void* dado;
    struct nolista* prox;
}NoLista;

typedef struct l{
    NoLista* cabeca;
}Lista;

Lista* CriarNovaLista ();


NoLista* CriarNovoNoLista(void* dado);

void InserirLista(Lista* lista, void* dado);

void RemoverLista(Lista* lista, void*dado, int(*Comparar)(void*, void*));

void* BuscarLista(Lista* lista, void*dado, int(*Comparar)(void*, void*), void*(*RetornarDadoBuscado)(void*));

void ImprimirLista(Lista* lista, void(*ExibirDados)(void*));








#endif // LISTAENCADEADA_H_INCLUDED
