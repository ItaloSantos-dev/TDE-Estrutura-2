#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "funcoes_admin.h"

void ExibirDadosUsuarios (SistemaUsuario* sistema){
    printf("Lista de usuarios cadastrados\n");
    ListarUsuarios(sistema, ImprimirUsuario );
}

void CriarNovoUsuario(SistemaUsuario* sistema){

    char nome[100];
    char sobrenome[100];
    char email[100];
    char senha[50];

    printf("Digite o nome do novo usuario: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite o sobrenome do novo usuario: ");
    fgets(sobrenome, sizeof(sobrenome), stdin);
    sobrenome[strcspn(sobrenome, "\n")] = '\0';

    printf("Digite o email do novo usuario: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Digite a senha do novo usuario: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0';

    User* novoUsuario = CriarUsuario(sistema->arvoreUsuarios->quantidadeno+1, nome, sobrenome, email, senha);

    CodigoErro statusCriarNovoUsuario = CadastrarUsuario(sistema, novoUsuario);


    if(statusCriarNovoUsuario!=ERRO_OK){
        printf("Erro ao cadastrar usuario: %s\n", CodigoErroParaTexto(statusCriarNovoUsuario));
    }
    else{
        printf("Novo usuario criado com sucesso\n");
    }
}

void EditarUsuario(SistemaUsuario* sistema){
    ExibirDadosUsuarios(sistema);
    printf("Digite o email do usuario que voce deseja editar os dados\n");
    char emailBuscado[100];

    fgets(emailBuscado, sizeof(emailBuscado), stdin);
    emailBuscado[strcspn(emailBuscado, "\n")] = '\0';

    User* usuarioBuscado = BuscarUsuario(sistema, emailBuscado);

    if(usuarioBuscado){
        EditardadosAdminUsuario(usuarioBuscado);
    }
    else{
        printf("Nao achou");
    }
}


void EditardadosAdminUsuario(User* usuarioBuscado){
    int novoId;
    int novoTipo;

    char novoNome[100];
    char novoSobrenome[100];
    char novaSenha[100];

    // ----- ID -----
    printf("Digite o novo ID do usuario: ");
    scanf("%d", &novoId);
    getchar(); // limpa \n

    // ----- TIPO -----
    printf("Digite o novo tipo do usuario (1=admin, 0=comum): ");
    scanf("%d", &novoTipo);
    getchar(); // limpa \n

    // ----- NOME -----
    printf("Digite o novo nome do usuario: ");
    fgets(novoNome, sizeof(novoNome), stdin);
    novoNome[strcspn(novoNome, "\n")] = '\0';

    // ----- SOBRENOME -----
    printf("Digite o novo sobrenome do usuario: ");
    fgets(novoSobrenome, sizeof(novoSobrenome), stdin);
    novoSobrenome[strcspn(novoSobrenome, "\n")] = '\0';

    // ----- SENHA -----
    printf("Digite a nova senha do usuario: ");
    fgets(novaSenha, sizeof(novaSenha), stdin);
    novaSenha[strcspn(novaSenha, "\n")] = '\0';


    CodigoErro statusEditarUsuario = AdminEditarUsuario(usuarioBuscado, novoId, novoTipo, novoNome, novoSobrenome, novaSenha);

    if(statusEditarUsuario!=ERRO_OK){
        printf("Erro ao editar usuario: %s\n", CodigoErroParaTexto(statusEditarUsuario));
    }
    else{
        printf("Dados do usuario editado com sucesso com sucesso\n");
    }

}


void ApagarUsuario(SistemaUsuario* sistema){
    ExibirDadosUsuarios(sistema);
    printf("Digite o email do usuario que voce deseja deletar\n");
    char email[100];

    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    CodigoErro statusDeletarUsuario = DeletarUsuario(sistema, email);

    if(statusDeletarUsuario!=ERRO_OK){
        printf("Erro ao deletar usuario: %s\n", CodigoErroParaTexto(statusDeletarUsuario));
    }
    else{
        printf("Usuario deletado com sucesso\n");
    }
}
