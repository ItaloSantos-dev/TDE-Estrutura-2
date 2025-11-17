#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

typedef struct usuario{
    int id;
    char nome[100];
    char sobrenome[100];
    char email[100];
    char senha[50];

}User;

User* CriarUsuario(int _id, char* _nome, char* _sobrenome, char* _email, char* _senha);
void ImprimirUsuario(void* _dado);
int CompararUsuarioPorId(void*_user1 , void*_user2);
int CompararUsuarioPorEmail(void* _user1, void* _user2);










#endif // USUARIO_H_INCLUDED
