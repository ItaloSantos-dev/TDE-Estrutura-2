#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core/avl.h"
#include "core/util.h"
#include "core/hash.h"






int main(){
    Hash* TabelaHash= CriarNovaHash(17);
    if(TabelaHash){
        printf("Tabela iniciada com sucesso\n");
        char c1[]="Italo@.com";
        char v1[]= "1131";

        char c2[]= "Clarice@.com";
        char v2[]= "abacaxi02";

        char c3[]= "Mateus@.com";
        char v3[]= "AdoroUno";

        InserirHash(TabelaHash, c1, v1, FuncaoDeEspalhamentoString, ExibirDadosString, ExibirDadosString);
        InserirHash(TabelaHash, c2, v2, FuncaoDeEspalhamentoString, ExibirDadosString, ExibirDadosString);
        InserirHash(TabelaHash, c3, v3, FuncaoDeEspalhamentoString, ExibirDadosString, ExibirDadosString);


        ImprimirHash(TabelaHash, ImprimirEntradaHash);
        BuscarHash(TabelaHash, c1, FuncaoDeEspalhamentoString, CompararEntradaHashChave);

    }










}
