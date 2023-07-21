#include "Queue_LinkedList.h"
#include "stdio.h"
#include "stdlib.h"

void enqueue_LinkedList(QueueLinkedList *q, int val) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = val;

    if (q->front == NULL && q->rear == NULL) {
        q->front = newNode;
    } else {
        q->rear->next = newNode;
    }
    q->rear = newNode;
}

int dequeue_LinkedList(QueueLinkedList *q) {
    if (q->front == NULL) {
        printf("Queue empty\n");
        return -1;
    }
    Node *current = q->front;
    int temp = current->data;
    q->front = current->next;
    free(current);
    return temp;
}

bool empty_LinkedList(QueueLinkedList *q) {
    return q->front == NULL && q->rear == NULL;
}

void print_LinkedList(QueueLinkedList *q) {
    Node *current = q->front;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf("->");
        }
        current = current->next;
    }
    printf("\n");
}
