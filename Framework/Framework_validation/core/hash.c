#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"hash.h"
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

int FuncaoDeEspalhamentoInt(int tamanhoVetor, void* chave){
    int intA = *(int*)chave;
    return intA%tamanhoVetor;

}
int FuncaoDeEspalhamentoString(int tamanhoVetor, void* chave){
    char* stringA = (char*)chave;
    int resultado = 0;
    while(*stringA!='\0'){
        resultado+=(int)(*stringA);
        stringA++;
    }
    return resultado%tamanhoVetor;


}
void ImprimirEntradaHash(void* dado){
    EntradaHash* entradaHash = (EntradaHash*)dado;

    printf("Entrada hash:\n");
    printf("Chave: "); entradaHash->ImprimirChave(entradaHash->chave);
    printf("Valor: "); entradaHash->ImprimirValor(entradaHash->valor);
    printf("\n");


}
EntradaHash* CriarNovaEntradaHash(void* chave, void* valor, void(*ExibirChave)(void*), void(*ExibirValor)(void* )){
    EntradaHash* novaEntradaHash = malloc (sizeof(EntradaHash));
    novaEntradaHash->chave = chave;
    novaEntradaHash->valor = valor;
    novaEntradaHash->ImprimirChave=ExibirChave;
    novaEntradaHash->ImprimirValor=ExibirValor;
    return novaEntradaHash;
}

void InserirHash(Hash* tabelHash, void* chave, void* valor, int(*FuncaoDeEspalhamento)(int,void*), void(*ExibirChave)(void*), void(*ExibirValor)(void*)){

    int posicao = FuncaoDeEspalhamento (tabelHash->tamanhoVetorHash, chave);
    EntradaHash* novaEntradaHash = CriarNovaEntradaHash(chave, valor, ExibirChave, ExibirValor);

    InserirLista(tabelHash->hashVetor[posicao], novaEntradaHash);

}

void ImprimirHash(Hash* tabelaHash, void(*Imprimir)(void*)){

    for(int i=0; i<tabelaHash->tamanhoVetorHash;i++){
        if(tabelaHash->hashVetor[i]->cabeca->prox!=NULL){
            printf("Posicao no vetor: %i\n", i);
            ImprimirLista(tabelaHash->hashVetor[i], Imprimir);
        }
    }
}

void* RetornarEntradaHash(void* entradaHash){
    EntradaHash* entradaHashBuscada = (EntradaHash*)entradaHash;
    return entradaHashBuscada;
}
int CompararEntradaHashChave(void* _chave, void* _entradaHash){
    EntradaHash* entradaHash = (EntradaHash*)_entradaHash;
    return CompararString(_chave, entradaHash->chave);
}

void BuscarHash(Hash* tabelaHash, void* chave, int(*FuncaoDeEspalhamento)(int,void*), int(*Comparar)(void*,void*) ){
    int posicao = FuncaoDeEspalhamento(tabelaHash->tamanhoVetorHash, chave);
    EntradaHash* entradaBuscada=BuscarLista(tabelaHash->hashVetor[posicao], chave, CompararEntradaHashChave, RetornarEntradaHash);

    if(entradaBuscada){
        printf("Entrada encontrada---------------------------------------\n");
        ImprimirEntradaHash(entradaBuscada);
    }
}







