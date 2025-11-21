#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sistema_usuario.h"
#include "admin.h"
#include "core/menu.h"


int main()
{
    SistemaUsuario* sistema;
    CodigoErro statusSistema = IniciarSistemaUsuarios(&sistema);


    if(statusSistema==ERRO_OK){
        MenuPrincipal(sistema);
    }
    else{
        printf("Erro: %s\n", CodigoErroParaTexto(statusSistema));
    }
}
