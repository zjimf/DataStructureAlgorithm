#ifndef Queue_Arr_H
#define Queue_Arr_H

class QueueArr {
private:
    int *data;
    int front;
    int rear;
    int size;

public:
    QueueArr(int size);

    /** @brief Enqueue data in the Queue
     *
     * @param val the value we want to enqueue
     *
     * @return Void.
     */
    void enqueue_Arr(int val);

    /** @brief Dequeue data in the Queue
     *
     * @return Int. the value we dequeue
     */
    int dequeue_Arr();

    /** @brief Determine the Queue is empty
     *
     * @return Bool. is empty
     */
    bool empty_Arr();

    /** @brief Print all data in Queue
     *
     * @return Void.
     */
    void print_Arr();
};

#endif