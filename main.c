#include <stdio.h>
#include "my_mat.h"

int matrix[N][N]; // input matrix
int shortest_path[N][N];

int main() {
    int run = 1, len_path;
    char action = 'D';
    while (run) {
//        printf("There are four option right now:\n A-insert values into the matrix\n B- Find if there is a route from point X to point Y\n "
//               "C - Find the shortest path between point X to point Y\n D- Exit\nPlease Enter which action would you like to preform:");
        scanf("%c", &action);
        if (action == 'D') {
            run = 0; // Stop running. Function no. 4 in the assignment
        } else if (action == 'A') {
            insert(matrix); // Function no. 1 in the assigment
        } else {
            calc_matrix(); // calculating the shortest path
            if (action == 'B') { // Function no. 2 in the assigment
                is_there_a_route(shortest_path) ? printf("True\n") : printf("False\n");
            } else if (action == 'C') { // Function no. 3 in the assignment
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