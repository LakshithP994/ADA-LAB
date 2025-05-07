#include <stdio.h>
#include <math.h>

int x[20], count = 1;  // Array to store positions of queens

void queens(int k, int n);
int place(int k, int j);

int main() {
    int n;
    printf("\nEnter the number of queens to be placed: ");
    scanf("%d", &n);
    queens(1, n);
    return 0;
}

void queens(int k, int n) {
    int j, i;
    // Try to place the queen in all columns for the current row (k)
    for (j = 1; j <= n; j++) {
        if (place(k, j)) {
            x[k] = j;  // Place the queen at row k and column j

            // If we have placed queens in all rows, print the solution
            if (k == n) {
                printf("\nSolution %d:\n", count++);
                for (i = 1; i <= n; i++) {
                    printf("\tRow %d -> Column %d\n", i, x[i]);
                }
            } else {
                queens(k + 1, n);  // Recur to place the next queen
            }
        }
    }
}

// Function to check if a queen can be placed at row k, column j
int place(int k, int j) {
    int i;
    for (i = 1; i < k; i++) {
        // Check if queens are in the same column or on the same diagonal
        if (x[i] == j || abs(x[i] - j) == abs(i - k)) {
            return 0;  // Can't place queen
        }
    }
    return 1;  // Can place queen
}
