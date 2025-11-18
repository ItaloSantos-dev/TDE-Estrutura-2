#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "erros.h"




const char* CodigoErroParaTexto(CodigoErro erro) {


    switch (erro) {

        case ERRO_OK: return "Nenhum erro";
        case ERRO_MEMORIA: return "Falha de memória";

        case ERRO_USUARIO_EXISTE: return "Usuário já existe";
        case ERRO_USUARIO_NAO_ENCONTRADO: return "Usuário não encontrado";

        case ERRO_HASH_COLISAO_FALHOU: return "Falha ao resolver colisão da hash";
        case ERRO_HASH_MEMORIA: return "Falha de memória na hash";
        case ERRO_HASH_INSERCAO_FALHOU: return "Falha ao inserir na hash";

        case ERRO_AVL_CHAVE_DUPLICADA: return "Chave duplicada na AVL";
        case ERRO_AVL_MEMORIA: return "Falha de memória na AVL";
        case ERRO_AVL_INSERCAO_FALHOU: return "Falha ao inserir na AVL";
        case ERRO_AVL_NO_NAO_ENCONTRADO: return "No da AVL nao encontrado";
        case ERRO_AVL_DUPLICADO: return "Nó duplicado na AVL";

        case ERRO_LISTA_MEMORIA: return "Falha de memória na lista";
        case ERRO_LISTA_NO_MEMORIA: return "Falha ao criar nó da lista";
        case ERRO_LISTA_NO_NAO_ENCONTRADO: return "No da lista nao encontrado";

        case ERRO_DESCONHECIDO: return "Erro desconhecido";
        case ERRO_PARAMETRO_INVALIDO: return "Parâmetro inválido";
        case ERRO_EMAIL_NAO_ENCONTRADO: return "Email não encontrado";
        case ERRO_SISTEMA_NAO_INICIADO: return "Sistema não iniciado";

        case ERRO_LOGIN_SUCESSO: return "Login realizado com sucesso";
        case ERRO_LOGIN_FALHOU: return "Login falhou";

        default: return "Erro não mapeado";
    }
}
