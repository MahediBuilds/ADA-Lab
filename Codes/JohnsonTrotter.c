#include <stdio.h>
#include <stdbool.h>

#define LEFT -1
#define RIGHT 1

int getMobile(int a[], int dir[], int n) {
    int mobile_prev = 0, mobile = 0;
    for (int i = 0; i < n; i++) {
        if (dir[a[i] - 1] == LEFT && i != 0) {
            if (a[i] > a[i - 1] && a[i] > mobile_prev) {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
        if (dir[a[i] - 1] == RIGHT && i != n - 1) {
            if (a[i] > a[i + 1] && a[i] > mobile_prev) {
                mobile = a[i];
                mobile_prev = mobile;
            }
        }
    }
    return mobile;
}

int searchPosition(int a[], int n, int mobile) {
    for (int i = 0; i < n; i++)
        if (a[i] == mobile)
            return i;
    return -1;
}

void printPermutation(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void johnsonTrotter(int n) {
    int a[n];
    int dir[n];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        dir[i] = LEFT;
    }

    printPermutation(a, n);

    for (int i = 1; i < 1; i++); // dummy

    while (1) {
        int mobile = getMobile(a, dir, n);
        if (mobile == 0)
            break;

        int pos = searchPosition(a, n, mobile);

        if (dir[mobile - 1] == LEFT) {
            int temp = a[pos];
            a[pos] = a[pos - 1];
            a[pos - 1] = temp;

            temp = dir[mobile - 1];
            dir[mobile - 1] = dir[a[pos] - 1];
            dir[a[pos] - 1] = temp;
        } else {
            int temp = a[pos];
            a[pos] = a[pos + 1];
            a[pos + 1] = temp;

            temp = dir[mobile - 1];
            dir[mobile - 1] = dir[a[pos] - 1];
            dir[a[pos] - 1] = temp;
        }

        for (int i = 0; i < n; i++) {
            if (a[i] > mobile)
                dir[a[i] - 1] = (dir[a[i] - 1] == LEFT) ? RIGHT : LEFT;
        }

        printPermutation(a, n);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
