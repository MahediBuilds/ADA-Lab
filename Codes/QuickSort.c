#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a; *a = *b; *b = t;
}

int fixedPivotIndex = 3;

int partition(int arr[], int low, int high) {
    int pivotPos = low + fixedPivotIndex;
    if (pivotPos > high) {
        pivotPos = high;
    }
    swap(&arr[pivotPos], &arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

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
    quickSort(arr, 0, n - 1);
    clock_t end = clock();
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);
    free(arr);
}

void runAndRecordTimes() {
    printf("\n--- Sorting and Recording Times ---\n");
    for (int n = 500; n <= 14500; n += 1000) {
        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            arr[i] = n - i;
        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Time taken to sort %5d elements: %f seconds\n", n, time_taken);
        free(arr);
    }
}

int main() {
    printf("Quick Sort Time Measurement Program\n");
    fixedPivotIndex = 3;
    sortUserInput();
    runAndRecordTimes();
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
