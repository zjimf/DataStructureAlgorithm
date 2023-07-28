#include "Sort.h"
#include <stdio.h>

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("original arr: \n");
    printArr(arr, len);
    // printf("insertion sort: \n");
    // insertionSort(arr, len);
    // printf("selection sort: \n");
    // selectionSort(arr, len);
    // printf("bubble sort: \n");
    // bubbleSort(arr, len);
    // printf("merge sort: \n");
    // mergeSort(arr, 0, len - 1);
    // printf("quick sort: \n");
    // quickSort(arr, 0, len - 1);
    printArr(arr, len);
}