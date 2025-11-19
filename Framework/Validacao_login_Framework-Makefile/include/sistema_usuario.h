#ifndef SISTEMA_USUARIO_H_INCLUDED
#define SISTEMA_USUARIO_H_INCLUDED
#include "avl.h"
#include "util.h"
#include "hash.h"
#include "usuario.h"
#include "erros.h"


typedef struct sistemaUsuario {
    AVL* arvoreUsuarios;
    Hash* tabelaPorEmail;
    Lista* listaEncadeada;
} SistemaUsuario;



CodigoErro IniciarSistemaUsuarios(SistemaUsuario** sistema);

CodigoErro CadastrarUsuario(SistemaUsuario* sistemaIniciado, User* novoUsuario);
CodigoErro LoginUsuario (SistemaUsuario* sistemaIniciado, char* _email, char*_senha, User** usuarioLogado);

User* CapturarDadosParaCadastroConsole(void* sistema);

CodigoErro InserirUsuarioEstruturas(SistemaUsuario* sistemaIniciado, User* novoUsuario);


CodigoErro ValidarNovoemail(Hash* tabelaHash, User* novousuario);
int ValidarStringEmail(char* _email);
void ImprimirUsuarioEntradaHash(void* dado);
int ConfirmarSenha(char* _senha, User* usuarioBuscado);



#endif // SISTEMA_USUARIO_H_INCLUDED
