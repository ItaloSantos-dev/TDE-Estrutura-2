#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"avl.h"
#include"util.h"


AVL* IniciarAvl(CodigoErro* erro){
    AVL* arvore = malloc(sizeof(AVL));
    if(!arvore){
        if(erro)*erro = ERRO_AVL_MEMORIA;
        return NULL;
    }
    arvore->raiz=NULL;
    arvore->quantidadeno=0;
    if(erro)*erro = ERRO_OK;
    return arvore;
}

NoAvl* CriarNovoNoAvl(void* _dado, CodigoErro* erro){
    NoAvl* novoNoAVL = malloc(sizeof(NoAvl));
    if(!novoNoAVL){
        if(erro)*erro = ERRO_AVL_MEMORIA;
        return NULL;
    }
    novoNoAVL->dado = _dado;
    novoNoAVL->esq = NULL;
    novoNoAVL->dir =NULL;
    novoNoAVL->altura = 0;
    if(erro)*erro = ERRO_OK;
    return novoNoAVL;


}


NoAvl* InserirAvl(AVL* arvore, NoAvl* raiz, void* novoDado, int (*comparar)(void*, void*), CodigoErro* erro){
    if(raiz==NULL){
        arvore->quantidadeno++;
        return CriarNovoNoAvl(novoDado, erro);

    }
    else{
        int comparacao = comparar(novoDado, raiz->dado);
        if(comparacao==0){
            if(erro) *erro = ERRO_DADO_JA_EXISTENTE;
            return raiz;
        }

        if(comparacao<0){
            raiz->esq = InserirAvl(arvore, raiz->esq, novoDado, comparar, erro);
        }
        else{
            raiz->dir = InserirAvl(arvore, raiz->dir, novoDado, comparar, erro);
        }
    }

    raiz->altura = Maior(AlturaDoNo(raiz->esq), AlturaDoNo(raiz->dir))+1;
    raiz = Balancear(raiz);
    return raiz;

}

NoAvl* BuscarAvl (NoAvl* raiz, void* valoChave, int (*comparar)(void*, void*), CodigoErro* erro){
    if(raiz==NULL){
        if(erro)*erro = ERRO_AVL_NO_NAO_ENCONTRADO;
        return NULL;
    }
    else{
        int comparacao =  comparar(valoChave, raiz->dado);
        if(comparacao==0){
            if(erro)*erro = ERRO_OK;
            return raiz;
        }
        else if(comparacao<0){
            return BuscarAvl(raiz->esq, valoChave, comparar, erro);
        }
        else{
            return BuscarAvl(raiz->dir, valoChave, comparar, erro);
        }

    }

}


NoAvl* RemoverNoAvl(AVL* arvore, NoAvl* raiz, void* valoChave, int (*comparar)(void*, void*), CodigoErro* erro){

    if(raiz==NULL){
        if(erro)*erro = ERRO_AVL_NO_NAO_ENCONTRADO;
        return NULL;
    }
    else{
        int comparacao = comparar(valoChave, raiz->dado);

        if(comparacao==0){

            if(raiz->esq==NULL && raiz->dir==NULL){
                free(raiz);
                arvore->quantidadeno--;
                if(erro)*erro = ERRO_OK;
                return NULL;
            }
            else{
                if(raiz->esq!=NULL && raiz->dir !=NULL){
                    NoAvl* aux = raiz->esq;
                    while(aux->dir!=NULL){
                        aux = aux->dir;
                    }
                    raiz->dado=aux->dado;
                    raiz->esq = RemoverNoAvl(arvore, raiz->esq, aux->dado, comparar, erro);
                    return raiz;

                }
                else{
                    NoAvl* substituto;
                    if(raiz->esq!=NULL){
                        substituto = raiz->esq;
                    }
                    else{
                        substituto = raiz->dir;
                    }
                    free(raiz);
                    arvore->quantidadeno--;
                    if(erro)*erro = ERRO_OK;
                    return substituto;
                }
            }
        }
        else if(comparacao<0){
            raiz->esq = RemoverNoAvl(arvore, raiz->esq, valoChave, comparar, erro);
        }
        else{
            raiz->dir = RemoverNoAvl(arvore, raiz->dir, valoChave, comparar,erro);
        }
    }
    raiz->altura = Maior(AlturaDoNo(raiz->esq), AlturaDoNo(raiz->dir))+1;
    raiz = Balancear(raiz);
    return raiz;


}

