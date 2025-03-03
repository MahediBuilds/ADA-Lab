// 3rd March 2025
// LeetCode Qn : https://leetcode.com/problems/min-stack/

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>  

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} MinStack;


MinStack* minStackCreate() {
    MinStack* stack = (MinStack*)malloc(sizeof(MinStack));  
    if (stack != NULL) {
        stack->top = -1;
    }
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    if (obj->top < MAX - 1) {  
        obj->top++;
        obj->arr[obj->top] = val;
    }
}

void minStackPop(MinStack* obj) {
    if (obj->top >= 0) {  
        obj->top--;
    }
}

int minStackTop(MinStack* obj) {
    if (obj->top >= 0) {
        return obj->arr[obj->top];
    }
    return -1; 
}

int minStackGetMin(MinStack* obj) {
    if (obj->top < 0) return -1; 

    int min = INT_MAX;  
    for (int i = 0; i <= obj->top; i++) {
        if (obj->arr[i] < min) {
            min = obj->arr[i];
        }
    }

    return min;
}

void minStackFree(MinStack* obj) {
    free(obj);  
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
*/

