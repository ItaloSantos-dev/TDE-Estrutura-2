#ifndef FUNCOES_USUARIO_H_INCLUDED
#define FUNCOES_USUARIO_H_INCLUDED
#include "sistema_usuario.h"

void FazerLogin (SistemaUsuario** sistema);

void Cadastrarse (SistemaUsuario* sistema);

void VerMeusDados(User* usuarioLogado);

void EditarMeusDados(User* usuarioLogado, SistemaUsuario* sistema);

void ChamarMenu(SistemaUsuario* sistema, User* usuarioLogado);

void DeletarMinhaConta(SistemaUsuario* sistema, User* usuarioLogado);




#endif // FUNCOES_USUARIO_H_INCLUDED
