#ifndef LISTAENCADEADA_H_INCLUDED
#define LISTAENCADEADA_H_INCLUDED
#include "erros.h"
typedef struct nolista{
    void* dado;
    struct nolista* prox;
}NoLista;

typedef struct l{
    NoLista* cabeca;
}Lista;

Lista* CriarNovaLista (CodigoErro* erro);


NoLista* CriarNovoNoLista(void* dado, CodigoErro* erro);

void InserirLista(Lista* lista, void* dado, CodigoErro* erro);

void RemoverLista(Lista* lista, void*dado, int(*Comparar)(void*, void*), CodigoErro* erro);

void* BuscarLista(Lista* lista, void*dado, int(*Comparar)(void*, void*), void*(*RetornarDadoBuscado)(void*), CodigoErro* erro);

void ImprimirLista(Lista* lista, void(*ExibirDados)(void*));

Lista* LiberarLista(Lista* lista);

void ImprimirEntradaHash(void* dado);










#endif // LISTAENCADEADA_H_INCLUDED
