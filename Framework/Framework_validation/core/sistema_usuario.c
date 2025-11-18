#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "sistema_usuario.h"



SistemaUsuario* IniciarSistemaUsuarios(){
    SistemaUsuario* novoSistemaUsuarios = malloc(sizeof(SistemaUsuario));
    novoSistemaUsuarios->arvoreUsuarios = IniciarAvl();
    novoSistemaUsuarios->tabelaPorEmail = CriarNovaHash(2);
    novoSistemaUsuarios->listaEncadeada = CriarNovaLista();
    return novoSistemaUsuarios;

}
int ValidarNovoemail(Hash* tabelaHash, User* novousuario){
    EntradaHash* entradaBuscada = BuscarHash(tabelaHash, novousuario->email, FuncaoDeEspalhamentoString, CompararEntradaHashChave);
    if(entradaBuscada){
        //Se achou retorna 0 para parar o cadastro
        return 0;
    }
    else{
        return 1;
    }
}

int ValidarStringEmail(char* _email){
    if(strchr(_email, '@')!=NULL && strstr(_email, ".com")!=NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int InserirUsuarioEstruturas(SistemaUsuario* sistemaIniciado, User* novoUsuario){
    if(ValidarNovoemail(sistemaIniciado->tabelaPorEmail, novoUsuario) && ValidarStringEmail(novoUsuario->email)){
        sistemaIniciado->arvoreUsuarios->raiz = InserirAvl(sistemaIniciado->arvoreUsuarios, sistemaIniciado->arvoreUsuarios->raiz, novoUsuario, CompararUsuarioPorEmail);
        sistemaIniciado->tabelaPorEmail = InserirHash(sistemaIniciado->tabelaPorEmail, novoUsuario->email, novoUsuario, FuncaoDeEspalhamentoString, ExibirDadosString, ImprimirUsuario);
        return 1;
    }
    else{
        return 0;
    }

}

int CadastrarUsuario(SistemaUsuario* sistemaIniciado, User* novoUsuario){
    if(!sistemaIniciado){
        return 0;
    }
    else{
        if(InserirUsuarioEstruturas(sistemaIniciado, novoUsuario)){
            return 1;
        }
        else{
            return 0;
        }
    }

}

User* CapturarDadosParaCadastro(SistemaUsuario* sistemaIniciado){
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

User* LoginUsuario (SistemaUsuario* sistemaIniciado, char* _email, char*_senha){
    EntradaHash* entradaBuscada = BuscarHash(sistemaIniciado->tabelaPorEmail, _email, FuncaoDeEspalhamentoString, CompararUsuarioPorEmail );
    if(entradaBuscada && ConfirmarSenha(_senha, entradaBuscada->valor)){
        return entradaBuscada->valor;
    }
    else{
        return NULL;
    }

}


