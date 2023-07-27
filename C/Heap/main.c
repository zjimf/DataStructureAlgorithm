#include "Heap.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    heap *heap = createHeap(9, arr);
    printf("create heap\n");
    printHeap(heap);

    insert(heap, 10);
    printf("after insert 10\n");
    printHeap(heap);

    deleteMax(heap);
    printf("after delete Max\n");
    printHeap(heap);
}