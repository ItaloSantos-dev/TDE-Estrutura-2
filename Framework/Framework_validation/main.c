#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core/sistema_usuario.h"

void AddUsuarios(SistemaUsuario* sistema){
    User* user1 = malloc(sizeof(User));
    user1->id = 1;
    strcpy(user1->nome, "Italo");
    strcpy(user1->sobrenome, "Santos");
    strcpy(user1->email, "italo@.com");
    strcpy(user1->senha, "1131");
    InserirUsuarioEstruturas(sistema,user1);

    User* user2 = malloc(sizeof(User));
    user2->id = 1;
    strcpy(user2->nome, "Clarice");
    strcpy(user2->sobrenome, "Freire");
    strcpy(user2->email, "clarice@.com");
    strcpy(user2->senha, "1131");
    InserirUsuarioEstruturas(sistema,user2);
}


int main(){
    SistemaUsuario* sistemaUsuarios = IniciarSistemaUsuarios();
    printf("Tamanho do hashvetor: %i\n", sistemaUsuarios->tabelaPorEmail->tamanhoVetorHash);
    printf("Quantidade de elementos: %i\n", sistemaUsuarios->tabelaPorEmail->quantidadeEntradaHash);
    printf("Fator de carga: %i\n", FatorDeCarga(sistemaUsuarios->tabelaPorEmail));
    AddUsuarios(sistemaUsuarios);
    printf("Tamanho do hashvetor: %i\n", sistemaUsuarios->tabelaPorEmail->tamanhoVetorHash);
    printf("Quantidade de elementos: %i\n", sistemaUsuarios->tabelaPorEmail->quantidadeEntradaHash);
    printf("Fator de carga: %f\n", FatorDeCarga(sistemaUsuarios->tabelaPorEmail));




}
