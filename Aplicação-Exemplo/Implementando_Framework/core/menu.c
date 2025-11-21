#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"menu.h"

void MenuPrincipal(SistemaUsuario* sistema){
    int loop=1;
    printf("Bem vindo ao Framework de validacao de login\n");
    while (loop){
        printf("-----------------------------------------------------------------------------\n");
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



void  ChamarMenu(SistemaUsuario* sistema, User* usuarioLogado){
    if(usuarioLogado->admin==1){
        MenuUsuarioAdmin(sistema, usuarioLogado);
    }
    else{
        MenuUsuarioComum(sistema, usuarioLogado);
    }
}

void MenuUsuarioAdmin(SistemaUsuario* sistema, User* usuarioLogado){
    int loop =1;
    while(loop){
        printf("-----------------------------------------------------------------------------\n");
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


void MenuUsuarioComum(SistemaUsuario* sistema, User* usuarioLogado){
    int loop =1;
    while(loop){
        printf("-----------------------------------------------------------------------------\n");
        printf("Digite o que deseja fazer\n");
        printf("1 - Ver meus dados\n");
        printf("2 - Editar meus dados\n");
        printf("3 - Apagar minha conta\n");
        printf("0 - Sair\n");

        int acao;
        scanf("%i", &acao);
        getchar();

        if(acao==1){
            VerMeusDados(usuarioLogado);
        }
        else if(acao==2){
            EditarMeusDados(usuarioLogado, sistema);
        }
        else if(acao==3){
            DeletarMinhaConta(sistema, usuarioLogado);
            printf("Saindo\n");
            loop=0;
        }
        else if(acao==0){
            printf("Saindo\n");
            loop=0;
        }

    }
}



