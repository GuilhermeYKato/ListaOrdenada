#include "ListaOrdenada.h"
#include <stdio.h>

int main() {
    Objeto obj;
    Lista Listona;

    iniciaLista(&Listona);

    obj.chave = 1000;
    inserir(&Listona, obj);
    imprimirLista(&Listona);

    obj.chave = 5;
    inserir(&Listona, obj);
    imprimirLista(&Listona);

    obj.chave = 50;
    inserir(&Listona, obj);
    imprimirLista(&Listona);

    obj.chave = -14;
    inserir(&Listona, obj);
    imprimirLista(&Listona);

    obj.chave = -1;
    inserir(&Listona, obj);
    imprimirLista(&Listona);

    obj.chave = 700;
    inserir(&Listona, obj);
    imprimirLista(&Listona);

    obj.chave = 45;
    inserir(&Listona, obj);
    imprimirLista(&Listona);

    obj.chave = 49;
    inserir(&Listona, obj);

    imprimirLista(&Listona);
    printf("Tamanho: %d\n", TamanhoLista(&Listona));
    printf("Primeiro: %d\n", primeiro(&Listona).chave);
    printf("Ultimo: %d\n", ultimo(&Listona).chave);
    int x = 50;
    if (pesquisar(&Listona, x)) {
        printf("Achou\n");
    } else {
        printf("Não tem, SADBOY\n");
    }
    return 0;
}