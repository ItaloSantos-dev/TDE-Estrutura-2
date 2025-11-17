#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "core/sistema_usuario.h"




int main(){
    SistemaUsuario* sistemaUsuarios = IniciarSistemaUsuarios();
    if(sistemaUsuarios){
        CadastrarUsuario(sistemaUsuarios);
        char email[] = "italo@.com";
        char senha[] = "1131";
        User* usuarioLogado = LoginUsuario(sistemaUsuarios, email, senha);
        if(usuarioLogado){
            printf("Usuario logado com sucesso\n");
            ImprimirUsuario(usuarioLogado);

        }
    }


}
