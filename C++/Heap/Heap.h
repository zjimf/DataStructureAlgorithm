#ifndef Heap_H
#define Heap_H
class Heap {
private:
    int currentNodeNums;
    int capacity;
    int *arr;

public:
    Heap(int len, int *arr);

    /** @brief build max-heap with arr
     *
     * @param capacity heap size
     * @param arr pointer to the array, insert into the heap
     *
     * @return heap. prepared heap
     */
    Heap *createHeap(int capacity, int *arr);

    /** @brief Adjust to max-heap
     *
     * @param index the position we want adjust
     *
     * @return Void.
     */
    void heapify(int index);

    /** @brief if insert the value in full heap, the heap will double the size
     *
     * @return Void.
     */
    void resizeHeap();

    /** @brief insert data in heap
     *
     * @param data the data we want insert
     *
     * @return Void.
     */
    void insert(int data);

    /** @brief insert helper
     *
     * @param index the position start to adjust to max-heap
     *
     * @return Void.
     */
    void insertHelper(int index);

    /** @brief delete root in the heap
     *
     * @return Int. maximum value in heap
     */
    int deleteMax();

    /** @brief print all value in the heap
     *
     * @return Void.
     */
    void printHeap();
};
#endif
