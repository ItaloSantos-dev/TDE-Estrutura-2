#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core/sistema_usuario.h"
#include "core/admin.h"

void AddUsuarios(SistemaUsuario* sistema){
    CodigoErro erroCad;
    User* user1 = malloc(sizeof(User));
    user1->id = 1;
    strcpy(user1->nome, "Italo");
    strcpy(user1->sobrenome, "Santos");
    strcpy(user1->email, "italo@.com");
    strcpy(user1->senha, "1131");
    erroCad = CadastrarUsuario(sistema, user1);
    if(erroCad!=ERRO_OK){
        printf("ERRO ao cadastrar ususario %s\n", CodigoErroParaTexto(erroCad));
    }
    else{
        printf("Sucesso no cadastro\n");
    }

    User* user2 = malloc(sizeof(User));
    user2->id = 2;
    strcpy(user2->nome, "Clarice");
    strcpy(user2->sobrenome, "Freire");
    strcpy(user2->email, "clarice@.com");
    strcpy(user2->senha, "1131");
    erroCad = CadastrarUsuario(sistema,user2);
    if(erroCad!=ERRO_OK){
        printf("ERRO ao cadastrar ususario %s\n", CodigoErroParaTexto(erroCad));
    }
    else{
        printf("Sucesso no cadastro\n");
    }

    DeletarUsuario(sistema, user1->email);
}


int main(){
    CodigoErro statusIniciasSistema;
    SistemaUsuario* sistemaIniciado;
    statusIniciasSistema= IniciarSistemaUsuarios(&sistemaIniciado);
    AddUsuarios(sistemaIniciado);







}
