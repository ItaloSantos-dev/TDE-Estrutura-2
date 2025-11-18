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
    NovaHash->quantidadeEntradaHash=0;
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

Hash* InserirHash(Hash* tabelHash, void* chave, void* valor, int(*FuncaoDeEspalhamento)(int,void*), void(*ExibirChave)(void*), void(*ExibirValor)(void*)){

    int posicao = FuncaoDeEspalhamento (tabelHash->tamanhoVetorHash, chave);
    EntradaHash* novaEntradaHash = CriarNovaEntradaHash(chave, valor, ExibirChave, ExibirValor);
    InserirLista(tabelHash->hashVetor[posicao], novaEntradaHash);
    tabelHash->quantidadeEntradaHash++;
    return RealocarMemoria(tabelHash);


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

EntradaHash* BuscarHash(Hash* tabelaHash, void* chave, int(*FuncaoDeEspalhamento)(int,void*), int(*Comparar)(void*,void*) ){
    int posicao = FuncaoDeEspalhamento(tabelaHash->tamanhoVetorHash, chave);
    EntradaHash* entradaBuscada=BuscarLista(tabelaHash->hashVetor[posicao], chave, CompararEntradaHashChave, RetornarEntradaHash);

    if(entradaBuscada){
        return entradaBuscada;
    }
    else {
        return NULL;
    }
}

double FatorDeCarga(Hash* tabelaHash){
    return (double) tabelaHash->quantidadeEntradaHash / tabelaHash->tamanhoVetorHash;
}
Hash* CopiarTabelaHash(Hash* hashAntiga, Hash* hashNova){
    for(int i =0; i<hashAntiga->tamanhoVetorHash; i++){
        if(hashAntiga->hashVetor[i]->cabeca->prox!=NULL){
            NoLista* atual = hashAntiga->hashVetor[i]->cabeca->prox;
            while(atual!=NULL){
                EntradaHash* entradaHashAtual = (EntradaHash*) atual->dado;
                InserirHash(hashNova, entradaHashAtual->chave, entradaHashAtual->valor, FuncaoDeEspalhamentoString, entradaHashAtual->ImprimirChave, entradaHashAtual->ImprimirValor);
                atual = atual->prox;
            }
        }
    }
    return hashNova;
}

Hash* RealocarMemoria(Hash* tabelaHash){
    double FC = FatorDeCarga(tabelaHash);
    printf("FC: %f\n", FC);
    if(FC>0.6){
        Hash* novaTabelaHash = CriarNovaHash(tabelaHash->tamanhoVetorHash*2);
        novaTabelaHash = CopiarTabelaHash(tabelaHash, novaTabelaHash);
        return novaTabelaHash;
    }
    else{
        return tabelaHash;
    }
}

void RemoverHash(Hash* tabelaHash, void* chave, int(*FuncaoDeEspalhamento)(int, void*),int(*Comparar)(void*,void*)){
    EntradaHash* entradaBuscada = BuscarHash(tabelaHash, chave, FuncaoDeEspalhamento,Comparar);
    int FE = FuncaoDeEspalhamento(tabelaHash->tamanhoVetorHash, chave);
    if(entradaBuscada){
        RemoverLista(tabelaHash->hashVetor[FE], entradaBuscada, CompararEntradaHashChave );
        tabelaHash->quantidadeEntradaHash--;
    }
}







