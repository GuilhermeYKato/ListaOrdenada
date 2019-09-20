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
    printf("\t Inserindo elemento: %d", x.chave);
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
    printf("\n\t| ");
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
    if (estaVazia(L)){
        return (false);
    }

    PtrNoLista aux =  L->primeiro;
    while((aux->proximo != NULL) && (key > aux->proximo->elemento.chave)){
        aux = aux->proximo;

    }
    if((aux == NULL) || (key < aux->proximo->elemento.chave)){
        return (false);
    } else {
        return (true);
    }

}

int TamanhoLista(Lista *L) {

    return L->Contador;

}
void removePrimeiro(Lista *L, Objeto *obj) {
    if(estaVazia(L) == 0){
        PtrNoLista aux = L->primeiro;
        *obj = aux->elemento;
        L->primeiro = L->primeiro->proximo;
        free(aux);
        L->Contador--;
        printf("Elemento: %d removido\n", (*obj).chave);
    } else {
        printf("\n\tERRO\n\n\tLISTA VAZIA\n\n");
    }

}

void removeUltimo(Lista *L, Objeto *obj) {
    if(estaVazia(L) == 0){
        if(TamanhoLista(L) == 1){
            removePrimeiro(L, obj);
        } else {
            PtrNoLista  aux = L->primeiro;

            for(aux = L->primeiro ; aux->proximo->proximo != NULL; aux = aux->proximo);
            PtrNoLista remove = aux->proximo;
            *obj = remove->elemento;
            aux->proximo = NULL;
            free(remove);
            printf("Elemento: %d removido\n", (*obj).chave);
            L->Contador--;
        }
    }else {
        printf("\n\tERRO\n\n\tLISTA VAZIA\n\n");
    }


}

bool removeElemento(Lista *L, int chave, Objeto *obj) {
    if(estaVazia(L) || (chave < L->primeiro->elemento.chave)){
            printf("\n\tA PORRA TA VAZIA CARALHO\n\n");
            return false;
    }
    if(chave == L->primeiro->elemento.chave){
        printf("Primeiro Elemento removido\n\n");
        removePrimeiro(L, obj);
        return printf("Elemento Removido: %d\n", chave);
    } else {
        /*
        PtrNoLista aux = L->primeiro;
        while((aux->proximo = NULL) && (chave > aux->proximo->elemento.chave)){
            aux = aux->proximo;
            printf("pup\n");

        }
        */
        PtrNoLista aux =  L->primeiro;
        while((aux->proximo != NULL) && (chave > aux->proximo->elemento.chave)){
            aux = aux->proximo;

        }
        if((aux->proximo == NULL) || (chave < aux->proximo->elemento.chave)){
            printf("\n\tNÃO EXISTE SA PORRA NA LISTA CARALHO\n\n");
            return false;
        } else {
            PtrNoLista remove = aux->proximo;
            aux->proximo = aux->proximo->proximo;
            free(remove);
            L->Contador--;
            printf("\n");
            return printf("Elemento Removido: %d\n", chave);

        }
    }
}



Objeto primeiro(Lista *L) {

    return (L->primeiro->elemento);

}

Objeto ultimo(Lista *L) {
    PtrNoLista ptr;
    for (ptr = L->primeiro; ptr != NULL; ptr = ptr->proximo) {

        if (ptr->proximo == NULL) {
            return ptr->elemento;
        }
    }

}

Lista* separa(Lista*lista, int n){
    //percorrer ate achar chave == n
    //lista
    //inciiaa lista
    // primeiro = aux->proximo
    //aux->proximo = NULL;
    //retorna L2
}
Lista* uniao(Lista*lista1, Lista*lista2){
    //cria L3
    //percorre L1 , inserção
    //percorre L2, inserção
    //  pesquisa o elemento para ver se tem igual
    //  bool n = pesq()
    //  if(n == false)
    //      insere
}

#endif //LISTAORDENADAS_LISTAORDENADA_H
