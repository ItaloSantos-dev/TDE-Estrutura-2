#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include "sistema_usuario.h"

void ListarUsuarios (SistemaUsuario* sistemaIniciado, void(*ExibirDados)(void* dado));

CodigoErro AdminCriarUsuario(SistemaUsuario* sistemaIniciado, User* novoUsuario);

CodigoErro DeletarUsuario(SistemaUsuario* sistemaIniciado, char* _email);

CodigoErro AdminEditarUsuario(User* userBuscado, int novoId, int novoTipo, char* novoNome, char* novoSobrenome, char*novaSenha);

int CompararUsuarioPorEmailAvl(void* dado, void* _u2);




#endif // ADMIN_H_INCLUDED
