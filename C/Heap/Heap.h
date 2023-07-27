#ifndef Heap_H
#define Heap_H

typedef struct Heap heap;
struct Heap {
    int *arr;
    int currentNodeNums;
    int capacity;
};

/** @brief build max-heap with arr
 *
 * @param capacity heap size
 * @param arr pointer to the array, insert into the heap
 *
 * @return heap. prepared heap
 */
heap *createHeap(int capacity, int *arr);

/** @brief Adjust to max-heap
 *
 * @param h pointer to the heap
 * @param index the position we want adjust
 *
 * @return Void.
 */
void heapify(heap *h, int index);

/** @brief if insert the value in full heap, the heap will double the size
 *
 * @param h pointer to the heap
 *
 * @return Void.
 */
void resizeHeap(heap *h);

/** @brief insert data in heap
 *
 * @param h pointer to the heap
 * @param data the data we want insert
 *
 * @return Void.
 */
void insert(heap *h, int data);

/** @brief insert helper
 *
 * @param h pointer to the heap
 * @param index the position start to adjust to max-heap
 *
 * @return Void.
 */
void insertHelper(heap *h, int index);

/** @brief delete root in the heap
 *
 * @param h pointer to the heap
 *
 * @return Int. maximum value in heap
 */
int deleteMax(heap *h);

/** @brief print all value in the heap
 *
 * @param h pointer to the heap
 *
 * @return Void.
 */
void printHeap(heap *h);
#endif