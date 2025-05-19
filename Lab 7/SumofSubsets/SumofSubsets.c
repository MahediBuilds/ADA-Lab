#include <stdio.h>

#define MAX 20

void printSubset(int subset[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++)
        printf("%d ", subset[i]);
    printf("}\n");
}

void sumOfSubsets(int set[], int subset[], int n, int subsetSize, int total, int node, int target) {
    if (total == target) {
        printSubset(subset, subsetSize);
        return;
    }
    if (node == n || total > target)
        return;

    subset[subsetSize] = set[node];
    sumOfSubsets(set, subset, n, subsetSize + 1, total + set[node], node + 1, target);

    sumOfSubsets(set, subset, n, subsetSize, total, node + 1, target);
}

int main() {
    int n, set[MAX], target, subset[MAX];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter the target sum: ");
    scanf("%d", &target);

    printf("Subsets with sum %d are:\n", target);
    sumOfSubsets(set, subset, n, 0, 0, 0, target);

    return 0;
}