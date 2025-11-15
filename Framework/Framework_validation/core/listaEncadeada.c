#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"listaEncadeada.h"
#include"util.h"


Lista* CriarNovaLista (){
    Lista* NovaLista = malloc(sizeof(Lista));
    NovaLista->cabeca = malloc(sizeof(NoLista));
    NovaLista->cabeca->prox = NULL;
    return NovaLista;
}

NoLista* CriarNovoNoLista(void* dado){
    NoLista* NovoNoLista = malloc(sizeof(NoLista));
    NovoNoLista->dado = dado;
    NovoNoLista->prox = NULL;

}

void InserirLista(Lista* lista, void* dado){
    NoLista* NovoNoLista = CriarNovoNoLista(dado);
    NoLista* atual = lista->cabeca;

    while(atual->prox!=NULL){
        atual=atual->prox;
    }
    atual->prox = NovoNoLista;

}

void RemoverLista(Lista* lista, void*dado, int(*Comparar)(void*, void*)){
    NoLista* atual = lista->cabeca->prox;
    NoLista* antecessor = lista->cabeca;

    while(atual!=NULL && Comparar(dado, atual->dado)!=0){
        antecessor = atual;
        atual = atual->prox;
    }
    if(atual==NULL){
        return;
    }
    else{
        antecessor->prox = atual->prox;
        free(atual);
    }

}

void* BuscarLista(Lista* lista, void*dado, int(*Comparar)(void*, void*), void(*RetornarDadoBuscado)(void*)){
    NoLista* atual = lista->cabeca->prox;
    while(atual!=NULL && Comparar(dado, atual->dado)!=0){
        atual=atual->prox;

    }
    if(atual==NULL){
        return NULL;
    }
    else{
        RetornarDadoBuscado(atual->dado);
    }
}

void ImprimirLista(Lista* lista, void(*ExibirDados)(void*)){
    NoLista* atual = lista->cabeca->prox;
    while (atual!=NULL){
        ExibirDados(atual->dado);
        atual= atual->prox;
    }
}







