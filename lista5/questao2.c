#include <stdio.h>
#include <stdlib.h>

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

void push(Stack* pilha, int valor) {
    Stack aux = (Stack)malloc(sizeof(TNoPilha));
    aux->info = valor;
    aux->prox = *pilha;
    *pilha = aux;
}

int pop(Stack* pilha) {  
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

int top(Stack pilha) {  
    if (pilha != NULL) {
        return pilha->info;
    } else {
        return -1;
    }
}

int isEmpty(Stack pilha) {
    if (pilha == NULL) {
        return -1;
    } else {
        return 0;
    }
}

void decimalParaBinario(int num) {
    Stack pilha;
    inicializar(&pilha);
    while (num > 0) {
        push(&pilha, num % 2);
        num = num / 2;
    }
    while (!isEmpty(pilha)) {
        printf("%d", pop(&pilha));
    }
    printf("\n");
}

int main() {
    int num;
    printf("Digite um número decimal: ");
    scanf("%d", &num);
    printf("O número binário equivalente é: ");
    decimalParaBinario(num);
    return 0;
}