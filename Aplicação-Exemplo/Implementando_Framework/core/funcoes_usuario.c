#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "funcoes_usuario.h"

void Cadastrarse (SistemaUsuario* sistema){
    char nome[100];
    char sobrenome[100];
    char email[100];
    char senha[50];

    printf("Digite seu nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite seu sobrenome: ");
    fgets(sobrenome, sizeof(sobrenome), stdin);
    sobrenome[strcspn(sobrenome, "\n")] = '\0';

    printf("Digite seu email: ");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Digite sua senha: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0';

    User* novoUsuario = CriarUsuario(sistema->arvoreUsuarios->quantidadeno+1, nome, sobrenome, email, senha);


    CodigoErro statusCadastro = CadastrarUsuario(sistema, novoUsuario);

    if(statusCadastro!=ERRO_OK){
        printf("Erro ao cadastrar usuario: %s\n", CodigoErroParaTexto(statusCadastro));
    }
    else{
        printf("Usuario cadastrado com sucesso, faça login\n");
    }
}


void FazerLogin(SistemaUsuario** sistema){
    char EmailFazerLogin[100];
    char SenhaFazerLogin[100];

    printf("Digite seu email: ");
    fgets(EmailFazerLogin, sizeof(EmailFazerLogin), stdin);
    EmailFazerLogin[strcspn(EmailFazerLogin, "\n")] = '\0';

    printf("Digite sua senha: ");
    fgets(SenhaFazerLogin, sizeof(SenhaFazerLogin), stdin);
    SenhaFazerLogin[strcspn(SenhaFazerLogin, "\n")] = '\0';

    User* usuarioLogado;

    CodigoErro statusLogin = LoginUsuario(*sistema, EmailFazerLogin, SenhaFazerLogin, &usuarioLogado);

    if(statusLogin==ERRO_LOGIN_SUCESSO){
        printf("Login bem sucedido\n");
        ChamarMenu(*sistema, usuarioLogado);
    }
    else{
        printf("Erro ao fazer login: %s\n", CodigoErroParaTexto(statusLogin));
    }
}

void EditarMeusDados(User* usuarioLogado, SistemaUsuario* sistema){

    char novoNome[100];
    char NovoSobrenome[100];
    char NovaSenha[100];

    printf("Digite seu novo nome: ");
    fgets(novoNome, sizeof(novoNome), stdin);
    novoNome[strcspn(novoNome, "\n")] = '\0';

    printf("Digite seu novo sobrenome: ");
    fgets(NovoSobrenome, sizeof(NovoSobrenome), stdin);
    NovoSobrenome[strcspn(NovoSobrenome, "\n")] = '\0';

    printf("Digite sua nova senha: ");
    fgets(NovaSenha, sizeof(NovaSenha), stdin);
    NovaSenha[strcspn(NovaSenha, "\n")] = '\0';

    EditarDadosUsuario(usuarioLogado, novoNome, NovoSobrenome, NovaSenha);
    printf("Dados alterado com sucesso\n");
}

void VerMeusDados(User* usuarioLogado){
    printf("Seus dados\n");
    ImprimirUsuario(usuarioLogado);
}

void DeletarMinhaConta(SistemaUsuario* sistema, User* usuarioLogado){
    CodigoErro statusDeletarConta = UsuarioDeletarConta(sistema, usuarioLogado);

    if(statusDeletarConta!=ERRO_OK){
        printf("Erro ao deletar conta: %s\n", CodigoErroParaTexto(statusDeletarConta));
    }
    else{
        printf("Conta deletada com sucesso\n");
    }
}
