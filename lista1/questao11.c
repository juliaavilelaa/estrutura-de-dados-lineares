#include <stdio.h>

void converte(int mnts, int *h, int *m) {
    *h = mnts / 60;
    *m = mnts % 60;
}

int main() {
    int mnts, h, m;

    printf("Digite a quantidade de minutos: ");
    scanf("%d", &mnts);

    converte(mnts, &h, &m);

    printf("Horas: %d\n", h);
    printf("Minutos: %d\n", m);

    return 0;
}
