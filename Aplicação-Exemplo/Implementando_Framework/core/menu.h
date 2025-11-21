#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "sistema_usuario.h"
#include "admin.h"
#include "funcoes_admin.h"
#include "funcoes_usuario.h"

void MenuPrincipal(SistemaUsuario* sistema);

void MenuUsuarioComum(SistemaUsuario* sistema, User* usuarioLogado);

void MenuUsuarioAdmin (SistemaUsuario* sistema, User* usuarioLogado);

void ChamarMenu(SistemaUsuario* sistema, User* usuarioLogado);





#endif // MENU_H_INCLUDED
