#include <stdio.h>
#include "my_mat.h"

void insert(int matrix[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Please enter a value to the matrix in cell [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

int is_there_a_route(int matrix[N][N]) {
    int i = 0, j = 0;
    printf("Please enter the nodes you want to find a path for: ");
    scanf("%d %d\n", &i, &j);
    if (matrix[i][j] == 0) {
        return 0;
    } else {
        return 1;
    }
}

int what_is_the_shortest_route(int matrix[N][N]) {
    int i, j;
    printf("Please enter the nodes you want to find the shortest path for: ");
    scanf("%d %d\n", &i, &j);
    return matrix[i][j];
}