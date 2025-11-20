#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"menu.h"

void MenuPrincipal(SistemaUsuario* sistema){
    int loop=1;
    while (loop){
        printf("Bem vindo ao Framework de validacao de login\n");
        printf("Digite o que deseja fazer\n");
        printf("1 - Fazer login\n");
        printf("2 - Cadastrar-se\n");
        printf("0 - Sair\n");

        int acao;
        scanf("%i", &acao);
        getchar();

        if(acao==1){
            FazerLogin(&sistema);
        }
        else if(acao==2){
            Cadastrarse(sistema);
        }
        else if(acao==0){
            printf("Saindo\n");
            CodigoErro statusEncerrarSistema = EncerrarSistema(&sistema);
            if(statusEncerrarSistema==ERRO_OK){
                printf("Memoria do sistema liberada com sucesso\n");
                loop=0;
            }
            else{
                printf("Erro ao liberar memoria: %s\n", CodigoErroParaTexto(statusEncerrarSistema));
            }
        }
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

void  ChamarMenu(SistemaUsuario* sistema, User* usuarioLogado){
    if(usuarioLogado->admin==1){
        MenuUsuarioAdmin(sistema, usuarioLogado);
    }
    else{
        printf("Comum\n");
    }
}

void MenuUsuarioAdmin(SistemaUsuario* sistema, User* usuarioLogado){
    int loop =1;
    while(loop){
        printf("Digite o que deseja fazer\n");
        printf("1 - Listar usuarios\n");
        printf("2 - Criar novo usuario\n");
        printf("3 - Editar dados de um usuario\n");
        printf("4 - Deletar um usuario\n");
        printf("0 - Sair\n");

        int acao;
        scanf("%i", &acao);
        getchar();

        if(acao==1){
            ExibirDadosUsuarios(sistema);
        }
        else if(acao==2){
            CriarNovoUsuario(sistema);
        }
        else if(acao==3){
            EditarUsuario(sistema);
        }
        else if(acao==4){
            ApagarUsuario(sistema);
        }
        else if(acao==0){
            printf("Saindo\n");
            loop=0;
        }

    }
}

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
        printf("Erro ao deletar usuario: %s\n", CodigoErroParaTexto(statusCadastro));
    }
    else{
        printf("Usuario deletado com sucesso\n");
    }
}
