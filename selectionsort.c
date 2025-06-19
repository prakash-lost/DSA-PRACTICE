#include <stdio.h>
void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Finding the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) 
            {
                min_idx = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {44, 20, 12, 25, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Array before sorting: \n");
       for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    selectionSort(arr, n);
    
    printf("Array after sorting: \n");
       for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}