#include <stdio.h>
#include "my_mat.h"

void insert(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int is_there_a_route(int matrix[N][N]) {
    int i, j;
    scanf("%d %d", &i, &j);
    return matrix[i][j] ? 1 : 0;
}

int what_is_the_shortest_route(int matrix[N][N]) {
    int i, j;
    scanf("%d %d", &i, &j);
    return matrix[i][j];
}