#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"avl.h"
#include"util.h"

AVL* IniciarAvl(){
    AVL* arvore = malloc(sizeof(AVL));
    arvore->raiz=NULL;
    return arvore;
}

NoAvl* CriarNovoNoAvl(void* _dado){
    NoAvl* novoNoAVL = malloc(sizeof(NoAvl));
    if(novoNoAVL==NULL){
        printf("Erro ao alocar memoria\n");
        return NULL;
    }
    else{
        novoNoAVL->dado = _dado;
        novoNoAVL->esq = NULL;
        novoNoAVL->dir =NULL;
        novoNoAVL->altura = 0;
        return novoNoAVL;
    }

}




NoAvl* InserirAvl(NoAvl* raiz, void* novoDado, int (*comparar)(void*, void*)){
    if(raiz==NULL){
        return CriarNovoNoAvl(novoDado);
    }
    else{
        int comparacao = comparar(novoDado, raiz->dado);

        if(comparacao<0){
            raiz->esq = InserirAvl(raiz->esq, novoDado, comparar);
        }
        else{
            raiz->dir = InserirAvl(raiz->dir, novoDado, comparar);
        }
    }

    raiz->altura = Maior(AlturaDoNo(raiz->esq), AlturaDoNo(raiz->dir))+1;
    raiz = Balancear(raiz);
    return raiz;

}

NoAvl* BuscarAvl (NoAvl* raiz, void* valoChave, int (*comparar)(void*, void*)){
    if(raiz==NULL){
        return NULL;
    }
    else{
        int comparacao =  comparar(valoChave, raiz->dado);
        if(comparacao==0){
            return raiz;
        }
        else if(comparacao<0){
            return BuscarAvl(raiz->esq, valoChave, comparar);
        }
        else{
            return BuscarAvl(raiz->dir, valoChave, comparar);
        }

    }

}


NoAvl* RemoverNoAvl(NoAvl* raiz, void* valoChave, int (*comparar)(void*, void*)){
    if(raiz==NULL){
        return NULL;
    }
    else{
        int comparacao = comparar(valoChave, raiz->dado);
        if(comparacao==0){
            if(raiz->esq==NULL && raiz->dir==NULL){
                free(raiz);
                return NULL;
            }
            else{
                if(raiz->esq!=NULL && raiz->dir !=NULL){
                    NoAvl* aux = raiz->esq;
                    while(aux->dir!=NULL){
                        aux = aux->dir;
                    }
                    void* temp = raiz->dado;
                    raiz->dado=aux->dado;
                    aux->dado = temp;
                    raiz->esq = RemoverNoAvl(raiz->esq, temp, comparar);
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
                    return substituto;
                }
            }
        }
        else if(comparacao<0){
            raiz->esq = RemoverNoAvl(raiz->esq, valoChave, comparar);
        }
        else{
            raiz->dir = RemoverNoAvl(raiz->dir, valoChave, comparar);
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
    raiz=RotacaoSimplesDir(raiz);
}

NoAvl* RotacaoEsqDir(NoAvl* raiz){
    raiz->dir = RotacaoSimplesDir(raiz->dir);
    raiz = RotacaoSimplesEsq(raiz);
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












