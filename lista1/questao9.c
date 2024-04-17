#include <stdio.h>

int main() {
    double rates[] = {12.9, 18.6, 11.4, 9.5, 15.2, 17.6};

    for (int i = 0; i < 6; i++) {
        printf("rates[%d] = %.1lf\n", i, *(rates + i));
    }

    return 0;
}