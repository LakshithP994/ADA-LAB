
#include <stdio.h>

#define INF 999
#define MAX 20

int main() {
    int i, j, n, v, k, min, u;
    int c[MAX][MAX], s[MAX], d[MAX];

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    printf("Enter 999 for no edge:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &c[i][j]);
        }
    }

    printf("\nEnter the source vertex: ");
    scanf("%d", &v);

    // Initialize distances and visited set
    for (i = 1; i <= n; i++) {
        s[i] = 0;
        d[i] = c[v][i];
    }

    d[v] = 0;
    s[v] = 1;

    for (k = 2; k <= n; k++) {
        min = INF;
        for (i = 1; i <= n; i++) {
            if (s[i] == 0 && d[i] < min) {
                min = d[i];
                u = i;
            }
        }

        s[u] = 1;

        for (i = 1; i <= n; i++) {
            if (s[i] == 0 && d[i] > d[u] + c[u][i]) {
                d[i] = d[u] + c[u][i];
            }
        }
    }

    printf("\nThe shortest distance from %d is:\n", v);
    for (i = 1; i <= n; i++) {
        printf("%d --> %d = %d\n", v, i, d[i]);
    }

    return 0;
}
