#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NR_VERTICES_A 5

static bool const A[NR_VERTICES_A][NR_VERTICES_A] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 0, 1},
    {0, 1, 0, 0, 0},
    {0, 0, 1, 0, 1}};

void bfs(size_t n, bool const A[n][n], bool visited[n], size_t source) {
    size_t front = 0, rear = 0;
    size_t queue[n];
    for (size_t i = 0; i < n; i++) {
        queue[i] = 0;
    }
    // Enqueue
    visited[source] = true;
    queue[rear++] = source;
    printf("%zu ", source);
    while (front < rear) {
        size_t v = queue[front++];
        for (size_t i = 0; i < n; i++) {
            if (A[v][i] && !visited[i]) {
                // Enqueue
                visited[i] = true;
                queue[rear++] = i;
                printf("%zu ", i);
            }
        }
    }
    printf("\n");
}

void connected_components(size_t n, bool const A[n][n]) {
    bool visited[n];
    for (size_t i = 0; i < n; i++) {
        visited[i] = false;
    }
    for (size_t i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(n, A, visited, i);
        }
    }
    printf("\n");
}

int main(void) {
    printf("A:\n");
    for (size_t i = 0; i < NR_VERTICES_A; i++) {
        for (size_t j = 0; j < NR_VERTICES_A; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("BFS on A: ");
    bool visited[NR_VERTICES_A] = {0};
    bfs(NR_VERTICES_A, A, visited, 0);
    printf("Connected components on A: ");
    connected_components(NR_VERTICES_A, A);

    return EXIT_SUCCESS;
}