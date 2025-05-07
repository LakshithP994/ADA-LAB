#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to create a max heap
void heapify(int a[], int n, int i) {
    int largest = i;  // Initialize largest as root
    int left = 2 * i + 1;  // Left child
    int right = 2 * i + 2;  // Right child

    // If left child is larger than root
    if (left < n && a[left] > a[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && a[right] > a[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        int temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;

        // Recursively heapify the affected subtree
        heapify(a, n, largest);
    }
}

// Function to perform heap sort
void heapsort(int a[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }

    // One by one extract elements from heap
    for (int i = n - 1; i >= 1; i--) {
        // Move current root to the end
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        // Call heapify on the reduced heap
        heapify(a, i, 0);
    }
}

int main() {
    int i, n, ch = 1;
    int a[20];
    clock_t start, end;

    while (ch) {
        // Input the number of elements to sort
        printf("\nEnter the number of elements to sort: ");
        scanf("%d", &n);

        // Input the elements to sort
        printf("\nEnter the elements to sort:\n");
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        // Start measuring time
        start = clock();

        // Perform heap sort
        heapsort(a, n);

        // End measuring time
        end = clock();

        // Output the sorted list
        printf("\nThe sorted list of elements is:\n");
        for (i = 0; i < n; i++) {
            printf("%d\n", a[i]);
        }

        // Output the time taken
        printf("\nTime taken is %lf CPU cycles\n", (double)(end - start) / CLOCKS_PER_SEC);

        // Ask if user wants to run again
        printf("Do you wish to run again (0/1)? ");
        scanf("%d", &ch);
    }

    return 0;
}
