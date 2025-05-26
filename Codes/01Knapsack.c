#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

void knapsack(int n, int W, int weights[], int values[]) {
    int dp[n + 1][W + 1];

    // Build the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Print DP table
    printf("\nThe Table is:\n");
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            printf("%d\t", dp[i][w]);
        }
        printf("\n");
    }

    // Print maximum value
    printf("\nMaximum value: %d\n", dp[n][W]);

    // Trace back to find selected items
    printf("Selected items (weight, value):\n");
    int w = W;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            printf("Item %d-(%d, %d)\n", i, weights[i - 1], values[i - 1]);
            w -= weights[i - 1];
        }
    }
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];

    printf("Enter the weights and values of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &weights[i]);
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &values[i]);
    }

    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);

    knapsack(n, W, weights, values);

    return 0;
}


/*
Sample Input/Output:

Enter the number of items: 3
Enter the weights and values of the items:
Item 1 - Weight: 1
Item 1 - Value: 10
Item 2 - Weight: 3
Item 2 - Value: 40
Item 3 - Weight: 4
Item 3 - Value: 50
Enter the maximum capacity of the knapsack: 5

The Table is:
0	0	0	0	0	0
0	10	10	10	10	10
0	10	10	40	50	50
0	10	10	40	50	60

Maximum value: 60
Selected items (weight, value):
Item 3-(4, 50)
Item 1-(1, 10)
*/
