#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"listaEncadeada.h"
#include"util.h"


Lista* CriarNovaLista (CodigoErro* erro){
    Lista* NovaLista = malloc(sizeof(Lista));
    NovaLista->cabeca = malloc(sizeof(NoLista));
    if(!NovaLista && !NovaLista->cabeca){
        if(erro) *erro = ERRO_LISTA_MEMORIA;
        return NULL;
    }
    NovaLista->cabeca->prox = NULL;
    if(erro) *erro = ERRO_OK;
    return NovaLista;
}

NoLista* CriarNovoNoLista(void* dado, CodigoErro* erro){
    NoLista* NovoNoLista = malloc(sizeof(NoLista));
    if(!NovoNoLista){
        if(erro)*erro = ERRO_LISTA_NO_MEMORIA;
        return NULL;
    }

    NovoNoLista->dado = dado;
    NovoNoLista->prox = NULL;
    if(erro)*erro = ERRO_OK;
    return NovoNoLista;

}

void InserirLista(Lista* lista, void* dado, CodigoErro* erro){
    NoLista* NovoNoLista = CriarNovoNoLista(dado, erro);
    NoLista* atual = lista->cabeca;

    while(atual->prox!=NULL){
        atual=atual->prox;
    }
    atual->prox = NovoNoLista;
    if(erro)*erro = ERRO_OK;

}

void RemoverLista(Lista* lista, void*dado, int(*Comparar)(void*, void*), CodigoErro* erro){
    NoLista* atual = lista->cabeca->prox;
    NoLista* antecessor = lista->cabeca;
    while(atual!=NULL && Comparar(dado, atual->dado)!=0){
        antecessor = atual;
        atual = atual->prox;
    }
    if(atual==NULL){
        if(erro) *erro = ERRO_LISTA_NO_NAO_ENCONTRADO;
        return;
    }
    else{
        antecessor->prox = atual->prox;
        free(atual);
        if(erro)*erro = ERRO_OK;
    }

}

void* BuscarLista(Lista* lista, void*dado, int(*Comparar)(void*, void*), void*(*RetornarDadoBuscado)(void*), CodigoErro* erro){
    NoLista* atual = lista->cabeca->prox;
    while(atual!=NULL && Comparar(dado, atual->dado)!=0){
        atual=atual->prox;

    }
    if(atual==NULL){
        if(erro) *erro = ERRO_LISTA_NO_NAO_ENCONTRADO;
        return NULL;
    }
    else{
        if(erro) *erro = ERRO_OK;
        return RetornarDadoBuscado(atual->dado);
    }
}

void ImprimirLista(Lista* lista, void(*ExibirDados)(void*)){
    NoLista* atual = lista->cabeca->prox;
    while (atual!=NULL){
        ExibirDados(atual->dado);
        atual= atual->prox;
    }
}

Lista* LiberarLista(Lista* lista){
    if(!lista) return NULL;

    NoLista* atual = lista->cabeca;
    while(atual != NULL){
        NoLista* aux = atual;
        atual = atual->prox;

        // remove o free(aux->dado);
        free(aux);
    }

    free(lista);
    return NULL;
}









