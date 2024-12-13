#include <stdio.h>

// Function prototypes
void selectionSort(int arr[], int n);
void displayArray(int arr[], int n);

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array: ");
    displayArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted Array: ");
    displayArray(arr, n);

    return 0;
}

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n-1; i++) {
        // Assume the first element as the minimum
        minIndex = i;
        for (j = i+1; j < n; j++) {
            // Find the smallest element in the unsorted part
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found smallest element with the first element
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}