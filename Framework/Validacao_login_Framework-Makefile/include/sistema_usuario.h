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

CodigoErro EncerrarSistema(SistemaUsuario** sistema);

void LiberarUsuariosAVL(NoAvl* raiz, CodigoErro* erro);

void LiberarUsuariosHash(Hash* tabelaHash, CodigoErro* erro);

CodigoErro LiberarUsuarios(SistemaUsuario* sistema);

void  EditarDadosUsuario(User* usuariouscado, char* novoNome, char* novoSobrenome, char* novaSenha);

CodigoErro UsuarioEditarUsuario(SistemaUsuario* sistemaInicado, char* _email, char* novoNome, char* novoSobrenome, char*novaSenha);
User* BuscarUsuario (SistemaUsuario* sistema, char* _email);





#endif // SISTEMA_USUARIO_H_INCLUDED
