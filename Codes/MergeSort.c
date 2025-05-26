#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Merge Sort functions
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Function to sort user input and measure time
void sortUserInput() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid size.\n");
        return;
    }

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);

    free(arr);
}

// Function to run Merge Sort for different N and record time
void runAndRecordTimes() {
    printf("\n--- Sorting and Recording Times ---\n");

    for (int n = 500; n <= 14500; n += 1000) {
        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            arr[i] = n - i;

        clock_t start = clock();
        mergeSort(arr, 0, n - 1);
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Time taken to sort %5d elements: %f seconds\n", n, time_taken);

        free(arr);
    }
}

int main() {
    printf("Merge Sort Time Measurement Program\n");

    sortUserInput();        // Part 1: Sort a given set of N integers
    runAndRecordTimes();    // Part 2: Run for various N values and record time

    return 0;
}

/*
Sample Input:
Enter the number of elements: 5
Enter 5 integers:
4 2 5 1 3

Sample Output:
Sorted array:
1 2 3 4 5
Time taken to sort 5 elements: 0.0000xx seconds

--- Sorting and Recording Times ---
Time taken to sort   500 elements: ... seconds
Time taken to sort  1500 elements: ... seconds
...
Time taken to sort 14500 elements: ... seconds
*/

