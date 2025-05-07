#include <stdio.h>
#include <limits.h>

#define MAX_CITIES 16  // Maximum number of cities, adjust as needed
#define INF INT_MAX

int cost[MAX_CITIES][MAX_CITIES];  // Cost matrix
int dp[1 << MAX_CITIES][MAX_CITIES];  // DP table, 2^n subsets for n cities

// Function to calculate the minimum cost using DP and bitmasking
int tsp(int mask, int pos, int n) {
    // Base case: if all cities have been visited, return the cost to go back to the starting city
    if (mask == (1 << n) - 1) {
        return cost[pos][0];  // Return to the starting city
    }

    // If the result is already computed, return it
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;  // Initialize the answer to a large value

    // Try to go to each unvisited city
    for (int city = 0; city < n; city++) {
        // If the city has not been visited yet (not in the current mask)
        if ((mask & (1 << city)) == 0) {
            // Recursively calculate the cost of visiting the next city
            int newAns = cost[pos][city] + tsp(mask | (1 << city), city, n);
            ans = (ans < newAns) ? ans : newAns;  // Update the answer if a better one is found
        }
    }

    dp[mask][pos] = ans;  // Memoize the result
    return ans;
}

int main() {
    int n;

    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the cost matrix (enter -1 for no direct path):\n");
    // Reading the cost matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == -1) {  // No direct path between cities
                cost[i][j] = INF;
            }
        }
    }

    // Initialize dp table with -1 (indicating not calculated)
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    // Call the TSP function starting from city 0 with just city 0 visited
    int result = tsp(1, 0, n);  // Initial mask = 1 (city 0 visited), starting from city 0

    printf("The minimum cost to visit all cities and return to the starting city is: %d\n", result);

    return 0;
}
