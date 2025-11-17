#ifndef SISTEMA_USUARIO_H_INCLUDED
#define SISTEMA_USUARIO_H_INCLUDED
#include "avl.h"
#include "util.h"
#include "hash.h"
#include "usuario.h"


typedef struct sistemaUsuario {
    AVL* arvoreUsuarios;
    Hash* tabelaPorEmail;
    Lista* listaEncadeada;
} SistemaUsuario;

SistemaUsuario* IniciarSistemaUsuarios();

int CadastrarUsuario(SistemaUsuario* sistemaIniciado);
User* LoginUsuario (SistemaUsuario* sistemaIniciado, char* _email, char*_senha);
User* CapturarDadosParaCadastro(SistemaUsuario* sistemaIniciado);

int InserirUsuarioEstruturas(SistemaUsuario* sistemaIniciado, User* novoUsuario);


int ValidarNovoemail(Hash* tabelaHash, User* novousuario);
int ValidarStringEmail(char* _email);
void ImprimirUsuarioEntradaHash(void* dado);
int ConfirmarSenha(char* _senha, User* usuarioBuscado);



#endif // SISTEMA_USUARIO_H_INCLUDED
