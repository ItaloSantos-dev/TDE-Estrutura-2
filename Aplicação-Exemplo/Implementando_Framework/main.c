#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sistema_usuario.h"
#include "admin.h"
#include "core/menu.h"


void AddCadastrosFakes(SistemaUsuario** sistema){
    User* user1 = malloc(sizeof(User));
    user1->id = (*sistema)->arvoreUsuarios->quantidadeno+1;
    strcpy(user1->nome, "Italo");
    strcpy(user1->sobrenome, "Santos");
    strcpy(user1->email, "italo@.com");
    strcpy(user1->senha, "1131");
    user1->admin = 0;
    CodigoErro statusCadFake = CadastrarUsuario(*sistema, user1);
    printf("Cad fake: %s\n", CodigoErroParaTexto(statusCadFake));

    User* user2 = malloc(sizeof(User));
    user2->id = (*sistema)->arvoreUsuarios->quantidadeno+1;
    strcpy(user2->nome, "Clarice");
    strcpy(user2->sobrenome, "freire");
    strcpy(user2->email, "clarice@.com");
    strcpy(user2->senha, "1131");
    user2->admin = 0;
     statusCadFake = CadastrarUsuario(*sistema, user2);
    printf("Cad fake: %s\n", CodigoErroParaTexto(statusCadFake));


}



int main()
{
    SistemaUsuario* sistema;
    CodigoErro statusSistema = IniciarSistemaUsuarios(&sistema);
    AddCadastrosFakes(&sistema);


    if(statusSistema==ERRO_OK){
        MenuPrincipal(sistema);
    }
    else{
        printf("Erro: %s\n", CodigoErroParaTexto(statusSistema));
    }
}
