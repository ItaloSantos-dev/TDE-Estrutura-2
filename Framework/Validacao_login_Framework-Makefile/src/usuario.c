#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"usuario.h"


User* CriarUsuario(int _id, char* _nome, char* _sobrenome, char* _email, char* _senha){
    User* novoUsuario = malloc(sizeof(User));
    novoUsuario->id = _id;
    novoUsuario->admin = 0;
    strcpy(novoUsuario->nome, _nome);
    strcpy(novoUsuario->sobrenome, _sobrenome);
    strcpy(novoUsuario->email, _email);
    strcpy(novoUsuario->senha, _senha);

    return novoUsuario;

}

void ImprimirUsuario(void* _dado){
    User* u = (User*)_dado;
    printf("Id: %d\n", u->id);
    printf("Nome: %s\n", u->nome);
    printf("Sobrenome: %s\n", u->sobrenome);
    printf("Email: %s\n", u->email);
    printf("Senha: %s\n", u->senha);
    printf("-------------------------\n");
}

int CompararUsuarioPorId(void*_user1 , void*_user2){
    User* u1 = (User*)_user1;
    User* u2 = (User*)_user2;

    if (u1->id < u2->id) return -1;
    if (u1->id > u2->id) return 1;
    return 0;

}

int CompararUsuarioPorEmail(void* _u1, void* _u2){
    User* u1 = (User*)_u1;
    User* u2 = (User*)_u2;

    return strcmp(u1->email, u2->email);
}


