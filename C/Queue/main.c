#include "Queue_Arr.h"
#include "Queue_LinkedList.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
void queue_Arr();
void queue_LinkedList();

int main() {
    printf("Implement Stack with Array\n");
    queue_Arr();
    printf("-------------------------------------------------\n");
    printf("Implement Stack with LinkedList\n");
    queue_LinkedList();
}

void queue_Arr() {
    QueueArr q = {{0}, 0, 0};

    printf("The Queue is %s\n", empty_Arr(&q) ? "empty" : "have data");

    enqueue_Arr(&q, 1);
    enqueue_Arr(&q, 2);
    enqueue_Arr(&q, 3);
    enqueue_Arr(&q, 4);
    enqueue_Arr(&q, 5);
    print_Arr(&q);

    printf("dequeue value is:%d\n", dequeue_Arr(&q));
    printf("dequeue value is:%d\n", dequeue_Arr(&q));
    printf("dequeue value is:%d\n", dequeue_Arr(&q));
    printf("dequeue value is:%d\n", dequeue_Arr(&q));
    printf("dequeue value is:%d\n", dequeue_Arr(&q));
    print_Arr(&q);

    printf("The Queue is %s\n", empty_Arr(&q) ? "empty" : "have data");
}
void queue_LinkedList() {
    QueueLinkedList *q = (QueueLinkedList *)malloc(sizeof(QueueLinkedList));
    q->front = q->rear = NULL;

    printf("The Queue is %s\n", empty_LinkedList(q) ? "empty" : "have data");

    enqueue_LinkedList(q, 1);
    enqueue_LinkedList(q, 2);
    enqueue_LinkedList(q, 3);
    enqueue_LinkedList(q, 4);
    enqueue_LinkedList(q, 5);
    print_LinkedList(q);

    printf("dequeue value is:%d\n", dequeue_LinkedList(q));
    printf("dequeue value is:%d\n", dequeue_LinkedList(q));
    printf("dequeue value is:%d\n", dequeue_LinkedList(q));
    printf("dequeue value is:%d\n", dequeue_LinkedList(q));
    printf("dequeue value is:%d\n", dequeue_LinkedList(q));
    print_LinkedList(q);

    printf("The Queue is %s\n", empty_LinkedList(q) ? "empty" : "have data");
}