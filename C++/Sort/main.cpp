#include "Sort.h"
#include <iostream>
using namespace std;

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << "original arr: " << endl;
    printArr(arr, len);
    // cout << "insertion sort: " << endl;
    // insertionSort(arr, len);
    // cout << "selection sort: " << endl;
    // selectionSort(arr, len);
    // cout << "bubble sort: " << endl;
    // bubbleSort(arr, len);
    // cout << "merge sort: " << endl;
    // mergeSort(arr, 0, len - 1);
    // cout << "quick sort: " << endl;
    // quickSort(arr, 0, len - 1);
    printArr(arr, len);
}