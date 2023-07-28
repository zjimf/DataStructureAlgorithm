#include "Sort.h"
#include <stdbool.h>
#include <stdio.h>
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

void insertionSort(int arr[], int len) {
    int key, j;
    for (int i = 1; i < len; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int len) {

    for (int i = 0; i < len - 1; i++) {
        int k = i;
        for (int j = i + 1; j < len; j++)
            if (arr[j] < arr[k])
                k = j;

        if (k != i)
            swap(&arr[k], &arr[i]);
    }
}

void bubbleSort(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        bool swapped = false;
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            return;
    }
}

void merge(int arr[], int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    // set value
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    int i = 0, j = 0, k = left;

    // insert in original arr
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    // if there is left
    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;

    int middle = left + ((right - left) / 2);

    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    merge(arr, left, middle, right);
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int j = left - 1;
    for (int i = left; i <= right - 1; i++)
        if (arr[i] < pivot)
            swap(&arr[i], &arr[++j]);

    swap(&arr[j + 1], &arr[right]);
    return (j + 1);
}

void quickSort(int arr[], int left, int right) {
    if (left >= right)
        return;
    int pivot = partition(arr, left, right);

    quickSort(arr, left, pivot - 1);
    quickSort(arr, pivot + 1, right);
}

void printArr(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}