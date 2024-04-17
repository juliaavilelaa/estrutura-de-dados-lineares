#include <stdio.h>
#include <stdlib.h>

typedef struct Dados {
    char sexo;
    float altura;
    int idade;
    char olhos;
} TDados;

void letraa(TDados *Dados, int quantd) {
    int somaIdadeC = 0;
    int countAlturaC = 0;

    for (int i = 0; i < quantd; i++) {
        if (Dados[i].olhos == 'C' && Dados[i].altura > 1.60) {
            somaIdadeC += Dados[i].idade;
            countAlturaC++;
        }
    }
    if (countAlturaC > 0) {
        float media = (float)somaIdadeC / (float)countAlturaC;
        printf("Media de idade das pessoas com olhos castanhos e altura superior a 1,60m: %.2f\n", media);
    } else {
        printf("Não há pessoas com olhos castanhos e altura superior a 1,60m na pesquisa.\n");
    }
}

void letrab(TDados *Dados, int quantd) {
    int maiorIdade = Dados[0].idade;
    for (int i = 1; i < quantd; i++) {
        if (Dados[i].idade > maiorIdade) {
            maiorIdade = Dados[i].idade;
        }
    }
    printf("Maior idade entre os habitantes: %d anos\n", maiorIdade);
}

void letrac(TDados *Dados, int quantd) {
    int countMulheres = 0;
    for (int i = 0; i < quantd; i++) {
        if ((Dados[i].sexo == 'F' && Dados[i].idade >= 20 && Dados[i].idade <= 45) ||
            (Dados[i].olhos == 'V' && Dados[i].altura < 1.70)) {
            countMulheres++;
        }
    }
    printf("Quantidade de mulheres com idade entre 20 e 45 anos ou com olhos verdes e altura inferior a 1,70m: %d\n", countMulheres);
}

void letrad(TDados *Dados, int quantd) {
    int countHomens = 0;
    for (int i = 0; i < quantd; i++) {
        if (Dados[i].sexo == 'M') {
            countHomens++;
        }
    }
    float percentualHomens = ((float)countHomens / (float)quantd) * 100;
    printf("Percentual de homens na pesquisa: %.2f%%\n", percentualHomens);
}

int main() {
    int quantd;
    TDados *ptrDados;

    printf("Informe a quantidade de habitantes na pesquisa: ");
    scanf("%d", &quantd);

    ptrDados = (TDados *)malloc(quantd * sizeof(TDados));

    for (int i = 0; i < quantd; i++) {
        printf("Dados do habitante %d: \n", i + 1);
        printf("Sexo (M/F): ");
        scanf(" %c", &ptrDados[i].sexo);
        printf("Altura (em metros): ");
        scanf("%f", &ptrDados[i].altura);
        printf("Idade: ");
        scanf("%d", &ptrDados[i].idade);
        printf("Cor dos olhos (A - Azuis/V - Verdes/C - Castanhos/P - Pretos): ");
        scanf(" %c", &ptrDados[i].olhos);
    }

    letraa(ptrDados, quantd);
    letrab(ptrDados, quantd);
    letrac(ptrDados, quantd);
    letrad(ptrDados, quantd);

    free(ptrDados);

    return 0;
}