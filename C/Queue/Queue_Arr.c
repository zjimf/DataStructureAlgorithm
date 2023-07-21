#include "Queue_Arr.h"
#include <stdbool.h>
#include <stdio.h>

void enqueue_Arr(QueueArr *q, int val) {
    if ((q->rear + 1) % MAX_LEN == q->front) {
        printf("Queue full\n");
        return;
    }
    q->value[q->rear] = val;
    q->rear = (q->rear + 1) % MAX_LEN;
}

int dequeue_Arr(QueueArr *q) {
    if (q->front == q->rear) {
        printf("Queue empty\n");
        return -1;
    }
    int front = q->value[q->front];
    q->front = (q->front + 1) % MAX_LEN;
    return front;
}

bool empty_Arr(QueueArr *q) {
    if (q->front == q->rear)
        return true;
    return false;
}

void print_Arr(QueueArr *q) {
    for (int i = q->front; i < q->rear; i++) {
        if (i > q->front) {
            printf("%s", "->");
        }
        printf("%d", q->value[i]);
    }
    printf("\n");
}
