#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED

typedef struct h{
    void** hashVetor;
    int tamanhoVetorHash;

}Hash;

Hash* CriarNovaHash(int tamanho);
#endif // HASH_H_INCLUDED
