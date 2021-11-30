#include <stdio.h>
#include "my_mat.h"

int matrix[N][N]; // input matrix
int shortest_path[N][N];

int main() {
    int run = 1, len_path;
    char action = 'D';
    while (run) {
        // action A: insert values into the matrix
        // action B: check if there is a route between two nodes (boolean)
        // action C: find the shortest path between two nodes (int)
        // action D: exit the program
        scanf("%c", &action);
        if (action == 'D') {
            run = 0;
        } else if (action == 'A') {
            insert(matrix);
        } else {
            calc_matrix(); // calculate the shortest path
            if (action == 'B') {
                is_there_a_route(shortest_path) ? printf("True\n") : printf("False\n");
            } else if (action == 'C') {
                len_path = what_is_the_shortest_route(shortest_path);
                len_path ? printf("%d\n", len_path) : printf("-1\n");
            }
        }
    }
    return 0;
}

void calc_matrix() {
    int prev_mat[N][N];
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            shortest_path[i][j] = matrix[i][j];
            prev_mat[i][j] = matrix[i][j];
        }
    }
    // Dynamic programming: Floyd–Warshall algorithm
    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (i != j) {
                    if (prev_mat[i][k] != 0 && prev_mat[k][j] != 0) {
                        shortest_path[i][j] = min(prev_mat[i][j], prev_mat[i][k] + prev_mat[k][j]);
                    }
                }
            }
        }
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                prev_mat[i][j] = shortest_path[i][j];
            }
        }
    }

}

int min(int a, int b) {
    if (a == 0) {
        return b;
    }
    return (a < b) ? a : b;
}