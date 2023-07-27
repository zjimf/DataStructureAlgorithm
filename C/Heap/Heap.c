#include "Heap.h"
#include <stdio.h>
#include <stdlib.h>

heap *createHeap(int capacity, int *arr) {
    heap *h = (heap *)malloc(sizeof(heap));

    // init
    h->currentNodeNums = 0;
    h->capacity = capacity;
    h->arr = (int *)malloc(sizeof(int) * capacity);

    int i;
    for (i = 0; i < capacity; i++)
        h->arr[i] = arr[i];
    h->currentNodeNums = i;

    // last node's parent index
    i = (h->currentNodeNums - 2) / 2;

    while (i >= 0) {
        heapify(h, i);
        i--;
    }
    return h;
}

void heapify(heap *h, int index) {
    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int maxIndex = index;

    // have left/right child
    if (left >= h->currentNodeNums || left < 0)
        left = -1;
    if (right >= h->currentNodeNums || right < 0)
        right = -1;

    if (left != -1 && h->arr[left] > h->arr[maxIndex])
        maxIndex = left;
    if (right != -1 && h->arr[right] > h->arr[maxIndex])
        maxIndex = right;

    if (maxIndex != index) {
        int temp = h->arr[maxIndex];
        h->arr[maxIndex] = h->arr[index];
        h->arr[index] = temp;

        heapify(h, maxIndex);
    }
}

void resizeHeap(heap *h) {
    // if full double the capacity
    int newCapacity = h->capacity * 2;
    int *newArr = (int *)malloc(sizeof(int) * newCapacity);
    if (newArr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    for (int i = 0; i < h->currentNodeNums; i++) {
        newArr[i] = h->arr[i];
    }

    free(h->arr);

    h->arr = newArr;
    h->capacity = newCapacity;
}

void insert(heap *h, int data) {
    if (h->currentNodeNums >= h->capacity)
        resizeHeap(h);

    if (h->currentNodeNums < h->capacity) {
        h->arr[h->currentNodeNums] = data;
        insertHelper(h, h->currentNodeNums);
        h->currentNodeNums++;
    }
}

// bottom up
void insertHelper(heap *h, int index) {
    int parent = (index - 1) / 2;

    if (h->arr[parent] < h->arr[index]) {

        int temp = h->arr[parent];
        h->arr[parent] = h->arr[index];
        h->arr[index] = temp;

        insertHelper(h, parent);
    }
}

int deleteMax(heap *h) {
    int deleteItem = h->arr[0];

    h->arr[0] = h->arr[h->currentNodeNums - 1];
    h->currentNodeNums--;

    heapify(h, 0);
    return deleteItem;
}

void printHeap(heap *h) {
    if (h == NULL)
        return;
    for (int i = 0; i < h->currentNodeNums; i++)
        printf("%d ", h->arr[i]);
    printf("\n");
}