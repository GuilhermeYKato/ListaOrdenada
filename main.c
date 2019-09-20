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

    int x = 49;
    printf("Elemento %d está na lista?\n1 - para Verdadeira e 0 - para Falso:\n\t ##### %d #####\n\n",x ,pesquisar(&Listona, x));
    removePrimeiro(&Listona, &obj);
    imprimirLista(&Listona);
    for(int i = 0; i < 5; i++){
        removeUltimo(&Listona, &obj);

    }
    int N = 5;

    printf("Elemento %d está na lista?\n1 - para Verdadeira e 0 - para Falso:\n\t ##### |%d| #####\n\n",N ,pesquisar(&Listona, N));
    imprimirLista(&Listona);
    printf("1 - para Verdadeira e 0 - para Falso:\n\t ##### %d #####\n",removeElemento(&Listona, N, &obj));
    imprimirLista(&Listona);

    return 0;
}
