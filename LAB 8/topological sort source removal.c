#include <stdio.h>

int a[10][10], n, t[10], indegree[10];
int queue[10], front = 0, rear = -1;

void computeIndegree(int, int [][10]);
void tps_SourceRemoval(int, int [][10]);

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int i, j;
    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    computeIndegree(n, a);
    tps_SourceRemoval(n, a);

    printf("Solution: ");
    for(i = 0; i < n; i++) {
        printf("%d ", t[i]);
    }

    return 0;
}

void computeIndegree(int n, int a[][10]) {
    int i, j;
    for(i = 0; i < n; i++) {
        indegree[i] = 0;
        for(j = 0; j < n; j++) {
            indegree[i] += a[j][i];
        }
    }
}

void tps_SourceRemoval(int n, int a[][10]) {
    int i, j, v, k = 0;

    // Enqueue all nodes with indegree 0
    for(i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    while(front <= rear) {
        v = queue[front++]; // Dequeue
        t[k++] = v;         // Add to result

        for(i = 0; i < n; i++) {
            if(a[v][i] != 0) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    queue[++rear] = i; // Enqueue if indegree becomes 0
                }
            }
        }
    }
}
