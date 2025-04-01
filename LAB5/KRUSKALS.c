#include <stdio.h>
#include <limits.h>

int cost[10][10], n, t[10][2], sum;

void kruskal(int cost[10][10], int n);
int find(int parent[10], int i);
void unionSets(int parent[10], int rank[10], int u, int v);

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use a large value like 999 for no edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    kruskal(cost, n);

    printf("Edges of the minimum spanning tree:\n");
    for (i = 0; i < n - 1; i++) {
        printf("(%d, %d) ", t[i][0], t[i][1]);
    }

    printf("\nSum of the minimum spanning tree: %d\n", sum);
    return 0;
}

void kruskal(int cost[10][10], int n) {
    int parent[10], rank[10];
    int min, u, v, count = 0, k = 0;

    sum = 0;

    // Initialize Union-Find structure
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    while (count < n - 1) {
        min = INT_MAX;
        u = -1;
        v = -1;

        // Find the minimum weighted edge
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] && cost[i][j] < min && find(parent, i) != find(parent, j)) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (u == -1 || v == -1) {
            break;  // No more valid edges
        }

        // Union operation
        unionSets(parent, rank, u, v);
        t[k][0] = u;
        t[k][1] = v;
        sum += min;
        k++;
        count++;
    }
}

// Optimized Find with Path Compression
int find(int parent[10], int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);  // Path compression
    }
    return parent[i];
}

// Union by Rank
void unionSets(int parent[10], int rank[10], int u, int v) {
    int root_u = find(parent, u);
    int root_v = find(parent, v);

    if (root_u != root_v) {
        if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
}
