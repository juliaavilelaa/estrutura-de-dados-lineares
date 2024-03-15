// Esboço do código de uma Stack de números inteiros implementada utilizando o conceito de lista encadeada.
// Implementar as partes do código que estão incompletas.

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct noPilha {
    int info;
    struct noPilha* prox;
} TNoPilha;
typedef TNoPilha* Stack;

void inicializar(Stack* pilha) {
    *pilha = NULL;
}

void push(Stack* pilha, int valor) { // empilhar
    Stack aux = (Stack)malloc(sizeof(TNoPilha));
    aux->info = valor;
    aux->prox = *pilha;
    *pilha = aux;
}

int pop(Stack* pilha) {  // desempilhar
    if (*pilha != NULL) {
        Stack aux = *pilha;
        int valor = aux->info;
        *pilha = aux->prox;
        free(aux);
        return valor;
    } else {
        return -1;
    }
}

int top(Stack pilha) {   // retornar o valor que está no topo
    if (pilha != NULL) {
        return pilha->info;
    } else {
        return -1;
    }
}

// int isFull(Stack pilha) {  // checa se a pilha está cheia
    // não é necessário utilizar uma função is full em listas encadeadas.
// }

int isEmpty(Stack pilha) { // checa se a pilha está vazia
    if (pilha == NULL) {
        return -1;
    } else {
        return 0;
    }
}

void exibirOpcoes() {
    printf("Opcoes: \n");
    printf("1 - Push \n");
    printf("2 - Pop \n");
    printf("3 - Top \n");
    printf("0 - Encerrar programa \n");
    printf("Informe a opcao desejada: ");
}

int main()
{
    Stack minhaPilha;
    inicializar(&minhaPilha);
    int op, num;
    do {
        exibirOpcoes();
        scanf("%d", &op);
        switch (op) {
        case 1: printf("Informe o valor: ");
            scanf("%d", &num);
            push(&minhaPilha, num);
            printf("Valor empilhado!\n");
            break;
        case 2:
            if (!isEmpty(minhaPilha)) {
                int valor = pop(&minhaPilha);
                printf("Valor desempilhado = %d\n", valor);
            } else {
                printf("Pilha vazia\n");
            }
            break;
        case 3:
            if (!isEmpty(minhaPilha)) {
                int valor = top(minhaPilha);
                printf("Valor no topo da pilha = %d\n", valor);
            } else {
                printf("Pilha vazia\n");
            }
            break;
        case 0:
            printf("Fim de programa!");
            break;
        default: printf("Opcao invalida!");
        }
    } while (op != 0);
    return 0;
}