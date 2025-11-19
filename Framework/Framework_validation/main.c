#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core/sistema_usuario.h"
#include "core/admin.h"

void AddUsuarios(SistemaUsuario* sistema){
    CodigoErro erroCad;
    User* user1 = malloc(sizeof(User));
    user1->id = 1;
    strcpy(user1->nome, "italo");
    strcpy(user1->sobrenome, "Santos");
    strcpy(user1->email, "Italo@.com");
    strcpy(user1->senha, "1131");
    erroCad = CadastrarUsuario(sistema, user1);
    printf("STATUS cad1: %s\n", CodigoErroParaTexto(erroCad));

    User* user2 = malloc(sizeof(User));
    user2->id = 2;
    strcpy(user2->nome, "Clarice");
    strcpy(user2->sobrenome, "Freire");
    strcpy(user2->email, "clarice@.com");
    strcpy(user2->senha, "1131");
    erroCad = CadastrarUsuario(sistema,user2);
    printf("STATUS cad2: %s\n", CodigoErroParaTexto(erroCad));

    User* user3 = malloc(sizeof(User));
    user3->id = 3;
    strcpy(user3->nome, "Clarice");
    strcpy(user3->sobrenome, "Freire");
    strcpy(user3->email, "clarice@.com");
    strcpy(user3->senha, "1131");
    erroCad = CadastrarUsuario(sistema,user3);
    printf("STATUS cad3: %s\n", CodigoErroParaTexto(erroCad));



    char emailfalso[] = "Clelton@.com";
    User* usuarioLogado;
    CodigoErro erroLogin = LoginUsuario(sistema, emailfalso, user1->senha, &usuarioLogado);
    printf("STATUS Login: %s\n", CodigoErroParaTexto(erroLogin));
    printf("Bem vindo: %s\n", usuarioLogado->nome);

    printf("AVL-------------------------\n");
    ImprimirAvl(sistema->arvoreUsuarios->raiz, ImprimirUsuario );
    printf("\n");
    printf("Hash-------------------------\n");
    ImprimirHash(sistema->tabelaPorEmail, ImprimirEntradaHash);
    printf("\n");
    printf("Lista-------------------------\n");
    ImprimirLista(sistema->tabelaPorEmail->hashVetor[4], ImprimirEntradaHash );

}


int main(){
    CodigoErro statusIniciasSistema;
    SistemaUsuario* sistemaIniciado;
    statusIniciasSistema= IniciarSistemaUsuarios(&sistemaIniciado);
    AddUsuarios(sistemaIniciado);

}
