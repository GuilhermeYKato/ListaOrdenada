#ifndef LISTAORDENADAS_LISTAORDENADA_H
#define LISTAORDENADAS_LISTAORDENADA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int chave;
} Objeto;

typedef struct NoLista *PtrNoLista;

typedef struct NoLista {
    Objeto elemento;
    PtrNoLista proximo;
} NoLista;

typedef struct {
    PtrNoLista primeiro;
    int Contador; //Tamanho
} Lista;

void iniciaLista(Lista *L) {
    L->primeiro = NULL;
    L->Contador = 0;
}

bool estaVazia(Lista *L) {
    if (L->Contador == 0) {
        return true;
    } else {
        return false;
    }

}

void inserir(Lista *L, Objeto x) {
    PtrNoLista Novo;
    Novo = (PtrNoLista) malloc(sizeof(NoLista));
    Novo->elemento = x;
    printf("\t Inserindo elemento: %d\n", x.chave);
    if (estaVazia(L) || x.chave < L->primeiro->elemento.chave) {
        Novo->proximo = L->primeiro; //Novo->proximo == NULL 
        L->primeiro = Novo;
        L->Contador++;
    } else {
        PtrNoLista Aux = L->primeiro;
        while (Aux->proximo != NULL && (x.chave > Aux->proximo->elemento.chave)) {
            Aux = Aux->proximo;
        }
        Novo->proximo = Aux->proximo;
        Aux->proximo = Novo;
        L->Contador++;
    }
}

void imprimirLista(Lista *L) {
    PtrNoLista ptr;
    printf("\t | ");
    for (ptr = L->primeiro; ptr != NULL; ptr = ptr->proximo) {
        printf("%d ", ptr->elemento.chave);
    }
    printf("|\n\n");

}

void destruirLista(Lista *L) {
    PtrNoLista ptr;
    for (ptr = L->primeiro; ptr != NULL; ptr = ptr->proximo) {
        free(ptr);
    }
}

bool pesquisar(Lista *L, int key) {
    if (estaVazia(L)) {
        return false;
    }
    PtrNoLista Aux = L->primeiro;
    while ((Aux != NULL) && (key > Aux->elemento.chave)) {
        Aux = Aux->proximo;
    }
    if ((Aux == NULL) || (Aux->elemento.chave > key)) { //nao existe elemento
        return false;
    }
    return true;
}

int TamanhoLista(Lista *L) {

    return L->Contador;

}

void removeElemento(Lista *L, int chave, Objeto *obj) {


}

void removePrimeiro(Lista *L, Objeto *obj) {


}

void removeUltimo(Lista *L, Objeto *obj) {


}

Objeto primeiro(Lista *L) {

    return L->primeiro->elemento;

}

Objeto ultimo(Lista *L) {
    PtrNoLista ptr;
    for (ptr = L->primeiro; ptr != NULL; ptr = ptr->proximo) {

        if (ptr->proximo == NULL) {
            L->primeiro->elemento.chave = ptr->elemento.chave;
            return L->primeiro->elemento;
        }
    }

}


#endif //LISTAORDENADAS_LISTAORDENADA_H
