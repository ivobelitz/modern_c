#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isPrime(size_t n) {
    for (size_t i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void factor(size_t n) {
    printf("N: ");
    for (size_t i = 0; i <= n; i++) {
        if (isPrime(i)) {
            if (n % i == 0) {
                printf("%zu ", i);
            }
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    size_t input;
    printf("Before scanf\n");
    sscanf(argv[1], "%zu", &input);
    printf("input = %zu\n", input);
    factor(input);
    return EXIT_SUCCESS;
}