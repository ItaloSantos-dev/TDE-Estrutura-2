#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include "listaEncadeada.h"

typedef struct h{
    Lista** hashVetor;
    int tamanhoVetorHash;

}Hash;

typedef struct entradahash{
    void* chave;
    void* valor;
    void(*ImprimirChave)(void*);
    void(*ImprimirValor)(void*);
}EntradaHash;

Hash* CriarNovaHash(int tamanho);
EntradaHash* CriarNovaEntradaHash(void* chave, void* valor, void(*ExibirChave)(void*), void(*ExibirValor)(void* ));
void ImprimirEntradaHash(void* dado);

int FuncaoDeEspalhamentoInt(int tamanhoVetor, void* chave);
int FuncaoDeEspalhamentoString(int tamanhoVetor, void* chave);

void InserirHash(Hash* tabelHash, void* chave, void* valor, int(*FuncaoDeEspalhamento)(int,void*), void(*ExibirChave)(void*), void(*ExibirValor)(void*));
void ImprimirHash(Hash* tabelaHash, void(*Imprimir)(void*));
EntradaHash* BuscarHash(Hash* tabelaHash, void* chave, int(*FuncaoDeEspalhamento)(int,void*), int(*Comparar)(void*,void*) );
int CompararEntradaHashChave(void* _chave, void* _entradaHash);
void* RetornarEntradaHash(void* entradaHash);

#endif // HASH_H_INCLUDED
