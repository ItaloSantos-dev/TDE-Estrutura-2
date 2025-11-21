#ifndef FUNCOES_ADMIN_H_INCLUDED
#define FUNCOES_ADMIN_H_INCLUDED
#include "sistema_usuario.h"
#include "admin.h"

void ExibirDadosUsuarios (SistemaUsuario* sistema);

void CriarNovoUsuario(SistemaUsuario* sistema);

void EditarUsuario(SistemaUsuario* sistema);

void EditardadosAdminUsuario(User* usuarioBuscado);

void ApagarUsuario(SistemaUsuario* sistema);



#endif // FUNCOES_ADMIN_H_INCLUDED
