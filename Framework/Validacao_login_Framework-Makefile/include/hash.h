#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include "listaEncadeada.h"
#include "erros.h"

typedef struct h{
    Lista** hashVetor;
    int tamanhoVetorHash;
    int quantidadeEntradaHash;

}Hash;

typedef struct entradahash{
    void* chave;
    void* valor;
    void(*ImprimirChave)(void*);
    void(*ImprimirValor)(void*);
}EntradaHash;

Hash* CriarNovaHash(int tamanho,CodigoErro* erro);

EntradaHash* CriarNovaEntradaHash(void* chave, void* valor, void(*ExibirChave)(void*), void(*ExibirValor)(void* ),CodigoErro* erro);

void ImprimirEntradaHash(void* dado);

int FuncaoDeEspalhamentoInt(int tamanhoVetor, void* chave);
int FuncaoDeEspalhamentoString(int tamanhoVetor, void* chave);

Hash* InserirHash(Hash* tabelHash, void* chave, void* valor, int(*FuncaoDeEspalhamento)(int,void*), void(*ExibirChave)(void*), void(*ExibirValor)(void*),CodigoErro* erro);

void ImprimirHash(Hash* tabelaHash, void(*Imprimir)(void*));

EntradaHash* BuscarHash(Hash* tabelaHash, void* chave, int(*FuncaoDeEspalhamento)(int,void*), int(*Comparar)(void*,void*),CodigoErro* erro );

int CompararEntradaHashChave(void* _chave, void* _entradaHash);
void* RetornarEntradaHash(void* entradaHash);

Hash* RealocarMemoria(Hash* tabelaHash,CodigoErro* erro);

Hash* CopiarTabelaHash(Hash* hashAntiga, Hash* hashNova,CodigoErro* erro);

double FatorDeCarga(Hash* tabelaHash);

void RemoverHash(Hash* tabelaHash, void* chave, int(*FuncaoDeEspalhamento)(int, void*),int(*Comparar)(void*,void*),CodigoErro* erro);
void LiberarHash(Hash* tabelaHash);

#endif // HASH_H_INCLUDED
