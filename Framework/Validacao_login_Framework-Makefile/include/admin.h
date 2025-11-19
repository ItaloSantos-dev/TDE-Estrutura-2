#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include "sistema_usuario.h"

void ListarUsuarios (SistemaUsuario* sistemaIniciado, void(*ExibirDados)(void* dado));

CodigoErro admin_CriarUsuario(SistemaUsuario* sistemaIniciado, User*(*CapturarDados)(void* id));

CodigoErro DeletarUsuario(SistemaUsuario* sistemaIniciado, char* _email);

CodigoErro EditarUsuario(SistemaUsuario* sistemaInicado, char* _email, char* novoNome, char* novoSobrenome, char*novaSenha);

void  EditarDadosUsuario(User* usuariouscado, char* novoNome, char* novoSobrenome, char* novaSenha);

#endif // ADMIN_H_INCLUDED
