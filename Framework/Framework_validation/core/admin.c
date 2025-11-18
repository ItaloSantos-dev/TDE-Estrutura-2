#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "admin.h"

void ListarUsuarios (SistemaUsuario* sistemaIniciado){
    ImprimirAvl(sistemaIniciado->arvoreUsuarios->raiz, ImprimirUsuario);
}

int admin_CriarUsuario(SistemaUsuario* sistemaIniciado){
    User* novoUser = CapturarDadosParaCadastro(sistemaIniciado);
    return CadastrarUsuario(sistemaIniciado, novoUser);
}

int DeletarUsuario(SistemaUsuario* sistemaIniciado, char* _email){
    sistemaIniciado->arvoreUsuarios->raiz = RemoverNoAvl(sistemaIniciado->arvoreUsuarios, sistemaIniciado->arvoreUsuarios->raiz, _email, CompararUsuarioPorEmail);
    RemoverHash(sistemaIniciado->tabelaPorEmail, _email, FuncaoDeEspalhamentoString, CompararString );
}
void EditarUsuario(SistemaUsuario* sistemaInicado, char* _email, char* novoNome, char* novoSobrenome, char*novaSenha){
    EntradaHash* entradaHashBuscada = BuscarHash(sistemaInicado->tabelaPorEmail, _email, FuncaoDeEspalhamentoString, CompararEntradaHashChave);
    if(entradaHashBuscada){
        User* usuariouscado =(User*) entradaHashBuscada->valor;
        EditarDadosUsuario(usuariouscado, novoNome, novoSobrenome, novaSenha);
    }
}


