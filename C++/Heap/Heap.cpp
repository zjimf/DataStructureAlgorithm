#include "Heap.h"
#include <iostream>
using namespace std;

Heap::Heap(int capacity, int *arr) {
    this->currentNodeNums = capacity;
    this->capacity = capacity;
    this->arr = (int *)malloc(sizeof(int) * capacity);

    for (int i = 0; i < capacity; i++)
        this->arr[i] = arr[i];

    int i = (this->currentNodeNums - 2) / 2;
    while (i >= 0) {
        heapify(i);
        i--;
    }
}

void Heap::heapify(int index) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int maxIndex = index;

    if (left < currentNodeNums && arr[left] > arr[maxIndex])
        maxIndex = left;
    if (right < currentNodeNums && arr[right] > arr[maxIndex])
        maxIndex = right;

    if (maxIndex != index) {
        int temp = arr[maxIndex];
        arr[maxIndex] = arr[index];
        arr[index] = temp;

        heapify(maxIndex);
    }
}

void Heap ::resizeHeap() {
    // if full double the capacity
    int newCapacity = capacity * 2;
    int *newArr = (int *)malloc(sizeof(int) * newCapacity);
    if (newArr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < currentNodeNums; i++) {
        newArr[i] = arr[i];
    }

    free(arr);

    arr = newArr;
    capacity = newCapacity;
}

void Heap ::insert(int data) {
    if (currentNodeNums >= capacity)
        resizeHeap();

    if (currentNodeNums < capacity) {
        arr[currentNodeNums] = data;
        insertHelper(currentNodeNums);
        currentNodeNums++;
    }
}

void Heap ::insertHelper(int index) {
    int parent = (index - 1) / 2;

    if (arr[parent] < arr[index]) {

        int temp = arr[parent];
        arr[parent] = arr[index];
        arr[index] = temp;

        insertHelper(parent);
    }
}

int Heap ::deleteMax() {
    int deleteItem = arr[0];

    arr[0] = arr[currentNodeNums - 1];
    currentNodeNums--;

    heapify(0);
    return deleteItem;
}

void Heap ::printHeap() {
    for (int i = 0; i < currentNodeNums; i++)
        cout << arr[i] << " ";

    cout << endl;
}
