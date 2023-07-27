#include "Heap.h"
#include <iostream>
using namespace std;

int main() {
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(arr) / sizeof(arr[0]);

    Heap *heap = new Heap(len, arr);
    cout << "create heap" << endl;
    heap->printHeap();

    heap->insert(10);
    cout << "after insert 10" << endl;
    heap->printHeap();

    heap->deleteMax();
    cout << "after delete Maximum" << endl;
    heap->printHeap();
}