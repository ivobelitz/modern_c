#include <stdio.h>
#include <stdlib.h>

size_t fibCacheRec(size_t n, size_t cache[n]) {
    if (!cache[n - 1]) {
        cache[n - 1] = fibCacheRec(n - 1, cache) + fibCacheRec(n - 2, cache);
    }
    return cache[n - 1];
}

size_t fibCache(size_t n) {
    if (n + 1 <= 3) return 1;
    // Set up a VLA to cache the values
    size_t cache[n];
    // A VLA must be initialized by assignment
    cache[0] = 1;
    cache[1] = 1;
    for (size_t i = 2; i < n; i++) {
        cache[i] = 0;
    }
    return fibCacheRec(n, cache);
}

int main(void) {
    size_t n = 20;
    printf("Fibonacci [%zu] = %zu\n", n, fibCache(n));
}