#include <stdio.h>
void bubbleSort(int arr[], int n) {
    int i, j, temp;

    // Outer loop to traverse through the entire array
    for (i = 0; i < n-1; i++) {
        // Inner loop to compare and swap adjacent elements
        for (j = 0; j < n-i-1; j++) {
            // If the current element is greater than the next element, swap them
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {84, 34, 29, 12, 27, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array before sorting: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Call Bubble Sort function
    bubbleSort(arr, n);

    printf("Array after sorting: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}