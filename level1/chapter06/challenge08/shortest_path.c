#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NR_VERTICES 6

unsigned int A[NR_VERTICES][NR_VERTICES] = {
    {UINT_MAX, 7, 9, UINT_MAX, UINT_MAX, 14},
    {UINT_MAX, UINT_MAX, 10, 15, UINT_MAX, UINT_MAX},
    {UINT_MAX, UINT_MAX, UINT_MAX, 11, UINT_MAX, 2},
    {UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, 6, UINT_MAX},
    {UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, 9},
    {UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX, UINT_MAX}};

unsigned int shortest_path(size_t n, unsigned int A[n][n], unsigned int startingNode, unsigned int target) {
    bool visited[n];
    unsigned int distance[n];
    for (size_t i = 0; i < n; i++) {
        visited[i] = false;
        distance[i] = UINT_MAX;
    }
    visited[startingNode] = true;
    distance[startingNode] = 0;

    unsigned int currentNode = startingNode;
    while (currentNode != target) {
        for (size_t i = 0; i < n; i++) {
            if (!visited[i] && A[currentNode][i] != UINT_MAX) {
                if (distance[currentNode] + A[currentNode][i] < distance[i]) {
                    distance[i] = distance[currentNode] + A[currentNode][i];
                }
            }
        }
        visited[currentNode] = true;
        unsigned int nextNode = 0;
        unsigned int minDistance = UINT_MAX;
        for (size_t i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < minDistance) {
                nextNode = i;
                minDistance = distance[i];
            }
        }

        if (minDistance == UINT_MAX) {
            break;
        }
        currentNode = nextNode;
    }
    return distance[target];
}

int main(void) {
    printf("Shortest path to %d is %d\n", 4, shortest_path(NR_VERTICES, A, 0, 4));
    return EXIT_SUCCESS;
}