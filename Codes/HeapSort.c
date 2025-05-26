#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
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
    heapSort(arr, n);
    clock_t end = clock();

    printf("Sorted array:\n");
    printArray(arr, n);

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
        heapSort(arr, n);
        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Time taken to sort %5d elements: %f seconds\n", n, time_taken);

        free(arr);
    }
}

int main() {
    printf("Heap Sort Time Measurement Program\n");

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
Time taken to sort   500 elements: 0.000xxx seconds
Time taken to sort  1500 elements: 0.000xxx seconds
...
Time taken to sort 14500 elements: 0.00xxxx seconds
*/
