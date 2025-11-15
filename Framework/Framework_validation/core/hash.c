#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"util.h"
#include "listaEncadeada.h"

Hash* CriarNovaHash(int tamanho){
    Hash* NovaHash = malloc(sizeof(Hash));
    NovaHash->tamanhoVetorHash = tamanho;
    NovaHash->hashVetor = malloc(tamanho*sizeof(Lista*));
    for(int i=0; i<tamanho; i++){
        NovaHash->hashVetor[i]=CriarNovaLista();
    }
    return NovaHash;


}