//--------------------------------------------Rotacoes

NoAvl* RotacaoSimplesDir(NoAvl* raiz){
    NoAvl* aux1, *aux2;

    aux1=raiz->esq;
    aux2 = aux1->dir;

    aux1->dir = raiz;
    raiz->esq = aux2;
    raiz->altura = Maior(AlturaDoNo(raiz->esq), AlturaDoNo(raiz->dir))+1;
    aux1->altura = Maior(AlturaDoNo(aux1->esq), AlturaDoNo(aux1->dir))+1;
    return aux1;

}

NoAvl* RotacaoSimplesEsq(NoAvl* raiz){
    NoAvl* aux1, *aux2;

    aux1= raiz->dir;
    aux2=aux1->esq;

    aux1->esq = raiz;
    raiz->dir = aux2;

    raiz->altura = Maior(AlturaDoNo(raiz->esq), AlturaDoNo(raiz->dir))+1;
    aux1->altura = Maior(AlturaDoNo(aux1->esq), AlturaDoNo(aux1->dir))+1;
    return aux1;


}

NoAvl* RotacaoDirEsq(NoAvl* raiz){
    raiz->esq = RotacaoSimplesEsq(raiz->esq);
    return RotacaoSimplesDir(raiz);
}

NoAvl* RotacaoEsqDir(NoAvl* raiz){
    raiz->dir = RotacaoSimplesDir(raiz->dir);
    return RotacaoSimplesEsq(raiz);
}




//Retorna o maior valor entre A e B
int Maior(int a, int b){
    return (a>b)? a:b;
}

//Retorna a altura do no ou -1 se for NULL
int AlturaDoNo(NoAvl* no){
    if(no==NULL){
        return -1;
    }
    else{
        return no->altura;
    }
}


//Retorna o FTB do no. altura do no->esq - altura do no->dir
int FatorDeBalanceamento(NoAvl* no){
    if(no){
        return (AlturaDoNo(no->esq) - AlturaDoNo(no->dir));
    }
    else{
        return 0;
    }
}

NoAvl* Balancear(NoAvl* raiz){
    int ftb = FatorDeBalanceamento(raiz);

    if(ftb>1&& FatorDeBalanceamento(raiz->esq)>=0){
        raiz = RotacaoSimplesDir(raiz);
    }
    else if(ftb<-1&& FatorDeBalanceamento(raiz->dir)<=0){
        raiz = RotacaoSimplesEsq(raiz);
    }
    else if(ftb>1&&FatorDeBalanceamento(raiz->esq)<0){
        raiz = RotacaoDirEsq(raiz);
    }
    else if(ftb<-1 && FatorDeBalanceamento(raiz->dir)>0){
        raiz = RotacaoEsqDir(raiz);
    }
    return raiz;
}

//----------------------

void ImprimirAvl(NoAvl* raiz, void(*ExibirDados)(void*)){
    ExibirDados(raiz->dado);
    if(raiz->esq!=NULL){
        ImprimirAvl(raiz->esq, ExibirDados);
    }
    if(raiz->dir!=NULL){
        ImprimirAvl(raiz->dir, ExibirDados);
    }

}

void LiberarAvl(AVL* arvore){
    if(arvore->raiz==NULL){
        free(arvore->raiz);
        free(arvore);
        return;
    }
    else{
       LiberarNosAvl(arvore->raiz);
    }
}

void LiberarNosAvl(NoAvl* raiz){
    free(raiz->dado);
    if(raiz->esq!=NULL){
        LiberarNosAvl(raiz->esq);
    }
    if(raiz->dir!=NULL){
        LiberarNosAvl(raiz->dir);
    }
    free(raiz);
}












