#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sistema_usuario.h"

User* FazerLogin (SistemaUsuario** sistema){
    User* usuarioLogado=NULL;
    char EmailFazerLogin[100];
    char SenhaFazerLogin[50];

    printf("Digite seu email\n");
    fgets(EmailFazerLogin, sizeof(EmailFazerLogin), stdin);
    EmailFazerLogin[strcspn(EmailFazerLogin, "\n")] = '\0';

    printf("Digite sua senha\n");
    fgets(SenhaFazerLogin, sizeof(SenhaFazerLogin), stdin);
    SenhaFazerLogin[strcspn(SenhaFazerLogin, "\n")]='\0';

    CodigoErro statusLogin = LoginUsuario(*sistema, EmailFazerLogin, SenhaFazerLogin, &usuarioLogado);
    if(statusLogin!=ERRO_LOGIN_SUCESSO){
        printf("Erro ao realizar login: %s\n", CodigoErroParaTexto(statusLogin));

        return NULL;
    }
    else{
        printf("Login realizado com sucesso\n");
        return usuarioLogado;
    }

}

void AddCadastrosFakes(SistemaUsuario** sistema){
    User* user1 = malloc(sizeof(User));
    user1->id = 1;
    strcpy(user1->nome, "Italo");
    strcpy(user1->sobrenome, "Santos");
    strcpy(user1->email, "italo@.com");
    strcpy(user1->senha, "1131");
    user1->admin = 0;
    CodigoErro statusCadFake = CadastrarUsuario(*sistema, user1);
    printf("Cad fake: %s\n", CodigoErroParaTexto(statusCadFake));

}
void ChamarMenu(User* usuarioLogado){
    if(usuarioLogado->admin){
        printf("Chama menu admin\n");
    }
    printf("Chama menu usuario comum\n");
}

int main()
{
    SistemaUsuario* sistema;
    CodigoErro statusSistema = IniciarSistemaUsuarios(&sistema);
    AddCadastrosFakes(&sistema);

    if(statusSistema==ERRO_OK){
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
                User* usuarioLogado = FazerLogin(&sistema);
                ChamarMenu(usuarioLogado);

            }
            else if(acao==2){
                User* novoUsuario = CapturarDadosParaCadastroConsole(sistema);
                CodigoErro statusCad = CadastrarUsuario(sistema, novoUsuario);
                if(statusCad!=ERRO_OK){
                    printf("Erro ao cadastrar usuario %s\n", CodigoErroParaTexto(statusCad));
                }
                printf("Cadastro realizado com sucesso, agora faça login\n");
            }
            else if(acao==0){teucdu

                CodigoErro statusEncerrandoSistema =  EncerrarSistema(&sistema);
                if(statusEncerrandoSistema!=ERRO_OK){
                    printf("ERRO: %s\n", CodigoErroParaTexto(statusEncerrandoSistema));
                }

            }

        }
    }
    else{
        printf("Erro: %s\n", CodigoErroParaTexto(statusSistema));
    }
}
