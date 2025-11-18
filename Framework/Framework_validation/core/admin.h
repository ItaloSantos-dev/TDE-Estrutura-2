#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include "sistema_usuario.h"

void ListarUsuarios (SistemaUsuario* sistemaIniciado);

int admin_CriarUsuario(SistemaUsuario* sistemaIniciado);

void DeletarUsuario(SistemaUsuario* sistemaIniciado, char* _email);

void EditarUsuario(SistemaUsuario* sistemaInicado, char* _email);

#endif // ADMIN_H_INCLUDED
