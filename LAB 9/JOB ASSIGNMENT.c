#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10

// Function to find the minimum cost assignment
int hungarian_algorithm(int cost[MAX][MAX], int n) {
    int labelX[MAX], labelY[MAX];
    int matchX[MAX], matchY[MAX];
    int slack[MAX], slackX[MAX];
    int prev[MAX];

    // Initialize labels
    for (int i = 0; i < n; i++) {
        labelX[i] = 0;
        labelY[i] = 0;
        matchX[i] = -1;
        matchY[i] = -1;
    }

    // Solve the assignment problem
    for (int u = 0; u < n; u++) {
        // Arrays for sets S and T
        int S[MAX] = {0};  // workers already matched
        int T[MAX] = {0};  // jobs already matched
        int queue[MAX];
        int head = 0, tail = 0;

        // Initialize the queue
        queue[tail++] = u;
        prev[u] = -1;
        S[u] = 1;

        for (int v = 0; v < n; v++) {
            slack[v] = cost[u][v] - labelX[u] - labelY[v];
            slackX[v] = u;
        }

        // Main loop for each worker
        while (head < tail) {
            int worker = queue[head++];

            for (int job = 0; job < n; job++) {
                if (cost[worker][job] - labelX[worker] - labelY[job] == 0 && !T[job]) {
                    if (matchY[job] == -1) {
                        matchY[job] = worker;
                        matchX[worker] = job;
                        break;
                    }
                    T[job] = 1;
                    queue[tail++] = matchY[job];
                    prev[matchY[job]] = worker;
                }
            }
        }

        // Update the labels
        int delta = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!T[i] && slack[i] < delta) {
                delta = slack[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (S[i]) {
                labelX[i] += delta;
            }
            if (T[i]) {
                labelY[i] -= delta;
            } else {
                slack[i] -= delta;
            }
        }
    }

    // Calculate the total minimum cost
    int totalCost = 0;
    for (int i = 0; i < n; i++) {
        totalCost += cost[i][matchX[i]];
    }
    return totalCost;
}

int main() {
    int cost[MAX][MAX];
    int n;

    printf("Enter the number of workers/jobs: ");
    scanf("%d", &n);

    printf("Enter the cost matrix (cost[i][j] is the cost of assigning job j to worker i):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    int result = hungarian_algorithm(cost, n);
    printf("The minimum cost of assignment is: %d\n", result);

    return 0;
}
