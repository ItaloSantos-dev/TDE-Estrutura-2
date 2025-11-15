#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"util.h"


void ExibirDadosInt(void* a){

    printf("Dado: %i\n", *(int*)a);

}
void ExibirDadosString(void* a){

    printf("Dado: %s\n", (char*)a);

}

int CompararInt(void* a, void* b){
    int intA = *(int*)a;
    int intB = *(int*)b;

    if(intA==intB){
        return 0;
    }
    else if(intA<intB){
        return -1;
    }
    else{
        return 1;
    }
}

int CompararString(void* a, void* b){
    char* stringA = (char*)a;
    char* stringB = (char*)b;
    return strcmp(stringA,stringB);
}


