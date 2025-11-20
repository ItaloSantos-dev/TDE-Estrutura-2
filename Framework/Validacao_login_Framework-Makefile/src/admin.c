#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "admin.h"

int CompararUsuarioPorEmailAvl(void* dado, void* _u2){
    char* _email = (char*)dado;
    User* u2 = (User*)_u2;

    return strcmp(_email, u2->email);
}

void ListarUsuarios (SistemaUsuario* sistemaIniciado, void(*ExibirDados)(void* dado)){
    ImprimirAvl(sistemaIniciado->arvoreUsuarios->raiz, ExibirDados);
}

CodigoErro AdminCriarUsuario(SistemaUsuario* sistemaIniciado, User* novoUsuario){
    CodigoErro erroEmail =ERRO_OK;
    erroEmail = ValidarNovoemail(sistemaIniciado->tabelaPorEmail, novoUsuario);
    if(erroEmail==ERRO_OK){
        return EMAIL_JA_EXISTENTE;
    }
    if(ValidarStringEmail(novoUsuario->email)==0){
        return ERRO_EMAIL_INVALIDO;
    }

    return CadastrarUsuario(sistemaIniciado, novoUsuario);
}

CodigoErro DeletarUsuario(SistemaUsuario* sistemaIniciado, char* _email){

    CodigoErro erroHash= ERRO_OK;
    RemoverHash(sistemaIniciado->tabelaPorEmail, _email, FuncaoDeEspalhamentoString, CompararEntradaHashChave, &erroHash);

    if(erroHash!=ERRO_OK){
        return erroHash;
    }

    CodigoErro erroAvl= ERRO_OK;
    sistemaIniciado->arvoreUsuarios->raiz = RemoverNoAvl(sistemaIniciado->arvoreUsuarios, sistemaIniciado->arvoreUsuarios->raiz, _email, CompararUsuarioPorEmailAvl, &erroAvl);

    if(erroAvl!=ERRO_OK){
        return erroAvl;
    }

    return ERRO_OK;
}
CodigoErro AdminEditarUsuario(User* userBuscado, int novoId, int novoTipo, char* novoNome, char* novoSobrenome, char*novaSenha){

    userBuscado->id = novoId;
    userBuscado->admin = novoTipo;
    strcpy(userBuscado->nome, novoNome);
    strcpy(userBuscado->sobrenome, novoSobrenome);
    strcpy(userBuscado->senha, novaSenha);

    return ERRO_OK;

}




