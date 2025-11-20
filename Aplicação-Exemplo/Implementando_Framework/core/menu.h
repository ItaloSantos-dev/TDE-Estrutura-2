#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "sistema_usuario.h"
#include "admin.h"

void MenuPrincipal(SistemaUsuario* sistema);

void FazerLogin (SistemaUsuario** sistema);

void EditarMeusDados(User* usuarioLogado, SistemaUsuario* sistema);

void MenuUsuarioComum(SistemaUsuario* sistema, User* usuarioLogado);

void MenuUsuarioAdmin (SistemaUsuario* sistema, User* usuarioLogado);

void ChamarMenu(SistemaUsuario* sistema, User* usuarioLogado);

void ExibirDadosUsuarios (SistemaUsuario* sistema);

void CriarNovoUsuario(SistemaUsuario* sistema);

void EditarUsuario(SistemaUsuario* sistema);

void EditardadosAdminUsuario(User* usuarioBuscado);

void ApagarUsuario(SistemaUsuario* sistema);
void Cadastrarse (SistemaUsuario* sistema);




#endif // MENU_H_INCLUDED
