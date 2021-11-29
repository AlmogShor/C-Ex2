#include <stdio.h>
#include <limits.h>
#include "my_mat.h"

int matrix[N][N];

int main() {
    int run = 1, route_found = -1, short_path = INT_MAX;
    char action = 'D';
    int shortest_path[N][N];
    while (run) {
//        printf("There are four option right now:\n A-insert values into the matrix\n B- Find if there is a route from point X to point Y\n "
//               "C - Find shortest path between point X to point Y\n D- Exit\nPlease Enter which action would you like to preform:");
        scanf("%c", &action);
        if (action == 'D' || action == 'd') {
            run = 0; // Stop running. Function no. 4 in the assignment
            continue;
        }
        if (action == 'A' || action == 'a') {
            insert(matrix); // Function no. 1 in the assigment
        } else {
            // This calculating the shortest path - should it be in different location in the program??
            calc_matrix(shortest_path);
            if (action == 'B' || action == 'b') {
                route_found = is_there_a_route(shortest_path); // Function no. 2 in the assignment
                if (route_found == 1) {
                    printf("True");
                }
//                if (route_found == -1) {
//                    printf("Error");
                } else {
                    printf("False");
                }
            } else {
                if (action == 'C' || action == 'c') {
                    short_path = what_is_the_shortest_route(shortest_path); // Function no. 3 in the assignment
                    if (short_path == INT_MAX) {
                        printf("-1");
                    } else {
                        printf("%d", short_path);
                    }
                }
            }
        }
    }
}

void calc_matrix(int shortest_path[N][N]) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            shortest_path[i][j] = matrix[i][j];
            if (matrix[i][j] == 0) {
                shortest_path[i][j] = INT_MAX;
            }
        }
    }
    for (k = 0; k < N; k++) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (i == j) {
                    shortest_path[i][j] = 0;
                } else {
                    shortest_path[i][j] = min(shortest_path[i][j], shortest_path[i][k] + shortest_path[k][j]);
                }
            }
        }
    }
}

int min(int a, int b) {
    if (a < b) {
        return (a);
    } else {
        return (b);
    }
}