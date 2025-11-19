#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "sistema_usuario.h"



CodigoErro IniciarSistemaUsuarios(SistemaUsuario** sistema){
    if(!sistema) return ERRO_PARAMETRO_INVALIDO;

    SistemaUsuario* novoSistema = malloc(sizeof(SistemaUsuario));

    if(!novoSistema) return ERRO_MEMORIA;

    CodigoErro erro = ERRO_OK;
    novoSistema->arvoreUsuarios = IniciarAvl(&erro);

    if(!novoSistema->arvoreUsuarios){
        free(novoSistema);
        return erro;
    }

    novoSistema->tabelaPorEmail=CriarNovaHash(5, &erro);
    if(!novoSistema->tabelaPorEmail){
        LiberarAvl(novoSistema->arvoreUsuarios);
        free(novoSistema);
        return erro;
    }

    novoSistema->listaEncadeada=CriarNovaLista(&erro);
    if(!novoSistema->listaEncadeada){
        LiberarAvl(novoSistema->arvoreUsuarios);
        LiberarHash(novoSistema->tabelaPorEmail);
        free(novoSistema);
        return erro;
    }
    *sistema = novoSistema;
    return ERRO_OK;

}
CodigoErro ValidarNovoemail(Hash* tabelaHash, User* novousuario){
    CodigoErro erro=ERRO_OK;
    EntradaHash* entradaBuscada = BuscarHash(tabelaHash, novousuario->email, FuncaoDeEspalhamentoString, CompararEntradaHashChave, &erro);
    return erro;
}

int ValidarStringEmail(char* _email){
    if(strchr(_email, '@')!=NULL && strstr(_email, ".com")!=NULL){
        return 1;
    }
    else{
        return 0;
    }
}

CodigoErro InserirUsuarioEstruturas(SistemaUsuario* sistemaIniciado, User* novoUsuario){
    CodigoErro erroValidacaoEmail = ValidarNovoemail(sistemaIniciado->tabelaPorEmail, novoUsuario);
    if(erroValidacaoEmail==ERRO_OK){
        return EMAIL_JA_EXISTENTE;
    }

    if(erroValidacaoEmail==ERRO_LISTA_NO_NAO_ENCONTRADO && ValidarStringEmail(novoUsuario->email)){

        CodigoErro erroHash = ERRO_OK;

        sistemaIniciado->tabelaPorEmail = InserirHash(sistemaIniciado->tabelaPorEmail, novoUsuario->email, novoUsuario, FuncaoDeEspalhamentoString, ExibirDadosString, ImprimirUsuario, &erroHash);
        if(erroHash!=ERRO_OK){
            return erroHash;
        }


         CodigoErro erroAvl = ERRO_OK;

         sistemaIniciado->arvoreUsuarios->raiz = InserirAvl(sistemaIniciado->arvoreUsuarios, sistemaIniciado->arvoreUsuarios->raiz, novoUsuario, CompararUsuarioPorEmail, &erroAvl);
        if(erroAvl!= ERRO_OK){
            return erroAvl;
        }


    }
    return ERRO_OK;
}

CodigoErro CadastrarUsuario(SistemaUsuario* sistemaIniciado, User* novoUsuario){

    if(!sistemaIniciado){
        return ERRO_SISTEMA_NAO_INICIADO;
    }
    else{
        return InserirUsuarioEstruturas(sistemaIniciado, novoUsuario);
    }

}

User* CapturarDadosParaCadastroConsole(void* sistema){
    SistemaUsuario* sistemaIniciado = (SistemaUsuario*) sistema;
    int id = sistemaIniciado->arvoreUsuarios->quantidadeno +1;
    char nome[100];
    char sobrenome[100];
    char email[100];
    char senha[50];

    printf("Digite seu nome:\n");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite seu sobrenome:\n");
    fgets(sobrenome, sizeof(sobrenome), stdin);
    sobrenome[strcspn(sobrenome, "\n")] = '\0';

    printf("Digite seu email:\n");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Digite sua senha:\n");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0';

    return CriarUsuario(id, nome, sobrenome, email, senha);


}

void ImprimirUsuarioEntradaHash(void* dado){
    EntradaHash* entradaHash = (EntradaHash*)dado;
    ImprimirUsuario(entradaHash->valor);
}
int ConfirmarSenha(char* _senha, User* usuarioBuscado){
    return strcmp(_senha, usuarioBuscado->senha)==0;
}

CodigoErro LoginUsuario (SistemaUsuario* sistemaIniciado, char* _email, char*_senha, User** usuarioLogado){

    CodigoErro erroBusca;
    EntradaHash* entradaBuscada = BuscarHash(sistemaIniciado->tabelaPorEmail, _email, FuncaoDeEspalhamentoString, CompararUsuarioPorEmail, &erroBusca);
    if(erroBusca!=ERRO_OK){
        return ERRO_LOGIN_EMAIL_NAO_ENCONTRADO;
    }
    if(ConfirmarSenha(_senha, entradaBuscada->valor)!=0){
        return ERRO_LOGIN_SENHA_INVALIDA;
    }
    *usuarioLogado = entradaBuscada->valor;
    return ERRO_LOGIN_SUCESSO;



}


