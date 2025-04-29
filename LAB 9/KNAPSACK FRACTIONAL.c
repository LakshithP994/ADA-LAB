#include <stdio.h>

int main() {
    int n, W;  // Number of items and the capacity of the knapsack
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int p[n];  // Array to store the weights of items
    int w[n];  // Array to store the values of items

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Enter the weights and values of the items (weight value):\n");
    for (int i = 0; i < n; ++i) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &p[i], &w[i]);
    }

    int cur_w = W;           // Current available weight
    float tot_v = 0.0;       // Total value of items added to the bag
    int i, maxi;             // Loop index and the index of the item with the highest value-to-weight ratio
    int used[n];             // Array to track whether an item has been used (added fully or partially)

    // Initialize used array to 0 (none of the items are used at the start)
    for (i = 0; i < n; ++i) {
        used[i] = 0;
    }

    while (cur_w > 0) {
        maxi = -1;

        // Find the item with the highest value-to-weight ratio that hasn't been used
        for (i = 0; i < n; ++i) {
            if ((used[i] == 0) && ((maxi == -1) || ((float)w[i] / p[i] > (float)w[maxi] / p[maxi]))) {
                maxi = i;
            }
        }

        // Add the item completely if there's enough space, otherwise partially add it
        used[maxi] = 1;
        cur_w -= p[maxi];
        tot_v += w[maxi];

        // If the item fits completely, print the message
        if (cur_w >= 0) {
            printf("Added object %d (%d, %d) completely in the bag. Space left: %d.\n", maxi + 1, w[maxi], p[maxi], cur_w);
        } else {
            // Otherwise, partially add the item and print the percentage added
            printf("Added %d%% (%d, %d) of object %d in the bag.\n", (int)((1 + (float)cur_w / p[maxi]) * 100), w[maxi], p[maxi], maxi + 1);
            tot_v -= w[maxi];
            tot_v += (1 + (float)cur_w / p[maxi]) * w[maxi];
        }
    }

    // Output the total value of the items added to the bag
    printf("Filled the bag with objects worth %.2f.\n", tot_v);
    return 0;
}
