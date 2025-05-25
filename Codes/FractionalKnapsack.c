#include <stdio.h>

// Structure for an item
struct Item {
    int weight;
    int value;
    int index;  // to track original position
};

// Function to swap items
void swap(struct Item* a, struct Item* b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items by value/weight ratio in descending order
void sortItems(struct Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double r1 = (double)arr[i].value / arr[i].weight;
            double r2 = (double)arr[j].value / arr[j].weight;
            if (r1 < r2) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

// Function to calculate max value and display selected items
double fractionalKnapsack(int capacity, struct Item items[], int n) {
    sortItems(items, n);

    double totalValue = 0.0;

    printf("\nItems selected (original index, weight taken, value gained):\n");

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            // Take the whole item
            capacity -= items[i].weight;
            totalValue += items[i].value;
            printf("Item %d: Full (Weight: %d, Value: %d)\n",
                   items[i].index, items[i].weight, items[i].value);
        } else {
            // Take a fraction of the item
            double fraction = (double)capacity / items[i].weight;
            double val = items[i].value * fraction;
            printf("Item %d: %.2f%% (Weight: %d, Value: %.2f)\n",
                   items[i].index, fraction * 100, capacity, val);
            totalValue += val;
            break;  // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item items[n];

    printf("Enter weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &items[i].value);
        items[i].index = i + 1;  // Store original index
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    double maxValue = fractionalKnapsack(capacity, items, n);
    printf("\nMaximum value in knapsack = %.2f\n", maxValue);

    return 0;
}
