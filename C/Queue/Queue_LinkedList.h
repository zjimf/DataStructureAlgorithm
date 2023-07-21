#ifndef Queue_LinkedList_H
#define Queue_LinkedList_H
#include "stdbool.h"

struct Node {
    int data;
    struct Node *next;
};
typedef struct Node Node;

struct QueueLinkedList {
    Node *front;
    Node *rear;
};
typedef struct QueueLinkedList QueueLinkedList;

/** @brief Enqueue data in the Queue
 *
 * @param q pointer to Queue
 * @param val the value we want to enqueue
 *
 * @return Void.
 */
void enqueue_LinkedList(QueueLinkedList *q, int val);

/** @brief Dequeue data in the Queue
 *
 * @param q pointer to Queue
 *
 * @return Int. the value we dequeue
 */
int dequeue_LinkedList(QueueLinkedList *q);

/** @brief Determine the Queue is empty
 *
 * @param q pointer to Queue
 *
 * @return Bool. is empty
 */
bool empty_LinkedList(QueueLinkedList *q);

/** @brief Print all data in Queue
 *
 * @param q pointer to Queue
 *
 * @return Void.
 */
void print_LinkedList(QueueLinkedList *q);

#endif