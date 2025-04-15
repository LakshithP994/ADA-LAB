#include <stdio.h>

int i, j, n, c, w[10], p[10], v[10][10];

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int n, int w[10], int p[10], int c) {
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= c; j++) {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (w[i] > j)
                v[i][j] = v[i - 1][j];
            else
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
        }
    }

    printf("\nMaximum Profit is: %d\n", v[n][c]);

    printf("\nTable:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= c; j++) {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter the no. of objects: ");
    scanf("%d", &n);

    printf("Enter the weights: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter the profits: ");
    for (i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter the capacity: ");
    scanf("%d", &c);

    knapsack(n, w, p, c);

    return 0;
}
