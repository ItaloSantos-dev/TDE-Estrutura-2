#ifndef AVL_H_INCLUDED
#define AVL_H_INCLUDED
#include "erros.h"

typedef struct noavl{
    void* dado;
    struct noavl* dir, *esq;
    int altura;

}NoAvl;

typedef struct avl{
    NoAvl* raiz;
    int quantidadeno
}AVL;
AVL* IniciarAvl(CodigoErro* erro);
NoAvl* CriarNovoNoAvl(void* dado, CodigoErro* erro);
NoAvl* InserirAvl(AVL* arvore, NoAvl* raiz, void* novoDado, int (*comparar)(void*, void*), CodigoErro* erro);
NoAvl* BuscarAvl (NoAvl* raiz, void* valoChave, int (*comparar)(void*, void*),CodigoErro* erro);

NoAvl* RemoverNoAvl(AVL* arvore,NoAvl* raiz, void* valoChave, int (*comparar)(void*, void*), CodigoErro* erro);
NoAvl* RotacaoSimplesDir(NoAvl* raiz);
NoAvl* RotacaoSimplesEsq(NoAvl* raiz);
NoAvl* RotacaoEsqDir(NoAvl* raiz);
NoAvl* RotacaoDirEsq(NoAvl* raiz);


int Maior(int a, int b);
int AlturaDoNo(NoAvl* no);
int FatorDeBalanceamento(NoAvl* no);

NoAvl* Balancear(NoAvl* raiz);


void ImprimirAvl(NoAvl* raiz, void(*ExibirDados)(void*));

void LiberarAvl(AVL* arvore);

void LiberarNosAvl(NoAvl* raiz);

//Funções utilitárias



#endif // AVL_H_INCLUDED
