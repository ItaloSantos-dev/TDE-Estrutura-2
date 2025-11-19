#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "admin.h"

void ListarUsuarios (SistemaUsuario* sistemaIniciado, void(*ExibirDados)(void* dado)){
    ImprimirAvl(sistemaIniciado->arvoreUsuarios->raiz, ExibirDados );
}

CodigoErro admin_CriarUsuario(SistemaUsuario* sistemaIniciado, User*(*CapturarDados)(void* id)){
    User* novoUser = CapturarDados(sistemaIniciado);
    return CadastrarUsuario(sistemaIniciado, novoUser);
}

CodigoErro DeletarUsuario(SistemaUsuario* sistemaIniciado, char* _email){

    CodigoErro erroHash= ERRO_OK;
    RemoverHash(sistemaIniciado->tabelaPorEmail, _email, FuncaoDeEspalhamentoString, CompararEntradaHashChave, &erroHash);

    if(erroHash!=ERRO_OK){
        return erroHash;
    }

    CodigoErro erroAvl= ERRO_OK;
    sistemaIniciado->arvoreUsuarios->raiz = RemoverNoAvl(sistemaIniciado->arvoreUsuarios, sistemaIniciado->arvoreUsuarios->raiz, _email, CompararUsuarioPorEmail, &erroAvl);

    if(erroAvl!=ERRO_OK){
        return erroAvl;
    }

    return ERRO_OK;
}
CodigoErro EditarUsuario(SistemaUsuario* sistemaInicado, char* _email, char* novoNome, char* novoSobrenome, char*novaSenha){

    CodigoErro erroBuscaHash = ERRO_OK;
    EntradaHash* entradaHashBuscada = BuscarHash(sistemaInicado->tabelaPorEmail, _email, FuncaoDeEspalhamentoString, CompararEntradaHashChave, &erroBuscaHash);
    if(erroBuscaHash!=ERRO_OK){
        return erroBuscaHash;
    }
    User* usuariouscado =(User*) entradaHashBuscada->valor;
    EditarDadosUsuario(usuariouscado, novoNome, novoSobrenome, novaSenha);
    return erroBuscaHash;

}
void  EditarDadosUsuario(User* usuariouscado, char* novoNome, char* novoSobrenome, char* novaSenha){

    strncpy(usuariouscado->nome, novoNome, sizeof(usuariouscado->nome));
    strncpy(usuariouscado->sobrenome, novoSobrenome, sizeof(usuariouscado->sobrenome));
    strncpy(usuariouscado->senha, novaSenha, sizeof(usuariouscado->senha));

    usuariouscado->nome[sizeof(usuariouscado->nome)-1] = '\0';
    usuariouscado->sobrenome[sizeof(usuariouscado->sobrenome)-1] = '\0';
    usuariouscado->senha[sizeof(usuariouscado->senha)-1] = '\0';

}


