#ifndef Queue_LinkedList_H
#define Queue_LinkedList_H

class QueueLinkedList;

class Node {
private:
    int data;
    Node *next;

public:
    Node(int data);

    friend class QueueLinkedList;
};

class QueueLinkedList {
private:
    Node *front;
    Node *rear;

public:
    QueueLinkedList();

    /** @brief Enqueue data in the Queue
     *
     * @param val the value we want to enqueue
     *
     * @return Void.
     */
    void enqueue_LinkedList(int val);

    /** @brief Dequeue data in the Queue
     *
     * @return Int. the value we dequeue
     */
    int dequeue_LinkedList();

    /** @brief Determine the Queue is empty
     *
     * @return Bool. is empty
     */
    bool empty_LinkedList();

    /** @brief Print all data in Queue
     *
     * @return Void.
     */
    void print_LinkedList();
};

#endif