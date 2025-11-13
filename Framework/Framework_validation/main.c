#include <stdio.h>
#include <stdlib.h>
#include "core/avl.h"

void addvalor(NoAvl* raiz, void* dado, int(*comparar)(void*, void*)){
    if(raiz==NULL){
        printf("Arvore esta vazia\n");
    }
    raiz = InserirAvl(raiz, dado, comparar);
}

int main()
{
    int comparar(void* a, void* b){
        int intA = *(int*)a;
        int intB = *(int*)b;

        if(intA<intB){
            return -1;
        }
        else{
            return 1;
        }
    }

    AVL* arvore;
    arvore->raiz = NULL;
    int x =10;
    addvalor(arvore->raiz, &x, comparar);



}
