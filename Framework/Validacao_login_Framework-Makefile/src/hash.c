#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"hash.h"
#include"util.h"
#include "listaEncadeada.h"

Hash* CriarNovaHash(int tamanho,CodigoErro* erro){
    Hash* NovaHash = malloc(sizeof(Hash));
    NovaHash->tamanhoVetorHash = tamanho;
    NovaHash->hashVetor = malloc(tamanho*sizeof(Lista*));
    NovaHash->quantidadeEntradaHash=0;
    for(int i=0; i<tamanho; i++){
        NovaHash->hashVetor[i]=CriarNovaLista(erro);
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

EntradaHash* CriarNovaEntradaHash(void* chave, void* valor, void(*ExibirChave)(void*), void(*ExibirValor)(void* ),CodigoErro* erro){
    EntradaHash* novaEntradaHash = malloc (sizeof(EntradaHash));
    if(!novaEntradaHash){
        if(erro)*erro = ERRO_HASH_MEMORIA;
        return NULL;

    }
    novaEntradaHash->chave = chave;
    novaEntradaHash->valor = valor;
    novaEntradaHash->ImprimirChave=ExibirChave;
    novaEntradaHash->ImprimirValor=ExibirValor;
    if(erro)*erro = ERRO_OK;
    return novaEntradaHash;
}

Hash* InserirHash(Hash* tabelHash, void* chave, void* valor, int(*FuncaoDeEspalhamento)(int,void*), void(*ExibirChave)(void*), void(*ExibirValor)(void*), CodigoErro* erro){

    int posicao = FuncaoDeEspalhamento (tabelHash->tamanhoVetorHash, chave);
    EntradaHash* novaEntradaHash = CriarNovaEntradaHash(chave, valor, ExibirChave, ExibirValor, erro);
    InserirLista(tabelHash->hashVetor[posicao], novaEntradaHash, erro);
    tabelHash->quantidadeEntradaHash++;
    return RealocarMemoria(tabelHash, erro);


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

EntradaHash* BuscarHash(Hash* tabelaHash, void* chave, int(*FuncaoDeEspalhamento)(int,void*), int(*Comparar)(void*,void*), CodigoErro* erro ){
    int posicao = FuncaoDeEspalhamento(tabelaHash->tamanhoVetorHash, chave);

    EntradaHash* entradaBuscada=BuscarLista(tabelaHash->hashVetor[posicao], chave, CompararEntradaHashChave, RetornarEntradaHash, erro);

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
Hash* CopiarTabelaHash(Hash* hashAntiga, Hash* hashNova, CodigoErro* erro){
    for(int i =0; i<hashAntiga->tamanhoVetorHash; i++){
        if(hashAntiga->hashVetor[i]->cabeca->prox!=NULL){
            NoLista* atual = hashAntiga->hashVetor[i]->cabeca->prox;
            while(atual!=NULL){
                EntradaHash* entradaHashAtual = (EntradaHash*) atual->dado;
                InserirHash(hashNova, entradaHashAtual->chave, entradaHashAtual->valor, FuncaoDeEspalhamentoString, entradaHashAtual->ImprimirChave, entradaHashAtual->ImprimirValor, erro);
                atual = atual->prox;
            }
        }
    }
    return hashNova;
}

Hash* RealocarMemoria(Hash* tabelaHash, CodigoErro* erro){
    double FC = FatorDeCarga(tabelaHash);
    if(FC>0.6){
        Hash* novaTabelaHash = CriarNovaHash(tabelaHash->tamanhoVetorHash*2, erro);
        novaTabelaHash = CopiarTabelaHash(tabelaHash, novaTabelaHash, erro);
        return novaTabelaHash;
    }
    else{
        return tabelaHash;
    }
}

void RemoverHash(Hash* tabelaHash, void* chave, int(*FuncaoDeEspalhamento)(int, void*),int(*Comparar)(void*,void*), CodigoErro* erro){

    EntradaHash* entradaBuscada = BuscarHash(tabelaHash, chave, FuncaoDeEspalhamento,Comparar, erro);

    int FE = FuncaoDeEspalhamento(tabelaHash->tamanhoVetorHash, chave);
    if(entradaBuscada){
        RemoverLista(tabelaHash->hashVetor[FE], chave, CompararEntradaHashChave, erro );
        tabelaHash->quantidadeEntradaHash--;
    }
}

Hash* LiberarHash(Hash* tabelaHash){
    if(tabelaHash==NULL) return NULL;

    for(int i=0; i<tabelaHash->tamanhoVetorHash; i++){
        tabelaHash->hashVetor[i]=LiberarLista(tabelaHash->hashVetor[i]);
    }
    free(tabelaHash);
    return NULL;

}

void ImprimirEntradaHash(void* dado){
    EntradaHash* entrada = (EntradaHash*)dado;
    entrada->ImprimirChave(entrada->chave);
    entrada->ImprimirValor(entrada->valor);
}







