#ifndef Queue_Arr_H
#define Queue_Arr_H
#define MAX_LEN 100
#include <stdbool.h>

struct QueueArr {
    int value[MAX_LEN];
    int front;
    int rear;
};

typedef struct QueueArr QueueArr;

/** @brief Enqueue data in the Queue
 *
 * @param q pointer to Queue
 * @param val the value we want to enqueue
 *
 * @return Void.
 */
void enqueue_Arr(QueueArr *q, int val);

/** @brief Dequeue data in the Queue
 *
 * @param q pointer to Queue
 *
 * @return Int. the value we dequeue
 */
int dequeue_Arr(QueueArr *q);

/** @brief Determine the Queue is empty
 *
 * @param q pointer to Queue
 *
 * @return Bool. is empty
 */
bool empty_Arr(QueueArr *q);

/** @brief Print all data in Queue
 *
 * @param q pointer to Queue
 *
 * @return Void.
 */
void print_Arr(QueueArr *q);

#endif